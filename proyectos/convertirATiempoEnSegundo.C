#include <stdio.h>
#include <conio.h>

int convertirATiempoEnSegundos(int horas, int minutos, int segundos) {
    return horas * 3600 + minutos * 60 + segundos;
}

int main() {
    int horas1, minutos1, segundos1;
    int horas2, minutos2, segundos2;
    int tiempoEnSegundos1, tiempoEnSegundos2, diferenciaEnSegundos;

    clrscr();

    printf("Ingrese el primer tiempo (formato HH:MM:SS): ");
    scanf("%d:%d:%d", &horas1, &minutos1, &segundos1);

   
    if (horas1 < 0 || horas1 > 23 || minutos1 < 0 || minutos1 > 59 || segundos1 < 0 || segundos1 > 59) {
        printf("Tiempo no valido\n");
        getch();
        return 1;
    }

   
    printf("Ingrese el segundo tiempo (formato HH:MM:SS): ");
    scanf("%d:%d:%d", &horas2, &minutos2, &segundos2);

    
    if (horas2 < 0 || horas2 > 23 || minutos2 < 0 || minutos2 > 59 || segundos2 < 0 || segundos2 > 59) {
        printf("Tiempo no valido\n");
        getch();
        return 1;
    }

   
    tiempoEnSegundos1 = convertirATiempoEnSegundos(horas1, minutos1, segundos1);
    tiempoEnSegundos2 = convertirATiempoEnSegundos(horas2, minutos2, segundos2);

    
    diferenciaEnSegundos = tiempoEnSegundos1 - tiempoEnSegundos2;

    
    printf("La diferencia en segundos entre los dos tiempos es: %d\n", diferenciaEnSegundos);

    getch(); 
    return 0;
}


