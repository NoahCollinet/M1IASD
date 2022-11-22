# Graphe de processus connectés

**Lancement**


Voici le guide d'utilisation de notre algorithme de génération de graphe. 
En premier lieu, on a besoin de lancer un parseur conçu spécialement pour le script avant de lancer celui-ci, afin d'avoir le nombre de sockets à allouer.

On exécute ce parseur avec la commande suivante :  
``gcc parseurscript.c -o parserExe ``

Comme expliqué ci-dessus on peut récupérer juste le nombre de sommets pour le script.

Ensuite on lance le script qui permet de créer le graphe :  
``python3 scriptAnneau.py ``

Le script va d'abord compiler nos fichiers. 
Ensuite il nous propose de rentrer un numéro de port, on choisit un numéro supérieur à 5000.

**Les connexions sont créées et le graphe est généré !**

Pour changer l'instance générée, il suffit d'aller modifier la ligne 22 du fichier *ScriptAnneau.py* et changer le nom du fichier test.
