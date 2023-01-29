#ifndef DANAZARETRUBINOCREATIONDATE_H
#define DANAZARETRUBINOCREATIONDATE_H
#include <stdio.h>
// Fichier ne servant qu'à la création d'horaire .dat vide.
// N'est actuellement pas utilisé mais peut sert lorsqu'on
// l'utilise seul.

creationDateHeader(){
	// Déclaration des VARIABLES
	int annee, mois, jour, i, n, m, y, s, anneeBis, nbJour = 0;	
	FILE *horaires;
	
	if( horaires = fopen("ressource/horaires.dat", "r")) {
		fclose(horaires);
	} else {
		horaires = fopen("ressource/horaires.dat", "w");		
		// Déclaration des "FONCTIONS" de temps (permettant notamment de trouver la date actuelle) (intégrées dans C via time.h)
		time_t rawtime;
	    time_t timestamp = time( NULL );	
		struct tm * now = localtime( & timestamp );
		struct tm *timeinfo;
		
		// Obtention de l'année actuelle
		annee = now->tm_year+1900;
	  	time(&rawtime);
	  	timeinfo = localtime (&rawtime);
	  	timeinfo->tm_year = annee - 1900;
	    
	    // Test permettant de savoir si l'année actuelle est BISEXTILE ou pas
	    if(annee % 4 == 0) {
	        if( annee % 100 == 0) {
	            if ( annee % 400 == 0){
	            	anneeBis = 1;
				} else {
	                anneeBis = 0;
				}
	        } else {
	            anneeBis = 1;
	        }
	    } else {
	        anneeBis = 0;
		}
		
		// Affichage des heures
		timeinfo->tm_hour = 7;
		timeinfo->tm_min = 30;
		for (y = 1; y < 17; y++){
			timeinfo->tm_min = timeinfo->tm_min + 30;
			if ((timeinfo->tm_min % 30) == 0 && timeinfo->tm_min == 60){
				timeinfo->tm_hour++;
				timeinfo->tm_min = 0;
				if (timeinfo->tm_hour == 12){
					timeinfo->tm_hour = 13;
				}
			}
			// Début des RDV à 08h00, pause à 12h00 (donc 11h30) et reprise à 13h00 jusqu'à 16h30 (fin à 17h00 donc)
			fprintf(horaires, "%02d:%02d ", timeinfo->tm_hour, timeinfo->tm_min);
		}
		fprintf(horaires, "\n");
	
		// Affichage des mois, jours sur toute l'année
	    for (i = 1; i <= 12; i++){
			nbJour = 0;
			timeinfo->tm_mon = mois - 1;
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
			
			timeinfo->tm_mon = mois;
			fprintf(horaires, "%s\n", listeMois[timeinfo->tm_mon]);
			for (n = 1; n <= nbJour; n++){
				jour = n;
				timeinfo->tm_mday = jour;
				mktime (timeinfo);
				fprintf(horaires, "%02d/%02d	", timeinfo->tm_mday, (timeinfo->tm_mon + 1));
				if ((n % 7) == 0){
					fprintf(horaires, "\n");
					for (y = 1; y < 17; y++){
						for (m = 1; m <= 7; m++){
							fprintf(horaires, "MED ");
							fprintf(horaires, "PAT	");
						}
						fprintf(horaires, "\n");
					}
				} else if ((i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) && n == 31){
					fprintf(horaires, "\n");
					for (y = 1; y < 17; y++){
						for (m = 1; m <= 3; m++){
							fprintf(horaires, "MED ");
							fprintf(horaires, "PAT	");
						}
						fprintf(horaires, "\n");
					}
				} else if ((i == 2 || i == 4 || i == 6 || i ==  9 || i ==  11) && n == 30) {
					fprintf(horaires, "\n");
					for (y = 1; y < 17; y++){
						for (m = 1; m <= 2; m++){
							fprintf(horaires, "MED ");
							fprintf(horaires, "PAT	");
						}
						fprintf(horaires, "\n");
					}	
				}
			}			
			mois = i;
		}				
	}
}

#endif
