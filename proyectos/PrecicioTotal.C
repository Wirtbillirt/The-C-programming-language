#include <stdio.h>
#include <conio.h>

void calcularPrecioTotal() {
    int numero_almacen, cantidad;
    double precio_por_unidad, precio_total;

   
    printf("Ingrese el numero de almacen: ");
    if (scanf("%d", &numero_almacen) != 1) {
        printf("Entrada no valida. Intente de nuevo.\n");
        return;
    }

    printf("Ingrese la cantidad pedida: ");
    if (scanf("%d", &cantidad) != 1 || cantidad < 0) {
        printf("Entrada no valida. Intente de nuevo.\n");
        return;
    }

    printf("Ingrese el precio por unidad: ");
    if (scanf("%lf", &precio_por_unidad) != 1 || precio_por_unidad < 0) {
        printf("Entrada no valida. Intente de nuevo.\n");
        return;
    }

    precio_total = cantidad * precio_por_unidad;

   
    printf("\nInformacion de la pieza:\n");
    printf("Numero de almacen: %d\n", numero_almacen);
    printf("Cantidad pedida: %d\n", cantidad);
    printf("Precio por unidad: %.2f\n", precio_por_unidad);
    printf("Importe total del pedido: %.2f\n", precio_total);
}

int main() {
    int opcion;
    char buffer[100];

    do {
        clrscr();
        printf("Seleccione una opcion:\n");
        printf("1. Calcular precio total de piezas\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &opcion) != 1) {
            opcion = 0;
        }

        clrscr();

        switch (opcion) {
            case 1:
                calcularPrecioTotal();
                break;
            case 2:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }

        if (opcion != 2) {
            printf("\nPresione cualquier tecla para continuar...\n");
            getch();
        }
    } while (opcion != 2);

    return 0;
}
