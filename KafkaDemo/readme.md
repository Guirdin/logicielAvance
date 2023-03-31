# Kafka projet

* 05-08-producer-poller-executable

## Présentation
* [Ressources du cours](https://drive.google.com/drive/folders/11tBnjQF_3RQmbr1hhlx37w8iPMv_VJ_7)  

## pré-requis

- Télécharger kafka: [Scala 2.13  - kafka_2.13-3.4.0.tgz](https://drive.google.com/drive/folders/11tBnjQF_3RQmbr1hhlx37w8iPMv_VJ_7)

## Technologies utilisées : 
 * Eclipse
 * Java

## Lancement du projets

Mettre le dossier décompresser kafka.zip à "C:\kafka"
Dans Eclipse faite `import -> Existing Maven Projects`

Ce projet est lancé à partir de:
* Fichier StartKafka.bat
* Puis `demo-producerpoller`lancer depuis Eclipse clic droit sur le projet puis `run as` avec goals = `spring-boot:run`

# Important
Si les cmd affiche deconnexion en boucle il faut relancer le .bat
Supprimer les 4 dernieres fenetre et relancer le .bat
Ensuite supprimer directement la premiere fenenetre de zookiper avec la fin du timer de l'autre fenetre

