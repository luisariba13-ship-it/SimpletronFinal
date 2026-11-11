# Requerimientos del proyecto

El proyecto **Simpletron** consiste en el desarrollo de un simulador de computadora utilizando el lenguaje de programación **C**. El sistema permite ejecutar instrucciones en lenguaje de máquina **SML (Simpletron Machine Language)**, evaluar expresiones aritméticas y compilar programas escritos en el lenguaje **Simple**.

El proyecto integra las funcionalidades del simulador, las modificaciones al lenguaje de máquina y el compilador en un programa principal, permitiendo comprobar su funcionamiento mediante diferentes pruebas.

---

## 1. Programación en lenguaje SML

El sistema debe implementar las 12 instrucciones originales del lenguaje SML.

- **Entrada y salida:** `READ`, `WRITE`.
- **Carga y almacenamiento:** `LOAD`, `STORE`.
- **Operaciones aritméticas:** `ADD`, `SUBTRACT`, `DIVIDE`, `MULTIPLY`.
- **Transferencias de control:** `BRANCH`, `BRANCHNEG`, `BRANCHZERO`.
- **Terminación:** `HALT`.

También debe permitir:

- Ejecutar instrucciones almacenadas en memoria.
- Realizar operaciones aritméticas con números enteros.
- Leer valores ingresados por el usuario.
- Mostrar los resultados de las operaciones.
- Implementar estructuras de selección mediante saltos.
- Ejecutar estructuras de repetición.
- Finalizar correctamente la ejecución de los programas.

---

## 2. Simulador de computadora Simpletron

**Archivo:** `simpletron.c`

El simulador debe:

- Contar con una memoria de **100 posiciones** para la ejecución de programas SML.
- Inicializar los registros especiales en cero.
- Cargar instrucciones desde el teclado.
- Cargar programas desde el archivo `programa.simp`.
- Permitir finalizar la carga manual mediante el valor `9999`.
- Ejecutar el ciclo de búsqueda, decodificación y ejecución.
- Interpretar las instrucciones SML.
- Actualizar los registros durante la ejecución.
- Detectar errores de ejecución.
- Mostrar el estado final de los registros y la memoria.

### Registros especiales

- `accumulator`
- `instructionCounter`
- `instructionRegister`
- `operationCode`
- `operand`

### Errores que debe detectar

- División entre cero.
- Código de operación inválido.
- Desbordamiento del acumulador.
- Direcciones de memoria inválidas.
- Valores fuera del rango permitido.

---

## 3. Modificaciones al simulador

**Archivo:** `simpletron.c`

Las modificaciones al simulador se encuentran integradas en el mismo archivo principal.

El sistema debe:

- Conservar las instrucciones originales SML.
- Incorporar operaciones adicionales.
- Permitir el procesamiento de cadenas.
- Ejecutar operaciones de módulo y potencia.
- Mantener el funcionamiento de los registros especiales.
- Mostrar los resultados de las nuevas instrucciones.

### Nuevas instrucciones SML

| Código | Operación |
|---|---|
| `34` | Módulo |
| `35` | Potencia |
| `44` | Salto de línea |
| `45` | Lectura de cadenas |
| `46` | Escritura de cadenas |
| `47` | Lectura de decimales |
| `48` | Escritura de decimales |

Las instrucciones adicionales permiten ampliar las capacidades del simulador sin eliminar las funcionalidades originales.

---

## 4. Evaluación de expresiones aritméticas

**Archivo:** `simpletron.c`

El evaluador de expresiones se encuentra integrado en el programa principal y puede utilizarse mediante la opción correspondiente del menú.

El sistema debe:

- Recibir expresiones aritméticas ingresadas por el usuario.
- Validar paréntesis, corchetes y llaves.
- Comprobar el balance de los símbolos de agrupación.
- Procesar expresiones con diferentes niveles de anidamiento.
- Convertir expresiones infijas a postfijas.
- Evaluar las expresiones postfijas.
- Utilizar pilas para procesar los operadores.
- Reconocer operandos de varios dígitos.
- Respetar la precedencia de operadores.
- Aplicar correctamente la asociatividad de las potencias.

### Operadores admitidos

- `+` Suma.
- `-` Resta.
- `*` Multiplicación.
- `/` División.
- `^` Potencia.

### Ejemplos de evaluación

| Expresión | Resultado esperado |
|---|---|
| `10 + 2 * 3` | `16` |
| `2 ^ 3 ^ 2` | `512` |
| `(10 + 5) * (8 - 3)` | `75` |

---

## 5. Lenguaje de programación Simple

**Archivo de entrada:** `ejemplo.simple`

El sistema debe reconocer programas escritos en el lenguaje Simple y permitir su traducción a instrucciones SML.

El lenguaje debe admitir:

- Números de línea en orden ascendente.
- Variables de una sola letra.
- Constantes enteras.
- Expresiones aritméticas.
- Instrucciones de entrada y salida.
- Condiciones.
- Saltos entre líneas.
- Estructuras de repetición.
- Comentarios.

### Comandos del lenguaje

- `rem`
- `input`
- `let`
- `print`
- `goto`
- `if/goto`
- `end`

### Operadores de comparación

- `<`
- `<=`
- `>`
- `>=`
- `==`
- `!=`

### Ejemplo de programa Simple

```text
10 rem Programa de prueba
20 let a = 5
30 let b = 3
40 let c = (a + b) * 2
50 print c
60 end
```

El programa realiza una operación aritmética y muestra el resultado `16`.

---

## 6. Construcción del compilador

**Archivo:** `simpletron.c`

El compilador se encuentra integrado en el programa principal y utiliza `ejemplo.simple` como archivo de entrada.

El compilador debe:

- Leer programas escritos en lenguaje Simple.
- Identificar los comandos del lenguaje.
- Analizar las instrucciones del programa.
- Construir una tabla de símbolos.
- Registrar variables, constantes y números de línea.
- Identificar referencias pendientes.
- Resolver los saltos hacia otras instrucciones.
- Convertir expresiones aritméticas a instrucciones SML.
- Generar el archivo
