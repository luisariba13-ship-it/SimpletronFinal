#include <stdio.h>
#include <string.h>
#include <ctype.h>

int memory[100];

int accumulator = 0;
int instructionCounter = 0;
int instructionRegister = 0;
int operationCode = 0;
int operand = 0;

int cargar_programa()
{
    int posicion = 0;
    int valor = 0;

    printf("*** Bienvenido a Simpletron! ***\n");
    printf("*** Introduzca su programa una instruccion ***\n");
    printf("*** (o palabra de datos) a la vez en la linea ***\n");
    printf("*** de texto de entrada. Yo indicare el numero ***\n");
    printf("*** de posicion y una interrogacion (?). Usted ***\n");
    printf("*** tecleara entonces la palabra para esa ***\n");
    printf("*** posicion. Introduzca 9999 para dejar de ***\n");
    printf("*** introducir su programa. ***\n");

    while (posicion < 100)
    {
        printf("%02d ? ", posicion);

        if (scanf("%d", &valor) != 1)
        {
            printf("Entrada invalida\n");
            return 0;
        }

        if (valor == 9999)
        {
            break;
        }

        if (valor >= -9999 && valor <= 9998)
        {
            memory[posicion] = valor;
            posicion++;
        }
        else
        {
            printf("Valor invalido\n");
            printf("Introduzca un valor entre -9999 y +9998\n");
        }
    }

    if (posicion == 0)
    {
        printf("No se cargaron instrucciones\n");
        return 0;
    }

    printf("\n");
    printf("Se termino de cargar el programa\n");
    printf("Comienza la ejecucion del programa\n");
    printf("\n");

    return 1;
}

int cargar_desde_archivo()
{
    FILE *archivo;
    int posicion = 0;
    int valor;
    int resultado;
    int terminado = 0;

    archivo = fopen("programa.simp", "r");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return 0;
    }

    while (posicion < 100)
    {
        resultado = fscanf(archivo, "%d", &valor);

        if (resultado == EOF)
        {
            break;
        }

        if (resultado != 1)
        {
            printf("El archivo contiene datos invalidos\n");
            fclose(archivo);
            return 0;
        }

        if (valor == 9999)
        {
            terminado = 1;
            break;
        }

        if (valor < -9999 || valor > 9998)
        {
            printf("Valor fuera del rango permitido\n");
            fclose(archivo);
            return 0;
        }

        memory[posicion] = valor;
        posicion++;
    }

    if (terminado == 0 && posicion == 100)
    {
        resultado = fscanf(archivo, "%d", &valor);

        if (resultado == 1 && valor == 9999)
        {
            terminado = 1;
        }
    }

    if (terminado == 1)
    {
        resultado = fscanf(archivo, "%d", &valor);

        if (resultado != EOF)
        {
            printf("El archivo contiene datos adicionales\n");
            fclose(archivo);
            return 0;
        }
    }

    fclose(archivo);

    if (posicion == 0)
    {
        printf("El archivo esta vacio\n");
        return 0;
    }

    printf("\n");
    printf("Se termino de leer el archivo\n");
    printf("Comienza la ejecucion del programa\n");
    printf("\n");

    return 1;
}

