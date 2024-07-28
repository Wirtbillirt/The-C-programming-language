#include <stdio.h>
#include <conio.h>

#define EURO_A_DOLAR 1.09
#define DOLAR_A_EURO (1 / 1.09)

void convertirEurosADolares() {
    float euros, dolares;

    printf("Ingrese el valor en euros: ");
    scanf("%f", &euros);

    dolares = euros * EURO_A_DOLAR;

    printf("%.2f euros son %.2f dolares.\n", euros, dolares);
}

void convertirDolaresAEuros() {
    float dolares, euros;

    printf("Ingrese el valor en dolares: ");
    scanf("%f", &dolares);

    euros = dolares * DOLAR_A_EURO;

    printf("%.2f dolares son %.2f euros.\n", dolares, euros);
}

int main() {
    int opcion;
    char buffer[10];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Convertir euros a dolares\n");
        printf("2. Convertir dolares a euros\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

       
        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                convertirEurosADolares();
                break;
            case 2:
                convertirDolaresAEuros();
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }

        if (opcion != 3) {
            printf("\nPresione cualquier tecla para continuar...\n");
            getch();
        }
    } while (opcion != 3);

    return 0;
}

