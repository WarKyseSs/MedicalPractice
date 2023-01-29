#ifndef DANAZARETRUBINOLISTES_H
#define DANAZARETRUBINOLISTES_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Globale
int nbPage = 1, total = 0;
int changement;
int nPersonnel = 1;
int nPatient = 1;
int unique = 0, idASupprimer = 0;
char personne[21];
char choixSupp[4];

typedef struct page
{	int nbPage;
	struct page *suivant, *precedent;
	struct personnel *precedentID;
	struct patient *precedentIDP;
} page;
page *liste, *prPage, *pageSuivante, *pagePrecedent;

void listePersonnel(int code){
	int i = 1;
	char choixPage[2];
	void listePersonnelChoix();
	unique = 0;
	nPersonnel = 0;
	// Initialisation des pages
	liste = malloc(sizeof(page));
	liste->nbPage = nbPage;
	liste->suivant = NULL;
	liste->precedent = NULL;
	liste->precedentID = debPersonnel;
	prPage = liste;

	printf("+=====================+======================+======================+==================+===============+ \n");
	printf("|        Nom          |       Prenom         |      Specialite      |    CodeInami     | Num.Telephone |\n");
	printf("+=====================+======================+======================+==================+===============+ \n");
	
	courantPersonnel = debPersonnel;
	nouveauPersonnel = courantPersonnel->suivant;
	while(courantPersonnel->suivant != NULL)
	{
		printf("| %-20s| %-20s | %-20s | %-14s   | %-14s|\n", courantPersonnel->nom, courantPersonnel->prenom, courantPersonnel->specialite, courantPersonnel->codeInami, courantPersonnel->numeroTel);
		printf("+---------------------+----------------------+----------------------+------------------+---------------+ \n");
		if(nouveauPersonnel->suivant == NULL){
			courantPersonnel = courantPersonnel->suivant;
			printf("| %-20s| %-20s | %-20s | %-14s   | %-14s|\n", courantPersonnel->nom, courantPersonnel->prenom, courantPersonnel->specialite, courantPersonnel->codeInami, courantPersonnel->numeroTel);
			printf("+---------------------+----------------------+----------------------+------------------+---------------+ \n");
			i = 10;
		} else {
			courantPersonnel = courantPersonnel->suivant;
			nouveauPersonnel = courantPersonnel->suivant;
		}
		
		if ((i % 10) == 0){
			if (code == 1){
				if (courantPersonnel->suivant != NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P) - suivante (S)\n");
					printf("Choisir l'employé à retirer (M)\n");
					printf("Quitter (Q)\n");
					scanf("%s", choixPage);
				} else if (courantPersonnel->suivant == NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P)\n");
					printf("Choisir l'employé à retirer (M)\n");
					printf("Quitter (Q)\n");
					scanf("%s", choixPage);
				}
			} else if (code == 2){
				if (courantPersonnel->suivant != NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P) - suivante (S)\n");
					printf("Choisir l'employé à modifier (M)\n");
					printf("Quitter (Q)\n");
					scanf("%s", choixPage);
				} else if (courantPersonnel->suivant == NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P)\n");
					printf("Choisir l'employé à modifier (M)\n");
					printf("Quitter (Q)\n");
					scanf("%s", choixPage);
				}
			} else if (code == 3){
				if (courantPersonnel->suivant != NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P) - suivante (S)\n");
					printf("Changer tri (Q)\n");
					scanf("%s", choixPage);
				} else if (courantPersonnel->suivant == NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P)\n");
					printf("Changer tri (Q)\n");
					scanf("%s", choixPage);
				}
			}
			
			// Passage en minuscule
			for (changement = 0; choixPage[changement]; changement++){
				choixPage[changement] = tolower(choixPage[changement]);
			}	
				
			if ((strcmp(choixPage, "s") == 0) && courantPersonnel->suivant != NULL){
				pageSuivante = malloc(sizeof(page));
				
							
				if (liste->suivant == NULL){
					nbPage++;
					liste->suivant = pageSuivante;
					pageSuivante->nbPage = nbPage;
					pageSuivante->precedent = liste;
					pageSuivante->precedentID = courantPersonnel;
					pageSuivante->suivant = NULL;
				}
				
				liste = liste->suivant;	
				
				system("cls");
				
				if (code == 3){
					void triMenuPersonnel();
					triMenuPersonnel();
				}
				
				printf("+=====================+======================+======================+==================+===============+ \n");
				printf("|        Nom          |       Prenom         |      Specialite      |    CodeInami     | Num.Telephone | \n");
				printf("+=====================+======================+======================+==================+===============+ \n");
			} else if (strcmp(choixPage, "s") == 0 && courantPersonnel->suivant == NULL){
				liste = prPage;
				courantPersonnel = debPersonnel;
				nouveauPersonnel = courantPersonnel->suivant;
				
				system("cls");
				
				if (code == 3){
					void triMenuPersonnel();
					triMenuPersonnel();
				}
				
				printf("+=====================+======================+======================+==================+===============+ \n");
				printf("|        Nom          |       Prenom         |      Specialite      |    CodeInami     | Num.Telephone | \n");
				printf("+=====================+======================+======================+==================+===============+ \n");
			} else if (strcmp(choixPage, "p") == 0 && (liste != prPage || liste == prPage)){	
				i = 0;
				liste = prPage;
				courantPersonnel = debPersonnel;
				nouveauPersonnel = courantPersonnel->suivant;
				
				system("cls");
				
				if (code == 3){
					void triMenuPersonnel();
					triMenuPersonnel();
				}
				
				printf("+=====================+======================+======================+==================+===============+ \n");
				printf("|        Nom          |       Prenom         |      Specialite      |    CodeInami     | Num.Telephone | \n");
				printf("+=====================+======================+======================+==================+===============+ \n");
			} else if (strcmp(choixPage, "m") == 0){
				listePersonnelChoix(code);
				break;
			} else {
				// printf("Entrée incorrecte. Annulation");
				break;
			}	
		}
		i++;
	}
}

