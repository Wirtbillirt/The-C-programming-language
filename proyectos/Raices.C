#include <stdio.h>
#include <math.h>
#include <conio.h>

void resolverEcuacion(float a, float b, float c) {
    float discriminante, raiz1, raiz2, parteReal, parteImaginaria;

    if (a == 0) {
        
        if (b != 0) {
            raiz1 = -c / b;
            printf("Ecuacion de primer grado: La solucion es x = %.2f\n", raiz1);
        } else {
            if (c == 0) {
                printf("Ecuacion indeterminada: 0 = 0\n");
            } else {
                printf("Ecuacion inconsistente: no tiene solucion.\n");
            }
        }
    } else {
        
        discriminante = b * b - 4 * a * c;

        if (discriminante > 0) {
            
            raiz1 = (-b + sqrt(discriminante)) / (2 * a);
            raiz2 = (-b - sqrt(discriminante)) / (2 * a);
            printf("Raices reales y diferentes:\n");
            printf("x1 = %.2f\n", raiz1);
            printf("x2 = %.2f\n", raiz2);
        } else if (discriminante == 0) {
            
            raiz1 = -b / (2 * a);
            printf("Raices reales e iguales:\n");
            printf("x1 = x2 = %.2f\n", raiz1);
        } else {
           
            parteReal = -b / (2 * a);
            parteImaginaria = sqrt(-discriminante) / (2 * a);
            printf("Raices complejas:\n");
            printf("x1 = %.2f + %.2fi\n", parteReal, parteImaginaria);
            printf("x2 = %.2f - %.2fi\n", parteReal, parteImaginaria);
        }
    }
}

int main() {
    float a, b, c;
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Resolver ecuacion\n");
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
                clrscr();
                resolverEcuacion(a, b, c);
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