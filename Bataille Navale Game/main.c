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
#define nbgrilles 4

void Bateau()
{
    //Boat
    printf("                         \t  )___(\n"
           "                           _______/__/_\n"
           "                  ___     /===========|   ___\n"
           " ____       __   [\\\\\\]___/____________|__[///]   __\n"
           " \\   \\_____[\\\\]__/___________________________\\__[//]___\n"
           "  \\40A                                                 |\n"
           "   \\                                                  /\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

}
int Grille[SIZE][SIZE] = {};
void chosegri() {

    int choosegrille = 1000;
    char randomname[50];
    do
    {
        printf("\n");
        for (int i = 0; i < nbgrilles; i++) {
            printf("\tGrille %d",i+1);
        }
        printf("\t0.Random");

        printf("\n\nChossissez une grille: ");
        scanf("%d", &choosegrille);

        if (choosegrille<1 && choosegrille>nbgrilles)
        {
            printf("\nCette grille n'est pas disponnible ou n'existe pas !");
            choosegrille+=1000;
        }
    }while(choosegrille<0 && choosegrille>nbgrilles);

    if(choosegrille==0)
    {
        choosegrille=  rand() % 4;
    }
    FILE *fichier = NULL;
    sprintf(randomname,"Grille%d.txt",choosegrille);
    fichier =fopen(randomname,"r");

    for (int x = 0; x < SIZE;x++)
    {
        for (int y = 0; y <SIZE ;y++)
        {
            char c = fgetc(fichier);
            Grille[x][y]= c - '0';
        }
    }
    fclose(fichier);
}
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
                    if(Grille[x][y] == 10+i)
                    {
                        Grille[x][y] += 10;
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
        if(Grille[row][colonne] < 0){    // À l'eau
            TabCase = '~';
        }
        if(Grille[row][colonne] > 10){   // Touché
            TabCase = 'x';
        }
        if(Grille[row][colonne] > 20){   // Coulé
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
    SetConsoleOutputCP(65001);
}
void Game() {
    int cvert;
    int chorz;
    int gameover = 0;
    do {
        Bateau();
        printf("\n\n");
        grille();
        printf("\nIntroduisez la coordonée horizontal: ");
        scanf("%d", &cvert);
        printf("\nIntroduisez la coordonée vertical: ");
        scanf("%d", &chorz);

        int o = Grille[chorz - 1][cvert - 1];

        if (o == 0) {
            Grille[chorz - 1][cvert - 1] = -1;

        }else if(o == 1){
            Coule[Grille[chorz - 1][cvert - 1]] += 1;
            Grille[chorz - 1][cvert - 1] += 20;
        }else if (o == 2 || o == 3 || o == 4) {
            Coule[Grille[chorz - 1][cvert - 1]] += 1;
            Grille[chorz - 1][cvert - 1] += 10;

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
void Jouer(int choix)
{
    system("cls");
    Bateau();
    printf("\n\n_____Jouer_____\n");
    printf("\nBievenue sur le mode jeu\n");
    printf("\nGrilles:");
    chosegri();
    Game();

}
void Instructions()
{
    system("cls");
    printf("\n\n_____Instructions_____\n");
    printf("\nPour démarrer une partie:");
    printf("\nSur le Menu Principal: Entrez le chiffre 1 pour aller dans le menu jouer et ensuite il suffit d'entrer le chiffre de la grille que vous souhaitez");
    printf("\n\nPour jouer une partie:");
    printf("\nIl faut d'abord entrer la coordonnée horizontale de la case ou vous voulez tirer et ensuite la coordonée vertical. Il faut couler les 4 bateaux pour gagner. À la fin de la partie il suffit d'appuyer sur une touche pour revenir au Menu Principal.");
    printf("\n\nLes 4 bateaux diffèrents: \t1 bateau de 1 case \t1 bateau de 2 cases \t 1 bateau de 3 cases \t 1 bateau de 4 cases");
    printf("\n\nLes diffèrents caractères: \t~ = à l'eau \tx = touché \t/ = coulé\n\n");
    system("pause");
}
void Parametres()
{
    system("cls");
    Bateau();
    printf("\n\n_____Paramètres_____\n");
    system("pause");
}

int main() {
    SetConsoleOutputCP(65001);

    int choix;
    Bateau();

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
            printf("\nCeci n'est pas un choix !");
        }
        switch (choix) {
            case 0:
                printf("\nA la prochaine !");
                return 0;

            case 1:
                Jouer(choix);
                break;

            case 2:
                Instructions();
                break;

            case 3:
                Parametres();
                break;
        }

    } while (choix > 0 || choix < 3);

    return 0;
}

