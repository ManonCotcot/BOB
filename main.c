#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "function.h"

//AVEC LE CARACTÈRE '\0'
#define TAILLE_COEUR 6 
#define TAILLE_TRAME 14


char TRAME_RECUE[]="1111531820000";
char TRAME_COEUR[TAILLE_COEUR];
int VERIFICATION_TRAME;
int ENCAPSULATION;
int MOTEUR;
int VITESSE;
int POSITION;


int main(int argc, char **argv){
	
	//strcpy(TRAME_COEUR, "HELLO");
	
	printf("trame_reçue [] = '");
	printf("%s'\n\n",TRAME_RECUE);
	
	//TRAME CONFORME ?
	VERIFICATION_TRAME = Conforme(TRAME_RECUE,TAILLE_TRAME);
	
		
	//verification encapsulation
	ENCAPSULATION = Encapsulation(TRAME_RECUE,TAILLE_TRAME);
	printf("\n");
	
	
	//desencapsulation
	Concatenation_trame(TRAME_RECUE, TRAME_COEUR);
	
	
	//analyse du moteur 
	int MOTEUR = Analyse_moteur(TRAME_COEUR);
	
	
	//analyse vitesse
	int VITESSE = Analyse_vitesse(TRAME_COEUR);
	
	int POSITION = Analyse_position(TRAME_COEUR);
	
return EXIT_SUCCESS;
}