void listePersonnelChoix(int code){
	if (code == 1){
		// Demande du nom du personnel à supprimer
		printf("+===============================================+ \n");
		printf("|  Quelle est le nom du personnel à retirer  :  | \n");
		printf("+===============================================+ \n -> ");		
	} else if (code == 2){
		// Demande du nom du patient à modifier
		printf("+=============================================+ \n");
		printf("|  Quelle est le nom du patient à modifier :  | \n");
		printf("+=============================================+ \n -> ");
		
	}
	scanf("%20s", personne);
	for (changement = 0; personne[changement]; changement++){
		personne[changement] = tolower(personne[changement]);
	}		
	unique = 0;
	nPersonnel = 1;

	// Affichage d'un tableau plus parlant
	printf("+======+=====================+======================+======================+==================+===============+ \n");
	printf("|  ID  |        Nom          |       Prenom         |      Specialite      |    CodeInami     | Num.Telephone |\n");
	printf("+======+=====================+======================+======================+==================+===============+ \n");
	
	// Parcours pour trouver les personnes correspondantes
	courantPersonnel=debPersonnel;
	while(courantPersonnel->suivant != NULL)
	{
		strcpy(courantPersonnel->tri, courantPersonnel->nom);
		for (changement = 0; courantPersonnel->tri[changement]; changement++){
			courantPersonnel->tri[changement] = tolower(courantPersonnel->tri[changement]);
		}
		if (strcmp(personne, courantPersonnel->tri) == 0){
			printf("| %2d   | %-20s| %-20s | %-20s | %-14s  | %-14s|\n", nPersonnel, courantPersonnel->nom, courantPersonnel->prenom, courantPersonnel->specialite, courantPersonnel->codeInami, courantPersonnel->numeroTel);
			printf("+======+=====================+======================+======================+==================+===============+ \n");
			
			// Si supérieur à 1, alors il faut choisir en suivant les ID
			unique = unique + 1;
			if (unique == 1){
				idASupprimer = nPersonnel;
			}
		}
		courantPersonnel = courantPersonnel->suivant;
		nPersonnel++;	
	}
	for (changement = 0; courantPersonnel->nom[changement]; changement++){
		courantPersonnel->tri[changement] = tolower(courantPersonnel->nom[changement]);
	}
	if (strcmp(personne, courantPersonnel->nom) == 0){
		printf("| %2d   | %-20s| %-20s | %-20s | %-14s  | %-14s|\n", nPersonnel, courantPersonnel->nom, courantPersonnel->prenom, courantPersonnel->specialite, courantPersonnel->codeInami, courantPersonnel->numeroTel);
		printf("+======+=====================+======================+======================+==================+===============+ \n");
		unique++;
		if (unique == 1){
			idASupprimer = nPersonnel;
		}
	}		
}


