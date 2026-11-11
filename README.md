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

Simpletron es un simulador de computadora que cuenta con una memoria de 100 posiciones y cinco registros principales que permiten controlar la ejecución de instrucciones.

El programa simula el funcionamiento básico de una computadora mediante la lectura, interpretación y ejecución de instrucciones almacenadas en memoria.

Los registros utilizados son:
- accumulator: almacena los resultados de las operaciones.
- instructionCounter: indica la posición de la siguiente instrucción.
- instructionRegister: almacena la instrucción que se está ejecutando.
- operationCode: identifica la operación que debe realizarse.
- operand: indica la dirección de memoria utilizada por la instrucción.
Al finalizar la ejecución, el simulador muestra el estado de los registros y el contenido de las 100 posiciones de memoria.

---

## Funcionalidades del proyecto

El proyecto incluye las siguientes características:

Carga manual de instrucciones SML.

Carga de programas desde archivos .simp.

Ejecución de operaciones aritméticas.

Lectura y escritura de datos.

Almacenamiento y recuperación de valores en memoria.

Saltos condicionales e incondicionales.

Ejecución de ciclos y condiciones.

Operaciones de módulo y potencia.

Saltos de línea y entrada/salida de cadenas.

Detección de errores durante la ejecución.

Visualización de registros y memoria.

Validación de expresiones aritméticas.

Conversión de expresiones infijas a postfijas.

Evaluación de expresiones postfijas.

Compilación de programas Simple a SML.

Primera y segunda pasada del compilador.

---

## Códigos de operación SML

El simulador utiliza los siguientes códigos para identificar las instrucciones que puede ejecutar.

Código

Operación

Descripción

10

READ

Leer un número

11

WRITE

Mostrar un número

20

LOAD

Cargar un valor al acumulador

21

STORE

Guardar el acumulador en memoria

30

ADD

Sumar

31

SUBTRACT

Restar

32

DIVIDE

Dividir

33

MULTIPLY

Multiplicar

34

MOD

Calcular el residuo

35

POWER

Calcular una potencia

40

BRANCH

Realizar un salto incondicional

41

BRANCHNEG

Saltar si el acumulador es negativo

42

BRANCHZERO

Saltar si el acumulador es cero

43

HALT

Finalizar la ejecución

44

NEWLINE

Insertar un salto de línea

45

WRITE_STRING

Mostrar una cadena de texto

46

READ_STRING

Leer una cadena de texto

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
