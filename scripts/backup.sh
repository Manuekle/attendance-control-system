#!/bin/bash
# Script de respaldo para la base de datos del Sistema de Control de Asistencia
# Configuración
DB_NAME="attendance_system"
DB_USER="postgres"
BACKUP_DIR="./backups"
DATE=$(date +"%Y%m%d_%H%M%S")
BACKUP_FILE="$BACKUP_DIR/backup_$DATE.sql"
# Crear directorio de respaldos si no existe
mkdir -p $BACKUP_DIR
# Realizar respaldo
echo "Creando respaldo de la base de datos $DB_NAME..."
pg_dump -U $DB_USER $DB_NAME > $BACKUP_FILE
# Verificar si el respaldo fue exitoso
if [ $? -eq 0 ]; then
echo "Respaldo creado exitosamente: $BACKUP_FILE"
# Comprimir el archivo
gzip $BACKUP_FILE
echo "Respaldo comprimido: $BACKUP_FILE.gz"
# Eliminar respaldos antiguos (mantener los últimos 7)
find $BACKUP_DIR -name "backup_*.sql.gz" -type f -mtime +7 -delete
echo "Respaldos antiguos eliminados."
else
echo "Error al crear el respaldo."
exit 1
fi
echo "Proceso de respaldo completado."