// *******
// Patient
void listePatients(int code){
	int i = 1;
	char choixPage[2];
	void listePatientsChoix();
	unique = 0;
	nPatient = 1;
	
	// Initialisation des pages
	liste = malloc(sizeof(page));
	liste->nbPage = nbPage;
	liste->suivant = NULL;
	liste->precedent = NULL;
	liste->precedentIDP = debPatient;
	prPage = liste;

	printf("+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");
	printf("| Num. reg. national |         Nom          |        Prenom        | Date de nais. | Genre |             Rue              | Num |           Ville           |  CP   | Pays |   Num. Tel.    |   %% Remboursement   | \n");
	printf("+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");;
	
	courantPatient = debPatient;
	nouveauPatient = courantPatient->suivant;
	while(courantPatient->suivant != NULL)
	{
		printf("|  %-15s   | %-20s | %-20s |  %-11s  |   %-1s   |%-30s| %3s | %-25s | %-5s |  %-3s | %-14s | %-3s%% de la mutuelle |\n",  courantPatient->numRegNat, courantPatient->nom, courantPatient->prenom, courantPatient->dateNais, courantPatient->genre, courantPatient->rue, courantPatient->num, courantPatient->ville, courantPatient->codePostal, courantPatient->pays, courantPatient->numeroTel, courantPatient->pourRemb);
		printf("+--------------------+----------------------+----------------------+---------------+-------+------------------------------+-----+---------------------------+-------+------+----------------+---------------------+ \n");
		
		if(nouveauPatient->suivant == NULL){
			courantPatient = courantPatient->suivant;
			printf("|  %-15s   | %-20s | %-20s |  %-11s  |   %-1s   |%-30s| %3s | %-25s | %-5s |  %-3s | %-14s | %-3s%% de la mutuelle |\n",  courantPatient->numRegNat, courantPatient->nom, courantPatient->prenom, courantPatient->dateNais, courantPatient->genre, courantPatient->rue, courantPatient->num, courantPatient->ville, courantPatient->codePostal, courantPatient->pays, courantPatient->numeroTel, courantPatient->pourRemb);
			printf("+--------------------+----------------------+----------------------+---------------+-------+------------------------------+-----+---------------------------+-------+------+----------------+---------------------+ \n");
			i = 10;
		} else {
			courantPatient = courantPatient->suivant;
			nouveauPatient = courantPatient->suivant;
		}

		if ((i % 10) == 0){			
			if (code == 1){
				if (courantPatient->suivant != NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P) - suivante (S)\n");
					printf("Choisir le patient à retirer (M)\n");
					printf("Quitter (Q)\n");
					scanf("%s", choixPage);
				} else if (courantPatient->suivant == NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P)\n");
					printf("Choisir le patient à retirer (M)\n");
					printf("Quitter (Q)\n");
					scanf("%s", choixPage);
				}
			} else if (code == 2){
				if (courantPatient->suivant != NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P) - suivante (S)\n");
					printf("Choisir le patient à modifier (M)\n");
					printf("Quitter (Q)\n");
					scanf("%s", choixPage);
				} else if (courantPatient->suivant == NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P)\n");
					printf("Choisir le patient à modifier (M)\n");
					printf("Quitter (Q)\n");
					scanf("%s", choixPage);
				}
			} else if (code == 3){
				if (courantPatient->suivant != NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P) - suivante (S)\n");
					printf("Changer tri (Q)\n");
					scanf("%s", choixPage);
				} else if (courantPatient->suivant == NULL){
					printf("Numéro de page : %02d\n", liste->nbPage);
					printf("Première page (P)\n");
					printf("Changer tri (Q)\n");
					scanf("%s", choixPage);
				}
			}
			for (changement = 0; choixPage[changement]; changement++){
				choixPage[changement] = tolower(choixPage[changement]);
			}
					
			if ((strcmp(choixPage, "s") == 0) && courantPatient->suivant != NULL){
				pageSuivante = malloc(sizeof(page));
								
				if (liste->suivant == NULL){
					nbPage++;
					liste->suivant = pageSuivante;
					pageSuivante->nbPage = nbPage;
					pageSuivante->precedent = liste;
					pageSuivante->precedentIDP = courantPatient;
					pageSuivante->suivant = NULL;
				}

				liste = liste->suivant;	

				system("cls");

				if (code == 3){
					void triMenuPatients();
					triMenuPatients();
				}
				
				printf("+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");
				printf("| Num. reg. national |         Nom          |        Prenom        | Date de nais. | Genre |             Rue              | Num |           Ville           |  CP   | Pays |   Num. Tel.    |   %% Remboursement   | \n");
				printf("+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");
			} else if (strcmp(choixPage, "s") == 0 && courantPatient->suivant == NULL){
				i = 0;
				liste = prPage;
				courantPatient = debPatient;
				nouveauPatient = courantPatient->suivant;
				
				system("cls");
				
				if (code == 3){
					void triMenuPatients();
					triMenuPatients();
				}
				
				printf("+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");
				printf("| Num. reg. national |         Nom          |        Prenom        | Date de nais. | Genre |             Rue              | Num |           Ville           |  CP   | Pays |   Num. Tel.    |   %% Remboursement   | \n");
				printf("+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");
			} else if (strcmp(choixPage, "p") == 0 && (liste != prPage || liste == prPage)){
				i = 0;
				liste = prPage;
				courantPatient = debPatient;
				nouveauPatient = courantPatient->suivant;
				
				system("cls");
				
				if (code == 3){
					void triMenuPatients();
					triMenuPatients();
				}
				
				printf("+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");
				printf("| Num. reg. national |         Nom          |        Prenom        | Date de nais. | Genre |             Rue              | Num |           Ville           |  CP   | Pays |   Num. Tel.    |   %% Remboursement   | \n");
				printf("+====================+======================+======================+===============+=======+==============================+=====+===========================+=======+======+================+=====================+ \n");
			} else if (strcmp(choixPage, "m") == 0){
				listePatientsChoix(code);
				break;
			} else {
				break;
			}
		}
		i++;
	}
}

