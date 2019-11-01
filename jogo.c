#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define LIN 9
#define COL 9

void montarCampo(char campo[LIN][COL], char comidas[32])
{
    int x, y;
    for (x = 0; x < 32; x++)
    {
        comidas[x] = '\0';
    }
    for (x = 0; x < LIN; x++)
    {
        for (y = 0; y < COL; y++)
        {
            campo[x][y] = '\0';
        }
    }

    campo[0][1] = '1';
    campo[0][2] = '2';
    campo[0][3] = '3';
    campo[0][4] = '4';
    campo[0][5] = '5';
    campo[0][6] = '6';
    campo[0][7] = '7';
    campo[0][8] = '8';

    campo[1][0] = '1';
    campo[2][0] = '2';
    campo[3][0] = '3';
    campo[4][0] = '4';
    campo[5][0] = '5';
    campo[6][0] = '6';
    campo[7][0] = '7';
    campo[8][0] = '8';

    campo[1][1] = 'T';
    campo[1][2] = 'C';
    campo[1][3] = 'B';
    campo[1][4] = 'R';
    campo[1][5] = 'K';
    campo[1][6] = 'B';
    campo[1][7] = 'C';
    campo[1][8] = 'T';
    campo[2][1] = 'P';
    campo[2][2] = 'P';
    campo[2][3] = 'P';
    campo[2][4] = 'P';
    campo[2][5] = 'P';
    campo[2][6] = 'P';
    campo[2][7] = 'P';
    campo[2][8] = 'P';

    campo[7][1] = 'p';
    campo[7][2] = 'p';
    campo[7][3] = 'p';
    campo[7][4] = 'p';
    campo[7][5] = 'p';
    campo[7][6] = 'p';
    campo[7][7] = 'p';
    campo[7][8] = 'p';
    campo[8][1] = 't';
    campo[8][2] = 'c';
    campo[8][3] = 'b';
    campo[8][4] = 'r';
    campo[8][5] = 'k';
    campo[8][6] = 'b';
    campo[8][7] = 'c';
    campo[8][8] = 't';
}
void imprimeCampo(char campo[LIN][COL], char comidas[32])
{
    int x, y;
    printf("\nPecas comidas: ");
    for (x = 0; x < 32; x++)
    {
        printf(" %c", comidas[x]);
    }
    printf("\nCampo: ");
    for (x = 0; x < LIN; x++)
    {
        printf("\n ");
        for (y = 0; y < COL; y++)
        {
            fflush(stdin);
            printf("%c ", campo[x][y]);
        }
    }
}
void jogada1(char campo[LIN][COL], char comidas[32], int *g, int *fim)
{
    int x, y, a, b, validar = 0;
    int h = *g;
    do
    {
        printf("\nJogador 1 forneca o local de origem e o destino da peca e realize sua jogada: ");
        printf("\nCoordenada X origem: ");
        scanf("%i", &x);
        printf("\nCoordenada y origem: ");
        scanf("%i", &y);
        if (x < 0 || y < 0 || x > 8 || y > 8 || islower(campo[x][y]))
        {
            printf("\nValor invalido, digite Novamente!!!");
        }
        else if (campo[x][y] != '\0')
        {
            printf("\nCoordenada X destino: ");
            scanf("%i", &a);
            printf("\nCoordenada y destino: ");
            scanf("%i", &b);
            if (a < 0 || b < 0 || a > 8 || b > 8 || isupper(campo[a][b]))
            {
                printf("\nValor invalido, digite Novamente!!!");
            }
            else if (campo[a][b] == '\0')
            {
                printf("Jogada Validada!");
                campo[a][b] = campo[x][y];
                campo[x][y] = '\0';
                validar = 1;
            }
            else
            {
                printf("Jogada Validada!");
                comidas[h] = campo[a][b];
                if (campo[a][b] == 'k')
                {
                    *fim = 1;
                }
                campo[a][b] = campo[x][y];
                campo[x][y] = '\0';
                validar = 1;
                h++;
                *g = h;
            }
        }
        else
        {
            printf("\nCoordenadas invalidas, digite novamente!!");
        }
    } while (validar != 1);
}
void jogada2(char campo[LIN][COL], char comidas[32], int *g, int *fim)
{
    int x, y, a, b, validar = 0;
    int h = *g;
    do
    {
        printf("\nJogador 2 forneca o local de origem e o destino da peca e realize sua jogada: ");
        printf("\nCoordenada X origem: ");
        scanf("%i", &x);
        printf("\nCoordenada y origem: ");
        scanf("%i", &y);
        if (x < 0 || y < 0 || x > 8 || y > 8 || isupper(campo[x][y]))
        {
            printf("\nValor invalido, digite Novamente!!!");
        }
        else if (campo[x][y] != '\0')
        {
            printf("\nCoordenada X destino: ");
            scanf("%i", &a);
            printf("\nCoordenada y destino: ");
            scanf("%i", &b);
            if (a < 0 || b < 0 || a > 8 || b > 8 || islower(campo[a][b]))
            {
                printf("\nValor invalido, digite Novamente!!!");
            }
            else if (campo[a][b] == '\0')
            {
                printf("Jogada Validada!");
                campo[a][b] = campo[x][y];
                campo[x][y] = '\0';
                validar = 1;
            }
            else
            {
                printf("Jogada Validada!");
                comidas[h] = campo[a][b];
                if (campo[a][b] == 'K')
                {
                    *fim = 1;
                }
                campo[a][b] = campo[x][y];
                campo[x][y] = '\0';
                validar = 1;
                h++;
                *g = h;
            }
        }
        else
        {
            printf("\nCoordenadas invalidas, digite novamente!!");
        }
    } while (validar != 1);
}
main()
{
    char *campo[LIN][COL];
    char *pecasComidas[32];
    int indexC = 0;
    int fim = 0;
    int x;
    montarCampo(campo, pecasComidas);
    imprimeCampo(campo, pecasComidas);
    do
    {
        jogada1(campo, pecasComidas, &indexC, &fim);
        for (x = 0; x < 32; x++)
        {
            if (pecasComidas[x] == 'k')
            {
                fim = 1;
            }
        }
        jogada2(campo, pecasComidas, &indexC, &fim);
        for (x = 0; x < 32; x++)
        {
            if (pecasComidas[x] == 'K')
            {
                fim = 1;
            }
        }
        imprimeCampo(campo, pecasComidas);
    } while (fim != 1);
    printf("\nFIM DE JOGO!!!");
}
