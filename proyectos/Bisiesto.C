#include <stdio.h>
#include <conio.h>

int esBisiesto(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int main() {
    int year;
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Verificar si un año es bisiesto\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                printf("Ingrese el año: ");
                if (scanf("%d", &year) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                clrscr();
                if (esBisiesto(year)) {
                    printf("El año %d es bisiesto.\n", year);
                } else {
                    printf("El año %d no es bisiesto.\n", year);
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
