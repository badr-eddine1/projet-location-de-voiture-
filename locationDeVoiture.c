#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
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
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Fonction pour dessiner une grande voiture

void drawBigCar(int x, int y) {
    
    gotoxy(x, y);   printf("      ___________________                   ___________________                     ___________________         \n");
    gotoxy(x,y+1);  printf("      //   w   |   E  \\\\                    //   t   |  O   \\\\                       //  L    |   O  \\\\       \n");
    gotoxy(x, y+2); printf("  ___//________|_______\\\\___            ___//________|_______\\\\___               ___//________|_______\\\\___   \n");
    gotoxy(x, y+3); printf(" |_   l   _  c _  O _`  M   _|         |_   G    _ E  _ R  _`  Z   _|           |_    C  _ A  _  T _`  I   _|  \n");
    gotoxy(x, y+4); printf(" '      =(_)--(_)--(_)'                '      =(_)--(_)--(_)'                  '      =(_)--(_)--(_)'         \n\n");
printf(" °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");
}
void affichervoiture(){
     int x = 0, y = 10; // Position initiale de la grande voiture
     int i=0;
      while(i!=70) {
        system("cls"); // Nettoie l'écran
        drawBigCar(x, y); // Dessine la grande voiture à la position (x, y)

        Sleep(50); // Pause de 100 millisecondes
        x++; // Déplace la grande voiture vers la droite

        if(x > 70) { // Si la grande voiture atteint le bord droit de l'écran
            x = 0; // Réinitialise la position de la grande voiture à gauche
        }
        i++;
    }
}
void afficher(char *nameFile){
    FILE *f;
    location t;
    int i;
    int nbr=longueur();
    f=fopen(nameFile,"rt");
    	if(f){
            printf("    _______                  _______                    _______                        _______                        _______                     _______                   _______       \n");
            printf("  _/___|___\\_                /___|___\\_                 _/___|___\\_                   _/___|___\\_                   _/___|___\\_                  _/___|___\\_              _/___|___\\_  \n");
            printf(" /     |       \\            /     |       \\            /     |       \\               /     |       \\               /     |       \\             /     |       \\           /     |       \\ \n");
            printf("||_____|_________|         ||_____|_________|         ||_____|_________|            ||_____|_________|            ||_____|_________|          ||_____|_________|         ||_____|_________|                                         \n");
            printf("  (O)      (O)                 (O)      (O)               (O)      (O)                  (O)      (O)                  (O)      (O)               (O)      (O)               (O)      (O)           \n");
        printf(" _______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
        printf("|          id            |          marque                |         type carburant          |           nbr_palce           |          transmission         |        prix/jour          |          disponibilite        |         nbr annee       |\n");
        printf("|_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________|\n");
          
		for(i=0;i<nbr;i++){ 
            
                 fscanf(f,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n",&t.id,t.marque,t.typecarburant,&t.nbrplace,t.transmission,&t.prixjour,t.disponibilite,&t.nbrannee);         
           t.id=i+1;
         
			printf("|         %d              |",t.id);
            printf("           %s                |",t.marque);
            printf("           %s              |",t.typecarburant);
            printf("           %d              |",t.nbrplace);
            printf("           %s              |",t.transmission);
            printf("           %.2f            |",t.prixjour);
            printf("           %s              |",t.disponibilite);
            printf("           %d              |\n",t.nbrannee);
            printf("|____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
          

		
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
    printf(" __________________________________________________________________________________\n");
    printf("|                      1:Affichage des voiture ayant la meme marque :              |\n"); 
    printf("|__________________________________________________________________________________|\n");
    printf(" __________________________________________________________________________________\n");
    printf("|                      2:Affichage des voitures disponible                         |\n ");
    printf("|__________________________________________________________________________________|\n");
    scanf("%d",&choix);
    if(choix==1){
        printf(" _______________________________________________________________\n");
        printf("|        donner la marque qur vous souhaitez afficher :         |\n");
        printf("|_______________________________________________________________|\n");
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
    printf(" __________________________________\n");
    printf("|     Choisissez le type de tri :  |\n");
    printf("|__________________________________|\n");
    printf(" ________________________\n");
    printf("|     1: Tri par prix    |\n");
    printf("|________________________|\n");
    printf(" ______________________________\n");
    printf("|      2: Tri par marque       |\n");
    printf("|______________________________|\n");
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
    printf("\033[0;32m");
    printf("       =======================================================================================================================================================================================================================================\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                    S t a t i s t i q u e s  d e s  m a r q u e s   d e  v o i t u r e s   d i s p o n i b l e s                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");    
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       =======================================================================================================================================================================================================================================\n\n");
    printf("\033[0m");for ( i = 0; i < nbMarques; i++) {
        
        for ( j = 0; j < stats[i].count; j++) {
             printf("____________________________________");
           
        }
        printf("\n");
        printf("        %s :\n ", stats[i].marque);
        for ( j = 0; j < stats[i].count; j++) {
            printf("____________________________________");
           
        }     
        
        for ( j = 0; j < stats[i].count; j++) {
            
            if(j==stats[i].count-1){
                printf("|");
            }
            
           
        }
        
       printf("\n\n");
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
     printf("\n\n\n\n\n\n");
    for( i=0;i<nbr;i++){
        if((voitures+i)->nbrannee>=4){
            k++;
            printf("                                        \xbb_______________________________________________\xbb\n");
            printf("                                          la voiture %s identifier par %d a depaser 4ans \n",(voitures+i)->marque,(voitures+i)->id);
            printf("                                         \xbb________________________________________________\xbb\n\n");
            printf("                                              ---------------------------------------\n");
            printf("                                              |  VOUS VOULLEZ VENDRE CETTE VOITURE ?  |\n");
            printf("                                              ---------------------------------------\n");
            printf("                                              -----------------\n");
            printf("                                              |    1:OUI:      |\n");
            printf("                                              -----------------\n");

            printf("                                              -----------------\n");
            printf("                                              |    2:NON:      |\n");
            printf("                                              -----------------\n");
            scanf("%d",&choix);
            if(choix==1){
                fprintf(f3,"%d\t%s\t%s\t%d\t%s\t%f\t%s\t%d\n", i + 1, (voitures+i)->marque, (voitures+i)->typecarburant,(voitures+i)->nbrplace,(voitures+i)->transmission, (voitures+i)->prixjour,(voitures+i)->disponibilite,(voitures+i)->nbrannee);
                printf("==================================================================================================================================\n");
                printf("CETTE VOITURE VA ETRES POSER DANS UN FICHIER NOMMER VOITURE A VENDRE ET IL VAS ETRE SUPPRIMER DE VOTRE BASE DE DONNEE PRINCIPALE ||\n");
                printf("==================================================================================================================================\n");
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
      printf("\n\n\n\n\n");
        afficher("voiture.csv");
      
}

void louer_voiture(char nom[]){
    FILE *f=fopen("voiture.csv","rt");
    int choix;
    location *voitures=affecter(f,voitures),t;
    int nbr = longueur();
    int nbrjr;
    int id;
    int i;
     FILE *f2;

      FILE *f4=fopen("voiturelouer.csv","wt");

    if(f4){
        fprintf(f4,"%s\t%s\t%s\t%s\t%s\t%s\n","ID","NOM","ID VOITURE","MARQUE","nbrjour a louer", "prix total");
    }
     system("pause");
     system("cls");
    printf("       =======================================================================================================================================================================================================================================\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                             M O D E   U T I L I S A T E U R                                                                                                        ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");    
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       =======================================================================================================================================================================================================================================\n");
   Sleep(1000);
   affichervoiture();
  
    system("pause");
    system("cls");
    printf("\n\n\n\n");
     printf("       =======================================================================================================================================================================================================================================\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                 W E L C O M E  %s                                                                                                                  ||\n",nom);
    printf("       ||                                                                                                                                                                                                                                    ||\n");    
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       =======================================================================================================================================================================================================================================\n\n\n\n");
    
    printf(" =============================================================\n");
    printf("||VOICI LA LISTE DES VOITURE DISPONIBLE DANS NOTRE LOCATION :||\n");
    printf(" =============================================================\n");
        printf("                                                ___________________________________________________________________________________\n");
        printf("                                               |              id            |           marque        |            prix/jr         |\n");
        printf("                                               |____________________________|_________________________|____________________________|\n");
    for(i=0;i<nbr;i++){
        printf("                                                ___________________________________________________________________________________\n");
        printf("                                               |              %d            |            %s           |             300 dhs        |\n",i+1,(voitures+i)->marque);
        printf("                                               |____________________________|_________________________|____________________________|\n");

    }
    printf("\n\n\n");
    saisir :
    printf("                                                   =============================================================\n");
    printf("                                                  ||veuillez saisir l'id de la voiture que vous voullez louer : ||\n");
    printf("                                                   ==============================================================\n");
    printf("                                                  |=================|\n");
    printf("                                                    ");scanf("%d",&id);
    printf("                                                  |=================|\n");
    if(strcmp((voitures+id-1)->disponibilite,"indisponible")==0){
        printf("DESOLE %s CETTE VOITURE EST INDISPONIBLE POUR L'INSTANT VEUILLEZ RESAISIR : \n",nom);goto saisir;
    }
    printf("\xbb______________________________________________________________\xbb\n");
    printf("saisir le nombres des jours que vous voullez louer cette voiture\n");
    printf("\xbb______________________________________________________________\xbb\n");
    scanf("%d",&nbrjr);
    f4=fopen("voiturelouer.csv","at");
    if(f4){
       for(i=0;i<nbr;i++){
        if(id==(voitures+i)->id){
            fprintf(f4,"%d\t%s\t%d\t%s\t%d\t%d\n",i+1,nom,(voitures+i)->id,(voitures+i)->marque,nbrjr,(300*nbrjr));
           
        }
    } 
    }
    
  system("pause");
     system("cls");
       printf("     =======================================================================================================================================================================================================================================\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                      V O T R E   C O N T R A T                                                                                                     ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");    
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       =======================================================================================================================================================================================================================================\n\n\n\n");
        printf("_____________________________________________________________________________________________________________________________________________\n");
        printf("_____________________________________________________________________________________________________________________________________________\n\n");
        printf("Le 21 / 05 / 2024                                                GERAZ LOCATION ");
        printf("Marrakech \n\n\n\n");
        printf("                                                 nom : %s \n\n",nom);
        printf("                                                 marque de voiture %s","dacia");
        printf("                              nbr de jour : %d\n\n\n",nbrjr);
        printf("                                        _________________________________________________________________________\n\n");
        printf("                                                 le prix total de  location : %d dhs\n\n\n\n\n\n\n\n\n",(300*nbrjr));
        printf("_____________________________________________________________________________________________________________________________________________\n");
        printf("_____________________________________________________________________________________________________________________________________________\n");
        printf(" ______________________________________\n");
        printf("|          1:Valide le contrat         |\n ");
       printf("|______________________________________|\n");
        printf(" ______________________________________\n");
        printf("|                 1:refuser            |\n ");
       printf("|______________________________________|\n");
        scanf("%d",&choix);
        if(choix==1){
            system("color 02");
            printf("\xbb__________________________________________________________________\xbb\n");
            printf(" felicitation mr %s la voiture %s est louer avec succes \n",nom,"dacia");
            printf("\xbb__________________________________________________________________\xbb\n");
            

        }
    }
void affichage(){

    printf("       =======================================================================================================================================================================================================================================\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                           G E R A Z   L O C A T I O N   -   V O T R E   C H O I X   D E   Q U A L I T E                                                                            ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");    
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       ||                                                                                                                                                                                                                                    ||\n");
    printf("       =======================================================================================================================================================================================================================================\n");
    
    

}
void animation(){
    printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
    printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
    printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
    printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
    printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
   
}


int main(){
    char nomutilisateur[10],password[10];
     int nbr;  
    char marque[20];
    int menu;
    int m;
    location voiture;
    

    system("color ");
    
    affichervoiture();
    animation();
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    affichage();
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    animation();
   system("pause");
    system("cls");
    animation();
    printf("\n\n");
            printf("    _______                  _______                    _______                        _______                        _______                     _______                   _______       \n");
            printf("  _/___|___\\_                /___|___\\_                 _/___|___\\_                   _/___|___\\_                   _/___|___\\_                  _/___|___\\_              _/___|___\\_  \n");
            printf(" /     |       \\            /     |       \\            /     |       \\               /     |       \\               /     |       \\             /     |       \\           /     |       \\ \n");
            printf("||_____|_________|         ||_____|_________|         ||_____|_________|            ||_____|_________|            ||_____|_________|          ||_____|_________|         ||_____|_________|                                         \n");
            printf("  (O)      (O)                 (O)      (O)               (O)      (O)                   (O)      (O)                   (O)      (O)                (O)      (O)               (O)      (O)           \n");
printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
    printf("\n\n\n\n");
    printf("                                \xbb___________________________________________________________           LOGIN                  ________________________________________________________\xbb\n\n\n\n");
    printf("                                                              ____________________________________\n");
    printf("                                                             |        entrez votre nom :          |\n");
    printf("                                                             |____________________________________|\t");
    fflush(stdin);
                                                    gets(nomutilisateur);
                                                                                    
    printf("                                                              ____________________________________\n");
    printf("                                                             |      entrez votre passWord :       |\n");
    printf("                                                             |____________________________________|\t");
        fflush(stdin);
                                                    gets(password);
    printf("\n\n\n\n");                                              
    printf("                                \xbb______________________________________________________________________________________________________________________________________________________ \xbb\n\n\n\n");
    animation();
    system("pause");
    system("cls");
    if(strcmp(password,"badr123456")==0){
    
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
            printf("    _______                  _______                    _______                        _______                        _______                     _______                   _______       \n");
            printf("  _/___|___\\_                /___|___\\_                 _/___|___\\_                   _/___|___\\_                   _/___|___\\_                  _/___|___\\_              _/___|___\\_  \n");
            printf(" /     |       \\            /     |       \\            /     |       \\               /     |       \\               /     |       \\             /     |       \\           /     |       \\ \n");
            printf("||_____|_________|         ||_____|_________|         ||_____|_________|            ||_____|_________|            ||_____|_________|          ||_____|_________|         ||_____|_________|                                         \n");
            printf("  (O)      (O)                 (O)      (O)                (O)      (O)                  (O)      (O)                  (O)      (O)               (O)      (O)               (O)      (O)           \n");
printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
      printf("\n\n");
    printf("                           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n ");
    printf("                           :::::::::::::::::::::::::::::::: BIENVENUE CHEZ GERAZ POUR LA LOCATION DE VOITURES ::::::::::::::::::::::::::: \n "); 
    printf("                           -------------------------------------------------------------------------------------------------------------------- \n")  ;        ;
    printf("                                                                          ::::::::::MENU::::::::::                                             \n")   ;     
    printf("                           --------------------------------------------------------------------------------------------------------------------   \n") ;                                                                                                           
    printf("                           |                          (1).Afficher la liste des voitures disponibles dans votre  location :                    |\n");
    printf("                           |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("                           |                          (2).Ajouter une voiture :                                                                |\n");
    printf("                           |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("                           |                          (3).Supprimer une voiture :                                                              |\n");
    printf("                           |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("                           |                          (4).Affichage des voiture par (Marque, Disponibilite) :                                  | \n");
    printf("                           |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("                           |                          (5).trier les voiture (Marque, Prix de location par jour):                               |\n");
    printf("                           |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("                           |                          (6).afficher les statistique des voiture qui existe                                      |\n");
    printf("                           |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("                           |                          (7).afficher la liste des voiture a vendre                                               |\n");
    printf("                           |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("\n    Veuillez choisir une option : ");

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
    }
    else{
        louer_voiture(nomutilisateur);
    }
}