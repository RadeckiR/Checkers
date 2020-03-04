#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ruch.h"

class damka
	: public ruch
{
private:
	int ruchydamka[5][8];
	int numerator, even_odd, l, check, remember;
public:
	bool damkaCheck(int i, int color, pole* tab);
	void addPossibilityDamkaWhite(int i, pole* tab);
	void addPossibilityDamkaBlack(int i, pole* tab);
	bool checkPossibilityDamka(int i, int color, pole* tab);
	void I_change_l(int even_odd);
	void II_change_l(int even_odd);
	~damka() = default;
};

