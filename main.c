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
        if (player == X) { printf("X's turn:"); }
        else if (player == O) { printf("O's turn:"); }
        else { break; }

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

    if (winner == X) { printf("X has won!\n"); }
    else if (winner == O) { printf("O has won!\n"); }
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
            if (arena[i][j] == X) {
                printf("X");
            } else if (arena[i][j] == O) {
                printf("O");
            } else {
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

    if (one == two && two == three) { return true; }
    return false;
}