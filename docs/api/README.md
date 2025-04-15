# Documentación de la API

Esta documentación describe los endpoints disponibles en la API del Sistema de Control de Asistencia.

## Autenticación

Todos los endpoints requieren autenticación mediante un token JWT o una API Key.

### Obtener Token

```plaintext
POST /api/auth/login
```

**Parámetros:**

- `email`: Correo electrónico del usuario
- `password`: Contraseña del usuario

**Respuesta:**

```json
{
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...",
  "user": {
    "id": "123",
    "name": "John Doe",
    "email": "john@example.com",
    "role": "ADMIN"
  }
}
```

## Endpoints para Dispositivos

### Registrar Dispositivo

```plaintext
POST /api/devices/register
```

**Parámetros:**

- `deviceId`: ID único del dispositivo
- `name`: Nombre del dispositivo
- `location`: Ubicación del dispositivo
- `companyId`: ID de la empresa

### Registrar Asistencia

```plaintext
POST /api/attendance/record
```

**Parámetros:**

- `deviceId`: ID del dispositivo
- `fingerprintId`: ID de la huella digital
- `timestamp`: Marca de tiempo (ISO 8601)
- `type`: Tipo de registro (CLOCK_IN, CLOCK_OUT, etc.)

## Endpoints para Empleados

### Listar Empleados

```plaintext
GET /api/employees
```

**Parámetros de consulta:**

- `companyId`: ID de la empresa
- `departmentId` (opcional): Filtrar por departamento
- `isActive` (opcional): Filtrar por estado activo/inactivo

### Crear Empleado

```plaintext
POST /api/employees
```

**Parámetros:**

- `firstName`: Nombre
- `lastName`: Apellido
- `email`: Correo electrónico
- `position`: Cargo
- `departmentId`: ID del departamento
- `companyId`: ID de la empresa

## Endpoints para Reportes

### Reporte de Asistencia

```plaintext
GET /api/reports/attendance
```

**Parámetros de consulta:**

- `companyId`: ID de la empresa
- `startDate`: Fecha de inicio (YYYY-MM-DD)
- `endDate`: Fecha de fin (YYYY-MM-DD)
- `departmentId` (opcional): Filtrar por departamento
- `employeeId` (opcional): Filtrar por empleado
