#include <stdio.h>
#include <conio.h>

int invertirDigitos(int num) {
    int invertido = 0;
    while (num != 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    return invertido;
}

int main() {
    int numero, numeroInvertido;

    clrscr();
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    numeroInvertido = invertirDigitos(numero);

    printf("El numero %d invertido es %d\n", numero, numeroInvertido);

    getch();  
    return 0;
}

