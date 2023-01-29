#ifndef DANAZARETRUBINORDV_H
#define DANAZARETRUBINORDV_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

int moisADD, jourADD;

// Voir les rendez-vous
lectureDateHeader(){
	void lectureJournee();	
	int mainOriginal();
	void affichageMenuRdvCM();

	int choix;	
	int journee, sem = 1;
	int n, y, i, m;
	int nbJourMax;
	
	printf("+===================================+\n");
	printf("| Listes des agendas disponibles :  |\n");
	printf("| 1. Dentiste                       |\n");
	printf("| 2. Infirmière                     |\n");
	printf("| 3. Généraliste                    |\n");
	printf("| 4. ORL                            |\n");
	printf("| 5. Urologue                       |\n");
	printf("| 0. Retour                         |\n");
	printf("+===================================+\n");
	printf("| Choissisez quel agenda afficher : |\n");
	printf("+===================================+\n");
	scanf("%1d", &specialite);
	if (specialite == 0){
		system("cls");
		mainOriginal();
	} else {
		while (specialite < 1 || specialite > 5){
			printf("+===================================+\n");
			printf("| Choissisez quel agenda afficher : |\n");
			printf("+===================================+\n");
			scanf("%1d", &specialite);	
		}
		system("cls");
	
		lectureJournee(specialite);
	
		printf("+===================================+\n");
		printf("| AGENDA %-20s       |\n", debJournee->specialite);
		printf("+===================================+\n");
		printf("| Mois disponibles :                |\n");
		printf("|  1. Janvier                       |\n");
		printf("|  2. Février                       |\n");
		printf("|  3. Mars                          |\n");
		printf("|  4. Avril                         |\n");
		printf("|  5. Mai                           |\n");
		printf("|  6. Juin                          |\n");
		printf("|  7. Juillet                       |\n");
		printf("|  8. Août                          |\n");
		printf("|  9. Septembre                     |\n");
		printf("| 10. Octobre                       |\n");
		printf("| 11. Novembre                      |\n");
		printf("| 12. Décembre                      |\n");
		printf("+===================================+\n");
		printf("| Choissisez quel mois afficher :   |\n");
		printf("+===================================+\n");
		scanf("%2d", &moisADD);	
		while (moisADD < 1 || moisADD > 12){
			printf("+===================================+\n");
			printf("| Choissisez quel mois afficher :   |\n");
			printf("+===================================+\n");
			scanf("%1d", &moisADD);	
		}	
		system("cls");
	
		printf("+============================+\n");
		printf("| AGENDA %-20s|\n", debJournee->specialite);
		printf("| MOIS %-20s  |\n", debJournee->moisE[moisADD]);
		printf("+============================+\n");
		printf("| Jour à afficher :          |\n");
		printf("|  0. Tous les jours         |\n");
		printf("|  1.                        |\n");
		printf("|  2.                        |\n");
		printf("|  3.                        |\n");
		printf("|  4.                        |\n");
		printf("| ...                        |\n");
		printf("| ...                        |\n");
		printf("| ...                        |\n");
		if (moisADD == 1 || moisADD == 3 || moisADD == 5 || moisADD == 7 || moisADD == 8 || moisADD == 10 || moisADD == 12){
			printf("| 28.                        |\n");
			printf("| 29.                        |\n");
			printf("| 30.                        |\n");
			printf("| 31.                        |\n");
			nbJourMax = 31;
		} else if (moisADD == 4 || moisADD == 6 || moisADD ==  9 || moisADD ==  11){
			printf("| 27.                        |\n");
			printf("| 28.                        |\n");
			printf("| 29.                        |\n");
			printf("| 30.                        |\n");
			nbJourMax = 30;
		} else if (moisADD == 2) {
			printf("| 25.                        |\n");
			printf("| 26.                        |\n");
			printf("| 27.                        |\n");
			printf("| 28.                        |\n");
			nbJourMax = 28;
		}
		printf("+============================+\n");
		printf("| Journée à afficher :       |\n");
		printf("+============================+\n");
		scanf("%2d", &jourADD);	
		while (jourADD < 0 || jourADD > 32){
			printf("+============================+\n");
			printf("| Journée à afficher :       |\n");
			printf("+============================+\n");
			scanf("%1d", &jourADD);	
		}	
		system("cls");
		
		if (jourADD == 0){	
			printf("+=======================================+\n");
			printf("| AGENDA %-20s           |\n", debJournee->specialite);
			printf("| MOIS %-20s             |\n", debJournee->moisE[moisADD]);
			printf("+=======================================+=======================================+=======================================+=======================================+=======================================+\n");
			for (n = 1; n <= nbJourMax; n++){
				printf("|	   	%02d/%02d	    		", n, moisADD);
				if ((n % 5) == 0){
					printf("| \n");
					for (y = 1; y < 17; y++){
						journee = n - 5;
						for (m = 1; m <= 5; m++){
							journee++;
							printf("| %s ", debJournee->heures[y]);
							printf(" %-10s - %-10s	", debJournee->medecin[moisADD][journee][y], debJournee->patient[moisADD][journee][y]);
						}
						printf("|\n");
					}
					printf("+=======================================+=======================================+=======================================+=======================================+=======================================+\n");
				} else if ((moisADD == 1 || moisADD == 3 || moisADD == 5 || moisADD == 7 || moisADD == 8 || moisADD == 10 || moisADD == 12) && n == 31){
					printf("|\n");
					for (y = 1; y < 17; y++){
						journee = n - 1;
						for (m = 1; m <= 1; m++){
							journee++;
							printf("| %s ", debJournee->heures[y]);
							printf(" %-10s - %-10s	", debJournee->medecin[moisADD][journee][y], debJournee->patient[moisADD][journee][y]);
						}
						printf("|\n");
					}
					printf("+=======================================+\n");
				} else if (moisADD == 2 && n == 28){
					printf("| \n");
					for (y = 1; y < 17; y++){
						journee = n - 5;
						for (m = 1; m <= 3; m++){
							journee++;
							printf("| %s ", debJournee->heures[y]);
							printf(" %-10s - %-10s	", debJournee->medecin[moisADD][journee][y], debJournee->patient[moisADD][journee][y]);
						}
						printf("|\n\n");
					}
					printf("+======================================================================================================================+\n");
				}
			}
			
			printf("+=========================================+\n");
		    printf("|*        Gestion des rendez-vous        *|\n");
		    printf("+=========================================+\n");
		    printf("|+      Que souhaitez-vous faire ?       +|\n");
		    printf("+=========================================+\n");
		    printf("|-> Option 0 :  Retour                    |\n");
		    printf("+=========================================+\n\n");
		
			scanf("%d",&choix);
			system("cls");
			
			if(choix == 0 || choix > 0){
				affichageMenuRdvCM();
			}
			
		} else if (jourADD != 0){		
			printf("+=======================================+\n");
			printf("| AGENDA %-20s           |\n", debJournee->specialite);
			printf("| %-20s                  |\n", debJournee->moisE[moisADD]);
			printf("|	   	%02d/%02d	    		|\n", jourADD, moisADD);
			printf("+=======================================+\n");
			for (y = 1; y < 17; y++){
				printf("| %s ", debJournee->heures[y]);
				printf(" %-10s - %-10s	", debJournee->medecin[moisADD][jourADD][y], debJournee->patient[moisADD][jourADD][y]);
				printf("|\n");
			}
			printf("+=======================================+\n");
			  
			printf("+=======================================+\n");
		    printf("|*         Gestion des rendez-vous     *|\n");
		    printf("+=======================================+\n");
		    printf("|+       Que souhaitez-vous faire ?    +|\n");
		    printf("+=======================================+\n");
		    printf("|-> Option 1 :  Ajouter un r.d.v        |\n");
		    printf("|-> Option 2 :  Supprimer un r.d.v      |\n");
		    printf("|-> Option 3 :  Mutualité               |\n");
		    printf("|-> Option 0 :  Retour                  |\n");
		    printf("+=======================================+\n\n");
		
			scanf("%d", &choix);
			system("cls");
			
			if(choix==1){
				ajouterRdvHeader();
			}
			if(choix==2){
				supprimerRdvHeader();
			}
			if(choix==3){
				mutaliteRdvHeader();
			}
			if(choix==0 || choix > 3){
				void affichageMenuRdvCM();
				affichageMenuRdvCM();
			}
		}	
	}
}

