#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define IS_NUM(c) (c >= '0' && c <= '9')

// Fonction de parsing de fichier de graphe de la forme trouvable à l'adresse :
// https://cedric.cnam.fr/~porumbed/graphs/flat300_26_0.col
// IN : un stream, un pointeur vers un tableau d'entier et un tableau de couples
// d'entiers OUT : Nil RESULT : Initialise le tableau de sommets à la bonne
// taille et remplit le tableau d'arrêtes

void parse(FILE *file, int **vertices, int (**edges)[2], int **props) {
  char c;
  int *v, (*ed)[2], nbSommets, nbArretes;
  int e = 0;

  while ((c = fgetc(file)) != EOF) {

    if (c == 'c') {
      // Tant qu'on lit un commentaire on ignore
      while (c != '\n') {
        c = fgetc(file);
      }
    }

    if (c == 'p') {
      // Lecture des propriétés de la forme "p edge int int \n"

      while (!IS_NUM(c)) {
        // Tant que le caractère n'est pas un chiffre on ignore
        c = fgetc(file);
      }

      // Lecture du chiffre caractère par caractère
      char num[20];
      int i = 0;

      while (IS_NUM(c)) {
        num[i] = c;
        c = fgetc(file);
        ++i;
      }

      num[i] = '\0';

      // Quand on a notre nombre de sommets on alloue la mémoire dynamiquement
      printf("%d\n", atoi(num));
      nbSommets = atoi(num);
      v = malloc(atoi(num) * sizeof(int));

      if (!ed) {
        fprintf(stderr, "couldn't allocate memory\n");
        exit(3);
      }

      c = fgetc(file); // Ignorer un retour à la ligne

      // On fait la même chose pour le nombre d'arrêtes
      i = 0;

      while (IS_NUM(c)) {
        num[i] = c;
        c = fgetc(file);
        ++i;
      }

      num[i] = '\0';

      printf("%d\n", atoi(num));
      nbArretes = atoi(num);
      ed = malloc(sizeof(int[atoi(num)][2]));

      if (!v) {
        fprintf(stderr, "couldn't allocate memory\n");
        exit(2);
      }

      while (c != '\n') {
        c = fgetc(file);
      }
    }

    if (c == 'e') {
      // Si on lit une ligne qui commence par "e" on ajoute une arrête à notre
      // tableau
      while (!IS_NUM(c)) {
        c = fgetc(file);
      }

      char num[20];
      int i = 0;

      while (IS_NUM(c)) {
        num[i] = c;
        c = fgetc(file);
        ++i;
      }

      num[i] = '\0';

      ed[e][0] = atoi(num); // On lit le premier chiffre qu'on ajoute en premier
                            // élément de notre couple
      c = fgetc(file);

      i = 0;

      while (IS_NUM(c)) {
        num[i] = c;
        c = fgetc(file);
        ++i;
      }

      num[i] = '\0';

      ed[e][1] = atoi(num);

      while (c != '\n') {
        c = fgetc(file);
      }
      e++;
    }
  }
  *vertices = v;
  *edges = ed;


  int res[2] = {nbSommets, nbArretes};
  *props = res;
}

/*
 * Exemple d'utilisation de la procédure parse */
int main(int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "USAGE: %s <input name>", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "r");

  int *vertices, (*edges)[2], *props; // Création des tableaux
  parse(file, &vertices, &edges, &props); // Allocation et initialisation des tableaux

  /* for (size_t n = 0; n < props[1]; ++n) { // Affichage des arrêtes
    printf("%d -> ", edges[n][0]);
    printf("%d\n", edges[n][1]);
  } 
  */

//printf("%d", vertices);
  // Désallocation des pointeurs
  free(file);
  free(edges);
  free(vertices);

  return 0;
}
