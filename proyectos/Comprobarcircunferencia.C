#include <stdio.h>
#include <math.h>
#include <conio.h>

void comprobarCircunferencia(float x, float y) {
    float distancia = sqrt(x * x + y * y);
    if (distancia <= 10) {
        printf("El punto (%.2f, %.2f) pertenece a la circunferencia de radio 10 y centro (0,0).\n", x, y);
    } else {
        printf("El punto (%.2f, %.2f) no pertenece a la circunferencia de radio 10 y centro (0,0).\n", x, y);
    }
}

void averiguarCuadrante(float x, float y) {
    if (x > 0 && y > 0) {
        printf("El punto (%.2f, %.2f) se encuentra en el primer cuadrante.\n", x, y);
    } else if (x < 0 && y > 0) {
        printf("El punto (%.2f, %.2f) se encuentra en el segundo cuadrante.\n", x, y);
    } else if (x < 0 && y < 0) {
        printf("El punto (%.2f, %.2f) se encuentra en el tercer cuadrante.\n", x, y);
    } else if (x > 0 && y < 0) {
        printf("El punto (%.2f, %.2f) se encuentra en el cuarto cuadrante.\n", x, y);
    } else if (x == 0 && y != 0) {
        printf("El punto (%.2f, %.2f) se encuentra sobre el eje Y.\n", x, y);
    } else if (x != 0 && y == 0) {
        printf("El punto (%.2f, %.2f) se encuentra sobre el eje X.\n", x, y);
    } else {
        printf("El punto (%.2f, %.2f) es el origen de coordenadas.\n", x, y);
    }
}

void convertirAPolares(float x, float y) {
    float r = sqrt(x * x + y * y);
    float arg = atan2(y, x) * 180 / M_PI; // Convertir a grados
    printf("Las coordenadas polares del punto (%.2f, %.2f) son: r = %.2f, arg = %.2f grados.\n", x, y, r, arg);
}

int main() {
    float x, y;
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Ingrese las coordenadas del punto:\n");
        printf("x: ");
        scanf("%f", &x);
        printf("y: ");
        scanf("%f", &y);

        do {
            clrscr();
            printf("Seleccione una opcion:\n");
            printf("1. Comprobar si el punto pertenece a una circunferencia de radio 10 y centro (0,0)\n");
            printf("2. Averiguar el cuadrante en el que se encuentra el punto\n");
            printf("3. Convertir las coordenadas cartesianas (x, y) a polares (r, arg)\n");
            printf("4. Salir\n");
            printf("Opcion: ");
            scanf("%s", buffer);

            if (sscanf(buffer, "%d", &opcion) != 1) {
                opcion = 0;
            }

            clrscr();

            switch (opcion) {
                case 1:
                    comprobarCircunferencia(x, y);
                    break;
                case 2:
                    averiguarCuadrante(x, y);
                    break;
                case 3:
                    convertirAPolares(x, y);
                    break;
                case 4:
                    printf("Saliendo del programa.\n");
                    break;
                default:
                    printf("Opcion no valida. Intente de nuevo.\n");
            }

            if (opcion != 4) {
                printf("\nPresione cualquier tecla para continuar...\n");
                getch();
            }
        } while (opcion != 4);

    } while (1);

    return 0;
}
