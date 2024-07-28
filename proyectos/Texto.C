#include <stdio.h>
#include <conio.h>
#include <ctype.h>


int esNumerico(char c) {
    return isdigit(c);
}


int esAlfabetico(char c) {
    return isalpha(c);
}

int main() {
    char c;
    int numBlancos = 0;
    int numDigitos = 0;
    int numLetras = 0;
    int numLineas = 0;
    int numOtros = 0;

    clrscr();
    printf("Introduce el texto (finaliza con una linea vacia):\n");

    while ((c = getchar()) != '\n' || getchar() != '\n') {
        if (c == ' ' || c == '\t') {
            numBlancos++;
        } else if (esNumerico(c)) {
            numDigitos++;
        } else if (esAlfabetico(c)) {
            numLetras++;
        } else if (c == '\n') {
            numLineas++;
        } else {
            numOtros++;
        }
    }

    if (numBlancos > 0 || numDigitos > 0 || numLetras > 0 || numOtros > 0) {
        numLineas++;
    }

    clrscr();
    printf("Resultados:\n");
    printf("N.º de caracteres en blanco: %d\n", numBlancos);
    printf("N.º de dígitos: %d\n", numDigitos);
    printf("N.º de letras: %d\n", numLetras);
    printf("N.º de líneas: %d\n", numLineas);
    printf("N.º de otros caracteres: %d\n", numOtros);

    printf("Presione cualquier tecla para continuar...");
    getch();

    return 0;
}