void ejecutar_programa()
{
    int ejecutando = 1;
    int valor = 0;
    int resultado = 0;

    while (ejecutando == 1)
    {
        if (instructionCounter < 0 || instructionCounter > 99)
        {
            printf("Contador de instrucciones fuera de memoria\n");
            printf("La ejecucion de Simpletron termino anormalmente\n");

            ejecutando = 0;
        }
        else
        {
            instructionRegister = memory[instructionCounter];

            if (instructionRegister < 0)
            {
                printf("Instruccion invalida\n");
                printf("La ejecucion de Simpletron termino anormalmente\n");

                ejecutando = 0;
            }
            else
            {
                operationCode = instructionRegister / 100;
                operand = instructionRegister % 100;

                if (operationCode == 10)
                {
                    printf("? ");

                    if (scanf("%d", &valor) != 1)
                    {
                        printf("Entrada invalida\n");
                        printf("La ejecucion de Simpletron termino anormalmente\n");
                        ejecutando = 0;
                    }
                    else if (valor >= -9999 && valor <= 9998)
                    {
                        memory[operand] = valor;
                        instructionCounter++;
                    }
                    else
                    {
                        printf("Valor fuera del rango permitido\n");
                        printf("La ejecucion de Simpletron termino anormalmente\n");

                        ejecutando = 0;
                    }
                }

                else if (operationCode == 11)
                {
                    printf("%d\n", memory[operand]);

                    instructionCounter++;
                }

                else if (operationCode == 20)
                {
                    accumulator = memory[operand];

                    instructionCounter++;
                }

                else if (operationCode == 21)
                {
                    memory[operand] = accumulator;

                    instructionCounter++;
                }

                else if (operationCode == 30)
                {
                    resultado = accumulator + memory[operand];

                    if (resultado > 9999 || resultado < -9999)
                    {
                        printf("Desbordamiento del acumulador\n");
                        printf("La ejecucion de Simpletron termino anormalmente\n");

                        ejecutando = 0;
                    }
                    else
                    {
                        accumulator = resultado;
                        instructionCounter++;
                    }
                }

                else if (operationCode == 31)
                {
                    resultado = accumulator - memory[operand];

                    if (resultado > 9999 || resultado < -9999)
                    {
                        printf("Desbordamiento del acumulador\n");
                        printf("La ejecucion de Simpletron termino anormalmente\n");

                        ejecutando = 0;
                    }
                    else
                    {
                        accumulator = resultado;
                        instructionCounter++;
                    }
                }

                else if (operationCode == 32)
                {
                    if (memory[operand] == 0)
                    {
                        printf("Intento de dividir entre cero\n");
                        printf("La ejecucion de Simpletron termino anormalmente\n");

                        ejecutando = 0;
                    }
                    else
                    {
                        resultado = accumulator / memory[operand];

                        if (resultado > 9999 || resultado < -9999)
                        {
                            printf("Desbordamiento del acumulador\n");
                            printf("La ejecucion de Simpletron termino anormalmente\n");

                            ejecutando = 0;
                        }
                        else
                        {
                            accumulator = resultado;
                            instructionCounter++;
                        }
                    }
                }

                else if (operationCode == 33)
                {
                    resultado = accumulator * memory[operand];

                    if (resultado > 9999 || resultado < -9999)
                    {
                        printf("Desbordamiento del acumulador\n");
                        printf("La ejecucion de Simpletron termino anormalmente\n");

                        ejecutando = 0;
                    }
                    else
                    {
                        accumulator = resultado;
                        instructionCounter++;
                    }
                }

                else if (operationCode == 34)
                {
                    if (memory[operand] == 0)
                    {
                        printf("Intento de dividir entre cero\n");
                        printf("La ejecucion de Simpletron termino anormalmente\n");
                        ejecutando = 0;
                    }
                    else
                    {
                        accumulator = accumulator % memory[operand];
                        instructionCounter++;
                    }
                }

                else if (operationCode == 35)
                {
                    int potencia = memory[operand];
                    int contador = 0;
                    int base = accumulator;

                    resultado = 1;

                    if (potencia < 0)
                    {
                        printf("No se permiten exponentes negativos\n");
                        printf("La ejecucion de Simpletron termino anormalmente\n");
                        ejecutando = 0;
                    }
                    else
                    {
                        while (contador < potencia && ejecutando == 1)
                        {
                            long long calculo = (long long)resultado * base;

                            if (calculo > 9999 || calculo < -9999)
                            {
                                printf("Desbordamiento del acumulador\n");
                                printf("La ejecucion de Simpletron termino anormalmente\n");
                                ejecutando = 0;
                            }
                            else
                            {
                                resultado = (int)calculo;
                            }

                            contador++;
                        }

                        if (ejecutando == 1)
                        {
                            accumulator = resultado;
                            instructionCounter++;
                        }
                    }
                }

                else if (operationCode == 40)
                {
                    instructionCounter = operand;
                }

                else if (operationCode == 41)
                {
                    if (accumulator < 0)
                    {
                        instructionCounter = operand;
                    }
                    else
                    {
                        instructionCounter++;
                    }
                }

                else if (operationCode == 42)
                {
                    if (accumulator == 0)
                    {
                        instructionCounter = operand;
                    }
                    else
                    {
                        instructionCounter++;
                    }
                }

                else if (operationCode == 43)
                {
                    printf("\n");
                    printf("Termino la ejecucion de Simpletron\n");

                    ejecutando = 0;
                }

                else if (operationCode == 44)
                {
                    printf("\n");
                    instructionCounter++;
                }

                else
                {
                    printf("Codigo de operacion invalido\n");
                    printf("La ejecucion de Simpletron termino anormalmente\n");

                    ejecutando = 0;
                }
            }
        }
    }
}

void vaciado_memoria()
{
    int fila = 0;
    int columna = 0;
    int posicion = 0;

    printf("\n");
    printf("REGISTROS:\n");
    printf("accumulator:          %+05d\n", accumulator);
    printf("instructionCounter:   %02d\n", instructionCounter);
    printf("instructionRegister:  %+05d\n", instructionRegister);
    printf("operationCode:        %02d\n", operationCode);
    printf("operand:              %02d\n", operand);

    printf("\n");
    printf("MEMORIA\n");
    printf("\n");

    printf("       0      1      2      3      4      5      6      7      8      9\n");

    while (fila < 10)
    {
        printf("%d ", fila);

        columna = 0;

        while (columna < 10)
        {
            posicion = fila * 10 + columna;

            printf("%+05d ", memory[posicion]);

            columna++;
        }

        printf("\n");

        fila++;
    }
}

