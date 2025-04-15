#!/bin/bash
# Script de configuración inicial para el Sistema de Control de Asistencia
echo "Configurando el Sistema de Control de Asistencia..."
# Verificar requisitos
echo "Verificando requisitos..."
command -v node >/dev/null 2>&1 || { echo "Node.js no está instalado. Abortando."; exit 1; }
command -v npm >/dev/null 2>&1 || { echo "npm no está instalado. Abortando."; exit 1; }
command -v psql >/dev/null 2>&1 || { echo "PostgreSQL no está instalado. Abortando."; exit 1; }
# Configurar la aplicación web
echo "Configurando la aplicación web..."
cd web
npm install
cp .env.example .env
# Solicitar información de la base de datos
read -p "Ingrese el host de PostgreSQL [localhost]: " db_host
db_host=${db_host:-localhost}
read -p "Ingrese el puerto de PostgreSQL [5432]: " db_port
db_port=${db_port:-5432}
read -p "Ingrese el nombre de la base de datos: " db_name
read -p "Ingrese el usuario de PostgreSQL: " db_user
read -s -p "Ingrese la contraseña de PostgreSQL: " db_password
echo ""
# Actualizar archivo .env
echo "Actualizando configuración..."
sed -i "s|DATABASE_URL=.*|DATABASE_URL=postgresql://$db_user:$db_password@$db_host:$db_port/$db_name|g" .env
# Ejecutar migraciones de Prisma
echo "Ejecutando migraciones de la base de datos..."
npx prisma migrate dev --name init
echo "Configuración completada con éxito."
echo "Para iniciar el servidor de desarrollo, ejecute: cd web && npm run dev"