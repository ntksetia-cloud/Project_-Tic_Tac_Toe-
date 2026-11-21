#include <stdio.h>

char board[3][3];//Created a global 3x3 character array to store the game board structure.
void resetBoard(void)//function that will reset the board before a new game start.
{
    int i, j;
    char c = '1';
    for (i = 0; i < 3; i++)//loop for rows
        for (j = 0; j < 3; j++)//loop for columns
            board[i][j] = c++;
}

void printBoard(void)
{
    int i;
    printf("\n");
    for (i = 0; i < 3; i++)
    {
        printf("     %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("    ---+---+---\n");
    }
    printf("\n");
}

/* Returns 1 if the given player has three in a row */
int checkWin(char p)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return 1; /* row */
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return 1; /* column */
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return 1; /* diagonal */
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
        return 1; /* anti-diagonal */
    return 0;
}

/* Returns 1 if every cell is filled */
int checkDraw(void)
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

/* Asks the player for a move until a valid one is entered */
void getMove(char p)
{
    int pos, row, col, ok;
    char junk;

    do
    {
        ok = 0;
        printf("Player %c, enter a position (1-9): ", p);
        if (scanf("%d", &pos) != 1)
        {
            /* not a number: clear the bad input */
            while ((junk = getchar()) != '\n' && junk != EOF)
                ;
            printf("Invalid input! Please enter a number from 1 to 9.\n");
            continue;
        }
        if (pos < 1 || pos > 9)
        {
            printf("Out of range! Choose between 1 and 9.\n");
            continue;
        }
        row = (pos - 1) / 3;
        col = (pos - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("That cell is already taken! Try again.\n");
            continue;
        }
        board[row][col] = p;
        ok = 1;
    } while (!ok);
}

int main(void)
{
    int scoreX = 0, scoreO = 0, draws = 0;
    char current, again;
    int gameOver;

    printf("=====================================\n");
    printf("      TIC-TAC-TOE  (2 Players)\n");
    printf("=====================================\n");

    do
    {
        resetBoard();
        current = 'X';
        gameOver = 0;

        while (!gameOver)
        {
            printBoard();
            getMove(current);

            if (checkWin(current))
            {
                printBoard();
                printf("*** Player %c wins! ***\n", current);
                if (current == 'X')
                    scoreX++;
                else
                    scoreO++;
                gameOver = 1;
            }
            else if (checkDraw())
            {
                printBoard();
                printf("*** It's a draw! ***\n");
                draws++;
                gameOver = 1;
            }
            else
            {
                current = (current == 'X') ? 'O' : 'X';
            }
        }

        printf("\n------- SCOREBOARD -------\n");
        printf("Player X : %d\n", scoreX);
        printf("Player O : %d\n", scoreO);
        printf("Draws    : %d\n", draws);
        printf("--------------------------\n");

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("\nThanks for playing! Final score -> X: %d, O: %d, Draws: %d\n",
           scoreX, scoreO, draws);
    return 0;
}