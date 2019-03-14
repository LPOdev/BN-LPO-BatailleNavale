//Title: Bataille Navale
//Author: LPO
//Date: 07.03.2019
#include <stdio.h>

int main() {
    int choix;

    //Menu Principal
    do {
        printf("\n\n_____Bataille Navale_____\n\n");
        printf("1. Jouer");
        printf("\n2. Instructions");
        printf("\n3. Parametres");
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
                break;

            case 1: printf("\n\nJouer\n");
                printf("\nBievenue sur le mode jeu");
                printf("\nIntroduire 0 pour revenir en arriere: ");
                if (choix == 0)
                {
                    choix=+100;
                    break;
                break;


            case 2: printf("\n\nInstructions\n");
                printf("\nLes regles s'affichent...");
                printf("\nIntroduire 0 pour revenir en arriere: ");
                scanf("%d",&choix);
                if (choix == 0)
                {
                    choix=+100;
                    break;
                }
            case 3: printf("\n\nParametres\n");
                break;
        }

    }while (choix < 0 || choix > 3);




    return 0;
}