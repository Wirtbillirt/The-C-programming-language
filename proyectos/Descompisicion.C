#include <stdio.h>
#include <conio.h>


int esPrimo(int n) {
    int i;
    if (n <= 1) return 0;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}


void descomponerEnFactoresPrimos(int n) {
    int factor = 2;
    printf("Nº | Factores primos\n");
    printf("-- | ---------------\n");
    while (n > 1) {
        if (n % factor == 0) {
            printf("%d | %d\n", n, factor);
            n /= factor;
        } else {
            factor++;
            while (!esPrimo(factor)) {
                factor++;
            }
        }
    }
    printf("1 |\n");
}

int main() {
    int numero;

    clrscr();
    printf("Introduce un Nº entero -> ");
    scanf("%d", &numero);

    if (numero > 1) {
        descomponerEnFactoresPrimos(numero);
    } else {
        printf("El número debe ser mayor que 1.\n");
    }

    printf("Presione cualquier tecla para continuar...");
    getch();

    return 0;
}
