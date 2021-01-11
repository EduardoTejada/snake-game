#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>


// 219 = █
//254 = ■


char user, jogo[10][30];
int y, x, cobra_y = 5, cobra_x = 15, maca_y, maca_x, my, mx, acao_menu, morte = 0, pontos, recorde = 0;

void score()
{
	if(pontos > recorde)
  {
  	recorde = pontos;
  }
}

void reiniciar()
{
    printf("\n\n\n\t>> Voce perdeu! <<");
    printf("\n\n\t(1) -- Reinciar");
    printf("\n\n\t(3) -- Encerrar o jogo");

    printf("\n\n\tinforme a acao desejada: >> ");
    fflush(stdin);
    scanf("%d", &acao_menu);

    if(acao_menu == 1)
    {
        x = y = pontos = morte = 0;
        cobra_y = 5;
        cobra_x = 15;
    }

    if(acao_menu == 3)
    {
        system("CLS");
        printf(">> O jogo foi encerrado! <<");
        exit;
    }
}

void menu()
{

    printf("\t\t\t>> MENU <<");
    printf("\n\n\t(1) -- Iniciar jogo");
    printf("\n\t(2) -- Recorde");
    printf("\n\t(3) -- Encerrar jogo\n\n");

    printf("\tInforme a acao desejada: >> ");
    fflush(stdin);
    scanf("%d", &acao_menu);

    if(acao_menu == 3)
    {
        system("pause");
        system("CLS");
        printf(">> O jogo foi encerrado! <<\n\n");
        exit;
    }
}

void tabela(int my, int mx)
{
    for(y=0; y<=9; y++)
    {
        if(y==0)
            printf("________________________________\tPONTOS: %d\n", pontos);
        printf("|");
        for(x=0; x<=29; x++)
        {
            jogo[y][x] = ' ';
            if (y == cobra_y && x == cobra_x)
            {
                jogo[y][x] = 219;
            }
            if (y == my && x == mx && (y != cobra_y || x != cobra_x))
            {
                jogo[y][x] = 254;
            }
            if (y == my && x == mx && y == cobra_y && x == cobra_x)
            {
                pontos++;
                maca_y = rand() % 10;
                maca_x = rand() % 30;
              	y = x = 0;
              	continue;
            }
            printf("%c", jogo[y][x]);
        }
        printf("|\n");
    }
    printf("________________________________");
}




int main ()
{
    maca_y = rand() % 10;
    maca_x = rand() % 30;
    printf(" === JOGO DA COBRINHA === \nBy: Eduardo e Pedro\n\n");
    do
    {
        menu();

        system("pause");
        system("cls");
        tabela(maca_x, maca_y);

        while(acao_menu == 1)
        {
            fflush(stdin);
            user = getch();
            switch (user)
            {
            case 'w':
                if (cobra_y > 0)
                    cobra_y--;
                else
                {
                    printf("\a");
                    morte = 1;
                }
                break;

            case 'd':
                if (cobra_x < 29)
                    cobra_x++;
                else
                {
                    printf("\a");
                    morte = 1;
                }
                break;

            case 's':
                if (cobra_y < 9)
                    cobra_y++;
                else
                {
                    printf("\a");
                    morte = 1;
                }
                break;

            case 'a':
                if (cobra_x > 0)
                    cobra_x--;
                else
                {
                    printf("\a");
                    morte = 1;
                }
                break;
            }

            if(morte == 0)
            {
                system("cls");
                tabela(maca_y, maca_x);
            }

            else if(morte == 1)
            {
                printf("\n\n");
                system("pause");
                system("CLS");
                reiniciar();
            }
            else if(acao_menu == 3)
                break;
        }
    }
    while(acao_menu!=3);

    return 0;
}

