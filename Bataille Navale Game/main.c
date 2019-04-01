//Title: Bataille Navale
//Author: LPO
//Date: 01.04.2019
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

#pragma execution_character_set("UTF-8")
#define SIZE 9
#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center


int Grille1[SIZE][SIZE] =
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
            for (int s = 0; s < 9; s++)
            {
                for(int u =0; u < 9; u++)
                {
                    if(Grille1[x][y] == 10+i)
                    {
                        Grille1[x][y] += 10;
                    }
                }
            }
        }
    }
}

void topborder(int width) {
    printf("     ");
    printf("\n");
    printf("   %c", STLC);       // ┌
    for (int row = 1; row < width; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHTB);     // ┬
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, STRC);       // ┐
}
void verticalbars(int width, int row) {
    char TabCase = 'x';
    printf("%2d ", row + 1);    // Numéro de ligne
    for (int colonne = 0; colonne < width; colonne++) {
        TabCase = ' ';
        coule(row,colonne);
        if(Grille1[row][colonne] < 0){    // À l'eau
            TabCase = '~';
        }
        if(Grille1[row][colonne] > 10){   // Touché
            TabCase = 'x';
        }
        if(Grille1[row][colonne] > 20){   // Coulé
            TabCase = '/';
        }
        printf("%c %c ", SVSB, TabCase);     // │ + Modèle
    }
    printf("%c", SVSB);
}

void horizonbars(int width) {
    printf("\n   %c", SVLB);     // ├
    for (int row = 1; row < width; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SC);   // ┼
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, SVRB);   // ┤
}

void bottombars(int width) {
    printf("\n   %c", SBLC);     // └
    for (int row = 1; row < width; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHBB);     // ┴
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, SBRC);     // ┘
}




int grille(void) {
    SetConsoleOutputCP(65001);      // Pour les caractères accentués
    SetConsoleOutputCP(437);       // Pour les caractères semi-graphiques

    printf("  X  1   2   3   4   5   6   7   8   9");
    topborder(SIZE);        // Ligne du haut
    for (int row = 0; row < SIZE; row++) {
        if (row > 0) {
            horizonbars(SIZE);      // Ligne du milieu
        }
        verticalbars(SIZE, row);    // Ligne de barres verticales
    }
    bottombars(SIZE);       // Ligne du bas
}
void Game() {
    int cvert;
    int chorz;
    int gameover = 0;
    do {
        grille();
        printf("\nIntroduisez la coordonée horizontal: ");
        scanf("%d", &cvert);
        printf("\nIntroduisez la coordonée vertical: ");
        scanf("%d", &chorz);

        int o = Grille1[chorz - 1][cvert - 1];

        if (o == 0) {
            Grille1[chorz - 1][cvert - 1] = -1;

        }else if(o == 1){
            Coule[Grille1[chorz - 1][cvert - 1]] += 1;
            Grille1[chorz - 1][cvert - 1] += 20;
        }else if (o == 2 || o == 3 || o == 4) {
            Coule[Grille1[chorz - 1][cvert - 1]] += 1;
            Grille1[chorz - 1][cvert - 1] += 10;

        } else if (o > 10 || o == -1)
        {
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
                        grille();
                    } else {
                        printf("Ce n'est pas un choix !\n");
                    }
                } while (choix != 0);
                break;
        }

    } while (choix < 0 || choix > 3);

    return 0;
}

