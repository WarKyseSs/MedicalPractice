#ifndef DANAZARETRUBINOLECTUREDATE_H
#define DANAZARETRUBINOLECTUREDATE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int specialite;

void lectureJournee(int specialite){
	// Déclaration des VARIABLES
	int annee, mois, jour, i, n, m, y, anneeBis, nbJour = 0;
	int tmp, sem;	
	char heures[17][6];
	FILE *horaires;
	
	/*	1. Dentiste		2. Infirmiere	3. Generaliste	4. ORL	5. Urologue */
	if (specialite == 1){
		horaires = fopen("ressource/horaires/DaNazaretRubinoDentiste.dat", "r");
	} else if (specialite == 2){
		horaires = fopen("ressource/horaires/DaNazaretRubinoInfirmiere.dat", "r");
	} else if (specialite == 3){
		horaires = fopen("ressource/horaires/DaNazaretRubinoGeneraliste.dat", "r");
	} else if (specialite == 4){
		horaires = fopen("ressource/horaires/DaNazaretRubinoOrl.dat", "r");
	} else if (specialite == 5){
		horaires = fopen("ressource/horaires/DaNazaretRubinoUrologue.dat", "r");
	} else {
		printf("Erreur.");
		specialite = 0;
	}
    
    if (specialite != 0){	
		// Déclaration des "FONCTIONS" de temps (permettant notamment de trouver la date actuelle) (intégrées dans C via time.h)
		time_t rawtime;
	    time_t timestamp = time( NULL );	
		struct tm * now = localtime( & timestamp );
		struct tm *timeinfo;
		
		for (y = 1; y < 17; y++){
			fscanf(horaires, "%5s ", heures[y]);
		}
	    
	   	debJournee=malloc(sizeof(dates));
		for (y = 1; y < 17; y++){
			strcpy(debJournee->heures[y], heures[y]);
		}
		fscanf(horaires, "%15s", debJournee->specialite);
		
		// Affichage des mois, jours sur toute l'année
	    for (i = 1; i <= 12; i++){
			nbJour = 0;
			if (i == 2){			
				if (anneeBis == 1) {
					nbJour = 29;
				} else {
					nbJour = 28;
				}
			} else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
				nbJour = 31;			
			} else {
				nbJour = 30;
			}
	
			fscanf(horaires, "%9s", debJournee->moisE[i]);
			if ((i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)){
				jour = 0;
				for (sem = 1; sem < 5; sem++){
					if (sem != 1) {
						jour = (sem-1) * 7;	
						jour++;
					} else {
						jour = 1;
					}
					for (n = 1; n < 8; n++){
						fscanf(horaires, "%02d/%02d", &debJournee->jourmois[i][jour], &debJournee->mois[i]);
						jour++;
					}
					for (m = 1; m < 17; m++){
						if (sem != 1) {
							jour = (sem-1) * 7;	
							jour++;
						} else {
							jour = 1;
						}
						for (n = 1; n < 8; n++){
							fscanf(horaires, "%20s %20s", debJournee->medecin[i][jour][m], debJournee->patient[i][jour][m]);
							jour++;
						}
					}
				}
				for (m = 1; m < 17; m++){
					jour = 4 * 7;
					for (n = 1; n < 4; n++){
						jour++;
						fscanf(horaires, "%02d/%02d", &debJournee->jourmois[i][jour], &debJournee->mois[i]);
					}
					for (m = 1; m < 17; m++){
						jour = 4 * 7;
						for (n = 1; n < 4; n++){
							jour++;
							fscanf(horaires, "%20s %20s", debJournee->medecin[i][jour][m], debJournee->patient[i][jour][m]);
						}
					}
				}
			} else if ((i == 4 || i == 6 || i ==  9 || i ==  11)){
				jour = 0;
				for (sem = 1; sem < 5; sem++){
					if (sem != 1) {
						jour = (sem-1) * 7;	
						jour++;
					} else {
						jour = 1;
					}
					for (n = 1; n < 8; n++){
						fscanf(horaires, "%02d/%02d", &debJournee->jourmois[i][jour], &debJournee->mois[i]);
						jour++;
					}
					for (m = 1; m < 17; m++){
						if (sem != 1) {
							jour = (sem-1) * 7;	
							jour++;
						} else {
							jour = 1;
						}
						for (n = 1; n < 8; n++){
							fscanf(horaires, "%20s %20s", debJournee->medecin[i][jour][m], debJournee->patient[i][jour][m]);
							jour++;
						}
					}
				}
				for (m = 1; m < 17; m++){
					jour = 4 * 7;
					for (n = 1; n < 3; n++){
						jour++;
						fscanf(horaires, "%02d/%02d", &debJournee->jourmois[i][jour], &debJournee->mois[i]);
					}
					for (m = 1; m < 17; m++){
						jour = 4 * 7;
						for (n = 1; n < 3; n++){
							jour++;
							fscanf(horaires, "%20s %20s", debJournee->medecin[i][jour][m], debJournee->patient[i][jour][m]);
						}
					}
				}
			} else if (i == 2){
				jour = 0;
				for (sem = 1; sem < 5; sem++){
					if (sem != 1) {
						jour = (sem-1) * 7;	
						jour++;
					} else {
						jour = 1;
					}
					for (n = 1; n < 8; n++){
						fscanf(horaires, "%02d/%02d", &debJournee->jourmois[i][jour], &debJournee->mois[i]);
						jour++;
					}
					for (m = 1; m < 17; m++){
						if (sem != 1) {
							jour = (sem-1) * 7;	
							jour++;
						} else {
							jour = 1;
						}
						for (n = 1; n < 8; n++){
							fscanf(horaires, "%20s %20s", debJournee->medecin[i][jour][m], debJournee->patient[i][jour][m]);
							jour++;
						}
					}
				}
			}
		}
	}
}

