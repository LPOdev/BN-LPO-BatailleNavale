//Title: Bataille Navale
//Author: LPO
//Date: 15.03.2019
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>


#pragma execution_character_set("UTF-8")

int Grille1[9][9]=
        {
                0,4,4,4,4,0,0,0,0,
                0,0,0,0,0,0,0,0,0,
                0,0,0,0,3,0,0,0,0,
                0,0,0,0,3,0,0,0,0,
                0,0,0,0,3,0,0,0,0,
                0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,
                1,0,0,0,0,0,2,2,0
        };

void Grille()
{
    int x;
    int y;
    printf("  X  1   2   3   4   5   6   7   8   9");
    for(x= 0;x<9;x++)
    {
        printf("\n");

        if(x==0)
        {
            printf("   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐\n  ");
        }
        if(x!=0)
        {
            printf("   ├───┼───┼───┼───┼───┼───┼───┼───┼───┤\n  ");
        }


        printf("%d",x+1);
        for(y=0;y<9;y++)
        {
            if(Grille1[x][y]==0|| Grille1[x][y]==1 || Grille1[x][y]==2 || Grille1[x][y]==3 || Grille1[x][y]==4)
            {
            printf("│   ");
            }else if(Grille1[x][y]==12 || Grille1[x][y]==13 || Grille1[x][y]==14)
            {
                printf("│ x ");
            }else if(Grille1[x][y]==-1)
            {
                printf("│ ~ ");
            }else if(Grille1[x][y]==11 ||Grille1[x][y]==12 || Grille1[x][y]==13  || Grille1[x][y]==14)
            {
                printf("│ X ");
            }
        }
        if(y==9)
        {
            printf("│");
        }
        if(x==8)
        {
            printf("\n   └───┴───┴───┴───┴───┴───┴───┴───┴───┘");
        }
    }
}
void Game()
{
    int cvert;
    int chorz;
    int arret;
    do
    {
        Grille();
        printf("\nIntroduisez la coordonée vertical: ");
        scanf("%d",&cvert);
        printf("\nIntroduisez la coordonée horizontal: ");
        scanf("%d",&chorz);

        if(Grille1[chorz -1][cvert-1] == 0)
        {
            Grille1[chorz-1][cvert-1] = -1;
        }
        else if(Grille1[chorz-1][cvert-1] == 1 || Grille1[chorz-1][cvert-1] == 2 || Grille1[chorz-1][cvert-1] == 3 || Grille1[chorz-1][cvert-1] == 4)
        {
            Grille1[chorz-1][cvert-1]+= 10;
        } else if (Grille1[chorz-1][cvert-1] > 10 || Grille1[chorz-1][cvert-1] == -1)
        {
            printf("Vous avez deja tire la !");
        }

        printf("Arret: ");
        scanf("%d",&arret);
    } while(arret != 0);
}


int main() {
    SetConsoleOutputCP(65001);

    int choix;

    //Boat
    printf("                         \t  )___(\n"
           "                           _______/__/_\n"
           "                  ___     /===========|   ___\n"
           " ____       __   [\\\\\\]___/____________|__[///]   __\n"
           " \\   \\_____[\\\\]__/___________________________\\__[//]___\n"
           "  \\40A                                                 |\n"
           "   \\                                                  /\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    //Menu Principal
    do {
        printf("\n\n_____Bataille Navale_____\n\n");
        printf("1. Jouer");
        printf("\n2. Instructions");
        printf("\n3. Paramètres");
        printf("\n0. Quitter");

        //Que faire ?
        printf("\nIntroduisez un chiffre de 0 a 3: ");
        scanf("%d", &choix);
        if(choix <0 || choix > 3)
        {
            printf("Ceci n'est pas un choix !");
        }
        switch(choix)
        {
            case 0: printf("\nA la prochaine !");
                return 0;

            case 1: printf("\n_____Jouer_____\n");
                printf("\nBievenue sur le mode jeu");
                do
                {
                    printf("\nIntroduire 0 pour revenir en arriere ou 1 pour lancer une partie: \n");
                    scanf("%d", &choix);
                    if (choix == 0) {
                        choix = +100;
                        break;
                    } else if (choix == 1) {
                        Game();
                    } else
                    {
                        printf("Ce n'est pas un choix !\n");
                    }
                }while(choix != 0 && choix !=1);
                break;

            case 2: printf("\n\n_____Instructions_____\n");
                printf("\nLes règles s'affichent...\n");
                do {
                    printf("\n0. Revenir en arriere\n");
                    printf("\nIntroduire votre choix: ");
                    scanf("%d", &choix);
                    if (choix == 0) {
                        choix = +100;
                        break;
                    } else {
                        printf("Ce n'est pas un choix !\n");

                    }
                } while(choix != 0);
                break;

            case 3: printf("\n\n_____Paramètres_____\n");
                do {
                    printf("\n1. Modifier la grille");
                    printf("\n0. Revenir en arriere");
                    printf("\n\nIntroduire votre choix: ");
                    scanf("%d", &choix);
                    if (choix == 0) {
                        choix = +100;
                        break;
                    }else if(choix == 1)
                    {
                        Grille();
                    }
                    else {
                        printf("Ce n'est pas un choix !\n");

                    }
                } while(choix != 0);
                break;
        }

    }while (choix < 0 || choix > 3);

    return 0;
}

