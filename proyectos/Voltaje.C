#include <stdio.h>
#include <conio.h>

void calcularVoltaje(float resistencia, float intensidad) {
    float voltaje;
    if (resistencia < 0) {
        printf("Error: La resistencia no puede ser negativa.\n");
    } else if (resistencia > 1000) {
        printf("Error: La resistencia no puede ser mayor que 1000 ohmios.\n");
    } else {
        voltaje = intensidad * resistencia;
        printf("La caida de potencial (voltaje) es: %.2f V\n", voltaje);
    }
}

int main() {
    float resistencia, intensidad;
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Calcular caida de potencial\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                printf("Ingrese el valor de la resistencia (en ohmios): ");
                if (scanf("%f", &resistencia) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                printf("Ingrese el valor de la intensidad (en amperios): ");
                if (scanf("%f", &intensidad) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                clrscr();
                calcularVoltaje(resistencia, intensidad);
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
