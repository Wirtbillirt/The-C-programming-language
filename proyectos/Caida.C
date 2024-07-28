#include <stdio.h>
#include <math.h>
#include <conio.h>

#define G 9.81 
#define INTERVALO 0.1  

int main() {
    float altura_inicial, altura, velocidad, tiempo;
    char buffer[100];

    clrscr();
    printf("Ingrese la altura del edificio en metros: ");
    scanf("%f", &altura_inicial);

    if (altura_inicial <= 0) {
        printf("La altura debe ser un valor positivo.\n");
        return 1;
    }

    altura = altura_inicial;
    velocidad = 0.0;
    tiempo = 0.0;

    clrscr();
    while (altura > 0) {
        printf("t=%.1f segundos\t distancia al suelo=%.2f metros\t velocidad=%.2f m/s\n", tiempo, altura, velocidad);
        tiempo += INTERVALO;
        velocidad = G * tiempo;
        altura = altura_inicial - 0.5 * G * tiempo * tiempo;
        if (altura < 0) {
            altura = 0;
        }
    }
    printf("t=%.1f segundos\t distancia al suelo=%.2f metros\t velocidad=%.2f m/s\n", tiempo, altura, velocidad);
    printf("Fin del programa.\n");

    getch();  
    return 0;
}
