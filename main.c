#include <stdio.h>
#include <stdbool.h>

#define WIDTH 3
#define HEIGHT 3

typedef enum { empty, X, O } XO;

XO arena[WIDTH][HEIGHT];  //2D array initialized as empty (because it's the first enum in XO

XO player = X;  //x starts
XO winner = empty;  //winner has not been determined

XO checkWin(XO arena[WIDTH][HEIGHT]);

void print2DArr(XO arena[WIDTH][HEIGHT]);

bool check3equals(XO one, XO two, XO three);

int main(void)
{
    int x, y;
    while(winner == empty) {
        print2DArr(arena);

        //inform player
        switch (player) {
            case X:
                printf("X's turn:");
                break;
            case O:
                printf("O's turn:");
                break;
            default:
                break;  //hopefully break while loop
        }

        //get coords (from 1 - 3)
        scanf("%d %d", &x, &y);
        x--; y--;  //change to 0 - 2

        //failsafe: make sure the area isn't already taken
        if (arena[x][y] == empty) {

            //place X/O at chosen location
            arena[x][y] = player;

            //update winner
            winner = checkWin(arena);

            //switch player
            if (player == X){ player = O; }
            else { player = X; }

            continue;
        }
        printf("\nINVALID MOVE\n");
    }

    switch (winner) {
        case X:
            printf("X has won!\n");
            break;
        case O:
            printf("O has won!\n");
            break;
    }
    print2DArr(arena);

    return 0;
}

XO checkWin(XO arena[WIDTH][HEIGHT]) {
    //NOTE: will not work with any arena-sizes BUT 3x3
    for (int i = 0; i < HEIGHT; i++) {
        if (check3equals(arena[i][0], arena[i][1], arena[i][2])){ //horizontal
            return arena[i][0];
        }
        if (check3equals(arena[0][i], arena[1][i], arena[2][i])){  //vertical
            return arena[0][i];
        }
    }

    if (check3equals(arena[0][0], arena[1][1], arena[2][2])  //diagonal
        || check3equals(arena[0][2], arena[1][1], arena[2][0])){
        return arena[1][1];
    }

    return empty;
}

void print2DArr(XO arena[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            switch (arena[x][y]) {
                case X:
                    printf("X");
                    break;
                case O:
                    printf("O");
                    break;
                default:
                    printf("-");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool check3equals(const XO one, const XO two, const XO three) {
    if (one == empty) { return false; }
    if (two == empty) { return false; }
    if (three == empty) { return false; }

    return one == two && two == three;
}