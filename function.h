#include "function.c"
int Conforme(char trame[], int TAILLE_conforme);
void conversion_trame(char trame[], int newtrame[], int taille_tableau);
int Check_beginning_trame(char* trame);
int Check_end_trame(char trame[],int taille_tableau);
int Encapsulation(char tableau[],int size_table);
void Concatenation_trame(char trame[], char trame_reduite[]);
int Analyse_moteur(char trame[]);
int Analyse_vitesse(char trame_reduite[]);
int Analyse_position(char trame_reduite[]);
