#include <stdio.h>
#include <conio.h>


unsigned long long factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}


double calcular_e() {
    double e = 1.0;
    double term;
    int i = 1;

    do {
        term = 1.0 / factorial(i);
        e += term;
        i++;
    } while (term > 1e-15);  

    return e;
}


double calcular_e_x(double x) {
    double e_x = 1.0;
    double term = 1.0;
    int i = 1;

    do {
        term *= x / i;
        e_x += term;
        i++;
    } while (term > 1e-15); 

    return e_x;
}

int main() {
    int opcion;
    int numero;
    double x;

    do {
        clrscr();
        printf("Menu:\n");
        printf("1. Factorial de un numero\n");
        printf("2. Calculo de e\n");
        printf("3. Calculo de e^x\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un numero: ");
                scanf("%d", &numero);
                if (numero < 0) {
                    printf("El factorial no esta definido para numeros negativos.\n");
                } else {
                    printf("Factorial de %d es %llu\n", numero, factorial(numero));
                }
                break;

            case 2:
                printf("El valor de e es: %.15f\n", calcular_e());
                break;

            case 3:
                printf("Ingrese el valor de x: ");
                scanf("%lf", &x);
                printf("El valor de e^%.2f es: %.15f\n", x, calcular_e_x(x));
                break;

            case 0:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }

        printf("Presione cualquier tecla para continuar...");
        getch();
    } while (opcion != 0);

    return 0;
}
