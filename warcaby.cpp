// warcaby.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "pionek.h"
#include "pole.h"
#include "ruch.h"
#include "damka.h"
#include "plansza.h"

#include <fstream>
#include <ctime>
#include <vector> 
#include <string>

using namespace std;
using namespace sf;


int main()
{
	plansza Plansza;
	Plansza.createwindow();
	Plansza.createplansza();
	Plansza.ustawpionki();
	try
	{
		Plansza.whilee();
	}
	catch (logic_error & e) {
		cout << e.what() << endl;
			cout << "sprobuj jeszcze raz kliknac na wybrany pionek" << endl;
		Plansza.whilee();
	}
	
	return 0;
}


