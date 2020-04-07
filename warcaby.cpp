// warcaby.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "pionek.h"
#include "pole.h"
#include "ruch.h"
#include "damka.h"
#include "plansza.h"
#include <sstream>
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
	Plansza.whilee();
	return 0;
}