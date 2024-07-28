#include <stdio.h>
#include <conio.h>

void mostrarTamanos() {
	printf("Tipo de variable    Tama¤o en bytes\n");
    printf("----------------    --------------\n");
    printf("char                %8lu\n", sizeof(char));
    printf("int                 %8lu\n", sizeof(int));
    printf("short int           %8lu\n", sizeof(short int));
    printf("long int            %8lu\n", sizeof(long int));
    printf("float               %8lu\n", sizeof(float));
    printf("double              %8lu\n", sizeof(double));
}

int main() {
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
		printf("1. Mostrar tama¤os de variables\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
				mostrarTamanos();
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