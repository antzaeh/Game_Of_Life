#include "life.h"
/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:init_game
 DESCRIPTION: initializes board. Default, random or from .txt file
    Input: struct cell board[col][row]
    Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void init_game(struct cell board[col][row], int i, int j)
{
    int random;
    int input;

    printw("For default placements press 1\nFor random placements press 2\nFor placements from txt file press 3\n");
    scanw("%d", &input);

    if (input == 1)
    {
        board[2][2].current = 1;
        board[2][3].current = 1;
        board[3][2].current = 1;
        board[5][3].current = 1;
        board[3][5].current = 1;
        board[1][1].current = 1;
        board[1][1].current = 1;
        board[5][5].current = 1;
        board[4][4].current = 1;
        board[1][6].current = 1;
        board[6][1].current = 1;
    }
    else if (input == 2)
    {
        srand(time(NULL));
        for (i = 1; i < row - 1; i++)
        {
            for (j = 1; j < col - 1; j++)
            {
                random = rand() % 2;
                if (random == 1)
                {
                    board[i][j].current = 1;
                }
                else
                {
                    board[i][j].current = 0;
                    // refresh();
                }
            }
        }
    }
    else if (input == 3)
    {
        FILE *fp;
        char state_c;
        int state,
        i=0;
        j=0;

        fp = fopen("life.txt", "r");

        while (!feof(fp))
        {
            fscanf(fp, "%c", &state_c);
            state = state_c - '0';
            printw("%c",state_c);
            refresh();
            board[i][j].current = state;

            j++;
            if (j > col-1)
            {
                i++;
                j = 0;
                /* reads the newline characters away */
                fscanf(fp, "%c", &state_c); /* reads newline from file */
            }
        }
    }

}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:print_board
 DESCRIPTION: prints current situation of the game
    Input: struct cell board[col][row])
    Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void print_board(struct cell board[col][row], int i, int j)
{
    move(0, 0);
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j].current == 0)
            {
                printw(".");
                refresh();
            }
            else
            {
                printw("0");
                refresh();
            }
        }
        printw("\n");
    }
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_naap
 DESCRIPTION: Calculates cells neighbours positions
    Input: struct cell board[row][col],i,j
    Output: value for calc_game
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
int count_naap(struct cell board[col][row], int i, int j)
{
    int naap;

    naap = board[i - 1][j - 1].current + board[i][j - 1].current + board[i + 1][j - 1].current +
           board[i - 1][j].current + board[i + 1][j].current +
           board[i - 1][j + 1].current + board[i][j + 1].current + board[i + 1][j + 1].current;
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: calc_game
 DESCRIPTION: Counts current state of the game and writes new board
    Input: struct cell board[row][col],i,j
    Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void calc_game(struct cell board[col][row], int i, int j)
{

    for (i = 1; i < row - 1; i++)
    {
        for (j = 1; j < col - 1; j++)
        {
            int naap = count_naap(board, i, j);

            if (board[i][j].current == 1 && naap < 2)
            {
                board[i][j].future = 0;
            }
            else if (board[i][j].current == 1 && naap >= 4)
            {
                board[i][j].future = 0;
            }
            else if (board[i][j].current == 1 && (naap == 2 || naap == 3))
            {
                board[i][j].future = 1;
            }
            else if (board[i][j].current == 0 && naap == 3)
            {
                board[i][j].future = 1;
            }
        }
        refresh();
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j].current = board[i][j].future;
        }
    }
    refresh();
}
