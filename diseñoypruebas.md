Simpletron — Simulador de computadora en C
Descripción general
Simpletron es un proyecto académico desarrollado en lenguaje C que simula una computadora con memoria, registros e instrucciones de lenguaje máquina Simpletron (SML). También incorpora un evaluador de expresiones aritméticas y un compilador básico del lenguaje Simple.

Este documento presenta la arquitectura del proyecto, los requisitos para ejecutarlo y seis pruebas funcionales reproducibles. Los resultados indicados son los esperados para cada caso; deben contrastarse con la salida obtenida al ejecutar la versión correspondiente.
1. Arquitectura del sistema
Las funcionalidades principales se encuentran integradas en un único archivo fuente, simpletron.c. Los programas SML y Simple se almacenan en archivos de texto independientes.
SIMPLETRONPROYECTO/
│
├── simpletron.c       # Simulador, evaluador y compilador
├── simpletron.exe     # Ejecutable generado por GCC (Windows)
├── programa.simp      # Programa en instrucciones SML
├── ejemplo.simple     # Programa fuente en lenguaje Simple
└── README.md          # Documentación del proyecto
El archivo simpletron.exe se genera durante la compilación y no es necesario para compilar el proyecto desde su código fuente.
2. Requisitos y ejecución
Se requiere un compilador de C, como GCC, y una terminal. Los siguientes comandos corresponden a PowerShell en Windows y deben ejecutarse desde la carpeta del proyecto.

Compilar:
gcc simpletron.c -o simpletron.exe
Ejecutar:
.\simpletron.exe
El programa presenta un menú con cuatro opciones:
Opción	Función
1	Introducir instrucciones SML manualmente
2	Cargar y ejecutar programa.simp
3	Evaluar una expresión aritmética
4	Compilar ejemplo.simple a SML y ejecutarlo


La compilación con GCC solo debe repetirse cuando cambia simpletron.c. Los cambios en programa.simp o ejemplo.simple se leen en la siguiente ejecución. Advertencia: la opción 4 puede sobrescribir programa.simp; se recomienda conservar una copia antes de utilizarla.
3. Pruebas funcionales
Prueba 1. Operaciones e instrucciones SML
Objetivo: verificar lectura y escritura, operaciones aritméticas, saltos, ciclos, manejo de cadenas y visualización de registros y memoria.

Archivo: programa.simp.

Procedimiento: compilar y ejecutar el programa principal mediante los comandos de la sección 2; seleccionar la opción 2 e introducir los valores solicitados por el programa SML cargado.

En la prueba integral utilizada durante el desarrollo se proporcionaron las entradas 2, 5 y hola. Entre las salidas observadas se encontraron 7, -3, 10 y hola, además del estado final de los registros. Estos valores corresponden a ese programa de prueba específico y pueden cambiar si se sustituye programa.simp.
Prueba 2. Evaluación de expresiones con agrupadores
Objetivo: comprobar el procesamiento de expresiones aritméticas y el respeto de los signos de agrupación.

Procedimiento: ejecutar simpletron.exe, seleccionar la opción 3 e introducir:
{(10 + 5) * [8 - 3]}
Resultado esperado: 75, siempre que la versión del evaluador admita llaves y corchetes.
Prueba 3. Precedencia y asociatividad
Objetivo: comprobar el orden de evaluación de los operadores.

Procedimiento: ejecutar la opción 3 para cada una de las expresiones siguientes:
Expresión	Resultado esperado	Comportamiento evaluado
10 + 2 * 3	16	Precedencia de multiplicación
2 ^ 3 ^ 2	512	Asociatividad por la derecha de la potencia


El resultado 512 corresponde a interpretar la segunda expresión como 2 ^ (3 ^ 2).
Prueba 4. Compilación del lenguaje Simple
Objetivo: verificar la traducción de instrucciones de alto nivel a SML y su ejecución.

Archivo: ejemplo.simple.

Contenido de prueba:
10 rem Programa de prueba del compilador
20 let a = 5
30 let b = 3
40 let c = (a + b) * 2
50 print c
60 end
Procedimiento: ejecutar simpletron.exe y seleccionar la opción 4.

Resultado esperado: 16 y terminación normal del programa. El compilador genera instrucciones SML que pueden escribirse en programa.simp.
Prueba 5. Condiciones y ciclos
Objetivo: verificar las instrucciones if y goto, así como los saltos hacia líneas anteriores para implementar ciclos.

Archivo: ejemplo.simple.

Contenido de prueba:
10 rem Prueba de condiciones y ciclos
20 let a = 1
30 print a
40 let a = a + 1
50 if a <= 5 goto 30
60 end
Procedimiento: guardar este ejemplo en ejemplo.simple, ejecutar simpletron.exe y seleccionar la opción 4.

Resultado esperado: impresión consecutiva de 1, 2, 3, 4 y 5, seguida de la terminación normal. Si aparece 16, el archivo todavía contiene el ejemplo aritmético de la prueba 4.
Prueba 6. Detección de errores
Objetivo: verificar que el simulador identifique operaciones inválidas y detenga su ejecución de forma controlada.

Caso principal: división entre cero. El archivo programa.simp debe contener, temporalmente, las siguientes instrucciones SML, una por línea:
2004
3205
4300
0
10
0
9999
La instrucción 2004 carga el valor 10 de la posición 04, mientras que 3205 intenta dividirlo entre el valor 0 de la posición 05.

Procedimiento: ejecutar simpletron.exe y seleccionar la opción 2.

Resultado esperado: mensaje de división entre cero y terminación anormal controlada. También pueden realizarse pruebas independientes de desbordamiento del acumulador e instrucciones inválidas, según los controles implementados.

Cada error debe probarse por separado, ya que el primer fallo detectado interrumpe la ejecución.
4. Registro de resultados y evidencias
Para documentar las pruebas se recomienda registrar el archivo utilizado, los datos de entrada, la salida obtenida y el estado de ejecución. Las capturas de terminal pueden complementar la evidencia de las pruebas.

Los resultados esperados descritos en este README no equivalen, por sí mismos, a una certificación de que todas las pruebas hayan sido superadas. La validación depende de ejecutar cada caso y contrastar su salida.
5. Consideraciones
- El proyecto utiliza C para el simulador y el compilador; los archivos .simp y .simple contienen programas de entrada, no código C.
- El programa SML de la prueba 1 debe conservarse antes de sustituir programa.simp para la prueba 6.
- Los ejemplos de las pruebas 4 y 5 utilizan el mismo archivo ejemplo.simple, por lo que deben guardarse y ejecutarse de manera individual.
- Para distribuir el proyecto en GitHub se recomienda incluir el código fuente, los programas de ejemplo y esta documentación.