void ecritureJournee(int specialite){
	// Déclaration des VARIABLES
	void affichageMenuRdvCM();
	int annee, mois, jour, i, n, m, y, anneeBis, nbJour = 0;
	int tmp, sem;	
	FILE *horaires;
	
	/*	1. Dentiste		2. Infirmiere	3. Generaliste	4. ORL	5. Urologue */
	if (specialite == 1){
		horaires = fopen("ressource/horaires/DaNazaretRubinoDentiste.dat", "w");
	} else if (specialite == 2){
		horaires = fopen("ressource/horaires/DaNazaretRubinoInfirmiere.dat", "w");
	} else if (specialite == 3){
		horaires = fopen("ressource/horaires/DaNazaretRubinoGeneraliste.dat", "w");
	} else if (specialite == 4){
		horaires = fopen("ressource/horaires/DaNazaretRubinoOrl.dat", "w");
	} else if (specialite == 5){
		horaires = fopen("ressource/horaires/DaNazaretRubinoUrologue.dat", "w");
	} else {
		printf("Erreur.");
		specialite = 0;
	}
    
    if (specialite != 0){	
		for (y = 1; y < 17; y++){
			fprintf(horaires, "%5s ", debJournee->heures[y]);
		}
		fprintf(horaires, "\n");
		fprintf(horaires, "%-15s\n", debJournee->specialite);
		

		// Affichage des mois, jours sur toute l'année
	    for (i = 1; i <= 12; i++){
			nbJour = 0;
			if (i == 2){			
				if (anneeBis == 1) {
					nbJour = 29;
				} else {
					nbJour = 28;
				}
			} else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
				nbJour = 31;			
			} else {
				nbJour = 30;
			}
			
			fprintf(horaires, "%-9s\n", debJournee->moisE[i]);
			if ((i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)){
				jour = 0;
				for (sem = 1; sem < 5; sem++){
					if (sem != 1) {
						jour = (sem-1) * 7;	
						jour++;
					} else {
						jour = 1;
					}
					for (n = 1; n < 8; n++){
						fprintf(horaires, "%02d/%02d	", debJournee->jourmois[i][jour], debJournee->mois[i]);
						jour++;
					}
					fprintf(horaires, "\n");
					for (m = 1; m < 17; m++){
						if (sem != 1) {
							jour = (sem-1) * 7;	
							jour++;
						} else {
							jour = 1;
						}
						for (n = 1; n < 8; n++){
							fprintf(horaires, "%-20s %-20s", debJournee->medecin[i][jour][m], debJournee->patient[i][jour][m]);
							jour++;
						}
						fprintf(horaires, "\n");
					}
				}
				for (m = 1; m < 17; m++){
					jour = 4 * 7;
					for (n = 1; n < 4; n++){
						jour++;
						fprintf(horaires, "%02d/%02d ", debJournee->jourmois[i][jour], debJournee->mois[i]);
					}
					fprintf(horaires, "\n");
					for (m = 1; m < 17; m++){
						jour = 4 * 7;
						for (n = 1; n < 4; n++){
							jour++;
							fprintf(horaires, "%-20s %-20s", debJournee->medecin[i][jour][m], debJournee->patient[i][jour][m]);
						}
						fprintf(horaires, "\n");
					}
				}
			} else if ((i == 4 || i == 6 || i ==  9 || i ==  11)){
				jour = 0;
				for (sem = 1; sem < 5; sem++){
					if (sem != 1) {
						jour = (sem-1) * 7;	
						jour++;
					} else {
						jour = 1;
					}
					for (n = 1; n < 8; n++){
						fprintf(horaires, "%02d/%02d ", debJournee->jourmois[i][jour], debJournee->mois[i]);
						jour++;
					}
					fprintf(horaires, "\n");
					for (m = 1; m < 17; m++){
						if (sem != 1) {
							jour = (sem-1) * 7;	
							jour++;
						} else {
							jour = 1;
						}
						for (n = 1; n < 8; n++){
							fprintf(horaires, "%-20s %-20s", debJournee->medecin[i][jour][m], debJournee->patient[i][jour][m]);
							jour++;
						}
						fprintf(horaires, "\n");
					}
				}
				for (m = 1; m < 17; m++){
					jour = 4 * 7;
					for (n = 1; n < 3; n++){
						jour++;
						fprintf(horaires, "%02d/%02d ", debJournee->jourmois[i][jour], debJournee->mois[i]);
					}
					fprintf(horaires, "\n");
					for (m = 1; m < 17; m++){
						jour = 4 * 7;
						for (n = 1; n < 3; n++){
							jour++;
							fprintf(horaires, "%-20s %-20s", debJournee->medecin[i][jour][m], debJournee->patient[i][jour][m]);
						}
						fprintf(horaires, "\n");
					}
				}
			} else if (i == 2){
				jour = 0;
				for (sem = 1; sem < 5; sem++){
					if (sem != 1) {
						jour = (sem-1) * 7;	
						jour++;
					} else {
						jour = 1;
					}
					for (n = 1; n < 8; n++){
						fprintf(horaires, "%02d/%02d ", debJournee->jourmois[i][jour], debJournee->mois[i]);
						jour++;
					}
					fprintf(horaires, "\n");
					for (m = 1; m < 17; m++){
						if (sem != 1) {
							jour = (sem-1) * 7;	
							jour++;
						} else {
							jour = 1;
						}
						for (n = 1; n < 8; n++){
							fprintf(horaires, "%-20s %-20s", debJournee->medecin[i][jour][m], debJournee->patient[i][jour][m]);
							jour++;
						}
						fprintf(horaires, "\n");
					}
				}
			}
		}
	}
	affichageMenuRdvCM();
}

#endif
