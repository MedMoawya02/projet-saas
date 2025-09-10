#include <stdio.h>
#include <stdlib.h>

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

    }while(operation!=0);

    return 0;
}