// Ajouter un rendez-vous
ajouterRdvHeader(){
	void lecturePatient();
	void lecturePersonnel();
	void affichageMenuRdvCM();
	void ecritureJournee(int);
	char patient[21], nom[21], prenom[21], medEnCharge[21];
	int unique = 0, y;
		
	printf("+=========================================+ \n");
	printf("| Prise de rendez-vous pour un patient.   | \n");
	printf("+=========================================+ \n");
	printf("| Entrez le nom d'un patient :            | \n");
	printf("+=========================================+ \n");
	scanf("%20s", patient);
	for (changement = 0; patient[changement]; changement++){
		patient[changement] = tolower(patient[changement]);
	}
	
	lecturePatient();
	
	// Affichage d'un tableau plus parlant
	printf("+====+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");
	printf("| ID | Num. reg. national |         Nom          |        Prenom        | Date de nais. | Genre |             Rue              | Num |           Ville           |  CP   | Pays |   Num. Tel.    |   %% Remboursement   | \n");
	printf("+====+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");
	
	// Parcours pour trouver les personnes correspondantes
	courantPatient=debPatient;
	while(courantPatient->suivant != NULL)
	{		
		strcpy(courantPatient->tri, courantPatient->nom);
		for (changement = 0; courantPatient->tri[changement]; changement++){
			courantPatient->tri[changement] = tolower(courantPatient->tri[changement]);
		}
		if (strcmp(patient, courantPatient->tri) == 0){
			printf("| %2d |  %-15s   | %-20s | %-20s |  %-11s  |   %-1s   |%-30s| %3s | %-25s | %-5s |  %-3s | %-14s | %-3s%% de la mutuelle |\n",  nPatient, courantPatient->numRegNat, courantPatient->nom, courantPatient->prenom, courantPatient->dateNais, courantPatient->genre, courantPatient->rue, courantPatient->num, courantPatient->ville, courantPatient->codePostal, courantPatient->pays, courantPatient->numeroTel, courantPatient->pourRemb);
			printf("+----+--------------------+----------------------+----------------------+---------------+-------+------------------------------+-----+---------------------------+-------+------+----------------+---------------------+ \n");
			
			// Si supérieur à 1, alors il faut choisir en suivant les ID
			unique = unique + 1;
			if (unique == 1){
				idASupprimer = nPatient;
				strcpy(nom, courantPatient->nom);
				strcpy(prenom, courantPatient->prenom);
			}
		}
		courantPatient = courantPatient->suivant;
		nPatient++;	
	}
	strcpy(courantPatient->tri, courantPatient->nom);
	for (changement = 0; courantPatient->tri[changement]; changement++){
		courantPatient->tri[changement] = tolower(courantPatient->tri[changement]);
	}
	if (strcmp(patient, courantPatient->tri) == 0 && courantPatient->suivant == NULL){
		printf("| %2d |  %-15s   | %-20s | %-20s |  %-11s  |   %-1s   |%-30s| %3s | %-25s | %-5s |  %-3s | %-14s | %-3s%% de la mutuelle |\n",  nPatient, courantPatient->numRegNat, courantPatient->nom, courantPatient->prenom, courantPatient->dateNais, courantPatient->genre, courantPatient->rue, courantPatient->num, courantPatient->ville, courantPatient->codePostal, courantPatient->pays, courantPatient->numeroTel, courantPatient->pourRemb);
		printf("+----+--------------------+----------------------+----------------------+---------------+-------+------------------------------+-----+---------------------------+-------+------+----------------+---------------------+ \n");
		unique = unique + 1;
		if (unique == 1){
			idASupprimer = nPatient;
			strcpy(nom, courantPatient->nom);
			strcpy(prenom, courantPatient->prenom);
		}
	}
	
	if (unique == 0){
		system("cls");
		printf("+=========================================+ \n");
		printf("| Le patient n'existe pas.                | \n");
		printf("| Annulation de la prise de rendez-vous.  | \n");
		printf("+=========================================+ \n");
		printf("\n");
		system("pause");
	} else if (unique == 1){
		printf("+=========================================+ \n");
		printf("| Le patient sera ajouté au rendez-vous.  | \n");
		printf("| Quel médecin voulez-vous assigner ?     | \n");
		printf("+=========================================+ \n");
	} else if (unique > 1){
		printf("+=========================================+ \n");
		printf("| Quelle est l'ID du patient à ajouter ?  | \n");
		printf("+=========================================+ \n");
		scanf("%2d", &idASupprimer);	
				
		// Parcours pour trouver la personne correspondante
		nPatient = 1;
		courantPatient=debPatient;
		while(courantPatient->suivant != NULL)
		{
			if(nPatient == idASupprimer){
				strcpy(nom, courantPatient->nom);
				strcpy(prenom, courantPatient->prenom);
				break;
			}	
			courantPatient = courantPatient->suivant;
			nPatient++;
		}						
	}	

	if (unique != 0){
		lecturePersonnel();
		nPersonnel = 1;
		
		printf("+======+=====================+======================+======================+==================+===============+ \n");
		printf("|  ID  |        Nom          |       Prenom         |      Specialite      |    CodeInami     | Num.Telephone |\n");
		printf("+======+=====================+======================+======================+==================+===============+ \n");
		
		// Parcours pour trouver les personnes correspondantes
		courantPersonnel=debPersonnel;
		while(courantPersonnel->suivant != NULL)
		{
			strcpy(courantPersonnel->tri, courantPersonnel->specialite);
			for (changement = 0; courantPatient->tri[changement]; changement++){
				courantPatient->tri[changement] = tolower(courantPatient->tri[changement]);
			}
			if ((strcmp(debJournee->specialite, courantPersonnel->tri) == 0) && (strcmp(courantPersonnel->etat, "1") == 0)){
				printf("| %2d   | %-20s| %-20s | %-20s | %-14s   | %-14s|\n", nPersonnel, courantPersonnel->nom, courantPersonnel->prenom, courantPersonnel->specialite, courantPersonnel->codeInami, courantPersonnel->numeroTel);
				printf("+======+=====================+======================+======================+==================+===============+ \n");
			
				unique = unique + 1;
				if (unique == 1){
					idASupprimer = nPersonnel;
					strcpy(medEnCharge, courantPersonnel->nom);
				}
			}
			courantPersonnel = courantPersonnel->suivant;
			nPersonnel++;
		}
		if (strcmp(debJournee->specialite, courantPersonnel->tri) == 0 && courantPersonnel->suivant == NULL && (strcmp(courantPersonnel->etat, "1") == 0)){
			printf("| %2d   | %-20s| %-20s | %-20s | %-14s   | %-14s|\n", nPersonnel, courantPersonnel->nom, courantPersonnel->prenom, courantPersonnel->specialite, courantPersonnel->codeInami, courantPersonnel->numeroTel);
			printf("+======+=====================+======================+======================+==================+===============+ \n");
			unique++;
			if (unique == 1){
				idASupprimer = nPersonnel;
				strcpy(medEnCharge, courantPersonnel->nom);
			}
		}
		
		printf("+=========================================+ \n");
		printf("| Quelle est l'ID du médecin à ajouter ?  | \n");
		printf("+=========================================+ \n");
		scanf("%2d", &idASupprimer);	
		
		nPersonnel = 1;
		courantPersonnel=debPersonnel;
		while(courantPersonnel->suivant != NULL)
		{
			if(nPersonnel == idASupprimer){
				strcpy(medEnCharge, courantPersonnel->nom);
				break;
			}	
			courantPersonnel = courantPersonnel->suivant;
			nPersonnel++;
		}
		printf("\n");
			
		// Déclaration des "FONCTIONS" de temps (permettant notamment de trouver la date actuelle) (intégrées dans C via time.h)
		system("cls");
		printf("+=========================================+ \n");
		printf("| Listes des rendez-vous de ce jour :     | \n");
		printf("+=========================================+ \n");
		for (y = 1; y < 17; y++){
			if (strcmp(debJournee->medecin[moisADD][jourADD][y], "/") == 0){
				printf("| %2d |   %5s                            |\n", y, debJournee->heures[y]);
				printf("+=========================================+ \n");
			}
		}
		printf("+=========================================+ \n");
		printf("| A quelle heure faut-il l'ajouter ? (XX) | \n");
		printf("+=========================================+ \n");
		scanf("%2d", &unique);
		if (unique > 0 && unique < 17){
			strcpy(debJournee->medecin[moisADD][jourADD][unique], medEnCharge);
			strcpy(debJournee->patient[moisADD][jourADD][unique], nom);
		} else {
			printf("+=========================================+ \n");
			printf("| Erreur, annulation de l'opération.      | \n");
			printf("+=========================================+ \n");
		}
		
		system("cls");
		ecritureJournee(specialite);
	} else {
		system("cls");
		affichageMenuRdvCM();
	}
}

