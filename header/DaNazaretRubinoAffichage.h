#ifndef DANAZARETRUBINOAFFICHAGE_H
#define DANAZARETRUBINOAFFICHAGE_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Fonction d'affichage de MENU
void triMenuPersonnel(void)
{
    printf("+=========================================+\n");
    printf("|*         Afficher le personnel         *|\n");
    printf("+=========================================+\n");
    printf("|+      Choisissez une option de tri     +|\n");
    printf("+=========================================+\n");
    printf("|-> Option 1 :  Par Nom                   |\n"); 
    printf("|-> Option 2 :  Par Specialite            |\n");
    printf("|-> Option 0 :  Retour                    |\n");
    printf("+=========================================+\n\n");
}

// Fonction "mainOriginal" du HEADER à appeler dans le ".c" 
personnelHeader() {
	// Déclaration des fonctions
	void triMenuPersonnel(void);
	void triPersonnel(int);
	void listePersonnel(int);
	
	// Déclaration
	int choix = 0;
	
	// Appel de fonctions
	triMenuPersonnel();
	lecturePersonnel();	
	
	listePersonnel(3);
	
	// Demande
	printf("\nEntrez une option de tri : ");
    scanf("%1d", &choix);
    
	// Tri
	triPersonnel(choix);

	while(choix > 0 && choix < 4){	
		system("cls");
	
		triMenuPersonnel();
						
		listePersonnel(3);
		
		// Demande
		printf("\nEntrez une option de tri : ");
	    scanf("%1d", &choix);
	    
		// Tri
		triPersonnel(choix);	
	} 

	// Gerer le retour au menu d'avant
	if(choix <= 1 || choix >= 4){
		system("cls");
		void affichageMenuPersonnelCM();
		affichageMenuPersonnelCM();
	}
}

// Fonction de tri pour le personnel
void triPersonnel(int choix){
	// Ouverture du fichier DaNazaretRubinoPersonnels.dat
	// en lecture
	fdatPersonnel = fopen("ressource/DaNazaretRubinoPersonnels.dat","r");

	// On alloue debPersonnel une adresse mémoire
	debPersonnel=malloc(sizeof(personnel));
	fscanf(fdatPersonnel, "%20s %20s %20s %1s %14s %3s %14s %1s", debPersonnel->nom, debPersonnel->prenom, debPersonnel->specialite, debPersonnel->genre, debPersonnel->codeInami, debPersonnel->pays, debPersonnel->numeroTel, debPersonnel->etat);
	
	// Pareil
	nouveauPersonnel=malloc(sizeof(personnel));
	fscanf(fdatPersonnel, "%20s %20s %20s %1s %14s %3s %14s %1s", nouveauPersonnel->nom, nouveauPersonnel->prenom, nouveauPersonnel->specialite, nouveauPersonnel->genre, nouveauPersonnel->codeInami, nouveauPersonnel->pays, nouveauPersonnel->numeroTel, nouveauPersonnel->etat);
	
	// Si le choix est égal à 1, on défini debPersonnel->tri
	// comme étant "nom", et permet ainsi d'effectuer un tri
	// sans devoir changer les valeurs soi-même
	if (choix == 1) {
		strcpy(debPersonnel->tri, debPersonnel->nom);
		strcpy(nouveauPersonnel->tri, nouveauPersonnel->nom);
	} else if (choix == 2) {
		strcpy(debPersonnel->tri, debPersonnel->specialite);
		strcpy(nouveauPersonnel->tri, nouveauPersonnel->specialite);
	} else if (choix == 3) {
		strcpy(debPersonnel->tri, debPersonnel->etat);
		strcpy(nouveauPersonnel->tri, nouveauPersonnel->etat);
	}

	// Tri
	if (strcmp(nouveauPersonnel->tri, debPersonnel->tri) > 0) {
		debPersonnel->suivant = nouveauPersonnel;
		nouveauPersonnel->suivant = NULL;
	} else {
		nouveauPersonnel->suivant = debPersonnel;
		debPersonnel->suivant = NULL;
		debPersonnel = nouveauPersonnel;
	}
		
	intercalePersonnel=malloc(sizeof(personnel));
	fscanf(fdatPersonnel,"%20s %20s %20s %1s %14s %3s %14s %1s", intercalePersonnel->nom, intercalePersonnel->prenom, intercalePersonnel->specialite, intercalePersonnel->genre, intercalePersonnel->codeInami, intercalePersonnel->pays, intercalePersonnel->numeroTel, intercalePersonnel->etat);

	while (!feof(fdatPersonnel)) {
		i=0;
		n++;
		courantPersonnel = debPersonnel;

		if (choix == 1) {
			strcpy(intercalePersonnel->tri, intercalePersonnel->nom);
			strcpy(courantPersonnel->tri, courantPersonnel->nom);
		} else if (choix == 2) {
			strcpy(intercalePersonnel->tri, intercalePersonnel->specialite);
			strcpy(courantPersonnel->tri, courantPersonnel->specialite);
		} else if (choix == 3) {
			strcpy(intercalePersonnel->tri, intercalePersonnel->etat);
			strcpy(courantPersonnel->tri, courantPersonnel->etat);
		}
		
		while(strcmp(intercalePersonnel->tri, courantPersonnel->tri) > 0 && courantPersonnel->suivant != NULL) {
			precedentPersonnel=courantPersonnel;
		  	courantPersonnel=courantPersonnel->suivant;
		  	i++;
		}
		
		if((courantPersonnel->suivant == NULL) && (strcmp(intercalePersonnel->tri, courantPersonnel->tri) > 0)) {
				courantPersonnel->suivant = intercalePersonnel;
				intercalePersonnel->suivant = NULL;
		} else {
			intercalePersonnel->suivant = courantPersonnel;
			if(i == 0) {
				debPersonnel = intercalePersonnel;
			} else {
				precedentPersonnel->suivant = intercalePersonnel;
			}
		}
		
		intercalePersonnel = malloc(sizeof(personnel));
		fscanf(fdatPersonnel,"%20s %20s %20s %1s %14s %3s %14s %1s", intercalePersonnel->nom, intercalePersonnel->prenom, intercalePersonnel->specialite, intercalePersonnel->genre, intercalePersonnel->codeInami, intercalePersonnel->pays, intercalePersonnel->numeroTel, intercalePersonnel->etat);	
	}
}

