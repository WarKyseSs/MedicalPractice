#ifndef DANAZARETRUBINOAJOUT_H
#define DANAZARETRUBINOAJOUT_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Variables - Déclaration
ajoutPersonnel ajoutPe;
ajoutPatient ajoutPa;

int changement;

// Fonction d'ajout d'un Personnel
void ajouterPersonnelHeader(){
	
	// Ouverture du fichier
	fdatPersonnel = fopen("ressource/DaNazaretRubinoPersonnels.dat","a");

	// Traitements et demandes à l'utilisateur des différentes informations pour l'ajout du médecin
	fgets(ajoutPe.test, 99, stdin);
	strcpy(ajoutPe.test, " ");
	
	printf("+=========================================+\n");
    printf("|*   Veuillez entrer les informations    *|\n");
    printf("+=========================================+\n");
	printf(" -> Saisissez le nom du medecin : ");
	fgets(ajoutPe.nom, 20, stdin);	
	
	for (changement = 0; ajoutPe.nom[changement]; changement++){
		if (ajoutPe.nom[changement] == '\n'){
			ajoutPe.nom[changement] = ajoutPe.test[0];
		}
	}
	printf("+-----------------------------------------+\n");
	
	printf(" -> Saisissez le prenom du medecin : ");
	fgets(ajoutPe.prenom, 20, stdin);
	for (changement = 0; ajoutPe.prenom[changement]; changement++){
		if (ajoutPe.prenom[changement] == '\n'){
			ajoutPe.prenom[changement] = ajoutPe.test[0];
		}
	}
	printf("+-----------------------------------------+\n");
	
	printf(" -> Saisissez sa specialite : ");
	scanf("%20s", ajoutPe.specialite);	
	int valide = 0, nSpe = 0;
	char specialite[6][45] = {
            "Urologue", 
            "Infirmiere", 
            "ORL",
            "Dentiste",
            "Generaliste"
    };

	for (nSpe = 0; nSpe < 6; nSpe++){
		if (strcmp(ajoutPe.specialite, specialite[nSpe]) == 0){
			valide = 1;
		}
	}
	
	while(valide == 0){
		for (nSpe = 0; nSpe < 6; nSpe++){
			if (strcmp(ajoutPe.specialite, specialite[nSpe]) == 0){
			valide = 1;
			break;
			}
		}
		if (valide == 0){
			printf("Veuillez entrer une spécialité existante : \n");
			scanf("%20s", ajoutPe.specialite);		
		}
	} 
	printf("+-----------------------------------------+\n");
	
	printf(" -> Saisissez le genre du medecin \n    (M - F) : ");
	scanf("%1s", ajoutPe.genre);
	while((strcmp(ajoutPe.genre,"M")!=0)&&(strcmp(ajoutPe.genre,"F")!=0)){
		printf("Le genre entré est incorrect : \n");
		printf(" -> Saisissez le genre du medecin \n    (M - F) : ");	
		scanf("%1s", ajoutPe.genre);
	} 
	printf("+-----------------------------------------+\n");
	
	printf(" -> Saisissez son code inami  \n    (X-XXXXX-XX-XXX) : ");
	scanf("%14s", ajoutPe.codeInami);
	printf("+-----------------------------------------+\n");
	
	printf(" -> Saisissez son pays d\'origine  \n    (BEL - FRA) : ");
	scanf("%3s", ajoutPe.pays);
	while((strcmp(ajoutPe.pays,"BEL")!=0)&&(strcmp(ajoutPe.pays,"FRA")!=0)){
		printf("Le pays entré est incorrect \n");
		printf(" -> Saisissez son pays d\'origine \n    (BEL - FRA) : ");	
		scanf("%3s", ajoutPe.pays);
	} 
	printf("+-----------------------------------------+\n");
	
	// Test permettant de d'afficher le bon exemple de numéro de téléphone en fonction du pays
	if(strcmp(ajoutPe.pays,"BEL")==0){
		printf(" -> Saisissez son numero de telephone : \n    (04XX/XX.XX.XX) : ");
	} else if(strcmp(ajoutPe.pays,"FRA")==0){
		printf(" -> Saisissez son numero de telephone : \n    (0X.XX.XX.XX.XX) : ");
	}
	scanf("%14s", ajoutPe.numeroTel);
	printf("+-----------------------------------------+\n");

	// On considère que lors d'un ajoute de médecin, celui-ci n'est pas malade, ni en vacances et est donc disponible 
	strcpy(ajoutPe.etat, "1");
	
	// Ajout du médecin dans le fichier de données
	fprintf(fdatPersonnel,"%-20s %-20s %-20s %-1s %-14s %-3s %-14s %-1s", ajoutPe.nom, ajoutPe.prenom, ajoutPe.specialite, ajoutPe.genre, ajoutPe.codeInami, ajoutPe.pays, ajoutPe.numeroTel, ajoutPe.etat);
	fprintf(fdatPersonnel, "\n");
	
	// Fermeture du fichier de données - Permettant d'ajouter dans le fichier de données sans devoir quitter le programme
	fclose(fdatPersonnel);
	system("cls");
	void affichageMenuPersonnelCM();
	affichageMenuPersonnelCM();
}

