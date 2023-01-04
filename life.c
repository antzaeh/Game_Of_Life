#include "life.h"
/*********************************************************************
 *    MAIN PROGRAM                                                      *
 **********************************************************************/

int main(void)
{
    int i; // col
    int j; // row
    int round;

    initscr();
    clear();

    printw("Number of rounds: ");
    scanw("%d", &round);
    struct cell board[9][9] = {0, 0};
    noecho();
    init_game(board, i, j);

    for (i = 0; i <= round; i++)
    {
        print_board(board, i, j);
        sleep(1);
        calc_game(board, i, j);
    }

    getch();
    endwin();
    return 0;
} /* end of main */