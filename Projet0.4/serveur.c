// PROBLEME DE COLORATION DE SOMMETS
// Date : Novembre 2022

#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "tcp-utils.c"


#include "parser.h"

struct sousAnneau {
    int descripteur;
    struct sockaddr_in sockaddr_in;
};

void afficheListeSousAnneaux(struct sousAnneau sousAnneaux[], int taille) {
    char adresse[INET_ADDRSTRLEN];
    afficheLigne();
    printf("[SERVEUR] Liste des sous-anneaux:\n");
    for (int i=0; i<taille; i++) {
        inet_ntop(AF_INET, &sousAnneaux[i].sockaddr_in.sin_addr, adresse, INET_ADDRSTRLEN);
        int port = htons(sousAnneaux[i].sockaddr_in.sin_port);
        printf("[SERVEUR] %i) %i : %s:%i\n", i, sousAnneaux[i].descripteur, adresse, port);
    }
    afficheLigne();
}

int retraitListeSousAnneau(struct sousAnneau sousAnneaux[], int descripteur, int taille) {
    int index;
    int max = sousAnneaux[0].descripteur;
    for (index=0; index<taille; index++) {
        if (sousAnneaux[index].descripteur == descripteur) break;
        if (max < sousAnneaux[index].descripteur) max = sousAnneaux[index].descripteur;
    }
    if (index == taille) return -1;

    while (index < taille-1) {
        sousAnneaux[index] = sousAnneaux[index+1];
        if (max < sousAnneaux[index].descripteur) max = sousAnneaux[index].descripteur;
        index++;
    }
    return max;
}

void deconnexionSousAnneau(
    int descripteur, 
    fd_set* set,
    int* currentMax,
    int* maxDescripteur,
    struct sousAnneau sousAnneaux[]
) {
    FD_CLR(descripteur, set);
    printf("[SERVEUR] Un sous-anneau s'est déconnecté\n");
    close(descripteur);
    int newMax = retraitListeSousAnneau(sousAnneaux, descripteur, (*currentMax));
    if (newMax == -1) {
        printf("[SERVEUR] Problème: le sous-anneau n'était pas dans la liste\n");
    } else {
        (*currentMax)--;
        (*maxDescripteur) = newMax;
    }
}

int attributionNumeroSousAnneau(
    int descripteur, 
    int* currentMax, 
    struct sousAnneau sousAnneaux[], 
    struct sockaddr_in sockClient, 
    fd_set* set, 
    int* maxDescripteur
) {
    char adresse[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &sockClient.sin_addr, adresse, INET_ADDRSTRLEN);
    printf("[SERVEUR] Connexion d'un sous-anneau: %s\n", adresse);
    FD_SET(descripteur, set);
    if ((*maxDescripteur) < descripteur) (*maxDescripteur) = descripteur;
    sousAnneaux[(*currentMax)].descripteur = descripteur;
    sousAnneaux[(*currentMax)].sockaddr_in = sockClient;
    struct paquet attribution;
    attribution.requete = ATTRIBUTION_NUMERO;
    attribution.information = (*currentMax);
    (*currentMax)++;
    return send2TCP(descripteur, &attribution, sizeof(struct paquet));
}

int receptionAdresseEcoute(int descripteur, struct sockaddr_in* sock) {
    struct paquet msg;
    if (recv2TCP(descripteur, &msg, sizeof(struct paquet)) <= 0) {
        printf("[SERVEUR] Problème lors de la réception de l'adresse d'écoute\n");
        return -1;
    }
    (*sock) = msg.adresse;
    return 1;
}


//c'est de moi ça
int connectDeuxAnneaux(struct sousAnneau sousAnneau[], int a, int b){ //ajoute le processus b comme voisin du processus a
    struct paquet msg;
    msg.requete = ADRESSE_VOISIN;
    msg.adresse = sousAnneau[b].sockaddr_in;
    char adresse[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &msg.adresse.sin_addr, adresse, INET_ADDRSTRLEN);
    int port = htons(msg.adresse.sin_port);
    printf("[SERVEUR] Envoi de l'adresse: %s:%i\n", adresse, port);
    if (send2TCP(sousAnneau[a].descripteur, &msg, sizeof(struct paquet)) <= 0) {
        printf("[SERVEUR] Problème lors de l'envoi des adresses\n");
        return 1;
    }
    return 0;
}