// Fonction d'ajout d'un Patient
void ajouterPatientHeader(){
	// Ouverture du fichier
	fdatPatient = fopen("ressource/DaNazaretRubinoPatients.dat","a");

	// Traitements et demandes à l'utilisateur des différentes informations pour l'ajout du patient
	fgets(ajoutPa.test, 99, stdin);
	strcpy(ajoutPa.test, " ");
	
	printf("+=========================================+\n");
    printf("|*   Veuillez entrer les informations    *|\n");
    printf("+=========================================+\n");
	printf(" -> Saisissez le nom du patient : ");
	gets(ajoutPa.nom);
	printf("+-----------------------------------------+\n");
	
	for (changement = 0; ajoutPa.nom[changement]; changement++){
		if (ajoutPa.nom[changement] == '\n'){
			ajoutPa.nom[changement] = ajoutPa.test[0];
		}
	}
	
	printf(" -> Saisissez le prenom du patient : ");
	gets(ajoutPa.prenom);
	printf("+-----------------------------------------+\n");
	for (changement = 0; ajoutPa.prenom[changement]; changement++){
		if (ajoutPa.prenom[changement] == '\n'){
			ajoutPa.prenom[changement] = ajoutPa.test[0];
		}
	}
	
	printf(" -> Saisissez sa date de naissance \n    (XX-XX-XXXX) : ");
	gets(ajoutPa.dateNais);
	for (changement = 0; ajoutPa.dateNais[changement]; changement++){
		if (ajoutPa.dateNais[changement] == '\n'){
			ajoutPa.dateNais[changement] = ajoutPa.test[0];
		}
	}
	printf("+-----------------------------------------+\n");
	
	printf(" -> Saisissez le genre du patient : ");
	gets(ajoutPa.genre);
	while((strcmp(ajoutPa.genre,"M")!=0)&&(strcmp(ajoutPa.genre,"F")!=0)){
		printf("Le genre entré est incorrect : \n");
		printf(" -> Saisissez le genre du patient \n    (M - F) : ");	
		scanf("%1s", ajoutPa.genre);
	} 
	for (changement = 0; ajoutPa.genre[changement]; changement++){
		if (ajoutPa.genre[changement] == '\n'){
			ajoutPa.genre[changement] = ajoutPa.test[0];
		}
	}
	printf("+-----------------------------------------+\n");

	printf(" -> Saisissez son pays d\'origine  \n    (BEL - FRA) : ");
	gets(ajoutPa.pays);
	while((strcmp(ajoutPa.pays,"BEL")!=0)&&(strcmp(ajoutPa.pays,"FRA")!=0)){
		printf("Le pays entré est incorrect : \n");
		printf(" -> Saisissez son pays d\'origine \n    (BEL - FRA) : ");	
		scanf("%1s", ajoutPa.pays);
	} 
	for (changement = 0; ajoutPa.pays[changement]; changement++){
		if (ajoutPa.pays[changement] == '\n'){
			ajoutPa.pays[changement] = ajoutPa.test[0];
		}
	}
	printf("+-----------------------------------------+\n");
	
	printf(" -> Saisissez sa rue : ");
	gets(ajoutPa.rue);
	for (changement = 0; ajoutPa.rue[changement]; changement++){
		if (ajoutPa.rue[changement] == '\n'){
			ajoutPa.rue[changement] = ajoutPa.test[0];
		}
	}
	printf("+-----------------------------------------+\n");
	
	printf(" -> Saisissez son numero de porte \n    (XXX) : ");
	gets(ajoutPa.num);
	for (changement = 0; ajoutPa.num[changement]; changement++){
		if (ajoutPa.num[changement] == '\n'){
			ajoutPa.num[changement] = ajoutPa.test[0];
		}
	}
	printf("+-----------------------------------------+\n");
	
	printf(" -> Saisissez sa ville : ");
	gets(ajoutPa.ville);
	for (changement = 0; ajoutPa.ville[changement]; changement++){
		if (ajoutPa.ville[changement] == '\n'){
			ajoutPa.ville[changement] = ajoutPa.test[0];
		}
	}
	printf("+-----------------------------------------+\n");
	
	// Test permettant de d'afficher le bon exemple de code postal en fonction du pays
	if(strcmp(ajoutPa.pays,"BEL")==0){
		printf(" -> Saisissez son code postal \n    (XXXX) :");
	} else if(strcmp(ajoutPa.pays,"FRA")==0){
		printf(" -> Saisissez son code postal \n    (XXXXX) :");
	}
	gets(ajoutPa.codePostal);	
	for (changement = 0; ajoutPa.codePostal[changement]; changement++){
		if (ajoutPa.codePostal[changement] == '\n'){
			ajoutPa.codePostal[changement] = ajoutPa.test[0];
		}
	}
	printf("+-----------------------------------------+\n");
	
	// Test permettant de d'afficher le bon exemple de numéro de téléphone en fonction du pays
	if(strcmp(ajoutPa.pays,"BEL")==0){
		printf(" -> Saisissez son numero de telephone : \n    (04XX/XX.XX.XX) : ");
	} else if(strcmp(ajoutPa.pays,"FRA")==0){
		printf(" -> Saisissez son numero de telephone : \n    (0X.XX.XX.XX.XX) : ");
	}
	gets(ajoutPa.numeroTel);
	for (changement = 0; ajoutPa.numeroTel[changement]; changement++){
		if (ajoutPa.numeroTel[changement] == '\n'){
			ajoutPa.numeroTel[changement] = ajoutPa.test[0];
		}
	}
	printf("+-----------------------------------------+\n");
	
	// Test permettant de demander ou pas le numéro de registre national en fonction du pays - Par défaut, si il n'est pas français, le numRegNat est "null" donc "Inconnu"
	if(strcmp(ajoutPa.pays,"FRA")==0){
		strcpy(ajoutPa.numRegNat,"X (Français)");
	}
	else if(strcmp(ajoutPa.pays,"BEL")==0){
		printf(" -> Saisissez son num. registre national : \n    (XX.XX.XX-XXX.XX) : ");
		gets(ajoutPa.numRegNat);
		printf("+-----------------------------------------+\n");
	}
	for (changement = 0; ajoutPa.numRegNat[changement]; changement++){
		if (ajoutPa.numRegNat[changement] == '\n'){
			ajoutPa.numRegNat[changement] = ajoutPa.test[0];
		}
	}
	
	printf(" -> Saisissez le %% de remb. de la mutuelle : \n    (XXX) : ");
	gets(ajoutPa.pourRemb);
	for (changement = 0; ajoutPa.pourRemb[changement]; changement++){
		if (ajoutPa.pourRemb[changement] == '\n'){
			ajoutPa.pourRemb[changement] = ajoutPa.test[0];
		}
	}
	
	printf("+-----------------------------------------+\n");

	// Fermeture du fichier de données - Permettant d'ajouter dans le fichier de données sans devoir quitter le programme
	fprintf(fdatPatient, "%-20s%-20s%-10s%-1s%-30s %-3s%-25s%-5s%-3s%-14s%-14s %-3s\n", ajoutPa.nom, ajoutPa.prenom, ajoutPa.dateNais, ajoutPa.genre, ajoutPa.rue, ajoutPa.num, ajoutPa.ville, ajoutPa.codePostal, ajoutPa.pays, ajoutPa.numeroTel, ajoutPa.numRegNat, ajoutPa.pourRemb);
	fclose(fdatPatient);
	system("cls");
	void affichageMenuPatientsCM();
	affichageMenuPatientsCM();
}
#endif

