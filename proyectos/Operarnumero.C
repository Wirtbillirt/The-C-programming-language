#include <stdio.h>
#include <conio.h>

void operarNumero(int numero) {
    
    int multiplicado = numero << 2; 
    int resultado = multiplicado >> 1; 

    printf("Numero ingresado: %d\n", numero);
    printf("Multiplicado por 4: %d\n", multiplicado);
    printf("Dividido por 2: %d\n", resultado);
}

int main() {
    int numero;
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Multiplicar por 4 y dividir por 2 usando operadores de rotacion\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                printf("Ingrese un numero entero: ");
                if (scanf("%d", &numero) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                } else {
                    clrscr();
                    operarNumero(numero);
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
