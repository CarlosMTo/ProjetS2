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

interface::interface(){
	positionecran = 0;
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

void interface::ecrandacceuil() {

	int entree;

	printf("\n");
	printf("------------------------------------------------------\n");
	printf("Bienvenue chez Uberto pizza (Appuyer sur 'n' pour continuer) \n");
	printf("------------------------------------------------------\n");
	printf("\n");
	printf("appuyer sur 'n' pour demarrer votre commade\n");
	printf("appuyer sur 'x' pour quitter le programme\n");
	while (1) {
		entree = _getch();
		switch (entree) {
		case 'n':


			system("cls");
			positionecran = 1;
			selectionecran();
			break;

		case 'x':

			cout << "je quitte";
			exit(EXIT_SUCCESS);
			break;

		}
	}
}

void interface::ecranconfirmationcommande() {
	int n, positioncurseur = 0;
	int entree;
	string Condiments = "";
	while (1) {
		system("cls");
		cout << "Vous avez commander une pizza de taille "<<chercherGrandeurPizza()<<" avec les condiments suivant:"<<endl;
		prix1 = prix_base;
		for (n = 0; n < TAILLE_CONDIMENTS; n++) {
			if (choisis[n]) {
				cout<< chercherCondiment(n)<<endl;
				prix1 += prix[n];
			}
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << prix1<< endl;

		cout << "w : nouvelle commande x : quitter" << endl;
		entree = _getch();
		switch (entree) {
		case 'w':
			for (int i = 0;i < 10;i++) {
				choisis[i] = false;
			}
		system("cls");
		ecrandacceuil();
		
		case 'x':
			exit(EXIT_SUCCESS);
			break;
		}
	}

}
void interface::ecrancondiment() {
	int n, positioncurseur = 0;
	int entree;
	string Condiments ="";
	while (1) {
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
		entree = _getch();
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
				ecranconfirmationcommande();
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
	}
} 
void interface::ecrantaille() {
	int n, positioncurseur = 0;
	int entree;
	while (1) {
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
		entree = _getch();
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
				ecrancondiment();
				break;
			case 'x':
				exit(EXIT_SUCCESS);
				break;
		}
	}
}

int main()
{
	interface();
    return 0;
}

