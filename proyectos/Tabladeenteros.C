#include <stdio.h>
#include <conio.h>

void mostrarTablaEnteros(int numero) {
    int i, num, cuadrado, cubo;

    printf(" Numero  Cuadrado     Cubo\n");
    printf(" ------  --------  --------\n");

    for (i = 1; i <= 5; i++) {
        num = numero + i;
        cuadrado = num * num;
        cubo = num * num * num;
        printf(" %6d  %8d  %8d\n", num, cuadrado, cubo);
    }
}

void mostrarTablaUnsigned(unsigned int numero) {
    int i;
    unsigned int num, cuadrado, cubo;

    printf(" Numero  Cuadrado     Cubo\n");
    printf(" ------  --------  --------\n");

    for (i = 1; i <= 5; i++) {
        num = numero + i;
        cuadrado = num * num;
        cubo = num * num * num;
        printf(" %6u  %8u  %8u\n", num, cuadrado, cubo);
    }
}

int main() {
    int opcion;
    int numero_int;
    unsigned int numero_unsigned;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Mostrar tabla con int\n");
        printf("2. Mostrar tabla con unsigned int\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                printf("Ingrese un numero entero: ");
                if (scanf("%d", &numero_int) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                } else {
                    clrscr();
                    mostrarTablaEnteros(numero_int);
                }
                break;
            case 2:
                printf("Ingrese un numero entero sin signo: ");
                if (scanf("%u", &numero_unsigned) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                } else {
                    clrscr();
                    mostrarTablaUnsigned(numero_unsigned);
                }
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }

        if (opcion != 3) {
            printf("\nPresione cualquier tecla para continuar...\n");
            getch();
        }
    } while (opcion != 3);

    return 0;
}
