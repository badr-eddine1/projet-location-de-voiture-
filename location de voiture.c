#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int id;
    char marque[20] ;
    char nomutili[20];
    char typecarburant[20];
    int nbrplace;
    char transmission[20];
    float prixjour;
    char disponibilite[20];
}location;
void remp(location *loca ){ 
        printf("VEUILLEZ SAISIR LES INFORMATIONS SUIVANTE");   
        printf("Marque de la voiture :");
        fflush(stdin);
        gets(loca->marque);
        fflush(stdin);
        printf(" type du carburant de la voiture :  ");
        fflush(stdin);
        gets(loca->typecarburant);
        printf(" nbre de place :");
        scanf("%d",&loca->nbrplace);
        printf(" la transmission :");
        fflush(stdin);
        gets(loca->transmission);
        printf("prix / jour :");
        scanf("%f",&loca->prixjour);
        printf("Disponibilite : ");
        fflush(stdin);
        gets(loca->disponibilite);
    
}
void remplissage ( location *loca , char *nomutili, int nbr ){
    int i;
    FILE *f;
    f=fopen(nomutili,"wt");
    if(f){
        for(i=0;i<nbr;i++){
            remp(loca);
            loca->id=i+1;
            fprintf(f,"%d\t%s\t%s\t%d\t%s\t%f\t%s\n",loca->id,loca->marque,loca->typecarburant,loca->nbrplace,loca->transmission,loca->prixjour,loca->disponibilite);
        }
    }

}
void affi(location *loca ){
    
}
void ajouter (location *loca, char *nomutili , int nbr ,location *voiture ,int pos){
    FILE *f;
    int i;
    f=fopen(nomutili,"wt");
    if (f){
        loca=(location*)realloc(loca,(nbr+1)*sizeof(location));
      for(i=nbr-1;i>pos-1;i--){
        loca[i]=loca[i-1];
      }
}
}
void main(){
    location *loca;
    char nomu[20];
    int nbrvoiture;
    printf("LE NOM DE VOTRE LOCATION (nom.csv):");
    fflush(stdin);
    gets(nomu);
    printf("VEUILLEZ SAISIR LE NOMBRE DE VOITURE DANS VOTRE LOCATION  :");
    scanf("%d",&nbrvoiture);
    loca=(location*)malloc(nbrvoiture*sizeof(location));
    
    remplissage(loca,nomu,nbrvoiture);
}
