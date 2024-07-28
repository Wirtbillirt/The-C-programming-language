#include <stdio.h>
#include <math.h>
#include <conio.h>

#define VIDA_MEDIA 5700
#define MASA_ORIGINAL 300.0

double calcularMasaRestante(double masaOriginal, double tiempo, double vidaMedia) {
    double factor = pow(0.5, tiempo / vidaMedia);
    return masaOriginal * factor;
}

int main() {
    double tiempo, masaRestante;
    int i;
    int incrementos[] = {500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000};
    int numIncrementos = sizeof(incrementos) / sizeof(incrementos[0]);

    clrscr();
    printf("Tabla de masa restante de Carbono-14:\n");
    printf("====================================\n");
	printf("  Tiempo (a¤os)  |  Masa Restante (g)\n");
    printf("-----------------|-------------------\n");

    for (i = 0; i < numIncrementos; i++) {
        tiempo = incrementos[i];
        masaRestante = calcularMasaRestante(MASA_ORIGINAL, tiempo, VIDA_MEDIA);
        printf("     %4.0f        |     %10.4f\n", tiempo, masaRestante);
    }

    printf("Fin del programa.\n");
    getch();  
    return 0;
}
