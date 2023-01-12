
int Conforme(char trame[], int TAILLE){
	if(strlen(trame) != TAILLE-1){
		printf("TRAME REÇUE : NON CONFORME\n");
		return -1;}
	else{
		printf("TRAME REÇUE : CONFORME\n");
		return 1;
			}
	}



// le but de cette fonction est de verifier que les 2 premiers octets de la tramme sont a 1
int Check_beginning_trame(char* trame){
	
    int i = 0;
    int q = strlen(trame);
    
    for(i = 0; i<=3; i++) {
        if (trame[i] == '1' ){	
            // LES 4PREMIERS BITS SONT BIEN A 1 
        }
        else{
            printf("les premiers bits sont differents de 1\n");
            return 1;
			}
		}
	
        switch (i)
		{
        case 4 :
        //printf("%s", trame);
        //les 2 premiers octets sont a 1
        return 0;
        
        default :
        printf("erreur\n");
        return 1;
		}
	}



//cette fonction verifie que les 2 derniers octects sont à 0
int Check_end_trame(char trame[], int taille_tableau) {
    if (taille_tableau < 14) {
        printf("Erreur: la trame doit faire 14 en entrée.\n");
        return EXIT_FAILURE;
    }
    int j = 0;
    for (int i = taille_tableau - 5; i < taille_tableau-1; i++) { //
        if (trame[i] == '0') {
			//printf("'%c'",trame[i]);
            j++;
        }else {
            printf("Erreur: du caractere : '%c' à la position : '%d'.\n", trame[i], i);
            return EXIT_FAILURE;
        }
    }
    if (j == 4) {
        return EXIT_SUCCESS;
    } else {
        printf("Erreur: mauvaise encapsulation");
        return EXIT_FAILURE;
    }
}




//converti la trame char -> int
void conversion_trame(char trame[], int newtrame[], int taille_tableau){
	int i = 0;
	printf("\ntrame convertie : \ntrame[] : ");
	while(i<taille_tableau){
		newtrame[i] = trame[i]-48;
		printf("%d",newtrame[i]);
		i++;
	}
	printf("\n");
}



//verification l'encapsulation de la trame
int Encapsulation(char tableau[],int TAILLE_TRAME){

int a, b;

	printf("\nÉtat encapsulation :\n\n");
		//verification encapsulation debut de trame
		int verification_debut = Check_beginning_trame(tableau);
		if(verification_debut == 0){
			printf("encapsulation début : ok \n");
			a = 1;
		}
		else{
			printf("encapsulation début : échec \n\n");
		}

		
		//verification encapsulation fin de trame
		int verification_fin = Check_end_trame(tableau, TAILLE_TRAME);
		if(verification_fin == 0){
			printf("encapsulation fin : ok \n");
			b = 1;
		}
		else{
			printf("encapsulation fin : échec \n");
		}
		
		if( a == 1 && b ==1){
			return 1;
		}
		else{
			return -1;
		}
}



//desencapsule la trame
void Concatenation_trame(char trame[], char trame_reduite[]){
	
	int g = strlen(trame)-5;
	int indice = 0;
	
	printf("Coeur de la trame : ");
	//printf("%s\n", trame);
	for(int m=4; m<=g;m++){
		trame_reduite[indice] = trame[m]; 
		indice++;
	}
	trame_reduite[indice] = '\0';  // Add null terminator
	printf("%s\n", trame_reduite);
	//return trame_reduite;  // Return the concatenated string
}



//analyse le moteur ciblé
int Analyse_moteur(char trame_reduite[]){
	
	if (strlen(trame_reduite) != 5) {
        printf("Error: mauvaise longueur TRAME_Coeur\n");
        return -1; // you could also use some other value to indicate an error
    }
	
	char TRAME_MOTEUR[1];
	TRAME_MOTEUR[0] = trame_reduite[0];
	
	if (strcmp(TRAME_MOTEUR, "1") == 0) {
    printf("MOTEUR SELECTIONNÉ : 1\n");
		return 1;
    }
    else if (strcmp(TRAME_MOTEUR, "2") == 0) {
		printf("MOTEUR SELECTIONNÉ : 2\n");
		return 2;
    }
    else if (strcmp(TRAME_MOTEUR, "3") == 0) {
		printf("MOTEUR SELECTIONNÉ : 3\n");
		return 3;
    }
    else if (strcmp(TRAME_MOTEUR, "4") == 0) {
		printf("MOTEUR SELECTIONNÉ : 4\n");
		return 4;
    }
    else if (strcmp(TRAME_MOTEUR, "5") == 0) {
		printf("MOTEUR SELECTIONNÉ : 5\n");
		return 5;
    }
    else if (strcmp(TRAME_MOTEUR, "6") == 0) {
		printf("MOTEUR SELECTIONNÉ : 6\n");
		return 6;;
    }
    else if (strcmp(TRAME_MOTEUR, "7") == 0) {
		printf("MOTEUR SELECTIONNÉ : 7\n");
		return 7;
	}
    else{
		printf("AUCUN MOTEUR DE CES MOTEURS N'EST DEMANDÉPAS");
		return -1;
	}

}



//analyse la vitesse ciblé
int Analyse_vitesse(char trame_reduite[]){
	
	if (strlen(trame_reduite) != 5) {
        printf("Error: mauvaise longueur TRAME_Coeur\n");
        return -1; // you could also use some other value to indicate an error
    }
	
	char TRAME_VITESSE[1];
	TRAME_VITESSE[0] = trame_reduite[1];
	
	/*int index = 0;
	while(index<3){
		trame_vitesse[index] = trame_reduite[index+3];
		index++;
	}*/
	
	if (strcmp(TRAME_VITESSE, "1") == 0) {
	printf("VECTEUR VITESSE -> '1'\n");
    printf("VITESSE MOTEUR   : LOW\n");
    return 1;
    }
    else if(strcmp(TRAME_VITESSE, "2") == 0){
	printf("VECTEUR VITESSE ->  '2'\n");
	printf("VITESSE MOTEUR  :  MEDIUM\n");
	return 2;	
	}
	else if(strcmp(TRAME_VITESSE, "3") == 0){
	printf("VECTEUR VITESSE -> '3'\n");
	printf("VITESSE MOTEUR   :  HIGH\n");
	return 3;
	}
	else{
	printf("AUCUNE VITESSE NE CORRESPOND\n");
	return 0;
		}
	}



int Analyse_position(char trame_reduite[]){
	
	if (strlen(trame_reduite) != 5) {
        printf("Error: mauvaise longueur TRAME_Coeur\n");
        return -1; // you could also use some other value to indicate an error
    }
    
	int position = 0;
	int TRAME_POSITION_INT[3];
	
	for(int i=0; i<3;i++){
		TRAME_POSITION_INT[i] = trame_reduite[i+2]-48;
		//printf("%d",TRAME_POSITION_INT[i]);
	}
	position = TRAME_POSITION_INT[0]*100 + TRAME_POSITION_INT[1]*10 + TRAME_POSITION_INT[2];
	printf("POSITION MOTEUR DEMANDÉ : %d DEGRÉS \n",position);
	return position;
}

