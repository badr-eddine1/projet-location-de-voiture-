#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{   
    int id;
    char marque[20] ;
    char typecarburant[20];
    int nbrplace;
    char transmission[20];  
    float prixjour;
    char disponibilite[20];
    int nbrannee;
}location;
   typedef struct {
        char marque[20];
        int count;
    } MarqueStat;
void remp(location *t ){ 
        printf("VEUILLEZ SAISIR LES INFORMATIONS SUIVANTE\n");
        printf(" _______________________\n");   
        printf("| Marque de la voiture :|\n");
        printf("|_______________________|\n");
        fflush(stdin);
        gets(t->marque);
        fflush(stdin);
        printf(" __________________________________\n");
        printf("| type du carburant de la voiture  |\n");
        printf("|__________________________________|\n");
        fflush(stdin);
        gets(t->typecarburant);
        printf(" ________________\n");
        printf("| nbre de place :|\n");
        printf("|________________|\n");
        scanf("%d",&t->nbrplace);
        printf(" __________________\n");
        printf("| la transmission :|\n");
        printf("|__________________|\n");
        fflush(stdin);
        gets(t->transmission);
        printf(" _______________\n");
        printf("| prix / jour :|\n");
        printf("|______________|\n");
        scanf("%f",&t->prixjour);
        printf(" _______________\n");
        printf("| Disponibilite |\n");
        printf("|_______________|\n");
        fflush(stdin);
        gets(t->disponibilite);
        printf(" _________________________________________________ \n");
        printf("| nbr d'annee que cette voiture existe chez vous?:|\n");
        printf("|_________________________________________________|\n");
        scanf("%d",&t->nbrannee);

}
int fichier_existe() {
    FILE *fichier = fopen("voiture.csv", "r");
    if (fichier) {
        fclose(fichier);
        return 1; // Le fichier existe
    }
    return 0; // Le fichier n'existe pas
}

