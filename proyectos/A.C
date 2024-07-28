#include<stdio.h>
#include <conio.h>
#include<string.h>

void main(){
    int n,i,j,k,longitud;
    char nombre [50];
    clrscr();
 printf("ingrese el numero de estudiante: ");
 scanf("%d",&n);
 
 while(getchar () !='\n');
 for(i=0;i<n;i++){
    printf("ingrese el nombre estudiante: ");
    scanf("%[^\n]s",nombre);

    longitud=0;
    for (j=0;j<strlen(nombre);j++){
        if(nombre[j]!=''){
            longitud++;
        }
    }
    printf("longitud del nombre,%d\n",longitud);
    printf("longitud en astericos");
    printf("*");
    {
        printf("\n");
    }
    getch();
    
 }
}