// *********************************************************************************************************************
// ************************************************** PARTIE PATIENT **************************************************
// *********************************************************************************************************************
void triMenuPatients(void)
{
    printf("+=========================================+\n");
    printf("|*          Afficher le patient          *|\n");
    printf("+=========================================+\n");
    printf("|+     Choisissez une option de tri      +|\n");
    printf("+=========================================+\n");
    printf("|-> Option 1 :  Par Num.Reg National      |\n"); 
    printf("|-> Option 2 :  Par Nom                   |\n");
    printf("|-> Option 3 :  Par Genre                 |\n");
    printf("|-> Option 4 :  Par Ville                 |\n");
    printf("|-> Option 5 :  Par Pays                  |\n");
    printf("|-> Option 0 :  Quitter                   |\n");
    printf("+=========================================+\n\n");
}

// Fonction "mainOriginal" du HEADER à appeler dans le ".c" 
patientHeader() {
	void triMenuPatients(void);
	void affichageMenuPatientsCM();
	void listePatients(int);
	void triPatient(int);
	
	// Déclaration
	int choix = 0;
	
	triMenuPatients();
	lecturePatient();	
	
	listePatients(3);
	
	// Demande
	printf("\nOption de tri : ");
    scanf("%1d", &choix);
    
	// Tri
	triPatient(choix);

	while(choix > 0 && choix < 6){	
	 	system("cls");
	
		triMenuPatients();
						
		listePatients(3);
		
		// Demande
		printf("\nOption de tri : ");
	    scanf("%1d", &choix);
	    
		// Tri
		triPatient(choix);	
	} 
	
		// Gerer le retour au menu d'avant
	if(choix <= 1 || choix >= 7){
		system("cls");
		affichageMenuPatientsCM();
	}
}

