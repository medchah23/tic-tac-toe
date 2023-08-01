#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
bool verif(const char ch[20])
{
    size_t i = 0;
    bool b = true;
    while (i < strlen(ch) && b)
    {
        if (toupper(ch[i]) < 'A' || toupper(ch[i]) > 'Z')
        {
            b = false;
        }
        else
        {
            i++;
        }
    }
    return b;
}
char *saisir(int i)
{
    char nom[20];
    printf("Veuillez saisir votre nom player %d: ", i);
    scanf("%s", nom);
    while (verif(nom) == false)
    {
        printf("Veuillez saisir votre nom: ");
        scanf("%s", nom);
    }
    return strdup(nom);
}
struct Player
{
    char name[20];
    char symbol[2];
};
void players(struct Player *x, struct Player *y)
{
    int i = 1;

    strcpy(x->name, saisir(i));
    printf("Bonjour %s dans notre jeu Tic Tac Toe.\nVeuillez choisir un symbole avec lequel vous voulez jouer: ", x->name);
    scanf("%1s", x->symbol);

    i = 2;
    strcpy(y->name, saisir(i));
    printf("Bonjour %s dans notre jeu Tic Tac Toe.\nVeuillez choisir un symbole avec lequel vous voulez jouer: ", y->name);
    scanf("%1s", y->symbol);
}
bool caseval(char table[3][3], int row, int col)
{
    if (row < 0 || row >= 3 || col < 0 || col >= 3)
    {
        return false;
    }
    if (table[row][col] != ' ')
    {
        return false;
    }
    return true;
}
void printTable(char table[3][3])
{
    printf("\n");
    printf("   1   2   3  \n");
    printf(" --------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d |", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf(" %c |", table[i][j]);
        }
        printf("\n");
        printf(" --------------\n");
    }
}
void game(struct Player x, struct Player y)
{
    char table[3][3];
    int row, col;

    // Initialize the table
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            table[i][j] = ' ';
        }
    }

    bool player1Turn = true;
    int movesLeft = 9;

    while (movesLeft > 0)
    {
        printf("Player %s, it's your turn.\n", (player1Turn ? x.name : y.name));
        printf("Please choose your move (column): ");
        scanf("%d", &col);
        printf("Please choose your move (row): ");

        scanf("%d", &row);
        if (!caseval(table, row - 1, col - 1))
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        if (player1Turn)
        {
            table[row - 1][col - 1] = x.symbol[0];
        }
        else
        {
            table[row - 1][col - 1] = y.symbol[0];
        }

        movesLeft--;

        player1Turn = !player1Turn;

        printTable(table);
    }

    printf("It's a draw!\n");
}
int main()
{
    struct Player x, y;
    players(&x, &y);
    game(x, y);
    return 0;
}