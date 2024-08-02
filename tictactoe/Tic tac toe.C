#include <stdio.h>
#include <conio.h>

char tablero[3][3];
char jugador_actual = 'X';

void inicializar_tablero() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void mostrar_tablero() {
    int i;
    clrscr();
    printf(" %c | %c | %c \n", tablero[0][0], tablero[0][1], tablero[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tablero[1][0], tablero[1][1], tablero[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tablero[2][0], tablero[2][1], tablero[2][2]);
}

int verificar_ganador() {
    int i;
    for (i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ')
            return 1;
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ')
            return 1;
    }
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ')
        return 1;
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ')
        return 1;
    return 0;
}

void cambiar_jugador() {
    if (jugador_actual == 'X')
        jugador_actual = 'O';
    else
        jugador_actual = 'X';
}

int main() {
    int fila, columna, movimientos = 0;
    inicializar_tablero();

    while (1) {
        mostrar_tablero();
        printf("Jugador %c, ingresa fila y columna (1-3): ", jugador_actual);
        scanf("%d %d", &fila, &columna);

        fila--;
        columna--;

        if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ') {
			printf("Movimiento invalido. Intenta nuevamente.\n");
            getch();
            continue;
        }

        tablero[fila][columna] = jugador_actual;
        movimientos++;

        if (verificar_ganador()) {
            mostrar_tablero();
            printf("Jugador %c gana!\n", jugador_actual);
            break;
        }

        if (movimientos == 9) {
            mostrar_tablero();
            printf("Es un empate!\n");
            break;
        }

        cambiar_jugador();
    }

    return 0;
}