void listePatientsChoix(int code){
	if (code == 1){	
		// Demande du nom du personnel à supprimer
		printf("+=============================================+ \n");
		printf("|  Quelle est le nom du patient à retirer :   | \n");
		printf("+=============================================+ \n -> ");
	} else if (code == 2){
		// Demande du nom du patient à modifier
		printf("+=============================================+ \n");
		printf("|  Quelle est le nom du patient à modifier :  | \n");
		printf("+=============================================+ \n -> ");
	}	
	scanf("%20s", personne);
	for (changement = 0; personne[changement]; changement++){
		personne[changement] = tolower(personne[changement]);
	}
	unique = 0;
	nPatient = 1;
	
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
		if (strcmp(personne, courantPatient->tri) == 0){
			printf("| %2d |  %-15s   | %-20s | %-20s |  %-11s  |   %-1s   |%-30s| %3s | %-25s | %-5s |  %-3s | %-14s | %-3s%% de la mutuelle |\n",  nPatient, courantPatient->numRegNat, courantPatient->nom, courantPatient->prenom, courantPatient->dateNais, courantPatient->genre, courantPatient->rue, courantPatient->num, courantPatient->ville, courantPatient->codePostal, courantPatient->pays, courantPatient->numeroTel, courantPatient->pourRemb);
			printf("+----+--------------------+----------------------+----------------------+---------------+-------+------------------------------+-----+---------------------------+-------+------+----------------+---------------------+ \n");
			
			// Si supérieur à 1, alors il faut choisir en suivant les ID
			unique = unique + 1;
			if (unique == 1){
				idASupprimer = nPatient;
			}
		}
		courantPatient = courantPatient->suivant;
		nPatient++;	
	}
	strcpy(courantPatient->tri, courantPatient->nom);
	for (changement = 0; courantPatient->tri[changement]; changement++){
		courantPatient->tri[changement] = tolower(courantPatient->tri[changement]);
	}
	if (strcmp(personne, courantPatient->tri) == 0 && courantPatient->suivant == NULL){
		printf("| %2d |  %-15s   | %-20s | %-20s |  %-11s  |   %-1s   |%-30s| %3s | %-25s | %-5s |  %-3s | %-14s | %-3s%% de la mutuelle |\n",  nPatient, courantPatient->numRegNat, courantPatient->nom, courantPatient->prenom, courantPatient->dateNais, courantPatient->genre, courantPatient->rue, courantPatient->num, courantPatient->ville, courantPatient->codePostal, courantPatient->pays, courantPatient->numeroTel, courantPatient->pourRemb);
		printf("+----+--------------------+----------------------+----------------------+---------------+-------+------------------------------+-----+---------------------------+-------+------+----------------+---------------------+ \n");
		unique = unique + 1;
		if (unique == 1){
			idASupprimer = nPatient;
		}
	}		
}
#endif
