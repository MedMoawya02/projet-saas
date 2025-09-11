<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_AVIONS 100
struct Avion{
    int idAvion;
    char modele[20];
    int capacite;
    char statut[25];
};
struct Avion a;

struct Aeroport{
    char nom[20];
    int nbAvions;
    struct Avion avions[MAX_AVIONS];
};
struct Aeroport aer;
int id=1;


void afficherAeroport(){
printf("Nom de l'aeroport:%s\n",aer.nom);
if(aer.nbAvions==0){
    printf("Aucune avion enregistre\n");
    return;
}
for(int i=0;i<aer.nbAvions;i++){
    printf("Avion [%d]===>Modele:%s | Capacitee:%d | Statut:%s\n",i+1,aer.avions[i].modele,aer.avions[i].capacite,aer.avions[i].statut);
}


}
///////////
void ajouterAvion(){
if(aer.nbAvions>=MAX_AVIONS){
    printf("Impossible de depasser 100 avions\n");
    return;
}
int choix;
a.idAvion=id++;
printf("L'avion %d\n",a.idAvion);
printf("Modele:");
scanf("%s",a.modele);
printf("Capacite:");
scanf("%d",&a.capacite);
printf("Statut\n");
printf("1.Disponible\n");
printf("2.En_Vol\n");
printf("3.En_Maintenance\n");
scanf("%d",&choix);
switch(choix){
case 1:strcpy(a.statut,"Disponible");break;
case 2:strcpy(a.statut,"En_Vol");break;
case 3:strcpy(a.statut,"En_Maintenance");break;
default:printf("Choix invalide, statut défini à 'Indéfini'\n");
        strcpy(a.statut, "Indéfini");
        break;
}
aer.avions[aer.nbAvions]=a;
aer.nbAvions++;
printf("Avion ajoute avec succes.\n");
}


///////////////
void modifierAvion(){
int id,nouvelleC;
char nouveauM[20];
int existe=-1;
if(aer.nbAvions==0){
    printf("Aucune avion a modifiee\n");
    return;
}
printf("Quel est l'id de l'avion voulez-vous modifier ? ");
scanf("%d", &id);
for(int i=0;i<aer.nbAvions;i++){
    if(aer.avions[i].idAvion==id){
        existe=i;
        break;
    }
}
if(existe==-1){
    printf("Id indisponible.\n");
    return;
}
else{
    printf("Entrez le nouveau modele:");
    scanf("%s",nouveauM);
    strcpy(aer.avions[existe].modele, nouveauM);
    printf("Entrez la nouvelle capacitee:");
    scanf("%d",&nouvelleC);
    aer.avions[existe].capacite=nouvelleC;
}



}

/////////////////
void supprimerAvion(){
int id,i;
int existe=-1;
printf("Entrez l'id de l'avion a supprimee:");
scanf("%d",&id);
for(i=0;i<aer.nbAvions;i++){
    if(aer.avions[i].idAvion==id){
        existe=i;
        break;
    }
}
if(existe==-1){
    printf("Id indisponible\n");
    return;
}
else{
    for(i=existe;i<aer.nbAvions;i++){
        aer.avions[i]=aer.avions[i+1];
    }
        aer.nbAvions--;
    printf("Avion supprimee\n");
}
}
int main()
{
    aer.nbAvions=0;
    int operation;

    printf("\n---Gestion d'aeroport---\n");
    printf("Entrez le nom de l'aeroport:\n");
    scanf("%s",aer.nom);
    printf("---Menu---\n");
    printf("Bienvenue chez %s \n",aer.nom);

    do{
    //printf("Aeroport cree avec success\n");
    printf("1.Affichage aeroport\n");
    printf("2.Ajouter une avion\n");
    printf("3.Modifier une avion\n");
    printf("4.Supprimer une avion\n");
    printf("5.Rechercher une avion\n");
    printf("6.Trier par capacite\n");
    printf("7.Trier par modele\n");
    printf("8.Statistiques\n");
    printf("0.Quitter\n");
    printf("L'operation a effectuee:\n");
    scanf("%d",&operation);
    switch(operation){
    case 1:
        afficherAeroport();
        break;
    case 2:
        ajouterAvion();
        break;
    case 3:
        modifierAvion();
        break;
    case 4:
        supprimerAvion();
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 0:
        break;
    default:
        printf("Choix invalid\n");


    }
    }while(operation!=0);

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_AVIONS 100
struct Avion{
    int idAvion;
    char modele[20];
    int capacite;
    int statut[3];
};

struct Avion a;
struct Aeroport{
    char nom[20];
    int nbAvions;
    struct Avion avions[MAX_AVIONS];
};
struct Aeroport aer;
int id=1;
void afficherAeroport(){
printf("Entrez le nom de l'aeroport:\n");
scanf("%s",aer.nom);
aer.nbAvions=0;
printf("Aeroport cree avec success");
}
/////
void ajouterAvion(){
if(aer.nbAvions>=MAX_AVIONS){
    printf("Impossible de depasser 100 avions\n");
}

a.idAvion=id++;
printf("L'avion %d\n",a.idAvion);
printf("Modele:");
scanf("%s",a.modele);
printf("Capacite:");
scanf("%d",&a.capacite);
aer.avions[aer.nbAvions]=a;
aer.nbAvions++;
printf("Avion ajoute avec succes.\n");
printf("L'aeroport:%s\n",aer.nom);
printf("\n");
printf("Liste des avions :");
printf("\n");
for(int i=0;i<aer.nbAvions;i++){
    printf("%d %s %d\n",aer.avions[i].idAvion,aer.avions[i].modele,aer.avions[i].capacite );
}


}
////////
void modifierAvion(){
int id,nouvelleC;
char nouveauM[20];
int existe=-1;
if(aer.nbAvions==0){
    printf("Aucune avion a modifiee\n");
}
printf("Quel ID de l'avion voulez-vous modifier ? ");
scanf("%d", &id);
for(int i=0;i<aer.nbAvions;i++){
    if(aer.avions[i].idAvion==id){
        existe=i;
        break;
    }
}
if(existe==-1)
    printf("Id indisponible.\n");
else{
    printf("Entrez le nouveau modele:");
    fgets(nouveauM,sizeof(nouveauM),stdin);
    nouveauM[strcspn(nouveauM, "\n")] = 0;
    strcpy(aer.avions[existe].modele, nouveauM);
    printf("Entrez la nouvelle capacitee:");
    scanf("%d",&nouvelleC);
}



}



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
    printf("0.Quitter\n");
    printf("L'operation a effectuee:\n");
    scanf("%d",&operation);
    switch(operation){
    case 1:
        afficherAeroport();
        break;
    case 2:
        ajouterAvion();
        break;
    case 3:
        modifierAvion();
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 0:
        break;
    default:
        printf("Choix invalid\n");


    }
    }while(operation!=0);

    return 0;
}
>>>>>>> 98bcb590ec05c6ec36ed3d5bc1fd0ed74acea67f
