#include <stdio.h>
#include <conio.h>

void calcularDomingoPascua(int year) {
    int A, B, C, D, E;
    int dia, mes;

    A = year % 19;
    B = year % 4;
    C = year % 7;
    D = (19 * A + 24) % 30;
    E = (2 * B + 4 * C + 6 * D + 5) % 7;

    dia = 22 + D + E;

    if (dia > 31) {
        dia -= 31;
        mes = 4;
    } else {
        mes = 3; 
    }

    printf("El Domingo de Pascua en el año %d es el %d de ", year, dia);
    if (mes == 3) {
        printf("Marzo.\n");
    } else {
        printf("Abril.\n");
    }
}

int main() {
    int year;
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Calcular fecha del Domingo de Pascua\n");
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
                calcularDomingoPascua(year);
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
