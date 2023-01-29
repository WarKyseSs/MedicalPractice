#ifndef DANAZARETRUBINOMODIFIER_H
#define DANAZARETRUBINOMODIFIER_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Globale
int changement;

// PARTIE PERSONNEL
// ****************
// MODIFICATION
void modificationPersonnel(){
	int choix = -1;
	
	while (choix != 0){
		system("cls");
		printf("+================================================+ \n");
		printf("| Page d'information sur le personnel à modifier | \n");
		printf("+================================================+ \n");
		printf("|    Les informations dotées d'une astérix ne    | \n|             peuvent être modifiées             | \n");
		printf("+================================================+ \n");
		printf("| 1.                   Nom : %-20s| \n", courantPersonnel->nom);
		printf("| 2.                Prénom : %-20s| \n", courantPersonnel->prenom);
		printf("| 3.            Spécialité : %-20s| \n", courantPersonnel->specialite);
		printf("| 4.   Numéro de téléphone : %-14s      | \n", courantPersonnel->numeroTel);
		printf("| 5.                  Etat : %1s                   | \n", courantPersonnel->etat);
		printf("+------------------------------------------------+ \n");
		printf("| *.                 Genre : %1s                   | \n", courantPersonnel->genre);
		printf("| *.                  Pays : %-3s                 | \n", courantPersonnel->pays);
		printf("| *.                 INAMI : %-14s      | \n", courantPersonnel->codeInami);
		printf("+------------------------------------------------+ \n");
		printf("| 0.                  Quitter                    |\n");
		printf("+================================================+ \n\n");
		printf("Entrez le numéro de l'information à modifier : ");
		scanf("%d", &choix);
		
		while (choix < 0 || choix > 5){
			printf("Veuillez entrer un numéro correct. Numéro : ");
			scanf("%d", &choix);
		}
		
		switch (choix){
			case 0: printf("Retour au menu.\n"); choix = 0; break;
			case 1: printf("Modification du nom : "); gets(courantPatient->nom); gets(courantPatient->nom); break;
			case 2: printf("Modification du prénom : "); gets(courantPatient->prenom); gets(courantPatient->prenom); break;
			case 3: printf("Modification de la spécialité : "); scanf("%s", courantPersonnel->specialite); break;
			case 4: printf("Modification du numéro de téléphone (04XX/XX.XX.XX) : "); scanf("%s", courantPersonnel->numeroTel); break;
			case 5: printf("Modification de l'état' (1 : en service, 2 : en congé, 3 : en maladie):  "); scanf("%s", courantPersonnel->etat); break;
			default : printf("Erreur."); choix = 0; break;
		}
	}
}

