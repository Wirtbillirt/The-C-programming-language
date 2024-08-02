#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include "mouse.h"

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

void dibujar_tablero() {
    int i;
    cleardevice();
    for (i = 1; i < 3; i++) {
        line(i * 100, 0, i * 100, 300);
        line(0, i * 100, 300, i * 100);
    }
}

void dibujar_movimiento(int fila, int columna) {
    int x = columna * 100 + 50;
    int y = fila * 100 + 50;
    if (tablero[fila][columna] == 'X') {
        line(x - 25, y - 25, x + 25, y + 25);
        line(x + 25, y - 25, x - 25, y + 25);
    } else if (tablero[fila][columna] == 'O') {
        circle(x, y, 25);
    }
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

void detectar_click(int *fila, int *columna) {
    int x, y;
    while (!mclick());
    x = mxpos(1);
    y = mypos(1);
    *columna = x / 100;
    *fila = y / 100;
}

int main() {
    int gd = DETECT, gm;
    int fila, columna, movimientos = 0;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    if (graphresult() != grOk) {
        printf("Error initializing graphics mode\n");
        return 1;
    }


    if (mtest() == 0) {
        printf("Mouse not detected.\n");
        return 1;
    }
	mver();

    inicializar_tablero();
    dibujar_tablero();

    while (1) {
        detectar_click(&fila, &columna);

        if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ') {
            continue;
        }

        tablero[fila][columna] = jugador_actual;
        dibujar_movimiento(fila, columna);
        movimientos++;

        if (verificar_ganador()) {
            outtextxy(100, 310, jugador_actual == 'X' ? "Jugador X gana!" : "Jugador O gana!");
            break;
        }

        if (movimientos == 9) {
            outtextxy(100, 310, "Es un empate!");
            break;
        }

        cambiar_jugador();
    }

    getch();
    mocultar(); 
    closegraph();
    return 0;
}

