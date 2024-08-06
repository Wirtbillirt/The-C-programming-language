#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "mouse.h"

#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 50
#define BUTTON_PADDING 20

typedef enum { ROCK, PAPER, SCISSORS, NONE } Choice;
const char* choice_names[] = { "Piedra", "Papel", "Tijera" };


void draw_button(int x, int y, const char* text) {
    rectangle(x, y, x + BUTTON_WIDTH, y + BUTTON_HEIGHT);
    outtextxy(x + 10, y + 10, text);
}


void draw_choice(int x, int y, Choice choice) {
    switch (choice) {
        case ROCK:
            circle(x + 50, y + 50, 30);
            break;
        case PAPER:
            rectangle(x + 20, y + 20, x + 80, y + 80);
            break;
        case SCISSORS:
             line(x + 50, y + 20, x + 30, y + 70); 
    line(x + 50, y + 20, x + 70, y + 70); 
    line(x + 30, y + 70, x + 20, y + 90); 
    line(x + 70, y + 70, x + 80, y + 90); 
    arc(x + 30, y + 110, 0, 360, 10);
    arc(x + 70, y + 110, 0, 360, 10); 
    line(x + 30, y + 90, x + 30, y + 100); 
    line(x + 70, y + 90, x + 70, y + 100); 
    arc(x + 50, y + 50, 30, 330, 10); 
     break;
        case NONE:
            break;
    }
}


Choice detect_click(int *exit) {
    int x, y;
    while (!mclick());
    x = mxpos(1);
    y = mypos(1);

    if (x >= 50 && x <= 150 && y >= 300 && y <= 350) {
        return ROCK;
    } else if (x >= 200 && x <= 300 && y >= 300 && y <= 350) {
        return PAPER;
    } else if (x >= 350 && x <= 450 && y >= 300 && y <= 350) {
        return SCISSORS;
    } else if (x >= 200 && x <= 300 && y >= 400 && y <= 450) {
        *exit = 1;
    }
    return NONE;
}

const char* determine_winner(Choice user_choice, Choice computer_choice) {
    if (user_choice == computer_choice) {
        return "Empate";
    } else if ((user_choice == ROCK && computer_choice == SCISSORS) ||
               (user_choice == PAPER && computer_choice == ROCK) ||
               (user_choice == SCISSORS && computer_choice == PAPER)) {
        return "Ganaste";
    } else {
        return "Perdiste";
    }
}

int main() {
    int gd = DETECT, gm;
    Choice user_choice = NONE, computer_choice = NONE;
    const char* result;
    int exit = 0;

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

    srand(time(NULL));

    
    draw_button(50, 300, "Piedra");
    draw_button(200, 300, "Papel");
    draw_button(350, 300, "Tijera");
    draw_button(200, 400, "Salir");

    while (!exit) {
        user_choice = detect_click(&exit);
        if (user_choice != NONE) {
            
            computer_choice = rand() % 3;

            
            cleardevice();
            draw_choice(100, 100, user_choice);
            draw_choice(300, 100, computer_choice);

           
            result = determine_winner(user_choice, computer_choice);
            outtextxy(200, 250, result);

            
            draw_button(50, 300, "Piedra");
            draw_button(200, 300, "Papel");
            draw_button(350, 300, "Tijera");
            draw_button(200, 400, "Salir");
        }
    }

    mocultar(); 
    closegraph();
    return 0;
}