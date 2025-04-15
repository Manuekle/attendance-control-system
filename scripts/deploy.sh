#!/bin/bash
# Script de despliegue para el Sistema de Control de Asistencia
echo "Desplegando el Sistema de Control de Asistencia..."
# Verificar rama actual
current_branch=$(git rev-parse --abbrev-ref HEAD)
if [ "$current_branch" != "main" ]; then
read -p "No estás en la rama main. ¿Deseas continuar? (s/n): " confirm
if [ "$confirm" != "s" ]; then
echo "Despliegue cancelado."
exit 1
fi
fi
# Actualizar repositorio
echo "Actualizando repositorio..."
git pull
# Desplegar aplicación web
echo "Desplegando aplicación web..."
cd web
# Instalar dependencias
npm install
# Construir la aplicación
npm run build
# Ejecutar migraciones de base de datos
npx prisma migrate deploy
# Reiniciar servicio (ajustar según el entorno)
if command -v pm2 >/dev/null 2>&1; then
pm2 restart attendance-system
else
echo "PM2 no está instalado. Por favor, reinicie el servicio manualmente."
fi
echo "Despliegue completado con éxito."