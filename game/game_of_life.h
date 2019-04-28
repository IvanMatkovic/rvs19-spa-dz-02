#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_


#include <iostream>
#include <string>
#include <fstream>
#include <array>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	//bool _generacija[REDAKA][STUPACA];
	//bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	bool celija_zauzeta(int i, int j);
	bool gamestart = true;
	int how_much_neighbours_alive(int n, int m);
	
	//Postovani profesore, izgleda drukcije nego na primjeru ali mislim 
	//da je to jer ja na pocetku imam 25% a na danom primjeru je manje

public:

	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
	void game_start();
	//array<char, 800> polje;
	char polje [REDAKA][STUPACA];
};

#endif
