#include <stdio.h>
#include <conio.h>

void procesarNumeros(int num1, int num2, int num3) {
    int resultado;
    
    if (num1 < 0) {
        resultado = num1 * num2 * num3;
        printf("El primer numero es negativo.\n");
        printf("Producto de los tres numeros: %d\n", resultado);
    } else {
        resultado = num1 + num2 + num3;
        printf("El primer numero no es negativo.\n");
        printf("Suma de los tres numeros: %d\n", resultado);
    }
}

int main() {
    int num1, num2, num3;
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Ingresar tres numeros\n");
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
                printf("Ingrese el tercer numero: ");
                if (scanf("%d", &num3) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                clrscr();
                procesarNumeros(num1, num2, num3);
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