int longueur(){
    FILE *f=fopen("voiture.csv","rt");
    int nbr=0;
    location t;
     while( fscanf(f,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",&t.id,t.marque,t.typecarburant,&t.nbrplace,t.transmission,&t.prixjour,t.disponibilite,&t.nbrannee)==8){
           nbr++;
		}
        return nbr;
}
location *affecter(FILE *f,location *l){ 
    location t;
    int nbr=0;
    int i=0;
    nbr=longueur();
    f=fopen("voiture.csv","r");
    
         l=(location*)malloc(sizeof(location)*nbr);
         while( fscanf(f,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",&t.id,t.marque,t.typecarburant,&t.nbrplace,t.transmission,&t.prixjour,t.disponibilite,&t.nbrannee)==8){
           *(l+i)=t;
           i++;
           
		}
    return l;

}
void afficher(char *nameFile){
    FILE *f;
    location t;
    int i;
    int nbr=longueur();
    f=fopen(nameFile,"rt");
    	if(f){
            printf("    _______                     _______                      _______                        _______                        _______                                                                                                                        \n");
            printf("  _/___|___\\_                /___|___\\_                 _/___|___\\_                   _/___|___\\_                   _/___|___\\_   \n");
            printf(" /     |       \\            /     |       \\            /     |       \\               /     |       \\               /     |       \\ \n");
            printf("||_____|_________|          ||_____|_________|          ||_____|_________|             ||_____|_________|             ||_____|_________|\n");
            printf("  (O)      (O)                 (O)      (O)                  (O)      (O)                   (O)      (O)                   (O)      (O)\n");
           printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
           printf("\xb3     id     |      marque      |      type carburant      |    nbr_palce    |      transmission      |    prix/jour    |      disponibilite  |    nbr annee   \xb3\n");
            printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
          
		for(i=0;i<nbr;i++){ 
            
                 fscanf(f,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",&t.id,t.marque,t.typecarburant,&t.nbrplace,t.transmission,&t.prixjour,t.disponibilite,&t.nbrannee);         
           t.id=i+1;
         
			printf("|      %d      |",t.id);
            printf("      %s      |",t.marque);
            printf("          %s          |",t.typecarburant);
            printf("      %d        |",t.nbrplace);
            printf("        %s         |",t.transmission);
            printf("       %.2f        |",t.prixjour);
            printf("       %s         |",t.disponibilite);
            printf("       %d        |\n",t.nbrannee);
             printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
          

		
            }
          
		fclose(f);
	}else puts("\n Erreur d'ouverture du fichier!");
}
void EcrireFichier( int nbr){
	FILE *f;
	int i;
	location t;
    FILE *f2;
    f2=fopen("voiture2.csv","wt");
	f=fopen("voiture.csv","wt");

	if(f){
            fprintf(f2,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n","id","marque ","type_carburant","nbr_place","transmission","prix/jour","disponibilite","nbr annee");
		for(i=0;i<nbr;i++){
            t.id=i+1;
		remp(&t);
			 fprintf(f,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",t.id,t.marque,t.typecarburant,t.nbrplace,t.transmission,t.prixjour,t.disponibilite,t.nbrannee);
             fprintf(f2,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",t.id,t.marque,t.typecarburant,t.nbrplace,t.transmission,t.prixjour,t.disponibilite,t.nbrannee);


		}
		fclose(f);
	}

    else puts("\n Erreur d'ouverture du fichier!");	
     
}
void ajouter(location *voiture){
    FILE *f=fopen("voiture.csv","at");
     FILE *f2=fopen("voiture2.csv","at");
    int nbr=longueur();
    voiture->id=nbr+1;
    if(f){ 
     fprintf(f,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",voiture->id,voiture->marque,voiture->typecarburant,voiture->nbrplace,voiture->transmission,voiture->prixjour,voiture->disponibilite,voiture->nbrannee);
    fprintf(f2,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",voiture->id,voiture->marque,voiture->typecarburant,voiture->nbrplace,voiture->transmission,voiture->prixjour,voiture->disponibilite,voiture->nbrannee);
    fclose(f);
    fclose(f2);}
    afficher("voiture.csv");
}
void supprimer(char *marque){
    FILE *f;
    FILE *f2;
    location *t=affecter(f,t);
    int nbr=longueur();
    int i,j;
    int k=0;
         
 
    for(i=0;i<nbr;i++){
        if(strcmp((t+i)->marque,marque)==0){
            k++;
            for(j=i;j<nbr;j++){
                *(t+j)=*(t+j+1);
            }
        }
    }
 
     t=(location*)realloc(t,(nbr-k)*sizeof(location));
    nbr=nbr-k;
    f=fopen("voiture.csv","wt");
    f2=fopen("voiture2.csv","wt");
     
    if(f){ 
         fprintf(f2,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n","id","marque ","type_carburant","nbr_place","transmission","prix/jour","disponibilite","nbr annee");
    for(i=0;i<nbr;i++){
        (t+i)->id=i+1;
         fprintf(f,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",(t+i)->id,(t+i)->marque,(t+i)->typecarburant,(t+i)->nbrplace,(t+i)->transmission,(t+i)->prixjour,(t+i)->disponibilite,(t+i)->nbrannee);
         fprintf(f2,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",(t+i)->id,(t+i)->marque,(t+i)->typecarburant,(t+i)->nbrplace,(t+i)->transmission,(t+i)->prixjour,(t+i)->disponibilite,(t+i)->nbrannee);
      }
      fclose(f);
      fclose(f2);}
        afficher("voiture.csv");
        

}
void afficher_par_choix(){
    int choix;
     FILE *f;
    location *t=affecter(f,t);
    int nbr=longueur();
    int i;
    char marque[20];
    printf("                      1:Affichage des voiture ayant la meme marque :\n"); 
    printf("                      2:Affichage des voitures disponible\n ");
    scanf("%d",&choix);
    if(choix==1){
        printf("donner la marque qur vous souhaitez afficher :");
        fflush(stdin);
        gets(marque);
        for(i=0;i<nbr;i++){
        if(strcmp((t+i)->marque,marque)==0){
                printf("%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",(t+i)->id,(t+i)->marque,(t+i)->typecarburant,(t+i)->nbrplace,(t+i)->transmission,(t+i)->prixjour,(t+i)->disponibilite,(t+i)->nbrannee);
        }
    }
    }
    
   if(choix==2){
    for(i=0;i<nbr;i++){
        if(strcmp((t+i)->disponibilite,"disponible")==0){
            printf("%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",(t+i)->id,(t+i)->marque,(t+i)->typecarburant,(t+i)->nbrplace,(t+i)->transmission,(t+i)->prixjour,(t+i)->disponibilite,(t+i)->nbrannee);
        }
    }
   }

}
void tri() {
    FILE *f;
    FILE *f2;
    location *t;
    int i, j;
    location aide;
    int nbr = longueur();
    t = affecter(f, t); 
    int choix;
    printf("Choisissez le type de tri :\n");
    printf("1: Tri par prix\n");
    printf("2: Tri par marque\n");
    scanf("%d", &choix);
    if (choix == 1) {
        for (i = 0; i < nbr - 1; i++) {
            for (j = i + 1; j < nbr; j++) {
                if (t[i].prixjour < t[j].prixjour) {
                    aide = t[i];
                    t[i] = t[j];
                    t[j] = aide;}} }
    } else if (choix == 2) {
        for (i = 0; i < nbr - 1; i++) {
            for (j = i + 1; j < nbr; j++) {
                if (strcmp(t[i].marque, t[j].marque) > 0) {
                    aide = t[i];
                    t[i] = t[j];
                    t[j] = aide; }}} } 
    else {
        printf("Choix invalide.\n");
        return; 
    }
    f = fopen("voiture.csv", "wt");
    f2 = fopen("voiture2.csv", "wt");
    if (f && f2) {
        fprintf(f2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "id", "marque",  "type_carburant", "nbr_place", "transmission", "prix/jour", "disponibilite","nbr annee");
        for (i = 0; i < nbr; i++) {
            fprintf(f, "%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n", i + 1, t[i].marque, t[i].typecarburant, t[i].nbrplace, t[i].transmission, t[i].prixjour, t[i].disponibilite,t[i].nbrannee);
            fprintf(f2, "%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n", i + 1, t[i].marque, t[i].typecarburant, t[i].nbrplace, t[i].transmission, t[i].prixjour, t[i].disponibilite,t[i].nbrannee);
        }
        fclose(f);
        fclose(f2);
    }
    afficher("voiture.csv"); 
}
void afficher_statistiques() {
    FILE *f=fopen("voiture.csv","rt");
    location *voitures=affecter(f,voitures);
    int nbr = longueur(),i;
    int marqueTrouvee;
    int j;
    marqueTrouvee = 0;
    MarqueStat stats[20]; 
    int nbMarques = 0;
    for (int i = 0; i < 20; i++) {
        strcpy(stats[i].marque, "");
        stats[i].count = 0;
    }
    for ( i = 0; i < nbr; i++) {
         marqueTrouvee = 0;
        for (int j = 0; j < nbMarques; j++) {
            if (strcmp(voitures[i].marque, stats[j].marque) == 0) {
                stats[j].count++;
                marqueTrouvee = 1;
                break;
            }
        }
        if (!marqueTrouvee) {
            strcpy(stats[nbMarques].marque, voitures[i].marque);
            stats[nbMarques].count = 1;
            nbMarques++;
        }
    }
    printf("Statistiques des marques de voitures disponibles :\n");
    for ( i = 0; i < nbMarques; i++) {
        printf("%s : ", stats[i].marque);
        for ( j = 0; j < stats[i].count; j++) {
            printf("*");
        }
       printf("\n");
    }
}
void afficher_voiture_avendre(){
     FILE *f=fopen("voiture.csv","rt");
    location *voitures=affecter(f,voitures);
    int nbr = longueur();
    int choix;
    int i,j;
    FILE *f3,*f2;
    int k=0;
    f3=fopen("voitureAvendre.csv","wt");
     fprintf(f3,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n","id","marque ","type_carburant","nbr_place","transmission","prix/jour","disponibilite","nbr annee");
    for( i=0;i<nbr;i++){
        if((voitures+i)->nbrannee>=4){
            k++;
            printf("la voiture %s identifier par %d a depaser 4ans \n",(voitures+i)->marque,(voitures+i)->id);
            printf("VOUS VOULLEZ VENDRE CETTE VOITURE ?\n");
            printf("1:OUI:\n2:NON:\n");
            scanf("%d",&choix);
            if(choix==1){
                fprintf(f3,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n", i + 1, (voitures+i)->marque, (voitures+i)->typecarburant,(voitures+i)->nbrplace,(voitures+i)->transmission, (voitures+i)->prixjour,(voitures+i)->disponibilite,(voitures+i)->nbrannee);
                printf("CETTE VOITURE VA ETRES POSER DANS UN FICHIER NOMMER VOITURE A VENDRE ET IL VAS ETRE SUPPRIMER DE VOTRE BASE DE DONNEE PRINCIPALE\n");
                for(j=i;j<nbr;j++){
                    *(voitures+j)=*(voitures+j+1);
                }
            }
        }
    }
    voitures=(location*)realloc(voitures,(nbr-k)*sizeof(location));
    nbr=nbr-k;

    f=fopen("voiture.csv","wt");
    f2=fopen("voiture2.csv","wt");
     
    if(f){ 
         fprintf(f2,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n","id","marque ","type_carburant","nbr_place","transmission","prix/jour","disponibilite","nbr annee");
    for(i=0;i<nbr;i++){
        (voitures+i)->id=i+1;
         fprintf(f,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",(voitures+i)->id,(voitures+i)->marque,(voitures+i)->typecarburant,(voitures+i)->nbrplace,(voitures+i)->transmission,(voitures+i)->prixjour,(voitures+i)->disponibilite,(voitures+i)->nbrannee);
          fprintf(f2,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",(voitures+i)->id,(voitures+i)->marque,(voitures+i)->typecarburant,(voitures+i)->nbrplace,(voitures+i)->transmission,(voitures+i)->prixjour,(voitures+i)->disponibilite,(voitures+i)->nbrannee);
      }
      fclose(f);
      fclose(f2);}
        afficher("voiture.csv");
      
}
// void header(char nomFile[]){
//     FILE *f4=fopen(nomFile,"wt");
//     if(f4){
//         fprintf(f4,"%s\t%s\t%s\t%s\t%s\n","ID","NOM","PRENOM","ID VOITURE","MARQUE");
//     }
    
// }
void louer_voiture(){
    FILE *f=fopen("voiture.csv","rt");
    
    location *voitures=affecter(f,voitures),t;
    int nbr = longueur();
    char nom[10];
    char pre[10];
    int id;
    int i;
     FILE *f2;
      FILE *f4=fopen("voiturelouer.csv","wt");

    if(f4){
        fprintf(f4,"%s\t%s\t%s\t%s\t%s\n","ID","NOM","PRENOM","ID VOITURE","MARQUE");
    }
     system("pause");
     system("cls");
    printf("____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("                                                                                                                                               \n");
    printf("                                 *************************************************             |-_-| MODE UTILISATEUR |-_-|                          *****************************************\n");
    printf("\n");
    printf("____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("veuillez saisir votre nom : ");
    fflush(stdin);
    gets(nom);
   printf("veuillez saisir votre prenom : ");
    fflush(stdin);
    gets(pre);
    system("pause");
    system("cls");
    printf("____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("                                                                                                                                               \n");
    printf("                                 *************************************************             |-_-| WELCOM %s |-_-|                          *****************************************\n",nom);
    printf("\n");
    printf("____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("VOICI LA LISTE DES VOITURE DISPONIBLE DANS NOTRE LOCATION : \n");
    afficher("voiture.csv");
    saisir :
    printf("veuillez saisir l'id de la voiture que vous voullez louer : ");
    scanf("%d",&id);
    if(strcmp((voitures+id-1)->disponibilite,"indisponible")==0){
        printf("DESOLE %s CETTE VOITURE EST INDISPONIBLE POUR L'INSTANT VEUILLEZ RESAISIR : \n",nom);goto saisir;
    }
    f4=fopen("voiturelouer.csv","at");
    if(f4){
       for(i=0;i<nbr;i++){
        if(id==(voitures+i)->id){
            fprintf(f4,"%d\t%s\t%s\t%d\t%s\n",i+1,nom,pre,(voitures+i)->id,(voitures+i)->marque);
           
        }
    } 
    }
    
     f=fopen("voiture.csv","at");
    f2=fopen("voiture2.csv","at");
    	for(i=0;i<nbr;i++){ 
                 fscanf(f,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",&t.id,t.marque,t.typecarburant,&t.nbrplace,t.transmission,&t.prixjour,t.disponibilite,&t.nbrannee); 
                 if(t.id==id){
              
                    strcpy(t.disponibilite, "indisponible");
                     fprintf(f,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",(voitures+i)->id,(voitures+i)->marque,(voitures+i)->typecarburant,(voitures+i)->nbrplace,(voitures+i)->transmission,(voitures+i)->prixjour,(voitures+i)->disponibilite,(voitures+i)->nbrannee);
                     fprintf(f2,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",(voitures+i)->id,(voitures+i)->marque,(voitures+i)->typecarburant,(voitures+i)->nbrplace,(voitures+i)->transmission,(voitures+i)->prixjour,(voitures+i)->disponibilite,(voitures+i)->nbrannee);
                 }
    
    }
    afficher("voiture.csv");
    }
void affichage(){
    printf("____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("                                                                                                                                               \n");
    printf("                                 *************************************************             |-_-| WELCOM  GERAZ LOCATION |-_-|                          *****************************************\n");
    printf("\n");
    printf("____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
}
int main(){
    location voiture; 
    int nbr;  
    char marque[20];
    int menu;
    int m;
    system("color 02");
    if(fichier_existe()){
        affichage();
        goto menu;
    }
    system("pause");
     system("cls");
     affichage();
     printf("                         veuillez saisir le nombre de voiture :");
    scanf("%d",&nbr);
    EcrireFichier(nbr);
  
    afficher("voiture.csv");
    
     system("pause");
         system("cls");
        
    menu:
    printf("\n\n\n\n\n\n");
    printf("                                 ___________________________________________________________________________________________________________________\n");
    printf("                                |                          1:Afficher la liste des voitures disponibles dans votre  location :                      |\n");
    printf("                                |___________________________________________________________________________________________________________________|\n");
    printf("                                |                          2:Ajouter une voiture :                                                                  |\n");
    printf("                                |___________________________________________________________________________________________________________________|\n");
    printf("                                |                          3:Supprimer une voiture :                                                                |\n");
    printf("                                |___________________________________________________________________________________________________________________|\n");
    printf("                                |                          4:Affichage des voiture par (Marque, Disponibilite) :                                    | \n");
    printf("                                |___________________________________________________________________________________________________________________|\n");
    printf("                                |                          5:trier les voiture (Marque, Prix de location par jour):                                 |\n");
    printf("                                |___________________________________________________________________________________________________________________|\n");
    printf("                                |                          6:afficher les statistique des voiture qui existe                                        |\n");
    printf("                                |___________________________________________________________________________________________________________________|\n");
    printf("                                |                          7:afficher la liste des voiture a vendre                                                 |\n");
    printf("                                |___________________________________________________________________________________________________________________|\n");
    printf("                                |                          8:louer une voiture (MODE UTILISATEUR)                                                   |\n");
    printf("                                |___________________________________________________________________________________________________________________|\n");
    scanf("%d",&menu);

    system("pause");
     system("cls");
    if(menu==1){
        afficher("voiture.csv");
        printf("                     1:REAFFICHER LE MENU  :\n");
        printf("                     2:FERMER LE PROGRAMME :\n");                         
        scanf("%d",&m);
        if(m==1){
        system("pause");
         system("cls");goto menu;}
    }
    if(menu==2){
        remp(&voiture);
        ajouter(&voiture);
         printf("                    1:REAFFICHER LE MENU  :\n");
        printf("                     2:FERMER LE PROGRAMME :\n");  
        scanf("%d",&m);
        if(m==1){
        system("pause");
         system("cls");goto menu;}
    }
    if(menu==3){
        printf("donner la marque que vous voullez supprimer :");
        fflush(stdin);
        gets(marque);
        supprimer(marque);
        printf("                     1:REAFFICHER LE MENU  :\n");
        printf("                     2:FERMER LE PROGRAMME :\n");  
        scanf("%d",&m);
        if(m==1){
        system("pause");
         system("cls");goto menu;}
    }
    if(menu==4){
        afficher_par_choix();
        printf("                     1:REAFFICHER LE MENU  :\n");
        printf("                     2:FERMER LE PROGRAMME :\n");  
        scanf("%d",&m);
        if(m==1){
        system("pause");
         system("cls");goto menu;}

    }
    if(menu==5){
        tri();
        printf("                      1:REAFFICHER LE MENU  :\n");
        printf("                      2:FERMER LE PROGRAMME :\n");  
        scanf("%d",&m);
        if(m==1){
        system("pause");
         system("cls");goto menu;}
    }
    if(menu==6){
        afficher_statistiques();
         printf("                      1:REAFFICHER LE MENU  :\n");
        printf("                      2:FERMER LE PROGRAMME :\n");  
        scanf("%d",&m);
        if(m==1){
        system("pause");
         system("cls");goto menu;}
    }
    if(menu==7){
        afficher_voiture_avendre();
         printf("                      1:REAFFICHER LE MENU  :\n");
        printf("                      2:FERMER LE PROGRAMME :\n");  
        scanf("%d",&m);
        if(m==1){
        system("pause"); 
         system("cls");goto menu;}
    }
    if(menu==8){
        louer_voiture();
           printf("                      1:REAFFICHER LE MENU  :\n");
        printf("                      2:FERMER LE PROGRAMME :\n");  
        scanf("%d",&m);
        if(m==1){
        system("pause");
         system("cls");goto menu;}

    }

   
    
   


}