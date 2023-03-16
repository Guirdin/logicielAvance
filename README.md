# Créer un système de gestion de bases de données

Le but est de créer un système de base de données avec connexion. Toutes les données sont enregistrer sur la machine dans des fichiers au format CSV

Le choix de la technologie est à votre appréciation

## Collaborateurs
* [Julien Mercadal](https://github.com/jeremydeblaecker) 
* [Jérémy Deblaecker](https://github.com/borkevo)
* [Jimmy Muller](https://github.com/Guirdin)

## Consignes
Créer un logiciel en ligne de commande 

Les identifiants sont enregistrés dans un fichier, permettre de tester les identifiants sans devoir faire de requêtes SQL. (option -t permet de tester les identifiants)
mybdd -u user -p password -l
 Login success

Une fois la connexion faite laisser la possibilitée à l’utilisateur de faire les commandes suivante:
* CREATE DATABASE database
* SHOW DATABASES
* CREATE TABLE table (col1, col2, col3)
* SHOW TABLES
* DESCRIBE TABLE
* INSERT INTO table VALUES (value1, value2, value3)
* SELECT * FROM table


Donner la possibilitée à l’utilisateur de faire des requêtes en une ligne
mybdd -u user -p password --sql “CREATE DATABASE database”

Ajouter la possibilité de sortie d’affichage --format=csv
* CSV
* JSON
* Au format tableau visuel

Ajouter les options -h --help || -v --version || -l --login || -u --user || -p --password || -s --sql || -f --format