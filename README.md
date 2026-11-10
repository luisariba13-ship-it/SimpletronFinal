# Un simulador de Computadora

Proyecto académico desarrollado para la materia de **Programación Avanzada** de la **Universidad Popular Autónoma del Estado de Puebla (UPAEP)**.

Este proyecto está enfocado en el desarrollo de un simulador de computadora llamado **Simpletron**, el cual permite cargar y ejecutar instrucciones mediante una memoria y diferentes registros que representan el funcionamiento básico de una computadora.

El proyecto se desarrolla de manera progresiva, incorporando nuevas características y modificaciones conforme avanzan las actividades de la materia.

---

## Información del proyecto

- **Proyecto:** Un simulador de Computadora
- **Nombre:** Simpletron
- **Universidad:** Universidad Popular Autónoma del Estado de Puebla (UPAEP)
- **Carrera:** Ingeniería de Software
- **Materia:** Programación Avanzada
- **Periodo:** Otoño 2026
- **Tipo de proyecto:** Académico

---

## Descripción

Simpletron es un simulador de computadora que cuenta con una memoria de **100 posiciones** y diferentes registros para controlar la ejecución de instrucciones.

El simulador permite cargar programas, ejecutar operaciones y visualizar el estado final de la memoria y los registros.

Entre sus principales funcionalidades se encuentran:

- Carga de instrucciones y datos.
- Lectura y escritura de información.
- Operaciones aritméticas.
- Saltos condicionales e incondicionales.
- Control mediante un acumulador.
- Detección de errores.
- Visualización de registros.
- Visualización de la memoria.

---

## Códigos de operación

El simulador utiliza diferentes códigos para representar las instrucciones que puede ejecutar:

| Código | Operación |
|---|---|
| `10` | READ |
| `11` | WRITE |
| `20` | LOAD |
| `21` | STORE |
| `30` | ADD |
| `31` | SUBTRACT |
| `32` | DIVIDE |
| `33` | MULTIPLY |
| `40` | BRANCH |
| `41` | BRANCHNEG |
| `42` | BRANCHZERO |
| `43` | HALT |

ATENCIÓN
PARA PODER COMPILAR!!
Abrir la terminal en Visual Studio Code y correr el siguiente comando

gcc simpletron.c -o simpletron.exe

PARA EJECUTAR
.\simpletron.exe

O EN POWERSHELL
gcc simpletron.c -o simpletron.exe; if ($LASTEXITCODE -eq 0) { .\simpletron.exe }

--------------------------------------------------------------------

## Lenguaje utilizado

**Lenguaje:**
- C

**Estado:** En desarrollo

---

## Organización del proyecto

```text
Un-simulador-de-Computadora/
│
├── README.md
│
├── Simpletron.c
│
└── ...
