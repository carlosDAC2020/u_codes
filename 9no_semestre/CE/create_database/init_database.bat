@echo off
docker run --name mysql-inventario ^
  -e MYSQL_ROOT_PASSWORD=rootpassword ^
  -e MYSQL_DATABASE=inventario ^
  -e MYSQL_USER=user ^
  -e MYSQL_PASSWORD=password ^
  -v "%cd%/mysql_data/init.sql:/docker-entrypoint-initdb.d/init.sql" ^
  -p 3306:3306 ^
  -d mysql:latest

