
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
do{
printf("Statut\n");
printf("1.Disponible\n");
printf("2.En_Vol\n");
printf("3.En_Maintenance\n");
scanf("%d",&choix);
}while(choix<=0||choix>3);
switch(choix){
case 1:strcpy(a.statut,"Disponible");break;
case 2:strcpy(a.statut,"En_Vol");break;
case 3:strcpy(a.statut,"En_Maintenance");break;
default:printf("Choix invalide, statut defini à 'Indefini'\n");
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
    printf("Aucune avion dans l'aeroport pour le moment\n");
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
if(aer.nbAvions==0){
    printf("Aucune avion dans l'aeroport pour le moment \n");
    return;
}
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
///////////////

void rechercheId(){
    int id,existe=-1;
    int i;
    if(aer.nbAvions==0){
    printf("Aucune avion dans l'aeroport pour le moment\n");
    return;
}
    printf("L'id de l'avion qe tu veut?");
    scanf("%d",&id);
    for(i=0;i<aer.nbAvions;i++){
        if(aer.avions[i].idAvion==id){
            existe=i;
            break;
        }
    }
    if(existe==-1)
        printf("Id indisponible\n");
    else{
        printf("L'avion %d\n",id);
        printf("Id : %d | Modele : %s | Capacite : %d | Statut : %s\n",aer.avions[existe].idAvion,aer.avions[existe].modele,aer.avions[existe].capacite,aer.avions[existe].statut);
    }

}
//////////////
void triCapacite(){
    int i,j;
    struct Avion temp;
    for(i=0;i<aer.nbAvions-1;i++){
        for(j=i+1;j<aer.nbAvions;j++){
        if(aer.avions[i].capacite>aer.avions[j].capacite){
            temp=aer.avions[i];
            aer.avions[i]=aer.avions[j];
            aer.avions[j]=temp;
        }

    }
    }
    printf("La liste des avions apres un tri par capacite:\n");
    for(i=0;i<aer.nbAvions;i++){
        printf("L'id:%d |",aer.avions[i].idAvion);
        printf("Modele:=%s |",aer.avions[i].modele);
        printf("Capacite=%d |",aer.avions[i].capacite);
        printf("Statut=%s",aer.avions[i].statut);
    }
}
void triModele(){
    int i,j;
    struct Avion temp;
    for(i=0;i<aer.nbAvions-1;i++){
        for(j=i+1;j<aer.nbAvions;j++){
            if(strcasecmp(aer.avions[i].modele,aer.avions[j].modele)>0){
                temp=aer.avions[i];
                aer.avions[i]=aer.avions[j];
                aer.avions[j]=temp;
    }


        }
    }
    printf("La liste des avions apres un tri par modele:\n");
    for(i=0;i<aer.nbAvions;i++){
        printf("L'id:%d |",aer.avions[i].idAvion);
        printf("Modele:=%s |",aer.avions[i].modele);
        printf("Capacite=%d |",aer.avions[i].capacite);
        printf("Statut=%s",aer.avions[i].statut);
    }
}

/////////////

void statistiques(){
    int disponible=0;
    int vol=0;
    int maintenance=0;
printf("Le nombre total des avions chez %s est : %d\n",aer.nom,aer.nbAvions);
for(int i=0;i<aer.nbAvions;i++){
    if(strcasecmp(aer.avions[i].statut,"Disponible")==0){
        disponible++;
    }
    else if(strcasecmp(aer.avions[i].statut,"En_vol")==0){
        vol++;
    }
    else
        maintenance++;
}
printf("Le nombre des avions disponible :%d\n",disponible);
printf("Le nombre des avions En_Vol :%d\n",vol);
printf("Le nombre des avions maintenance :%d\n",maintenance);
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
    printf("1.Affichage aeroport\n");
    printf("2.Ajouter une avion\n");
    printf("3.Modifier une avion\n");
    printf("4.Supprimer une avion\n");
    printf("5.Rechercher une avion\n");
    printf("6.Trier les avions\n");
    printf("7.Statistiques\n");
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
        rechercheId();
        break;
    case 6:
        int choix;
        if(aer.nbAvions==0){
            printf("Aucune avion dans l'aeroport pour le moment\n");
        }
        else{

        printf("Options:\n");
        do{

        printf("1.Tri par capacite\n");
        printf("2.Tri par modele\n");
        printf("Quelle est votre choix:");
        scanf("%d",&choix);
        }while(choix<=0||choix>2);
        switch(choix){
            case 1:triCapacite();break;
            case 2:triModele();break;
            default:printf("Choix invalid\n");break;
        }
        }

        break;
    case 7:
        statistiques();
        break;
    case 0:
        break;
    default:
        printf("Choix invalid\n");


    }
    }while(operation!=0);

    return 0;
}