// Supprimer un rendez-vous
supprimerRdvHeader(){
	void ecritureJournee(int);
	int  y;	
	system("cls");
	printf("+=========================================+ \n");
	printf("| Listes des rendez-vous de ce jour :     | \n");
	printf("+=========================================+ \n");
	for (y = 1; y < 17; y++){
		if (strcmp(debJournee->medecin[moisADD][jourADD][y], "/") != 0){
			printf("| %2d |   %5s                            |\n", y, debJournee->heures[y]);
			printf("+=========================================+ \n");
		}
	}
	
	printf("+=========================================+ \n");
	printf("| A quelle heure faut-il supprimer ? (XX)  | \n");
	printf("+=========================================+ \n");
	scanf("%2d", &unique);
	if (unique > 0 && unique < 17){
		strcpy(debJournee->medecin[moisADD][jourADD][unique], "/");
		strcpy(debJournee->patient[moisADD][jourADD][unique], "/");
	} else {
		printf("+=======================================+ \n");
		printf("| Erreur, annulation de l'opération.    | \n");
		printf("+=======================================+ \n");
	}
	
	system("cls");
		
	ecritureJournee(specialite);
}

mutaliteRdvHeader(){
	void lecturePatient();
	void affichageMenuRdvCM();
	int  y, valrmb;	
	char nom[21], patient[21];
	char med[4], pat[4];
	int choix;
	float resultat;
	
	system("cls");
	printf("+=========================================+ \n");
	printf("| Listes des rendez-vous de ce jour :     | \n");
	printf("+=========================================+ \n");
	for (y = 1; y < 17; y++){
		if (strcmp(debJournee->medecin[moisADD][jourADD][y], "/") != 0){
			printf("| %2d |   %5s                            |\n", y, debJournee->heures[y]);
			printf("+=========================================+ \n");
		}
	}
	
	printf("+=========================================+ \n");
	printf("| La mutualité pour quel rendez-vous ?    | \n");
	printf("+=========================================+ \n");
	scanf("%2d", &choix);
	if (choix > 0 && choix < 17){
	unique = 0;
			
	lecturePatient();
	
	strcpy(patient, debJournee->patient[moisADD][jourADD][choix]);
	for (changement = 0; patient[changement]; changement++){
		patient[changement] = tolower(patient[changement]);
	}
	
	// Affichage d'un tableau plus parlant
	printf("+====+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");
	printf("| ID | Num. reg. national |         Nom          |        Prenom        | Date de nais. | Genre |             Rue              | Num |           Ville           |  CP   | Pays |   Num. Tel.    |   %% Remboursement   | \n");
	printf("+====+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");
	
	// Parcours pour trouver les personnes correspondantes
	courantPatient=debPatient;
	while(courantPatient->suivant != NULL)
	{		
		strcpy(courantPatient->tri, courantPatient->nom);
		for (changement = 0; courantPatient->tri[changement]; changement++){
			courantPatient->tri[changement] = tolower(courantPatient->tri[changement]);
		}
		if (strcmp(patient, courantPatient->tri) == 0){
			printf("| %2d |  %-15s   | %-20s | %-20s |  %-11s  |   %-1s   |%-30s| %3s | %-25s | %-5s |  %-3s | %-14s | %-3s%% de la mutuelle |\n",  nPatient, courantPatient->numRegNat, courantPatient->nom, courantPatient->prenom, courantPatient->dateNais, courantPatient->genre, courantPatient->rue, courantPatient->num, courantPatient->ville, courantPatient->codePostal, courantPatient->pays, courantPatient->numeroTel, courantPatient->pourRemb);
			printf("+----+--------------------+----------------------+----------------------+---------------+-------+------------------------------+-----+---------------------------+-------+------+----------------+---------------------+ \n");
			
			// Si supérieur à 1, alors il faut choisir en suivant les ID
			unique = unique + 1;
			if (unique == 1){
				idASupprimer = nPatient;
				strcpy(nom, courantPatient->nom);
				valrmb = atoi(courantPatient->pourRemb);
			}
		}
		courantPatient = courantPatient->suivant;
		nPatient++;	
	}
	strcpy(courantPatient->tri, courantPatient->nom);
	for (changement = 0; courantPatient->tri[changement]; changement++){
		courantPatient->tri[changement] = tolower(courantPatient->tri[changement]);
	}
	if (strcmp(patient, courantPatient->tri) == 0 && courantPatient->suivant == NULL){
		printf("| %2d |  %-15s   | %-20s | %-20s |  %-11s  |   %-1s   |%-30s| %3s | %-25s | %-5s |  %-3s | %-14s | %-3s%% de la mutuelle |\n",  nPatient, courantPatient->numRegNat, courantPatient->nom, courantPatient->prenom, courantPatient->dateNais, courantPatient->genre, courantPatient->rue, courantPatient->num, courantPatient->ville, courantPatient->codePostal, courantPatient->pays, courantPatient->numeroTel, courantPatient->pourRemb);
		printf("+----+--------------------+----------------------+----------------------+---------------+-------+------------------------------+-----+---------------------------+-------+------+----------------+---------------------+ \n");
		unique = unique + 1;
		if (unique == 1){
			idASupprimer = nPatient;
			strcpy(nom, courantPatient->nom);
			valrmb = atoi(courantPatient->pourRemb);
		}
	}
	
	if (unique == 1){
		for (changement = 0; changement < 3; changement++){
			med[changement] = toupper(debJournee->medecin[moisADD][jourADD][choix][changement]);
			pat[changement] = toupper(debJournee->patient[moisADD][jourADD][choix][changement]);
		}
			
		system("cls");
		printf("+=========================================+ \n");
		printf("| Le code de la mutualité est :           | \n");
		printf("| %3s.%3s-%02d.%02d                           | \n", med, pat, jourADD, moisADD);
		printf("| Montant d'une visite : 21€              | \n");
		printf("| Montant du remboursement : %3d%%         | \n", valrmb);
		resultat = (((float) 21 * (float) valrmb) / (float) 100);
		printf("| Montant du remboursement : %5.2f €      | \n", resultat);
		resultat = (float) 21 - (((float) 21 * (float) valrmb) / (float) 100);
		printf("| A payer : %5.2f €                       | \n", resultat);
		printf("+=========================================+ \n");
		system("pause");
	} else if (unique > 1){
		printf("+=========================================+ \n");
		printf("| Quelle est l'ID du patient à vérifier ?  | \n");
		printf("+=========================================+ \n");
		scanf("%2d", &idASupprimer);	
				
		// Parcours pour trouver la personne correspondante
		nPatient = 1;
		courantPatient=debPatient;
		while(courantPatient->suivant != NULL)
		{
			if(nPatient == idASupprimer){
				strcpy(nom, courantPatient->nom);
				break;
			}	
			courantPatient = courantPatient->suivant;
			nPatient++;
		}
		
		
		for (changement = 0; changement < 3; changement++){
			med[changement] = toupper(debJournee->medecin[moisADD][jourADD][choix][changement]);
			pat[changement] = toupper(debJournee->patient[moisADD][jourADD][choix][changement]);
		}
	
		float resultat;
	
		system("cls");
		printf("+=========================================+ \n");
		printf("| Le code de la mutualité est :           | \n");
		printf("| %3s.%3s-%02d.%02d                           | \n", med, pat, jourADD, moisADD);
		printf("| Montant d'une visite : 21€              | \n");
		printf("| Montant du remboursement : %3d%%         | \n", valrmb);
		resultat = (((float) 21 * (float) valrmb) / (float) 100);
		printf("| Montant du remboursement : %5.2f €      | \n", resultat);
		resultat = (float) 21 - (((float) 21 * (float) valrmb) / (float) 100);
		printf("| A payer : %5.2f €                       | \n", resultat);
		printf("+=========================================+ \n");
		system("pause");					
	}
		
	} else {
		printf("+=======================================+ \n");
		printf("| Erreur, annulation de l'opération.    | \n");
		printf("+=======================================+ \n");
	}
	
	system("cls");
	affichageMenuRdvCM();
}

#endif