modifierPersonnelHeader(){
	void modificationPersonnel();
	void listePersonnel(int);
	void lecturePersonnel();
	void ecriturePersonnel();
	void affichageMenuPersonnelCM();
	lecturePersonnel();
	
	// Ouverture du même fichier pour l'écriture
	fdatPersonnel = fopen("ressource/DaNazaretRubinoPersonnels.dat","w");
		
	listePersonnel(2);
	
	// Si une seule correspondance, demande de confirmation pour cett personne
	printf("%2d", unique);
	if (unique == 1){
		printf("Voulez-vous modifier le personnel ID %2d ? \n", idASupprimer);
		printf("Répondre par OUI (O) ou NON (N) : ");
		scanf("%3s", choixSupp);
		for (changement = 0; choixSupp[changement]; changement++){
			choixSupp[changement] = tolower(choixSupp[changement]);
		}
		
		// Si d'accord
		if (strcmp(choixSupp, "o") == 0 || strcmp(choixSupp, "oui") == 0){
			precedentPersonnel = debPersonnel;
			courantPersonnel=debPersonnel;
			while(courantPersonnel->suivant != NULL)
			{
				intercalePersonnel = courantPersonnel->suivant;
				if ((strcmp(personne, courantPersonnel->tri) == 0)){
					modificationPersonnel();
					break;
				} 
				precedentPersonnel = courantPersonnel;
				courantPersonnel = courantPersonnel->suivant;
			}
			// Dernier élément de la liste
			if ((strcmp(personne, courantPersonnel->tri) == 0) && courantPersonnel->suivant == NULL){
				modificationPersonnel();
			} 
			printf("Opération réalisé avec succès.\n");
			// system("pause");
		  // Si refus annulation
		} else if (strcmp(choixSupp, "n") == 0 || strcmp(choixSupp, "non") == 0){
			printf("Annulation de la modification.\n Retour au menu.\n");
			// system("pause");
			system("cls");
		} else {
			printf("Valeur encodée incorrecte.\nAnnulation de la modification.\n Retour au menu.\n");
			// system("pause");
			system("cls");
		}
		
	// Si plusieurs choix alors demande de confirmation du choix
	} else if (unique > 1) {
		printf("Quelle est l'ID du personne à modifier ? ");
		scanf("%2d", &idASupprimer);	
		
		printf("Voulez-vous modifier le personnel ID %2d ? \n", idASupprimer);
		
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
		
		if (strcmp(choixSupp, "o") == 0 || strcmp(choixSupp, "oui") == 0){
			precedentPersonnel = debPersonnel;
			courantPersonnel=debPersonnel;
			while(courantPersonnel->suivant != NULL)
			{
				intercalePersonnel = courantPersonnel->suivant;
				if (strcmp(personne, courantPersonnel->codeInami) == 0){
					modificationPersonnel();
					break;
				} 
				precedentPersonnel = courantPersonnel;
				courantPersonnel = courantPersonnel->suivant;
			}
			// Dernier élément de la liste
			if ((strcmp(personne, courantPersonnel->codeInami) == 0) && (courantPersonnel->suivant == 0)){
				modificationPersonnel();
			}
			printf("Opération réalisé avec succès.\n");
			// system("pause");
		} else if (strcmp(choixSupp, "N") == 0 || strcmp(choixSupp, "n") == 0 || strcmp(choixSupp, "NON") == 0 || strcmp(choixSupp, "Non") == 0 || strcmp(choixSupp, "non") == 0){
			printf("Annulation de la modification.\n Retour au menu.\n");
			// system("pause");
			system("cls");
			
		} else {
			printf("Valeur encodée incorrecte.\nAnnulation de la modification.\n Retour au menu.\n");
			// system("pause");
			system("cls");
		}
	} else if (unique == 0){
		printf("+================================+ \n");
		printf("| Aucun résultat, retour au menu | \n");
		printf("+================================+ \n");
		// system("pause");
	}

	// Ecriture dans le fichier
	ecriturePersonnel();	
	
	system("cls");

	affichageMenuPersonnelCM();
}

// PARTIE PATIENT
// ****************
// MODIFICATION
void modificationPatient(){
	int choix = -1;

	while (choix != 0){
		system("cls");
		printf("+================================================+ \n");
		printf("|  Page d'information sur le patient à modifier  | \n");
		printf("+================================================+ \n");
		printf("|    Les informations dotées d'une astérix ne    | \n|             peuvent être modifiées             | \n");
		printf("+================================================+ \n");
		printf("| 1.          Nom : %-20s         | \n", courantPatient->nom);
		printf("| 2.       Prénom : %-20s         | \n", courantPatient->prenom);
		printf("| 3.    Téléphone : %-14s               | \n", courantPatient->numeroTel);
		printf("| 4.          Rue :%-30s| \n", courantPatient->rue);
		printf("| 5.       Numéro : %-3s                          | \n", courantPatient->num);
		printf("| 6.        Ville : %-25s    | \n", courantPatient->ville);
		printf("| 7.  Code postal : %-5s                        | \n", courantPatient->codePostal);
		printf("| 8.         Pays : %-3s                          | \n", courantPatient->pays);
		printf("| 9.    Remb.mut. : %-3s%%                         | \n", courantPatient->pourRemb);
		printf("+------------------------------------------------+ \n");
		printf("| *.  Date Naiss. : %-10s                   | \n", courantPatient->dateNais);
		printf("| *.        Genre : %-1s                            | \n", courantPatient->genre);
		printf("| *. Num.Reg.Nat. : %-15s              | \n", courantPatient->numRegNat);
		printf("+------------------------------------------------+ \n");
		printf("| 0.                  Quitter                    |\n");
		printf("+================================================+ \n\n");
		
		printf("Entrez le numéro de l'information à modifier : ");
		scanf("%d", &choix);
		
		while (choix < 0 || choix > 9){
			printf("Veuillez entrer un numéro correct. Numéro : ");
			scanf("%d", &choix);
		}
		
		switch (choix){
			case 0: printf("Retour au menu.\n"); choix = 0; break;
			case 1: printf("Modification du nom : "); gets(courantPatient->nom); gets(courantPatient->nom); break;
			case 2: printf("Modification du prénom : "); gets(courantPatient->prenom); gets(courantPatient->prenom); ; break;
			case 3: printf("Modification du numéro de téléphone (04XX/XX.XX.XX) : "); scanf("%s", courantPatient->numeroTel); break;
			case 4: printf("Modification de la rue : "); /*scanf("%s", courantPatient->rue);*/ gets(courantPatient->rue); gets(courantPatient->rue); break;
			case 5: printf("Modification du numéro de rue : "); scanf("%s", courantPatient->num); break;
			case 6: printf("Modification de la ville : "); scanf("%s", courantPatient->ville); break;
			case 7: printf("Modification du code postal : "); scanf("%s", courantPatient->codePostal); break;
			case 8: printf("Modification du pays : "); scanf("%s", courantPatient->pays); break;
			case 9: printf("Modification du montant de remboursement : "); scanf("%s", courantPatient->pourRemb); break;			
			default : printf("Erreur."); choix = 0; break;
		}
	}
}

