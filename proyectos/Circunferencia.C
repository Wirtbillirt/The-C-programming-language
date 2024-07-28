#include <stdio.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265358979323846

void calcularCircunferencia() {
    float radio, longitud, area;

    printf("Ingrese el radio de la circunferencia: ");
    if (scanf("%f", &radio) != 1 || radio <= 0) {
        printf("Entrada no valida. Intente de nuevo.\n");
        return;
    }

    longitud = 2 * PI * radio;
    area = PI * radio * radio;

    printf("Radio: %.2f\n", radio);
    printf("Longitud de la circunferencia: %.2f\n", longitud);
    printf("Area de la circunferencia: %.2f\n", area);
}

int main() {
    int opcion;
    char buffer[10];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Calcular longitud y area de una circunferencia\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

       
        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                calcularCircunferencia();
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
