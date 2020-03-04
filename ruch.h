#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "pole.h"

class ruch
	: public pole
{
private:
	float ruchy[9][2];
	bool flag;
	int movements;
protected:
	int a, x;
public:
	void addPossibilityWhite(int i, pole* tab);
	void addPossibilityBlack(int i, pole* tab);
	void setFlag(bool f);
	bool getFlag();
	void setMovements();
	void countMovements();
	int getMovements();
	void set(int i, int j);
	bool checkPossibility(int i, pole* tab, int color);
	void CheckPossibilityTwoBlack(int i, pole* tab);
	void CheckPossibilityTwoWhite(int i, pole* tab);
	~ruch() = default;
};

