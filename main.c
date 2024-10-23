#include <stdio.h>
#include <stdbool.h>

typedef enum { X, O, empty } XO;
XO arena[3][3] = { {empty, empty, empty},
                        {empty, empty, empty},
                        {empty, empty, empty} };
XO player = X;
XO winner = empty;

XO checkWin(XO arena[3][3]);

void print2DArr(XO arena[3][3]);

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

        //get coords
        scanf("%d %d", &x, &y);
        x--; y--;

        //set coords
        if (arena[y][x] == empty) {
            arena[y][x] = player;

            winner = checkWin(arena);

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
            printf("X has won!\n");
            break;
    }
    print2DArr(arena);

    return 0;
}

XO checkWin(XO arena[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (check3equals(arena[i][0], arena[i][1], arena[i][2])){
            return arena[i][0];
        }
        if (check3equals(arena[0][i], arena[1][i], arena[2][i])){
            return arena[0][i];
        }
    }

    if (check3equals(arena[0][0], arena[1][1], arena[2][2])
        || check3equals(arena[0][2], arena[1][1], arena[2][0])){
        return arena[1][1];
    }

    return empty;
}

void print2DArr(XO arena[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch (arena[i][j]) {
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