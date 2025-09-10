#include <stdio.h>
#include <stdlib.h>
struct Avion{
    int idAvion;
    char modele[20];
    int capacite;
    char statut[20];
};
struct Aeroport{
    char nom[20];
    int nbAvions;
    struct Avion avions[100];
};
int main()
{
    int operation;
    do{
    printf("\n---Gestion d'aeroport---\n");
    printf("---Menu---\n");
    printf("1.Affichage aeroport\n");
    printf("2.Ajouter une avion\n");
    printf("3.Modifier une avion\n");
    printf("4.Supprimer une avion\n");
    printf("5.Rechercher une avion\n");
    printf("6.Trier par capacite\n");
    printf("7.Trier par modele\n");
    printf("8.Statistiques\n");
    printf("L'operation a effectuee:\n");
    scanf("%d",&operation);
    switch(operation){
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:

    }
    }while(operation!=0);

    return 0;
}
