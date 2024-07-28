#include <stdio.h>
#include <conio.h>

void convertirCelsiusAFahrenheit() {
    float celsius, fahrenheit;

    printf("Ingrese la temperatura en grados Celsius: ");
    if (scanf("%f", &celsius) != 1) {
        printf("Entrada no valida. Intente de nuevo.\n");
        return;
    }

    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f grados Celsius son %.2f grados Fahrenheit.\n", celsius, fahrenheit);
}

void convertirFahrenheitACelsius() {
    float fahrenheit, celsius;

    printf("Ingrese la temperatura en grados Fahrenheit: ");
    if (scanf("%f", &fahrenheit) != 1) {
        printf("Entrada no valida. Intente de nuevo.\n");
        return;
    }

    celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f grados Fahrenheit son %.2f grados Celsius.\n", fahrenheit, celsius);
}

int main() {
    int opcion;
    char buffer[10];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Convertir Celsius a Fahrenheit\n");
        printf("2. Convertir Fahrenheit a Celsius\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        
        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                convertirCelsiusAFahrenheit();
                break;
            case 2:
                convertirFahrenheitACelsius();
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
