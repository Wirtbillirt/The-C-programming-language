#include <stdio.h>
#include <conio.h>


int A = 0, B = 0, C = 0;


void leerPolinomio() {
    printf("Introduzca los coeficientes del polinomio (Ax^2 + Bx + C):\n");
    printf("A: ");
    scanf("%d", &A);
    printf("B: ");
    scanf("%d", &B);
    printf("C: ");
    scanf("%d", &C);
}

void escribirPolinomio() {
    if (A != 0) {
        printf("%dx^2", A);
        if (B > 0) printf(" + %dx", B);
        if (B < 0) printf(" - %dx", -B);
    } else if (B != 0) {
        if (B > 0) printf("%dx", B);
        if (B < 0) printf(" - %dx", -B);
    }
    if (C > 0) printf(" + %d", C);
    if (C < 0) printf(" - %d", -C);
    printf("\n");
}


double evaluarPolinomio(double x) {
    return A * x * x + B * x + C;
}

void derivarPolinomio() {
    int A_deriv = 2 * A;
    int B_deriv = B;

    printf("El polinomio derivado es: ");
    if (A_deriv != 0) {
        printf("%dx", A_deriv);
        if (B_deriv > 0) printf(" + %d", B_deriv);
        if (B_deriv < 0) printf(" - %d", -B_deriv);
    } else if (B_deriv != 0) {
        printf("%d", B_deriv);
    } else {
        printf("0");
    }
    printf("\n");
}

int main() {
    int opcion;
    double x;
    double resultado;

    do {
        clrscr();
        printf("Menu:\n");
        printf("1. Leer un polinomio\n");
        printf("2. Escribir un polinomio en su forma habitual\n");
        printf("3. Evaluar un polinomio en un punto\n");
        printf("4. Calcular el polinomio derivado\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                leerPolinomio();
                break;
            case 2:
                printf("El polinomio es: ");
                escribirPolinomio();
                break;
            case 3:
                printf("Introduzca el valor de x: ");
                scanf("%lf", &x);
                resultado = evaluarPolinomio(x);
                printf("El valor del polinomio en x = %.2lf es: %.2lf\n", x, resultado);
                break;
            case 4:
                derivarPolinomio();
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
