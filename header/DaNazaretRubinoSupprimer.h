#ifndef DANAZARETRUBINOSUPPRIMER_H
#define DANAZARETRUBINOSUPPRIMER_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// PARTIE PERSONNEL
// ****************
// Fonction de suppression d'un Personnel
supprimerPersonnelHeader(){
	// Déclaration des fonctions
	void lecturePersonnel();
	void ecriturePersonnel();
	void affichageMenuPersonnelCM();
	void listePersonnel(int);
	lecturePersonnel();
	unique = 0;
	
	// Ouverture du même fichier pour l'écriture
	fdatPersonnel = fopen("ressource/DaNazaretRubinoPersonnels.dat","w");
	listePersonnel(1);
		
	// Si une seule correspondance, demande de confirmation pour cett personne
	if (unique == 1){
		printf("Voulez-vous supprimer le personnel ID %2d ? \n", idASupprimer);
		printf("Répondre par OUI (O) ou NON (N) : ");
		scanf("%3s", choixSupp);
		for (changement = 0; choixSupp[changement]; changement++){
			choixSupp[changement] = tolower(choixSupp[changement]);
		}
		
		// Si d'accord
		if (strcmp(choixSupp, "o") == 0 ||  strcmp(choixSupp, "oui") == 0){
			precedentPersonnel = debPersonnel;
			courantPersonnel = debPersonnel;
			while(courantPersonnel->suivant != NULL)
			{
				for (changement = 0; courantPersonnel->nom[changement]; changement++){
					courantPersonnel->tri[changement] = tolower(courantPersonnel->nom[changement]);
				}
				if ((strcmp(personne, courantPersonnel->tri) == 0) && (courantPersonnel == debPersonnel)){
					debPersonnel = debPersonnel->suivant;
					break;
				} else if ((strcmp(personne, courantPersonnel->tri) == 0) && (courantPersonnel->suivant != NULL)){
					precedentPersonnel->suivant = courantPersonnel->suivant;					
					break;
				} 
				precedentPersonnel = courantPersonnel;
				courantPersonnel = courantPersonnel->suivant;
			}
			for (changement = 0; courantPersonnel->nom[changement]; changement++){
				courantPersonnel->tri[changement] = tolower(courantPersonnel->nom[changement]);
			}
			// Dernier élément de la liste
			if ((strcmp(personne, courantPersonnel->tri) == 0) && (courantPersonnel->suivant == 0)){
				precedentPersonnel->suivant = NULL;
			} 
			printf("Opération réalisé avec succès.\n");
		  // Si refus annulation
		} else if (strcmp(choixSupp, "n")  || strcmp(choixSupp, "non") == 0){
			printf("Annulation de la suppression.\n Retour au menu.\n");
			system("cls");
		} else {
			printf("Valeur encodée incorrecte.\nAnnulation de la suppression.\n Retour au menu.\n");
			system("cls");
		}
		
	// Si plusieurs choix alors demande de confirmation du choix
	} else if (unique > 1) {
		printf("Quelle est l'ID du personne à retirer ? ");
		scanf("%2d", &idASupprimer);	
		
		printf("Voulez-vous supprimer le personnel ID %2d ? \n", idASupprimer);
		
		// Parcours pour trouver la personne correspondante
		nPersonnel = 1;
		courantPersonnel=debPersonnel;
		while(courantPersonnel->suivant != NULL)
		{
			if(nPersonnel == idASupprimer){
				strcpy(personne, courantPersonnel->codeInami);
				break;
			}	
			courantPersonnel = courantPersonnel->suivant;
			nPersonnel++;
		}		
		
		printf("Répondre par OUI (O) ou NON (N) : ");
		scanf("%3s", choixSupp);
		for (changement = 0; choixSupp[changement]; changement++){
			choixSupp[changement] = tolower(choixSupp[changement]);
		}
		
		if (strcmp(choixSupp, "o") == 0 ||  strcmp(choixSupp, "oui") == 0){
			precedentPersonnel = debPersonnel;
			courantPersonnel=debPersonnel;
			while(courantPersonnel->suivant != NULL)
			{
				intercalePersonnel = courantPersonnel->suivant;
				if ((strcmp(personne, courantPersonnel->codeInami) == 0) && (precedentPersonnel == debPersonnel)){
					debPersonnel = debPersonnel->suivant;
					break;
				} else if ((strcmp(personne, courantPersonnel->codeInami) == 0) && (courantPersonnel->suivant != NULL)){
					precedentPersonnel->suivant = courantPersonnel->suivant;					
					break;
				} 
				precedentPersonnel = courantPersonnel;
				courantPersonnel = courantPersonnel->suivant;
			}
			// Dernier élément de la liste
			if ((strcmp(personne, courantPersonnel->codeInami) == 0) && (courantPersonnel->suivant == 0)){
				precedentPersonnel->suivant = NULL;
			}
			printf("Opération réalisé avec succès.\n");
		} else if (strcmp(choixSupp, "n")  || strcmp(choixSupp, "non") == 0){
			printf("Annulation de la suppression.\n Retour au menu.\n");
			system("cls");			
		} else {
			printf("Valeur encodée incorrecte.\nAnnulation de la suppression.\n Retour au menu.\n");
			system("cls");
		}
	} else if (unique == 0){
		printf("Retour au menu.\n");
	}

	// Ecriture dans le fichier
	ecriturePersonnel();	
	
	system("cls");
	affichageMenuPersonnelCM();
}

