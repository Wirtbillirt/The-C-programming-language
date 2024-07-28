#include <stdio.h>
#include <conio.h>

void resolverSistema(float a, float b, float c, float d, float e, float f) {
    float denominador = (a * d) - (b * c);
    float x, y;
    
    if (denominador == 0) {
        printf("El sistema de ecuaciones no tiene solucion o tiene infinitas soluciones.\n");
    } else {
        x = (e * d - b * f) / denominador;
        y = (a * f - e * c) / denominador;
        printf("Solucion:\n");
        printf("x = %.2f\n", x);
        printf("y = %.2f\n", y);
    }
}

int main() {
    float a, b, c, d, e, f;
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Ingresar coeficientes y resolver sistema\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                printf("Ingrese el coeficiente a: ");
                if (scanf("%f", &a) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                printf("Ingrese el coeficiente b: ");
                if (scanf("%f", &b) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                printf("Ingrese el coeficiente c: ");
                if (scanf("%f", &c) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                printf("Ingrese el coeficiente d: ");
                if (scanf("%f", &d) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                printf("Ingrese el coeficiente e: ");
                if (scanf("%f", &e) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                printf("Ingrese el coeficiente f: ");
                if (scanf("%f", &f) != 1) {
                    printf("Entrada no valida. Intente de nuevo.\n");
                    break;
                }
                clrscr();
                resolverSistema(a, b, c, d, e, f);
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