//Là il se passe des trucs cool
int envoyerAdressesSousAnneaux(struct sousAnneau sousAnneau[], int *vertices, int (*edges)[2], int nbEdges) { 

    for (size_t n = 0; n < nbEdges; ++n) { // Affichage des arrêtes
        printf("Connexion des arrêtes %i et %i\n",edges[n][0],edges[n][1]);

        connectDeuxAnneaux(sousAnneau, edges[n][0], edges[n][1]);
        connectDeuxAnneaux(sousAnneau, edges[n][1], edges[n][0]);
    }

    // if (nbNode < 3) {
    //     printf("[SERVEUR] Impossible de créer un anneau avec moins de trois sous-anneaux\n");
    //     return -1;
    // }

    // for (int i=0; i<taille; i++) {
    //     for (int j=0; j<taille; j++) {
    //         if(i!=j)
    //         connectDeuxAnneaux(sousAnneau, i, j);
    //     }
    // }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 4){
        printf("[SERVEUR] utilisation : %s port_serveur nombre_sous_anneaux fichierGraph\n", argv[0]);
        exit(1);
    }

    //////////////////Parsing du graphe 

    FILE *file = fopen(argv[3], "r"); //Ouverture du fichier

    int *vertices, (*edges)[2], *props; // Création des tableaux
    parse(file, &vertices, &edges, &props); // Allocation et initialisation des tableaux

    
    for (size_t n = 0; n < props[1]; ++n) { // Affichage des arrêtes
        printf("%d -> ", edges[n][0]);
        printf("%d\n", edges[n][1]);
    } 

    int nbNodes = props[0];
    int nbEdges = props[1];

    printf("Nombre de noeuds : %i\n",nbNodes);
    printf("Nombre d'arrêtes : %i\n",nbEdges);


    //////////////////



    int nombreSousAnneaux = atoi(argv[2]);
    nombreSousAnneaux = nbNodes;

    int ds = creerSocket();
    nommerSocket(argv[1],ds);
    int nbMaxAttente = 100;
    listenTCP(ds, nbMaxAttente);

    fd_set set, settmp;
    int dsClient;
    FD_ZERO(&set);
    FD_SET(ds, &set);
    int maxDescripteur = ds;
    struct sockaddr_in sockClient; 
    socklen_t lgAdr;
    int nbMaxAnneau = 1000;
    struct sousAnneau sousAnneaux[nbMaxAnneau];
    int currentMaxAnneau = 0;

    while (TRUE) {
        settmp = set;
        if (select(maxDescripteur+1, &settmp, NULL, NULL, NULL) == -1) {
            printf("[SERVEUR] Problème lors du select\n");
            afficheErreur();
            continue;
        }

        for (int df=2; df <= maxDescripteur; df++) {
            if (!FD_ISSET(df, &settmp)) {
                continue;
            }

            if (df == ds) {
                dsClient = accept(ds, (struct sockaddr*)&sockClient, &lgAdr);
                if (receptionAdresseEcoute(dsClient, &sockClient) < 0) {
                    continue;
                }
                if (attributionNumeroSousAnneau(dsClient, &currentMaxAnneau, sousAnneaux, sockClient, &set, &maxDescripteur) <= 0) {
                    deconnexionSousAnneau(dsClient, &set, &currentMaxAnneau, &maxDescripteur, sousAnneaux);
                } else {
                    afficheListeSousAnneaux(sousAnneaux, currentMaxAnneau);
                }
                continue;
            }
        }

        if (currentMaxAnneau == nombreSousAnneaux) {
            printf("[SERVEUR] Tous les anneaux sont connectés, envoi des adresses\n");
            if (envoyerAdressesSousAnneaux(sousAnneaux, vertices, edges, nbEdges) == -1) {
                printf("[SERVEUR] Problème lors de l'envoi des adresses\n");
            } else {
                printf("[SERVEUR] Envoi réussi\n");
            }
            if (close(ds) == -1) {
                printf("[SERVEUR] Problème lors de la fermeture du descripteur\n");
                afficheErreur();
            }
            printf("[SERVEUR] Au revoir.\n");
            exit(0);
        }
    }
}