// PARTIE PATIENT
// *************
// Suppresion d'un patient
supprimerPatientHeader(){
	void lecturePatient();
	void listePatients(int);
	void ecriturePatient();
	void affichageMenuPatientsCM();
	lecturePatient();
	
	// Ouverture du même fichier pour l'écriture
	fdatPatient = fopen("ressource/DaNazaretRubinoPatients.dat","w");
	
	listePatients(1);
	
	// Si une seule correspondance, demande de confirmation pour cett personne
	if (unique == 1){
		printf("Voulez-vous supprimer le personnel ID %2d ? \n", idASupprimer);
		printf("Répondre par OUI (O) ou NON (N) : ");
		scanf("%3s", choixSupp);
		for (changement = 0; choixSupp[changement]; changement++){
			choixSupp[changement] = tolower(choixSupp[changement]);
		}
		
		// Si d'accord
		if (strcmp(choixSupp, "o") == 0 ||  strcmp(choixSupp, "oui") == 0){
			precedentPatient = debPatient;
			courantPatient = debPatient;
			while(courantPatient->suivant != NULL)
			{
				for (changement = 0; courantPatient->nom[changement]; changement++){
					courantPatient->tri[changement] = tolower(courantPatient->nom[changement]);
				}
				if ((strcmp(personne, courantPatient->tri) == 0) && (courantPatient == debPatient)){
					debPatient = debPatient->suivant;
					break;
				} else if ((strcmp(personne, courantPatient->tri) == 0) && (courantPatient->suivant != NULL)){
					precedentPatient->suivant = courantPatient->suivant;					
					break;
				} 
				precedentPatient = courantPatient;
				courantPatient = courantPatient->suivant;
			}
			for (changement = 0; courantPatient->nom[changement]; changement++){
				courantPatient->tri[changement] = tolower(courantPatient->nom[changement]);
			}
			// Dernier élément de la liste
			if ((strcmp(personne, courantPatient->tri) == 0) && (courantPatient->suivant == 0)){
				precedentPatient->suivant = NULL;
			} 
			printf("Opération réalisé avec succès.\n");
			// system("pause");
			
		  // Si refus annulation
		} else if (strcmp(choixSupp, "n")  || strcmp(choixSupp, "non") == 0){
			printf("Annulation de la suppression.\n Retour au menu.\n");
			// system("pause");
			system("cls");
			
		} else {
			printf("Valeur encodée incorrecte.\nAnnulation de la suppression.\n Retour au menu.\n");
			// system("pause");
			system("cls");
		}
	// Si plusieurs choix alors demande de confirmation du choix
	} else if (unique > 1) {
		printf("Quelle est l'ID du personne à retirer ? ");
		scanf("%2d", &idASupprimer);	
		
		printf("Voulez-vous supprimer le personnel ID %2d ? \n", idASupprimer);
		
		// Parcours pour trouver la personne correspondante
		nPatient = 1;
		courantPatient=debPatient;
		while(courantPatient->suivant != NULL)
		{
			if(nPatient == idASupprimer){
				strcpy(personne, courantPatient->numRegNat);
				break;
			}	
			courantPatient = courantPatient->suivant;
			nPatient++;
		}		
		
		printf("Répondre par OUI (O) ou NON (N) : ");
		scanf("%3s", choixSupp);
		for (changement = 0; choixSupp[changement]; changement++){
			choixSupp[changement] = tolower(choixSupp[changement]);
		}
		
		if (strcmp(choixSupp, "o") == 0 ||  strcmp(choixSupp, "oui") == 0){
			precedentPatient = debPatient;
			courantPatient=debPatient;
			while(courantPatient->suivant != NULL)
			{
				intercalePatient = courantPatient->suivant;
				if ((strcmp(personne, courantPatient->numRegNat) == 0) && (precedentPatient == debPatient)){
					debPatient = debPatient->suivant;
					break;
				} else if ((strcmp(personne, courantPatient->numRegNat) == 0) && (courantPatient->suivant != NULL)){
					precedentPatient->suivant = courantPatient->suivant;					
					break;
				} 
				precedentPatient = courantPatient;
				courantPatient = courantPatient->suivant;
			}
			// Dernier élément de la liste
			if ((strcmp(personne, courantPatient->numRegNat) == 0) && (courantPatient->suivant == 0)){
				precedentPatient->suivant = NULL;
			}
			
			printf("Opération réalisé avec succès.\n");
		} else if (strcmp(choixSupp, "n")  || strcmp(choixSupp, "non") == 0){
			printf("Annulation de la suppression.\n Retour au menu.\n");
			system("cls");
		} else {
			printf("Valeur encodée incorrecte.\nAnnulation de la suppression.\n Retour au menu.\n");
			system("cls");
		}
	} else if (unique == 0){
		printf("Aucun résultat, retour au menu.\n");
	}

	// Ecriture dans le fichier
	ecriturePatient();
	system("cls");
	affichageMenuPatientsCM();
}
#endif
