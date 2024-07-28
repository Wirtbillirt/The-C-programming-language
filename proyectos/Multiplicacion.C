#include <stdio.h>
#include <conio.h>

void mostrarTablaMultiplicar(double numero) {
    int i;

    printf("TABLA DE MULTIPLICAR DEL NUMERO %.2f\n", numero);
    for (i = 1; i <= 10; i++) {
        printf("%.2f * %d = %.2f\n", numero, i, numero * i);
    }
}

int main() {
    double numero;
    char buffer[100];
    int opcion;

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Mostrar tabla de multiplicar\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                printf("Ingrese un numero real: ");
                if (scanf("%lf", &numero) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                } else {
                    clrscr();
                    mostrarTablaMultiplicar(numero);
                }
                break;
            case 2:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }

        if (opcion != 2) {
            printf("\nPresione cualquier tecla para continuar...\n");
            getch();
        }
    } while (opcion != 2);

    return 0;
}

