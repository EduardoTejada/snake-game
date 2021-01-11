#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>


// 219 = █
//254 = ■


char user, jogo[10][30];
int y, x, cont, cobra[2][300], maca_y, maca_x, acao_menu, morte = 0, pontos = 0, recorde = 0, table[10][30];

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
        for(y=0; y<=1; y++)
        {
            for(x=1; x<=29; x++)
                cobra[y][x] = -1;
        }
        cobra[1][0] = 5;
        cobra[0][0] = 15;
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

void tabela()
{

    for(y=0; y<=9; y++)
    {
        for(x=0; x<=29; x++)
        {
            table[y][x] = 0;
            for(cont = 0; cont < 300; cont++)
            {
                if (cobra[0][cont] == x && cobra[1][cont] == y)
                    table[y][x] = 1;
            }
            if (y == maca_y && x == maca_x && (y != cobra[1][0] || x != cobra[0][0]))
                table[y][x] = 2;
            if (y == maca_y && x == maca_x && y == cobra[1][0] && x == cobra[0][0])
            {
                pontos++;
                maca_y = rand() % 10;
                maca_x = rand() % 30;
            }
        }
    }




    for(y=0; y<=9; y++)
    {
        if(y==0)
            printf("________________________________\tPONTOS: %d\n", pontos);
        printf("|");
        for(x=0; x<=29; x++)
        {
            jogo[y][x] = ' ';
            if (table[y][x] == 1)
            {
                jogo[y][x] = 219;
            }
            if (table[y][x] == 2)
            {
                jogo[y][x] = 254;
            }
            printf("%c", jogo[y][x]);
        }
        printf("|\n");
    }
    printf("________________________________");
}


void getUser()
{
    for(cont = pontos-1; cont >= 0; cont--)
    {
        cobra[1][cont+1] = cobra[1][cont];
        cobra[0][cont+1] = cobra[0][cont];
    }
    fflush(stdin);
    user = getch();
    switch (user)
    {
    case 'w':
        if (cobra[1][0] > 0)
            cobra[1][0]--;
        else
        {
            printf("\a");
            morte = 1;
        }
        break;

    case 'd':
        if (cobra[0][0] < 29)
            cobra[0][0]++;
        else
        {
            printf("\a");
            morte = 1;
        }
        break;

    case 's':
        if (cobra[1][0] < 9)
            cobra[1][0]++;
        else
        {
            printf("\a");
            morte = 1;
        }
        break;

    case 'a':
        if (cobra[0][0] > 0)
            cobra[0][0]--;
        else
        {
            printf("\a");
            morte = 1;
        }
        break;
    }
}




int main ()
{
    for(y=0; y<=1; y++)
    {
        for(x=1; x<=29; x++)
            cobra[y][x] = -1;
    }
    cobra[1][0] = 5;
    cobra[0][0] = 15;
    maca_y = rand() % 10;
    maca_x = rand() % 30;
    printf(" === JOGO DA COBRINHA === \nBy: Eduardo e Pedro\n\n");
    do
    {
        menu();

        system("pause");
        system("cls");
        tabela();

        while(acao_menu == 1)
        {
            system("cls");
            tabela();
            getUser();
            if(morte == 0)
            {
                system("cls");
                tabela();
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

