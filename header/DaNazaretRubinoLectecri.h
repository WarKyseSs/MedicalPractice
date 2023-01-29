#ifndef DANAZARETRUBINOLECTECRI_H
#define DANAZARETRUBINOLECTECRI_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// *********************************************************************************************************************
// ************************************************** PARTIE GLOBALE ***************************************************
// *********************************************************************************************************************
// Globale 
int i, j, n = 2, numero, place;

void lecturePersonnel();
void lecturePatient();

// *********************************************************************************************************************
// ************************************************** PARTIE PERSONNEL *************************************************
// *********************************************************************************************************************

// Structure personnel
typedef struct personnel
{	char nom[21], prenom[21], specialite[21], genre[2], codeInami[15], pays[4], numeroTel[14], etat[2];
	char tri[21];
	struct personnel *suivant;
} personnel;
personnel *debPersonnel, *courantPersonnel, *nouveauPersonnel, *intercalePersonnel, *precedentPersonnel;

// Structure ajoutPersonnel
typedef struct 
{	char nom[21], prenom[21], specialite[21], genre[2], codeInami[15], pays[4], numeroTel[15], etat[2];
	char test[21];
} ajoutPersonnel;

// Fichier fdat associé
FILE *fdatPersonnel;

//  Fonction de lecture du personnel
void lecturePersonnel() {
	fdatPersonnel = fopen("ressource/DaNazaretRubinoPersonnels.dat","r");
	
	debPersonnel=malloc(sizeof(personnel));
	fscanf(fdatPersonnel, "%20s %20s %20s %1s %14s %3s %14s %1s", debPersonnel->nom, debPersonnel->prenom, debPersonnel->specialite, debPersonnel->genre, debPersonnel->codeInami, debPersonnel->pays, debPersonnel->numeroTel, debPersonnel->etat);

	nouveauPersonnel=malloc(sizeof(personnel));
	fscanf(fdatPersonnel, "%20s %20s %20s %1s %14s %3s %14s %1s", nouveauPersonnel->nom, nouveauPersonnel->prenom, nouveauPersonnel->specialite, nouveauPersonnel->genre, nouveauPersonnel->codeInami, nouveauPersonnel->pays, nouveauPersonnel->numeroTel, nouveauPersonnel->etat);

	debPersonnel->suivant = nouveauPersonnel;
	nouveauPersonnel->suivant = NULL;
			
	intercalePersonnel=malloc(sizeof(personnel));
	fscanf(fdatPersonnel,"%20s %20s %20s %1s %14s %3s %14s %1s", intercalePersonnel->nom, intercalePersonnel->prenom, intercalePersonnel->specialite, intercalePersonnel->genre, intercalePersonnel->codeInami, intercalePersonnel->pays, intercalePersonnel->numeroTel, intercalePersonnel->etat);

	while (!feof(fdatPersonnel)) {
		i=0;
		n++;
		
		courantPersonnel = debPersonnel;
		
		while(courantPersonnel->suivant != NULL) {
			precedentPersonnel=courantPersonnel;
		  	courantPersonnel=courantPersonnel->suivant;
		  	i++;
		}
		
		if(courantPersonnel->suivant == NULL) {
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

void ecriturePersonnel(){
	// impression de laurantPersonnel->su liste finale dans le fichier DAT
	courantPersonnel=debPersonnel;
	while(courantPersonnel->suivant != NULL)
	{
		precedentPersonnel = courantPersonnel;
		fprintf(fdatPersonnel, "%-20s %-20s %-20s %-1s %-14s %3s %-14s %1s\n", courantPersonnel->nom, courantPersonnel->prenom, courantPersonnel->specialite, courantPersonnel->genre, courantPersonnel->codeInami, courantPersonnel->pays, courantPersonnel->numeroTel, courantPersonnel->etat);
		courantPersonnel = courantPersonnel->suivant;
		free(precedentPersonnel);
	}
	fprintf(fdatPersonnel, "%-20s %-20s %-20s %-1s %-14s %3s %-14s %1s\n", courantPersonnel->nom, courantPersonnel->prenom, courantPersonnel->specialite, courantPersonnel->genre, courantPersonnel->codeInami, courantPersonnel->pays, courantPersonnel->numeroTel, courantPersonnel->etat);
	
	// Sauvegarde du fichier
	fclose(fdatPersonnel);
}

// *********************************************************************************************************************
// ************************************************** PARTIE PATIENT ***************************************************
// *********************************************************************************************************************
// Structure globale du patient
typedef struct patient
{	char nom[21], prenom[21], dateNais[11], genre[2], rue[31], num[4], ville[26], codePostal[6], pays[4], numeroTel[15], numRegNat[16], pourRemb[4];
	char tri[31];
	char test[31];
	struct patient *suivant;
} patient;
patient *debPatient, *courantPatient, *nouveauPatient, *intercalePatient, *precedentPatient;

// Structure ajoutPatients
typedef struct 
{	char nom[21], prenom[21], dateNais[11], genre[2], rue[31], num[4], ville[26], codePostal[6], pays[4], numeroTel[15], numRegNat[16], pourRemb[4];
	char test[21];
} ajoutPatient;

// Fichier fdat associé
FILE *fdatPatient;

// Fonction de lecture des patients
void lecturePatient() {	
	fdatPatient = fopen("ressource/DaNazaretRubinoPatients.dat","r");
	
	debPatient=malloc(sizeof(patient));
	fscanf(fdatPatient, "%20s %20s %10s %1s", debPatient->nom, debPatient->prenom, debPatient->dateNais, debPatient->genre);	
	fgets(debPatient->rue, 30, fdatPatient);
	fscanf(fdatPatient, "%3s %25s %5s %3s %14s %15s %3s", debPatient->num, debPatient->ville, debPatient->codePostal, debPatient->pays, debPatient->numeroTel, debPatient->numRegNat, debPatient->pourRemb);

	nouveauPatient=malloc(sizeof(patient));
	fscanf(fdatPatient, "%20s %20s %10s %1s", nouveauPatient->nom, nouveauPatient->prenom, nouveauPatient->dateNais, nouveauPatient->genre);	
	fgets(nouveauPatient->rue, 30, fdatPatient);
	fscanf(fdatPatient, "%3s %25s %5s %3s %14s %15s %3s", nouveauPatient->num, nouveauPatient->ville, nouveauPatient->codePostal, nouveauPatient->pays, nouveauPatient->numeroTel, nouveauPatient->numRegNat, nouveauPatient->pourRemb);
	
	debPatient->suivant = nouveauPatient;
	nouveauPatient->suivant = NULL;
			
	intercalePatient=malloc(sizeof(patient));
	fscanf(fdatPatient, "%20s %20s %10s %1s", intercalePatient->nom, intercalePatient->prenom, intercalePatient->dateNais, intercalePatient->genre);	
	
	fgets(intercalePatient->rue, 30, fdatPatient);
	fscanf(fdatPatient, "%3s %25s %5s %3s %14s %15s %3s", intercalePatient->num, intercalePatient->ville, intercalePatient->codePostal, intercalePatient->pays, intercalePatient->numeroTel, intercalePatient->numRegNat, intercalePatient->pourRemb);
	
	while (!feof(fdatPatient)) {
		i=0;
		n++;
		
		courantPatient = debPatient;
		while(courantPatient->suivant != NULL) {
			precedentPatient=courantPatient;
		  	courantPatient=courantPatient->suivant;
		  	i++;
		}
		
		if(courantPatient->suivant == NULL) {
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


void ecriturePatient(){
	// impression de la liste finale dans le fichier DAT
	courantPatient=debPatient;
	while(courantPatient->suivant != NULL)
	{
		precedentPatient = courantPatient;
		fprintf(fdatPatient, "%-20s %-20s %-10s %-1s%-30s %-3s %-25s %-5s %-3s %-14s %-14s %-3s\n", courantPatient->nom, courantPatient->prenom, courantPatient->dateNais, courantPatient->genre, courantPatient->rue, courantPatient->num, courantPatient->ville, courantPatient->codePostal, courantPatient->pays, courantPatient->numeroTel, courantPatient->numRegNat, courantPatient->pourRemb);
		courantPatient = courantPatient->suivant;
		free(precedentPatient);
	}
	fprintf(fdatPatient, "%-20s %-20s %-10s %-1s %-30s %-3s %-25s %-5s %-3s %-14s %-14s %-3s\n", courantPatient->nom, courantPatient->prenom, courantPatient->dateNais, courantPatient->genre, courantPatient->rue, courantPatient->num, courantPatient->ville, courantPatient->codePostal, courantPatient->pays, courantPatient->numeroTel, courantPatient->numRegNat, courantPatient->pourRemb);
	
	// Sauvegarde du fichier
	fclose(fdatPatient);
}
#endif
