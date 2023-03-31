cd C:\kafka
start bin\windows\zookeeper-server-start.bat config/zookeeper.properties
TIMEOUT /T 10
start bin\windows\kafka-server-start.bat config/server.properties
TIMEOUT /T 10
start bin\windows\kafka-console-consumer.bat --bootstrap-server localhost:9092 --topic blog
start bin\windows\kafka-console-consumer.bat --bootstrap-server localhost:9092 --topic notification
start bin\windows\kafka-console-producer.bat --broker-list localhost:9092 --topic notification