# Configuration de l'application

Vous pouvez effectuer les commandes `make` manuellement, ou utiliser le script fourni, **setup.sh**.
Il vous permettra de compiler et lancer le programme automatiquement dans un second terminal (nécessite d'installer le paquet gnome-terminal) :

    ./setup.sh

## Utilisation des différents programmes

Le programme **treeload** charge une arborescence en mémoire.
Avec le programme **treesearch** vous avez la possibilité de passer un argument sur la ligne de commande pour préciser le nom d'un dossier à trouver :

	ex : ./treesearch fichier

Le programme **treesearch** peut également fermer le programme **treeload** en placant en argument **--close** à la place du nom de fichier à rechercher :

	ex : ./treesearch --close

Toutes les opérations lancées depuis **treesearch** auront pour effet de générer des réponses de **treeload**, notamment les affichages des résultats, et ce dans le terminal ou est exécuté **treeload**.

## Auteur
- [GILLIER Théophile](https://github.com/gillie04th)
