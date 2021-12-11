
Projet C
Contents

    1. Sujet
    1.1. Partie I : à rendre le 6 novembre
    1.2. Partie II : à rendre le 18 décembre
    2. Infos pratiques
    2.1. Organisation du travail
    2.2. Remise du travail
    2.3. Correction
    2.4. Notation

Renseigner ICI la composition du binôme et l’URL github associée. Donner à l’utilisateur jaclin l’accès en lecture au repo git.
1. Sujet

Il s’agit de réaliser une application localisant rapidement une entrée de répertoire (fichier, répertoire, lien, etc) sur le disque. Par exemple, la recherche de passwd doit trouver /etc/passwd. De même, la recherche de tmp doit trouver /tmp et /var/tmp.
1.1. Partie I : à rendre le 6 novembre

Ecrire 2 fonctions : load qui charge en mémoire, dans une structure de données adaptée, une arborescence de répertoires, et search qui localise les occurrences d’une entrée donnée (dont le nom est fourni en argument) dans la structure de données précédente.

Créer une bibliothèque contenant ces 2 fonctions (et éventuellement d’autres fonctions ayant un potentiel de réutilisation).

Construire un programme treetest pour tester ces 2 fonctions. treetest est appelé avec un nom de fichier en argument (sur la ligne de commande), et écrit les emplacements correspondants.

treetest lit d’autres paramètres dans un fichier de configuration tree.conf.

tree.conf définit différentes variables. A ce stade, on commence par une seule variable rootdir spécifiant la racine de l’arborescence à traiter.
	Optionnellement, on pourra clarifier le fichier de configuration en autorisant les lignes blanches et les commentaires (sous une forme à choisir).
exemple de fichier tree.conf autorisant les commentaires

# racine des répertoires à charger
rootdir=/var

Faire en sorte que le programme utilise ce fichier de configuration.

Rédiger un Makefile pour la bibliothèque et un autre pour le programme.

#############################

1.2. Partie II : à rendre le 18 décembre

Ecrire un programme treeload, réceptif au signal SIGHUP, qui charge une arborescence en mémoire et reste indéfiniment en attente de signaux.

A l’arrivée de SIGHUP, treeload lit dans un fichier, dont le nom est spécifié dans le fichier de configuration tree.conf, le nom du fichier à rechercher, puis écrit les emplacements correspondants.

Ecrire un second programme treesearch qui :

    récupère un nom de fichier sur la ligne de commande,

    le mémorise dans le fichier dont le nom est spécifié dans le fichier de configuration,

    envoie un signal SIGHUP à treeload.

Cela nécessite de gérer 2 variables supplémentaires dans tree.conf, datafile et pidfile :
fichier tree.conf

# fichier pour passer les paramètres
datafile=/tmp/treeload.data

# fichier contenant le PID du treeload en cours d'exécution
pidfile=/tmp/treeload.pid

Réutiliser bien-entendu la bibliothèque faite en partie I. Faire en sorte que treeload et treesearch se compilent avec la commande make.

#############################

2. Infos pratiques
2.1. Organisation du travail

    projet à réaliser en binôme

    créer un dépot git privé sur github (par personne ou par binôme au choix), et donner des droits de lecture à jaclin

2.2. Remise du travail

Pour le 6 novembre

    Prévoir une démo à partir des fichiers du dépôt git.

    A la suite de cette démo, tout binôme pourra choisir d’utiliser la partie I d’un binôme de son choix pour réaliser sa partie II. Il devra alors le mentionner explicitement en commentaire dans ses fichiers sources.
Pour le 18 décembre

    Remettre sur Moodle une archive .tgz contenant les fichiers strictement nécessaires : code source, Makefile, fichiers de configuration de l’application et documentation (pas de binaire, ni tout autre fichier généré à partir de ces fichiers de base).
    	La date de fin de fermeture du dépôt Moodle ne sera pas repoussée, les projets non remis à la date donnée seront notés 0.

2.3. Correction

Le correcteur décompactera l’archive avec tar xzf. Il essaiera ensuite de compiler la bibliothèque par une commande make dans le dossier de la bibliothèque, puis l’application principale par un make dans le dossier du programme, sans se poser d’autres questions. Il testera ensuite l’application en suivant le mode d’emploi fourni, sans se poser d’autres questions.
2.4. Notation

La note tiendra compte des éléments suivants :

    stabilité de l’application (un programme qui plante sera très mal noté)
    	Mieux vaut donc jouer la transparence, en annonçant qu’une fonctionnalité n’a pas été implémentée, plutôt que de fournir un programme qui plante.

    conformité des résultats obtenus par rapport au sujet (un programme qui ne sort pas ce qu’il faut sera mal noté)
    	Mieux vaut donc jouer, là encore, la transparence, en annonçant qu’une fonctionnalité n’a pas été implémentée, plutôt que de sortir n’importe quoi.

    qualité du code : organisation, modularité, documentation, indentation (un programme propre, clair, agréable à comprendre sera favorisé)

    performances, fonctionnalités optionnelles et autres initiatives personnelles (des bonus)

Chaque reprise d’une partie I par un autre binome donnera lieu à bonus supplémentaires.
