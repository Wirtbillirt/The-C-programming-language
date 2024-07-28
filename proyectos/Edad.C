#include <stdio.h>
#include <conio.h>

void calcularEdadEn2010() {
    int year_actual, edad_actual, edad_en_2010;

	printf("Ingrese el a¤o actual: ");
    if (scanf("%d", &year_actual) != 1 || year_actual < 2010) {
        printf("Entrada no valida. Intente de nuevo.\n");
        return;
    }

    printf("Ingrese su edad actual: ");
    if (scanf("%d", &edad_actual) != 1 || edad_actual < 0) {
        printf("Entrada no valida. Intente de nuevo.\n");
        return;
    }

    edad_en_2010 = edad_actual - (year_actual - 2010);

    if (edad_en_2010 < 0) {
		printf("Usted no habia nacido en el a¤o 2010.\n");
    } else {
		printf("En el a¤o 2010, usted tenia %d a¤os.\n", edad_en_2010);
    }
}

int main() {
    int opcion;
    char buffer[10];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
		printf("1. Calcular edad en el a¤o 2010\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);


        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                calcularEdadEn2010();
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