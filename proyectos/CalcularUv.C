#include <stdio.h>
#include <conio.h>

void calcularUV(float x, float y) {
    float U, V;

    if (x * y < 1) {
        U = 10;
        V = 1;
    } else {
        U = y * y;
        V = y * y;
    }

    printf("Para el punto (%.2f, %.2f):\n", x, y);
    printf("U = %.2f\n", U);
    printf("V = %.2f\n", V);
}

int main() {
    float x, y;
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Calcular funciones U y V\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                printf("Ingrese la coordenada x: ");
                if (scanf("%f", &x) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                printf("Ingrese la coordenada y: ");
                if (scanf("%f", &y) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                clrscr();
                calcularUV(x, y);
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