// Fonction de tri pour les patients
void triPatient(int choix){
	fdatPatient = fopen("ressource/DaNazaretRubinoPatients.dat","r");
	
	debPatient=malloc(sizeof(patient));
	fscanf(fdatPatient, "%20s %20s %10s %1s", debPatient->nom, debPatient->prenom, debPatient->dateNais, debPatient->genre);	
	fgets(debPatient->rue, 30, fdatPatient);
	fscanf(fdatPatient, "%3s %25s %5s %3s %14s %15s %3s", debPatient->num, debPatient->ville, debPatient->codePostal, debPatient->pays, debPatient->numeroTel, debPatient->numRegNat, debPatient->pourRemb);

	nouveauPatient=malloc(sizeof(patient));
	fscanf(fdatPatient, "%20s %20s %10s %1s", nouveauPatient->nom, nouveauPatient->prenom, nouveauPatient->dateNais, nouveauPatient->genre);	
	fgets(nouveauPatient->rue, 30, fdatPatient);
	fscanf(fdatPatient, "%3s %25s %5s %3s %14s %15s %3s", nouveauPatient->num, nouveauPatient->ville, nouveauPatient->codePostal, nouveauPatient->pays, nouveauPatient->numeroTel, nouveauPatient->numRegNat, nouveauPatient->pourRemb);

	if (choix == 1) {
		strcpy(debPatient->tri, debPatient->numRegNat);
		strcpy(nouveauPatient->tri, nouveauPatient->numRegNat);
	} else if (choix == 2) {
		strcpy(debPatient->tri, debPatient->nom);
		strcpy(nouveauPatient->tri, nouveauPatient->nom);
	} else if (choix == 3) {
		strcpy(debPatient->tri, debPatient->genre);
		strcpy(nouveauPatient->tri, nouveauPatient->genre);
	} else if (choix == 4) {
		strcpy(debPatient->tri, debPatient->ville);
		strcpy(nouveauPatient->tri, nouveauPatient->ville);
	} else if (choix == 5) {
		strcpy(debPatient->tri, debPatient->pays);
		strcpy(nouveauPatient->tri, nouveauPatient->pays);
	}
	
	if (strcmp(nouveauPatient->tri, debPatient->tri) > 0) {
		debPatient->suivant = nouveauPatient;
		nouveauPatient->suivant = NULL;
	} else {
		nouveauPatient->suivant = debPatient;
		debPatient->suivant = NULL;
		debPatient = nouveauPatient;
	}
			
	intercalePatient=malloc(sizeof(patient));
	fscanf(fdatPatient, "%20s %20s %10s %1s", intercalePatient->nom, intercalePatient->prenom, intercalePatient->dateNais, intercalePatient->genre);	
	fgets(intercalePatient->rue, 30, fdatPatient);
	fscanf(fdatPatient, "%3s %25s %5s %3s %14s %15s %3s", intercalePatient->num, intercalePatient->ville, intercalePatient->codePostal, intercalePatient->pays, intercalePatient->numeroTel, intercalePatient->numRegNat, intercalePatient->pourRemb);

	while (!feof(fdatPatient)) {
		i=0;
		n++;
		courantPatient = debPatient;

		if (choix == 1) {
			strcpy(intercalePatient->tri, intercalePatient->numRegNat);
			strcpy(courantPatient->tri, courantPatient->numRegNat);
		} else if (choix == 2) {
			strcpy(intercalePatient->tri, intercalePatient->nom);
			strcpy(courantPatient->tri, courantPatient->nom);
		} else if (choix == 3) {
			strcpy(intercalePatient->tri, intercalePatient->genre);
			strcpy(courantPatient->tri, courantPatient->genre);
		} else if (choix == 4) {
			strcpy(intercalePatient->tri, intercalePatient->ville);
			strcpy(courantPatient->tri, courantPatient->ville);
		} else if (choix == 5) {
			strcpy(intercalePatient->tri, intercalePatient->pays);
			strcpy(courantPatient->tri, courantPatient->pays);
		}
		
		while(strcmp(intercalePatient->tri, courantPatient->tri) > 0 && courantPatient->suivant != NULL) {
			precedentPatient=courantPatient;
		  	courantPatient=courantPatient->suivant;
		  	i++;
		}
		
		if((courantPatient->suivant == NULL) && (strcmp(intercalePatient->tri, courantPatient->tri) > 0)) {
				courantPatient->suivant = intercalePatient;
				intercalePatient->suivant = NULL;
		} else {
			intercalePatient->suivant = courantPatient;
			if(i == 0) {
				debPatient = intercalePatient;
			} else {
				precedentPatient->suivant = intercalePatient;
			}
		}

		intercalePatient = malloc(sizeof(patient));
		fscanf(fdatPatient, "%20s %20s %10s %1s", intercalePatient->nom, intercalePatient->prenom, intercalePatient->dateNais, intercalePatient->genre);	
		fgets(intercalePatient->rue, 30, fdatPatient);
		fscanf(fdatPatient, "%3s %25s %5s %3s %14s %15s %3s", intercalePatient->num, intercalePatient->ville, intercalePatient->codePostal, intercalePatient->pays, intercalePatient->numeroTel, intercalePatient->numRegNat, intercalePatient->pourRemb);
	}
}
#endif
