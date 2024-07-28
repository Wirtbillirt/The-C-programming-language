#include <stdio.h>
#include <conio.h>


unsigned long long factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}


unsigned long long combinatorio(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int n, k;
    unsigned long long resultado;

    clrscr();

    
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    printf("Ingrese el valor de k: ");
    scanf("%d", &k);

   
    if (n < 0 || k < 0 || k > n) {
        printf("Valores no validos. Asegurese de que 0 <= k <= n y n >= 0\n");
        getch();
        return 1;
    }

    resultado = combinatorio(n, k);

    
    printf("C(%d, %d) = %llu\n", n, k, resultado);

    getch();  
    return 0;
}



