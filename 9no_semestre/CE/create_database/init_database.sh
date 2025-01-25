#!/bin/bash
docker run --name mysql-inventario -e MYSQL_ROOT_PASSWORD=rootpassword -e MYSQL_DATABASE=inventario -e MYSQL_USER=user -e MYSQL_PASSWORD=password -v $(pwd)/mysql_data/init.sql:/docker-entrypoint-initdb.d/init.sql -d mysql:latest


docker exec -it mysql-inventario mysql -uuser -ppassword -h 127.0.0.1 -P 3306
