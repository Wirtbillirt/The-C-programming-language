#include <stdio.h>
#include <conio.h>

int main() {
    int i;
    
    clrscr();
    
    for (i = 1; i <= 100; i++) {
        printf("%3d ", i);
        if (i % 10 == 0) {
            printf("\n");
        }
    }

    printf("Fin del programa\n");
    getch();  
    return 0;
}