modifierPatientHeader(){
	void modificationPatient();
	void lecturePatient();
	void listePatients(int);
	void ecriturePatient();
	void affichageMenuPatientsCM();
	lecturePatient();
	
	// Ouverture du même fichier pour l'écriture
	fdatPatient = fopen("ressource/DaNazaretRubinoPatients.dat","w");
	
	listePatients(2);
	
	// Si une seule correspondance, demande de confirmation pour cett personne
	if (unique == 1){
		printf("Voulez-vous modifier le personnel ID %2d ? \n", idASupprimer);
		printf("Répondre par OUI (O) ou NON (N) : ");
		scanf("%3s", choixSupp);
		for (changement = 0; choixSupp[changement]; changement++){
			choixSupp[changement] = tolower(choixSupp[changement]);
		}
		
		// Si d'accord
		if (strcmp(choixSupp, "o") == 0 || strcmp(choixSupp, "oui") == 0){
			precedentPatient = debPatient;
			courantPatient=debPatient;
			while(courantPatient->suivant != NULL)
			{
				intercalePatient = courantPatient->suivant;
				if (strcmp(personne, courantPatient->tri) == 0){
					modificationPatient();
					break;
				} 
				precedentPatient = courantPatient;
				courantPatient = courantPatient->suivant;
			}
			if ((strcmp(personne, courantPatient->tri) == 0) && courantPatient->suivant == NULL){
				modificationPatient();
			} 
			printf("Opération réalisé avec succès.\n");
			// system("pause");
			
		  // Si refus annulation
		} else if (strcmp(choixSupp, "n") == 0 || strcmp(choixSupp, "non") == 0){
			printf("Annulation de la modification.\n Retour au menu.\n");
			// system("pause");
			system("cls");
			
		} else {
			printf("Valeur encodée incorrecte.\nAnnulation de la modification.\n Retour au menu.\n");
			// system("pause");
			system("cls");
		}
	// Si plusieurs choix alors demande de confirmation du choix
	} else if (unique > 1) {
		printf("Quelle est l'ID du patient à modifier ? ");
		scanf("%2d", &idASupprimer);	
		
		printf("Voulez-vous modifier le patient ID %2d ? \n", idASupprimer);
		
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
		
		if (strcmp(choixSupp, "o") == 0 || strcmp(choixSupp, "oui") == 0){
			precedentPatient = debPatient;
			courantPatient=debPatient;
			while(courantPatient->suivant != NULL)
			{
				intercalePatient = courantPatient->suivant;
				if (strcmp(personne, courantPatient->numRegNat) == 0){
					modificationPatient();
					break;
				} 
				precedentPatient = courantPatient;
				courantPatient = courantPatient->suivant;
			}
			// Dernier élément de la liste
			if ((strcmp(personne, courantPatient->numRegNat) == 0) && (courantPatient->suivant == 0)){
				modificationPatient();
			}
			
			printf("Opération réalisé avec succès.\n");
			// system("pause");
		} else if (strcmp(choixSupp, "n") == 0 || strcmp(choixSupp, "non") == 0){
			printf("Annulation de la modification.\n Retour au menu.\n");
			// system("pause");
			system("cls");
			
		} else {
			printf("Valeur encodée incorrecte.\nAnnulation de la modification.\n Retour au menu.\n");
			// system("pause");
			system("cls");
		}
	} else if (unique == 0){
		printf("Aucun résultat, retour au menu.\n");
		// system("pause");
	}

	// Ecriture dans le fichier
	ecriturePatient();
	
	system("cls");
	
	affichageMenuPatientsCM();
}

#endif
