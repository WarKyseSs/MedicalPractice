#ifndef DANAZARETRUBINOINFORMATIONSDATES_H
#define DANAZARETRUBINOINFORMATIONSDATES_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Structure personnel
typedef struct dates
{	int annee[5], mois[13], jourmois[13][32];
	char moisE[13][10], heures[17][6], medecin[13][32][17][21], patient[13][32][17][21], specialite[20];
	struct dates *precedent, *suivant;
} dates;
dates *debJournee;

// Déclaration des MOIS et des JOURS de la SEMAINE
const char * listeMois[] = { 
    "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet",
    "Aout", "Septembre", "Octobre", "Novembre", "Decembre"
};
char * jourSemaine[] = {
	"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"
};
char * raccourciJour[] = {
	"Dim.", "Lun.", "Mar.", "Mer.", "Jeu.", "Vend.", "Sam."
};

#endif
