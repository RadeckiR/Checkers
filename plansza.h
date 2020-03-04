#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "pole.h"
#include "pionek.h"
#include "ruch.h"
#include "damka.h"
#include "PionekWhite.h"
#include "PionekBlack.h"
using namespace sf;
using namespace std;
class plansza : public pole
{
private:
	ruch Ruchy;
	damka Damka;

	float p = 0;
	pole* tab = new pole[32];


	int notup = 1; // notup: 1 - na planszy, 0 - podniesiony, 2 - musi biæ
	bool turn = true; // true - zaczyna bia³y, false - czarny
	int gra = true;
	int number = 0, color = 0, numberPionek = -1;

	vector <int> Remaining_Black;
	vector <int> Remaining_White;
	//pionek* pionekBlack = new pionek[32];
	PionekWhite* pionekWhite = new PionekWhite[32];
	PionekBlack* pionekBlack = new PionekBlack[32];

	//pionek* pionekWhite = new pionek[32];

	Sprite boardSprite;
	Texture board;
	RenderWindow window{ VideoMode(550, 550), "Warcaby" };

	Event event;

public:
		
	void createwindow();
	void createplansza();
	void ustawpionki();
	void whilee();
};

