#include "interface.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
string interface::chercherGrandeurPizza() {
	return grandeurPizza;
}
void interface::setgrandeurPizza(string grandeur) {
	grandeurPizza = grandeur;
}
string interface::chercherGrandeur(int index){
	return grandeur[index];
}
string interface::chercherCondiment(int index) {
	return condiments[index];
}
string interface::chercherViande(int index) {
	return viandes[index];
}

interface::interface(){
	positionecran = 0;
	positioncurseur = 0;
	selectionecran();
}   //test

interface::~interface()
{

};

void interface::selectionecran()
{
	switch (positionecran) {
		case 0 : 
			ecrandacceuil();
			break;
		case 1 :
			ecrantaille();
			break;
	}
};

char interface::interaction() {
	char sortie;
	sortie = _getch();

	return sortie;
};

void interface::ecrandacceuil() {

	int entree;
	system("cls");
	printf("\n");
	printf("------------------------------------------------------\n");
	printf("Bienvenue chez Uberto pizza (Appuyer sur 'n' pour continuer) \n");
	printf("------------------------------------------------------\n");
	printf("\n");
	printf("appuyer sur 'n' pour demarrer votre commande\n");
	printf("appuyer sur 'x' pour quitter le programme\n");

	entree = interaction();
	switch (entree) {
	case 'n':


		system("cls");
		positioncurseur = 0;
		positionecran = 1;
		selectionecran();
		break;

	case 'x':

		cout << "je quitte";
		exit(EXIT_SUCCESS);
		break;
	}
	ecrandacceuil();
}

void interface::ecranconfirmationcommande() {
	int n;
	int entree;
	//string Condiments = "";
	
	system("cls");
	cout << "Vous avez commander une pizza de taille "<<chercherGrandeurPizza()<<" avec les condiments suivant:"<<endl;
	prix1 = prix_base;
	for (n = 0; n < TAILLE_CONDIMENTS; n++) {
		if (choisis[n]) {
			cout<< chercherCondiment(n)<<endl;
			prix1 += prix[n];
		}
		if (choisisViande[n]) {
			cout << chercherViande(n) << endl;
			prix1 += prixViande[n];
		}
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Votre total est : $" << prix1<< endl;

	cout << "w : nouvelle commande x : quitter" << endl;
	entree = interaction();
	switch (entree) {
	case 'w':
		for (int i = 0;i < 10;i++) {
			choisisViande[i] = false;
			choisis[i] = false;
		}
		
	system("cls");
	positioncurseur = 0;
	ecrandacceuil();
		
	case 'x':
		exit(EXIT_SUCCESS);
		break;
	}
	ecranconfirmationcommande();
	
}
void interface::ecrancondiment() {
	int n;
	int entree;
	//string Condiments ="";
	system("cls");
	cout << "choisisez vos condiments:" << endl;
	for (n = 0; n < TAILLE_CONDIMENTS; n++) {
		if (n == positioncurseur) {
			cout << "=>   ";
		}
		else {
			cout << "     ";
		};

		cout << n << " : " << chercherCondiment(n);
		if (choisis[n]==true){
			cout << " [ x ]";
		}
		cout<< endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "w : haut, s : bas, n : selectionner, x : quitter" << endl;
	entree = interaction();
	switch (entree) {
	case 's':
		if (positioncurseur < TAILLE_CONDIMENTS - 1)
			positioncurseur++;
		break;
	case 'w':
		if (positioncurseur > 0)
			positioncurseur--;
		break;
	case 'n':
		if (positioncurseur ==TAILLE_CONDIMENTS-1){
			positioncurseur = 0;
			ecranviande();
		}
		else {
			if (!choisis[positioncurseur]) {
				choisis[positioncurseur] = true;
			}
			else
		if (choisis[positioncurseur]) {
			choisis[positioncurseur] = false;
			}

		}
		break;
	case 'x':
		exit(EXIT_SUCCESS);
		break;
	}
	ecrancondiment();
} 

void interface::ecranviande() {
	int n;
	int entree;
	//string Condiments ="";
	system("cls");
	cout << "choisisez vos viandes:" << endl;
	for (n = 0; n < TAILLE_VIANDES; n++) {
		if (n == positioncurseur) {
			cout << "=>   ";
		}
		else {
			cout << "     ";
		};

		cout << n << " : " << chercherViande(n);
		if (choisisViande[n] == true) {
			cout << " [ x ]";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "w : haut, s : bas, n : selectionner, x : quitter" << endl;
	entree = interaction();
	switch (entree) {
	case 's':
		if (positioncurseur < TAILLE_CONDIMENTS - 1)
			positioncurseur++;
		break;
	case 'w':
		if (positioncurseur > 0)
			positioncurseur--;
		break;
	case 'n':
		if (positioncurseur == TAILLE_CONDIMENTS - 1) {
			positioncurseur = 0;
			ecranconfirmationcommande();
		}
		else {
			if (!choisisViande[positioncurseur]) {
				choisisViande[positioncurseur] = true;
			}
			else
				if (choisisViande[positioncurseur]) {
					choisisViande[positioncurseur] = false;
				}

		}
		break;
	case 'x':
		exit(EXIT_SUCCESS);
		break;
	}
	ecranviande();
}

void interface::ecrantaille() {
	int n;
	int entree;
	system("cls");
	cout << "choisisez votre taille:" << endl;
	for (n = 0; n < TAILLE_SIZE; n++) {
		if (n == positioncurseur){
			cout << "=>   ";
		}
		else {
			cout << "     ";
		};

		cout << n << " : " << chercherGrandeur(n) << endl;
	}

	cout << endl;
	cout << endl; 
	cout << endl;
	cout << "w : haut, s : bas, n : selectionner, x : quitter" << endl;
	entree = interaction();
	switch (entree) {
		case 's' :
			if (positioncurseur < TAILLE_SIZE-1)
				positioncurseur++;
			break;
		case 'w':
			if (positioncurseur > 0)
				positioncurseur--;
			break;
		case 'n':
			setgrandeurPizza(chercherGrandeur(positioncurseur));
			prix_base = prix_Grandeur[positioncurseur];
			positioncurseur = 0;
			ecrancondiment();
			break;
		case 'x':
			exit(EXIT_SUCCESS);
			break;
	}
	interface::ecrantaille();
}


int main()
{
	interface();
    return 0;
}

