#include <stdio.h>
#include <conio.h>

void compararConIf(int num1, int num2) {
    if (num1 > num2) {
        printf("Usando if: El mayor numero es %d\n", num1);
    } else if (num2 > num1) {
        printf("Usando if: El mayor numero es %d\n", num2);
    } else {
        printf("Usando if: Ambos numeros son iguales\n");
    }
}

void compararConOperadorCondicional(int num1, int num2) {
    int mayor = (num1 > num2) ? num1 : num2;
    if (num1 == num2) {
        printf("Usando operador condicional: Ambos numeros son iguales\n");
    } else {
        printf("Usando operador condicional: El mayor numero es %d\n", mayor);
    }
}

int main() {
    int num1, num2;
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Comparar dos numeros\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                printf("Ingrese el primer numero: ");
                if (scanf("%d", &num1) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                printf("Ingrese el segundo numero: ");
                if (scanf("%d", &num2) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                clrscr();
                compararConIf(num1, num2);
                compararConOperadorCondicional(num1, num2);
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
