// Fonctions fourni par le langage C
#include <stdio.h>		// Fonctions basiques du C
#include <string.h>		// Utilisation de fonction traitant des strings
#include <time.h>		// Utilisation de fonction sur les heures
#include <stdlib.h>		// Utilisation de fonction sur la mémoire 
#include <windows.h>	// Affichage en plein écran

// Variable globale des structures
#include "header/DaNazaretRubinoLectecri.h" 	// Fonctions de lecture et d'écriture
#include "header/DaNazaretRubinoAffichage.h"	// Affichage du personnels et des patients
#include "header/DaNazaretRubinoListes.h" 		// Fonction permettant un affichage sous forme de page

// Fonctions liés à la gestion du personnel et des patients
#include "header/DaNazaretRubinoAjout.h"		// Fonction permettant l'ajout d'un personnel ou d'un patient
#include "header/DaNazaretRubinoModifier.h"	// Fonction permettant la modification d'un personnel ou d'un patient
#include "header/DaNazaretRubinoSupprimer.h"	// Fonction permettant la suppression d'un personnel ou d'un patient

// Fonctions liées aux tris
#include "header/DaNazaretRubinoInformationsDates.h"	// Récupération des dates
#include "header/DaNazaretRubinoCreationDate.h"			// Création des agendas
#include "header/DaNazaretRubinoLectureDate.h"			// Lecture et écriture des dates
#include "header/DaNazaretRubinoRdv.h"					// Prise de rendez-vous

int main(){
	// Affichage en plein écran
	// On passe par deux Main pour éviter que lorsqu'on appel le second
	// Il relance le plein écran (et donc le retire).
	// On passe donc par un Main alternatif
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
	
	// Appel le main principal
	int mainOriginal();
	mainOriginal();
}

// Programme principal
int mainOriginal() {
	// Déclaration des fonctions
	void affichageMenuPrincipalCM(void);
	void affichageMenuPersonnelCM(void);
	void affichageMenuPatientsCM(void);
	void affichageMenuRdvCM(void);
	
	// Déclaration pour les accents dans la console DOS
	SetConsoleOutputCP (1252);
	
	// Déclaration des variables
	int choix = 0;

	// Affichage du menu principal
	affichageMenuPrincipalCM();
	
	// Récupération de la valeur entrée 
	scanf("%d",&choix);
	system("cls");
	
	if(choix==1){
		affichageMenuPersonnelCM();
	}
	if(choix==2){
		affichageMenuPatientsCM();
	}
	if(choix==3){
		lectureDateHeader();
	}
	if(choix==0 || choix > 3){
		
	}
	system("cls");
}

// Fonction d'affichage de MENU PRINCIPAL
void affichageMenuPrincipalCM (void) {
    printf("+=========================================+\n");
    printf("|*            Cabinet Medical            *|\n");
    printf("+=========================================+\n");
    printf("|+      Que souhaitez-vous faire ?       +|\n");
    printf("+=========================================+\n");
    printf("|-> Option 1 :  Gestion du personnel      |\n"); 
    printf("|-> Option 2 :  Gestion des patients      |\n");
    printf("|-> Option 3 :  Gestion des rendez-vous   |\n");
    printf("|-> Option 0 :  Quitter le programme      |\n");
    printf("+=========================================+\n\n");
}

// Fonction d'affichage de MENU PERSONNEL
void affichageMenuPersonnelCM (void) {
    printf("+=========================================+\n");
    printf("|*         Gestion du personnel          *|\n");
    printf("+=========================================+\n");
    printf("|+      Que souhaitez-vous faire ?       +|\n");
    printf("+=========================================+\n");
    printf("|-> Option 1 :  Afficher le personnel     |\n"); 
    printf("|-> Option 2 :  Ajouter un membre         |\n");
    printf("|-> Option 3 :  Modifier un membre        |\n");
    printf("|-> Option 4 :  Supprimer un membre       |\n");
    printf("|-> Option 0 :  Retour                    |\n");
    printf("+=========================================+\n\n");
        
	int choix;
	
	scanf("%d",&choix);
	system("cls");
	
	if(choix==1){
		personnelHeader();
	}
	if(choix==2){
		ajouterPersonnelHeader();
	}
	if(choix==3){
		modifierPersonnelHeader();
	}
	if(choix==4){
		supprimerPersonnelHeader();
	}
	if(choix==0 || choix > 4){
		mainOriginal();
	}
}

// Fonction d'affichage de MENU PATIENTS
void affichageMenuPatientsCM (void) {
    printf("+=========================================+\n");
    printf("|*         Gestion des patients          *|\n");
    printf("+=========================================+\n");
    printf("|+      Que souhaitez-vous faire ?       +|\n");
    printf("+=========================================+\n");
    printf("|-> Option 1 :  Afficher les patient      |\n"); 
    printf("|-> Option 2 :  Ajouter un patient        |\n");
    printf("|-> Option 3 :  Modifier un patient       |\n");
    printf("|-> Option 4 :  Supprimer un patient      |\n");
    printf("|-> Option 0 :  Retour                    |\n");
    printf("+=========================================+\n\n");
    
	int choix;
	
	scanf("%d",&choix);
	system("cls");
	
	if(choix==1){
		patientHeader();
	}
	if(choix==2){
		ajouterPatientHeader();
	}
	if(choix==3){
		modifierPatientHeader();
	}
	if(choix==4){
		supprimerPatientHeader();
	}
	if(choix==0 || choix > 4){
		mainOriginal();
	}
}

// Fonction d'affichage de MENU RDV
void affichageMenuRdvCM (void) {
    printf("+=========================================+\n");
    printf("|*        Gestion des rendez-vous        *|\n");
    printf("+=========================================+\n");
    printf("|+      Que souhaitez-vous faire ?       +|\n");
    printf("+=========================================+\n");
    printf("|-> Option 1 :  Afficher les r.d.v        |\n"); 
    printf("|-> Option 0 :  Retour                    |\n");
    printf("+=========================================+\n\n");
    
	int choix;
	
	scanf("%d", &choix);
	system("cls");
	
	if(choix==1){
		lectureDateHeader();
	}
	if(choix==0 || choix > 1){
		mainOriginal();
	}
}
