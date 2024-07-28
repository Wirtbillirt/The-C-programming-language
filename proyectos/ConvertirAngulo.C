#include <stdio.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIANES_A_GRADOS (180.0 / PI)

void convertirAngulo(double radianes) {
    double grados_decimal;
    int grados, minutos;
    double segundos;

  
    grados_decimal = radianes * RADIANES_A_GRADOS;

    grados = (int)grados_decimal;
    minutos = (int)((grados_decimal - grados) * 60);
    segundos = ((grados_decimal - grados) * 60 - minutos) * 60;

	printf("El angulo en grados, minutos y segundos es: %dÂ` %d' %.2f\"\n", grados, minutos, segundos);
}

int main() {
    double radianes;
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Convertir angulo de radianes a grados, minutos y segundos\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                printf("Ingrese el valor del angulo en radianes: ");
                if (scanf("%lf", &radianes) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                } else {
                    clrscr();
                    convertirAngulo(radianes);
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
