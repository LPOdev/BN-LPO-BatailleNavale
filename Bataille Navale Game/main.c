//Title: Bataille Navale
//Author: LPO
//Date: 15.03.2019
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>


#pragma execution_character_set("UTF-8")

int Grille1[9][9] =
        {
                0, 4, 4, 4, 4, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 3, 0, 0, 0, 0,
                0, 0, 0, 0, 3, 0, 0, 0, 0,
                0, 0, 0, 0, 3, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                1, 0, 0, 0, 0, 0, 2, 2, 0
        };
int Coule[5] = {0, 0, 0, 0, 0};

void coule(int x, int y)
{
    //Fonction Coule
    for (int i = 1; i <=4; i++)
    {
        if(Coule[i]==i)
        {
            for (int s = 0; s < 9; s++) //for (x = 0; x < 9; x++)
            {
                for(int u =0; u < 9; u++)
                {
                    if(Grille1[x][y] == 12 || Grille1[x][y] == 13 || Grille1[x][y] == 14)
                    {
                        Grille1[x][y] += 10;
                    }
                }
            }
        }
    }
}

void Grille() {
    int x;
    int y;

    printf("  X  1   2   3   4   5   6   7   8   9");
    for (x = 0; x < 9; x++) {
        printf("\n");

        if (x == 0) {
            printf("   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐\n  ");
        }
        if (x != 0) {
            printf("   ├───┼───┼───┼───┼───┼───┼───┼───┼───┤\n  ");
        }


        printf("%d", x + 1);
        for (y = 0; y < 9; y++) {

           coule(x,y);

            if (Grille1[x][y] == 0 || Grille1[x][y] == 1 || Grille1[x][y] == 2 || Grille1[x][y] == 3 ||
                Grille1[x][y] == 4) {
                printf("│   ");

            } else if (Grille1[x][y] == -1) {
                printf("│ ~ ");
            } else if (Grille1[x][y] == 11 || Grille1[x][y] == 22 ||Grille1[x][y] == 23||Grille1[x][y] == 24) {
                printf("│ X ");
            } else if (Grille1[x][y] == 12 || Grille1[x][y] == 13 || Grille1[x][y] == 14) {
                printf("│ x ");
            }
            if (y == 8) {
                printf("│");
            }
        }

        if (x == 8) {
            printf("\n   └───┴───┴───┴───┴───┴───┴───┴───┴───┘");
        }
    }
}

void Game() {
    int cvert;
    int chorz;
    int gameover = 0;
    do {
        Grille();
        printf("\nIntroduisez la coordonée horizontal: ");
        scanf("%d", &cvert);
        printf("\nIntroduisez la coordonée vertical: ");
        scanf("%d", &chorz);

        int o = Grille1[chorz - 1][cvert - 1];

        if (o == 0) {
            Grille1[chorz - 1][cvert - 1] = -1;

        } else if (o == 1 || o == 2 || o == 3 || o == 4) {
            Coule[Grille1[chorz - 1][cvert - 1]] += 1;
            Grille1[chorz - 1][cvert - 1] += 10;

        } else if (o > 10 || o == -1) {
            printf("\nVous avez deja tire la !");
        }

        gameover = 1;
        system("cls");
        for (int i = 1; i <= 4; i++) {
            if (Coule[i] != i) {

                gameover = 0;
            }
        }
            if (gameover == 1) {
                printf(" /$$    /$$ /$$             /$$               /$$                    \n"
                       "| $$   | $$|__/            | $$              |__/                    \n"
                       "| $$   | $$ /$$  /$$$$$$$ /$$$$$$    /$$$$$$  /$$  /$$$$$$   /$$$$$$ \n"
                       "|  $$ / $$/| $$ /$$_____/|_  $$_/   /$$__  $$| $$ /$$__  $$ /$$__  $$\n"
                       " \\  $$ $$/ | $$| $$        | $$    | $$  \\ $$| $$| $$  \\__/| $$$$$$$$\n"
                       "  \\  $$$/  | $$| $$        | $$ /$$| $$  | $$| $$| $$      | $$_____/\n"
                       "   \\  $/   | $$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$| $$      |  $$$$$$$\n"
                       "    \\_/    |__/ \\_______/   \\___/   \\______/ |__/|__/       \\_______/ \n");
                system("pause");
            }

    } while (gameover == 0);
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
        if (choix < 0 || choix > 3) {
            printf("Ceci n'est pas un choix !");
        }
        switch (choix) {
            case 0:
                printf("\nA la prochaine !");
                return 0;

            case 1:
                printf("\n_____Jouer_____\n");
                printf("\nBievenue sur le mode jeu");
                do {
                    printf("\nIntroduire 0 pour revenir en arriere ou 1 pour lancer une partie: \n");
                    scanf("%d", &choix);
                    if (choix == 0) {
                        choix = +100;
                        break;
                    } else if (choix == 1) {
                        Game();
                    } else {
                        printf("Ce n'est pas un choix !\n");
                    }
                } while (choix != 0 && choix != 1);
                break;

            case 2:
                printf("\n\n_____Instructions_____\n");
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
                } while (choix != 0);
                break;

            case 3:
                printf("\n\n_____Paramètres_____\n");
                do {
                    printf("\n1. Modifier la grille");
                    printf("\n0. Revenir en arriere");
                    printf("\n\nIntroduire votre choix: ");
                    scanf("%d", &choix);
                    if (choix == 0) {
                        choix = +100;
                        break;
                    } else if (choix == 1) {
                        Grille();
                    } else {
                        printf("Ce n'est pas un choix !\n");
                    }
                } while (choix != 0);
                break;
        }

    } while (choix < 0 || choix > 3);

    return 0;
}

