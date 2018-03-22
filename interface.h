#include <string> 
#include "CommunicationFPGA.h"

using namespace std;

#define TAILLE_SIZE 4
#define TAILLE_CONDIMENTS 10
#define TAILLE_VIANDES 10

class interface {
public:
	interface();
	~interface();

	bool initFPGA();
	void selectionecran();
	int interaction();
	void ecrandacceuil();
	void ecrantaille();
	int lireRegistre(int registre);
	void ecrancondiment();
	void ecranviande();
	void ecranconfirmationcommande();
	string chercherGrandeur(int index);
	string chercherCondiment(int index);
	string chercherViande(int index);
	void setgrandeurPizza(string grandeur);
	string chercherGrandeurPizza();
	double calcul_prix();
	double prix1;
	double prix_base;

private:
	//enum Registre { SW = 8, BTN = 9, LD = 10, AN0 = 11, AN1 = 12, AN2 = 13, AN3 = 14 };
	enum Registre { SW = 8, BTN = 9, LD = 10, SWR = 1, BTNR = 0, AN0 = 11, AN1 = 12, AN2 = 13, AN3 = 14};
	bool choisis[TAILLE_CONDIMENTS] = {false,false, false, false, false, false, false, false, false, false};
	bool choisisViande[TAILLE_CONDIMENTS] = { false,false, false, false, false, false, false, false, false, false };
	double prix[TAILLE_CONDIMENTS] = { 0.50 , 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50,0 };
	double prixViande[TAILLE_CONDIMENTS] = { 0.50 , 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50,0 };
	double prix_Grandeur[TAILLE_SIZE] = {8.50,10.25,12.50,15.70 };
	string grandeurPizza;
	int positionecran;
	int positioncurseur;
	string grandeur[4] = { "petite","moyenne","grande","XL" };
	string condiments[10] = { "Tomates","Onions","Piments","Epinards","Champignons" ,"Jalapenos","Ananas","Olives","Ail", "Confirmer la selection" };
	string viandes[10] = { "Steak","Pepperoni","Salami","Jambon","Prosciutto","Bacon","Saucisse","Poulet","Anchois","Confirmer la selections" };
	CommunicationFPGA fpga;
};