#define MAX 200

int prioridad(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int operador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

int convertir(char entrada[], char salida[]) {
    char pila[MAX];
    int cima = -1, i = 0, j = 0, esperaNumero = 1;
    while (entrada[i] != '\0' && entrada[i] != '\n') {
        char c = entrada[i];
        if (c == ' ' || c == '\t') { i++; continue; }
        if (isdigit((unsigned char)c)) {
            if (!esperaNumero) return 0;
            while (isdigit((unsigned char)entrada[i])) {
                if (j >= MAX - 3) return 0;
                salida[j++] = entrada[i++];
            }
            salida[j++] = ' ';
            esperaNumero = 0;
            continue;
        }
        if (c == '(' && esperaNumero) {
            if (cima >= MAX - 2) return 0;
            pila[++cima] = c;
        } else if (c == ')' && !esperaNumero) {
            while (cima >= 0 && pila[cima] != '(') {
                if (j >= MAX - 3) return 0;
                salida[j++] = pila[cima--]; salida[j++] = ' ';
            }
            if (cima < 0) return 0;
            cima--;
        } else if (operador(c) && !esperaNumero) {
            while (cima >= 0 && pila[cima] != '(' &&
                   (prioridad(pila[cima]) > prioridad(c) ||
                   (prioridad(pila[cima]) == prioridad(c) && c != '^'))) {
                if (j >= MAX - 3) return 0;
                salida[j++] = pila[cima--]; salida[j++] = ' ';
            }
            pila[++cima] = c;
            esperaNumero = 1;
        } else return 0;
        i++;
    }
    if (esperaNumero) return 0;
    while (cima >= 0) {
        if (pila[cima] == '(' || j >= MAX - 3) return 0;
        salida[j++] = pila[cima--]; salida[j++] = ' ';
    }
    salida[j] = '\0';
    return 1;
}

int evaluar(char postfija[], long long *respuesta) {
    long long pila[MAX], a, b, r;
    int cima = -1, i = 0, k;
    while (postfija[i]) {
        if (postfija[i] == ' ') { i++; continue; }
        if (isdigit((unsigned char)postfija[i])) {
            r = 0;
            while (isdigit((unsigned char)postfija[i])) {
                r = r * 10 + postfija[i++] - '0';
                if (r > 9999) return 0;
            }
            pila[++cima] = r;
        } else if (operador(postfija[i])) {
            if (cima < 1) return 0;
            b = pila[cima--]; a = pila[cima--];
            if (postfija[i] == '+') r = a + b;
            else if (postfija[i] == '-') r = a - b;
            else if (postfija[i] == '*') r = a * b;
            else if (postfija[i] == '/') {
                if (b == 0) return 0;
                r = a / b;
            } else if (postfija[i] == '%') {
                if (b == 0) return 0;
                r = a % b;
            } else {
                if (b < 0) return 0;
                r = 1;
                for (k = 0; k < b; k++) {
                    r *= a;
                    if (r < -9999 || r > 9999) return 0;
                }
            }
            if (r < -9999 || r > 9999) return 0;
            pila[++cima] = r;
            i++;
        } else return 0;
    }
    if (cima != 0) return 0;
    *respuesta = pila[0];
    return 1;
}

int ejecutar_expresiones() {
    char entrada[MAX], postfija[MAX];
    long long resultado;
    printf("Escribe una expresion: ");
    if (!fgets(entrada, MAX, stdin)) return 1;
    if (!convertir(entrada, postfija)) {
        printf("Expresion invalida\n");
        return 1;
    }
    printf("Postfija: %s\n", postfija);
    if (!evaluar(postfija, &resultado)) {
        printf("Error: division por cero o resultado fuera de rango\n");
        return 1;
    }
    printf("Resultado: %lld\n", resultado);
    return 0;
}

int main()
{
    int i = 0;
    int opcion;
    int cargado = 0;

    while (i < 100)
    {
        memory[i] = 0;
        i++;
    }

    printf("SIMPLETRON\n");
    printf("1. Cargar programa manualmente\n");
    printf("2. Cargar programa desde archivo\n");
    printf("3. Evaluar expresion aritmetica\n");
    printf("Seleccione una opcion: ");

    if (scanf("%d", &opcion) != 1)
    {
        printf("Opcion invalida\n");
        return 1;
    }

    if (opcion == 3)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        return ejecutar_expresiones();
    }

    if (opcion == 1)
    {
        cargado = cargar_programa();
    }
    else if (opcion == 2)
    {
        cargado = cargar_desde_archivo();
    }
    else
    {
        printf("Opcion invalida\n");
        return 1;
    }

    if (cargado == 0)
    {
        printf("No se puede ejecutar el programa\n");
        return 1;
    }

    ejecutar_programa();

    vaciado_memoria();

    return 0;
}
