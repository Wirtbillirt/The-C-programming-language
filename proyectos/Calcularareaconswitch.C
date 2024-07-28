#include <stdio.h>
#include <math.h>
#include <conio.h>

void calcularAreaSwitch() {
    int opcion;
    float lado, radio, area;

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Calcular el area de un cuadrado\n");
        printf("2. Calcular el area de un circulo\n");
        printf("3. Calcular el area de un triangulo equilatero\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        clrscr();

        switch (opcion) {
            case 1:
                printf("Ingrese el lado del cuadrado: ");
                scanf("%f", &lado);
                area = lado * lado;
                printf("El area del cuadrado es: %.2f\n", area);
                break;
            case 2:
                printf("Ingrese el radio del circulo: ");
                scanf("%f", &radio);
                area = M_PI * radio * radio;
                printf("El area del circulo es: %.2f\n", area);
                break;
            case 3:
                printf("Ingrese el lado del triangulo equilatero: ");
                scanf("%f", &lado);
                area = (sqrt(3) / 4) * lado * lado;
                printf("El area del triangulo equilatero es: %.2f\n", area);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }

        if (opcion != 4) {
            printf("\nPresione cualquier tecla para continuar...\n");
            getch();
        }
    } while (opcion != 4);
}

int main() {
    calcularAreaSwitch();
    return 0;
}

