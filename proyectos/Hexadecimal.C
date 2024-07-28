#include <stdio.h>
#include <conio.h>

int main() {
    char caracter;

    clrscr();
    printf("Ingrese un caracter: ");
    caracter = getch(); 

    printf("\nCaracter introducido: %c\n", caracter);
    printf("Codigo ASCII (decimal): %d\n", caracter);
    printf("Codigo ASCII (hexadecimal): %X\n", caracter);

    printf("\nPresione cualquier tecla para salir...\n");
    getch(); 

    return 0;
}
