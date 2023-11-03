#ifndef pendu_hpp
#define pendu_hpp

#include <stdio.h>

int tailleMot(char motSecret[]);
void initTableau(int* lettreTrouves, int taille);
int gagne(int *lettreTrouves, int nombreLettres);
char lireCaractere();
int rechercheLettre(char lettre, char motSecret[], int *lettreTrouves);

#endif /* pendu_hpp */