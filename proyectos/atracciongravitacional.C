#include <stdio.h>
#include <conio.h>
#include <math.h>

#define G 6.67e-11

void calcularFuerzaGravitacional() {
    double M1, M2, R, F;

    printf("Ingrese la masa M1 en kilogramos: ");
    if (scanf("%lf", &M1) != 1 || M1 <= 0) {
        printf("Entrada no valida. Intente de nuevo.\n");
        return;
    }

    printf("Ingrese la masa M2 en kilogramos: ");
    if (scanf("%lf", &M2) != 1 || M2 <= 0) {
        printf("Entrada no valida. Intente de nuevo.\n");
        return;
    }

    printf("Ingrese la distancia R en metros: ");
    if (scanf("%lf", &R) != 1 || R <= 0) {
        printf("Entrada no valida. Intente de nuevo.\n");
        return;
    }

    F = G * M1 * M2 / (R * R);

    printf("La fuerza de atraccion gravitacional entre las masas es: %.10e N\n", F);
}

int main() {
    int opcion;
    char buffer[10];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Calcular fuerza de atraccion gravitacional\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);


        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                calcularFuerzaGravitacional();
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