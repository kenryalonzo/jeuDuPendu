#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Pendu.h"

int main(int argc, char *argv[]) {

    char lettre = 0;
    char motSecret[6] = "Rouge";
    int coupsRestants = 10;
    int nombreLettres = tailleMot(motSecret);
    int *lettreTrouves = NULL;
    lettreTrouves = malloc(nombreLettres * sizeof(int));
    
    if (lettreTrouves == NULL) {
        printf("Erreur lors de l'allocation de memoire.\n");
        return 1; // Quitter le programme avec un code d'erreur
    }

    initTableau(lettreTrouves, nombreLettres);

    printf("Bienvenue dans le jeu du Pendu !\n\n");

    while (coupsRestants > 0 && !gagne(lettreTrouves, nombreLettres)) {

        printf("\n\nIl vous reste %d coups a jouer.\n", coupsRestants);
        printf("Quel est le mot secret ? ");

        /* On affiche le mot secret en masquant les lettres non trouvées
           Exemple : *A**ON */
        for (int i = 0; i < nombreLettres; i++) {
            if (lettreTrouves[i])
                printf("%c", motSecret[i]);
            else
                printf("*");
        }

        printf("\nProposez une lettre : ");
        lettre = lireCaractere();

        // Si ce n'était PAS la bonne lettre
        if (!rechercheLettre(lettre, motSecret, lettreTrouves)) {
            coupsRestants--; // On enlève un coup au joueur
        }
    }

    if (gagne(lettreTrouves, nombreLettres))
        printf("\n\nGagne ! Le mot secret etait bien : %s\n", motSecret);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s\n", motSecret);

    free(lettreTrouves); // Libérer la mémoire allouée

    return 0;
}

int tailleMot(char motSecret[])
{
    int nombreLettre = 0;
    for(int i = 0; motSecret[i] != '\0'; i++)
    {
        nombreLettre++;
    }
    return nombreLettre;
}

char lireCaractere()
{
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu
}

void initTableau(int* lettreTrouvee, int taille)
{
    for(int i = 0; i < taille; i++)
    {
        lettreTrouvee[i] = 0;
    }
}

int gagne(int *lettreTrouvee, int nombreLettres)
{
    int i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < nombreLettres ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}


int rechercheLettre(char lettre, char motSecret[], int* lettreTrouvee)
{
    int i = 0;
    int bonneLettre = 0;

    // On parcourt motSecret pour vérifier si la lettre proposée y est
    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i]) // Si la lettre y est
        {
            bonneLettre = 1; // On mémorise que c'était une bonne lettre
            lettreTrouvee[i] = 1; // On met à 1 la case du tableau de booléens correspondant à la lettre actuelle
        }
    }

    return bonneLettre;
}