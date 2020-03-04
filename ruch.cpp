#include "ruch.h"
#include <iostream>

void ruch::addPossibilityWhite(int i, pole* tab)
{
	ruchy[0][0] = tab[i].poleX() - pole::size; // lewy sąsiad
	ruchy[0][1] = tab[i].poleY() - pole::size;
	ruchy[1][0] = tab[i].poleX() + pole::size; // prawy
	ruchy[1][1] = tab[i].poleY() - pole::size;
	ruchy[2][0] = tab[i].poleX(); // na miejsce
	ruchy[2][1] = tab[i].poleY();
	ruchy[3][0] = tab[i].poleX() - 2 * pole::size; // koszenie w lewo
	ruchy[3][1] = tab[i].poleY() - 2 * pole::size;
	ruchy[4][0] = tab[i].poleX() + 2 * pole::size; // koszenie w prawo
	ruchy[4][1] = tab[i].poleY() - 2 * pole::size;
	ruchy[5][0] = tab[i].poleX() - pole::size; // lewy sąsiad tył
	ruchy[5][1] = tab[i].poleY() + pole::size;
	ruchy[6][0] = tab[i].poleX() + pole::size; // prawy tył
	ruchy[6][1] = tab[i].poleY() + pole::size;
	ruchy[7][0] = tab[i].poleX() - 2 * pole::size; // koszenie w lewo tył
	ruchy[7][1] = tab[i].poleY() + 2 * pole::size;
	ruchy[8][0] = tab[i].poleX() + 2 * pole::size; // koszenie w prawo tył
	ruchy[8][1] = tab[i].poleY() + 2 * pole::size;
}

void ruch::addPossibilityBlack(int i, pole* tab)
{
	ruchy[0][0] = tab[i].poleX() - pole::size; // lewy sąsiad
	ruchy[0][1] = tab[i].poleY() + pole::size;
	ruchy[1][0] = tab[i].poleX() + pole::size; // prawy
	ruchy[1][1] = tab[i].poleY() + pole::size;
	ruchy[2][0] = tab[i].poleX(); // na miejsce
	ruchy[2][1] = tab[i].poleY();
	ruchy[3][0] = tab[i].poleX() - 2 * pole::size; // koszenie w lewo
	ruchy[3][1] = tab[i].poleY() + 2 * pole::size;
	ruchy[4][0] = tab[i].poleX() + 2 * pole::size; // koszenie w prawo
	ruchy[4][1] = tab[i].poleY() + 2 * pole::size;
	ruchy[5][0] = tab[i].poleX() - pole::size; // lewy sąsiad tył
	ruchy[5][1] = tab[i].poleY() - pole::size;
	ruchy[6][0] = tab[i].poleX() + pole::size; // prawy tył
	ruchy[6][1] = tab[i].poleY() - pole::size;
	ruchy[7][0] = tab[i].poleX() - 2 * pole::size; // koszenie w lewo tył
	ruchy[7][1] = tab[i].poleY() - 2 * pole::size;
	ruchy[8][0] = tab[i].poleX() + 2 * pole::size; // koszenie w prawo tył
	ruchy[8][1] = tab[i].poleY() - 2 * pole::size;
}

void ruch::setFlag(bool f)
{
	flag = f;
}

bool ruch::getFlag()
{
	return flag;
}

void ruch::setMovements()
{
	movements = 1;
}

void ruch::countMovements()
{
	movements += 1;
}

int ruch::getMovements()
{
	return movements;
}

void ruch::set(int i, int j)
{
	a = i;
	x = j;
}

bool ruch::checkPossibility(int i, pole* tab, int color)
{
	// jeżeli odkładam z powrotem na miejsce
	if (tab[i].poleX() == ruchy[2][0] && tab[i].poleY() == ruchy[2][1] && movements < 2) { setFlag(false); return true; }

	for (int j = 0; j < 2; j++)
	{
		if (tab[i].poleX() == ruchy[j][0] && tab[i].poleY() == ruchy[j][1] && movements < 2) { setFlag(true); return true; }
	}

	// sprawdzanie bicia najpierw po lewej, potem po prawej u czarnego, potem lewa tył, potem prawa tył
	if (color == 2 && tab[i].poleX() == ruchy[3][0] && tab[i].poleY() == ruchy[3][1]) {
		for (int k = 0; k < 32; k++)
			if (tab[k].poleX() == ruchy[0][0] && tab[k].poleY() == ruchy[0][1] && (tab[k].getState() == 1 || tab[k].getState() == 3)) { setFlag(true); tab[k].setState(0); countMovements();  return true; }
	}
	else if (color == 2 && tab[i].poleX() == ruchy[4][0] && tab[i].poleY() == ruchy[4][1]) {
		for (int k = 0; k < 32; k++)
			if (tab[k].poleX() == ruchy[1][0] && tab[k].poleY() == ruchy[1][1] && (tab[k].getState() == 1 || tab[k].getState() == 3)) { setFlag(true); tab[k].setState(0); countMovements(); return true; }
	}
	else if (color == 2 && tab[i].poleX() == ruchy[7][0] && tab[i].poleY() == ruchy[7][1]) {
		for (int k = 0; k < 32; k++)
			if (tab[k].poleX() == ruchy[5][0] && tab[k].poleY() == ruchy[5][1] && (tab[k].getState() == 1 || tab[k].getState() == 3)) { setFlag(true); tab[k].setState(0); countMovements();  return true; }
	}
	else if (color == 2 && tab[i].poleX() == ruchy[8][0] && tab[i].poleY() == ruchy[8][1]) {
		for (int k = 0; k < 32; k++)
			if (tab[k].poleX() == ruchy[6][0] && tab[k].poleY() == ruchy[6][1] && (tab[k].getState() == 1 || tab[k].getState() == 3)) { setFlag(true); tab[k].setState(0); countMovements(); return true; }
	}

	// sprawdzanie bicia najpierw po lewej, potem po prawej u białego
	if (color == 1 && tab[i].poleX() == ruchy[3][0] && tab[i].poleY() == ruchy[3][1]) {
		for (int k = 0; k < 32; k++)
			if (tab[k].poleX() == ruchy[0][0] && tab[k].poleY() == ruchy[0][1] && (tab[k].getState() == 2 || tab[k].getState() == 4)) { setFlag(true); tab[k].setState(0); countMovements(); return true; }
	}
	else if (color == 1 && tab[i].poleX() == ruchy[4][0] && tab[i].poleY() == ruchy[4][1]) {
		for (int k = 0; k < 32; k++)
			if (tab[k].poleX() == ruchy[1][0] && tab[k].poleY() == ruchy[1][1] && (tab[k].getState() == 2 || tab[k].getState() == 4)) { setFlag(true); tab[k].setState(0); countMovements(); return true; }
	}
	else if (color == 1 && tab[i].poleX() == ruchy[7][0] && tab[i].poleY() == ruchy[7][1]) {
		for (int k = 0; k < 32; k++)
			if (tab[k].poleX() == ruchy[5][0] && tab[k].poleY() == ruchy[5][1] && (tab[k].getState() == 2 || tab[k].getState() == 4)) { setFlag(true); tab[k].setState(0); countMovements();  return true; }
	}
	else if (color == 1 && tab[i].poleX() == ruchy[8][0] && tab[i].poleY() == ruchy[8][1]) {
		for (int k = 0; k < 32; k++)
			if (tab[k].poleX() == ruchy[6][0] && tab[k].poleY() == ruchy[6][1] && (tab[k].getState() == 2 || tab[k].getState() == 4)) { setFlag(true); tab[k].setState(0); countMovements(); return true; }
	}

	return false;
}

void ruch::CheckPossibilityTwoBlack(int i, pole* tab)
{
	// dla czarnego w dol, dla srodkowych pól, dla pierwszego wiersza; a = 1; x = 2
	set(1, 2);
	if (i == a || i == x || i == a + 8 || i == x + 8 || i == a + 2 * 8 || i == x + 2 * 8) {
		if (((tab[i + 4].getState() == 1 || tab[i + 4].getState() == 3) && tab[i + 7].getState() == 0) || ((tab[i + 5].getState() == 1 || tab[i + 5].getState() == 3) && tab[i + 9].getState() == 0)) { setFlag(false); return; }
	}
	// dla czarnego w dol, dla skrajnych pól, dla pierwszego wierszja; a = 0; x = 3
	set(0, 3);
	if (i == a || i == a + 8 || i == a + 2 * 8) {
		if ((tab[i + 5].getState() == 1 || tab[i + 5].getState() == 3) && tab[i + 9].getState() == 0) { setFlag(false); return; }
	}
	else if (i == x || i == x + 8 || i == x + 2 * 8)
	{
		if ((tab[i + 4].getState() == 1 || tab[i + 4].getState() == 3) && tab[i + 7].getState() == 0) { setFlag(false); return; }
	}
	// dla czarnego w dół, drugi wiersz, dla srodkowych pól; a = 5; x = 6
	set(5, 6);
	if (i == a || i == x || i == a + 8 || i == x + 8 || i == a + 2 * 8 || i == x + 2 * 8) {
		if (((tab[i + 3].getState() == 1 || tab[i + 3].getState() == 1) && tab[i + 7].getState() == 0) || ((tab[i + 4].getState() == 1 || tab[i + 4].getState() == 3) && tab[i + 9].getState() == 0)) { setFlag(false); return; }
	}
	// dla czarnego w dol, drugi wiersz, skrajne pola; a = 4; x = 7
	set(4, 7);
	if (i == a || i == a + 8 || i == a + 2 * 8) {
		if ((tab[i + 4].getState() == 1 || tab[i + 4].getState() == 3) && tab[i + 9].getState() == 0) { setFlag(false); return; }
	}
	else if (i == x || i == x + 8 || i == x + 2 * 8) {
		if ((tab[i + 3].getState() == 1 || tab[i + 3].getState() == 3) && tab[i + 7].getState() == 0) { setFlag(false); return; }
	}

	// dla bialego w gore, dla srodkowych pól, dla ostatniego wiersza; a = 29; x = 30
	set(29, 30);
	if (i == a || i == x || i == a - 8 || i == x - 8 || i == a - 2 * 8 || i == x - 2 * 8) {
		if (((tab[i - 4].getState() == 1 || tab[i - 4].getState() == 3) && tab[i - 7].getState() == 0) || ((tab[i - 5].getState() == 1 || tab[i - 5].getState() == 3) && tab[i - 9].getState() == 0)) { setFlag(false); return; }
	}
	// dla bialego w gore, dla skrajnych pól, dla ostatniego wiersza; a = 28; x = 31
	set(28, 31);
	if (i == a - 8 || i == a - 2 * 8) {
		if ((tab[i - 4].getState() == 1 || tab[i - 4].getState() == 3) && tab[i - 7].getState() == 0) { setFlag(false); return; }
	}
	else if (i == x - 8 || i == x - 2 * 8)
	{
		if ((tab[i - 5].getState() == 1 || tab[i - 5].getState() == 3) && tab[i - 9].getState() == 0) { setFlag(false); return; }
	}
	// dla bialego w gore, przedostatni wiersz, dla srodkowych pól; a = 25; x = 26
	set(25, 26);
	if (i == a || i == x || i == a - 8 || i == x - 8 || i == a - 2 * 8 || i == x - 2 * 8) {
		if (((tab[i - 3].getState() == 1 || tab[i - 3].getState() == 3) && tab[i - 7].getState() == 0) || ((tab[i - 4].getState() == 1 || tab[i - 4].getState() == 3) && tab[i - 9].getState() == 0)) { setFlag(false); return; }
	}
	// dla bialego w gore, przedostatni wiersz, skrajne pola; a = 24; x = 27
	set(24, 27);
	if (i == a || i == a - 8 || i == a - 2 * 8) {
		if ((tab[i - 3].getState() == 1 || tab[i - 3].getState() == 3) && tab[i - 7].getState() == 0) { setFlag(false); return; }
	}
	else if (i == x || i == x - 8 || i == x - 2 * 8) {
		if ((tab[i - 4].getState() == 1 || tab[i - 4].getState() == 3) && tab[i - 9].getState() == 0) { setFlag(false); return; }
	}
	return;
}

void ruch::CheckPossibilityTwoWhite(int i, pole* tab)
{
	// dla bialego w gore, dla srodkowych pól, dla ostatniego wiersza; a = 29; x = 30
	set(29, 30);
	if (i == a || i == x || i == a - 8 || i == x - 8 || i == a - 2 * 8 || i == x - 2 * 8) {
		if (((tab[i - 4].getState() == 2 || tab[i - 4].getState() == 4) && tab[i - 7].getState() == 0) || ((tab[i - 5].getState() == 2 || tab[i - 5].getState() == 4) && tab[i - 9].getState() == 0)) { setFlag(false); return; }
	}
	// dla bialego w gore, dla skrajnych pól, dla ostatniego wiersza; a = 28; x = 31
	set(28, 31);
	if (i == a || i == a - 8 || i == a - 2 * 8) {
		if ((tab[i - 4].getState() == 2 || tab[i - 4].getState() == 4) && tab[i - 7].getState() == 0) { setFlag(false); return; }
	}
	else if (i == x || i == x - 8 || i == x - 2 * 8)
	{
		if ((tab[i - 5].getState() == 2 || tab[i - 5].getState() == 4) && tab[i - 9].getState() == 0) { setFlag(false); return; }
	}
	// dla bialego w gore, przedostatni wiersz, dla srodkowych pól; a = 25; x = 26
	set(25, 26);
	if (i == a || i == x || i == a - 8 || i == x - 8 || i == a - 2 * 8 || i == x - 2 * 8) {
		if (((tab[i - 3].getState() == 2 || tab[i - 3].getState() == 4) && tab[i - 7].getState() == 0) || ((tab[i - 4].getState() == 2 || tab[i - 4].getState() == 4) && tab[i - 9].getState() == 0)) { setFlag(false); return; }
	}
	// dla bialego w gore, przedostatni wiersz, skrajne pola; a = 24; x = 27
	set(24, 27);
	if (i == a || i == a - 8 || i == a - 2 * 8) {
		if ((tab[i - 3].getState() == 2 || tab[i - 3].getState() == 4) && tab[i - 7].getState() == 0) { setFlag(false); return; }
	}
	else if (i == x || i == x - 8 || i == x - 2 * 8) {
		if ((tab[i - 4].getState() == 2 || tab[i - 4].getState() == 4) && tab[i - 9].getState() == 0) { setFlag(false); return; }
	}

	// dla czarnego w dol, dla srodkowych pól, dla pierwszego wiersza; a = 1; x = 2
	set(1, 2);
	if (i == a || i == x || i == a + 8 || i == x + 8 || i == a + 2 * 8 || i == x + 2 * 8) {
		if (((tab[i + 4].getState() == 2 || tab[i + 4].getState() == 4) && tab[i + 7].getState() == 0) || ((tab[i + 5].getState() == 2 || tab[i + 5].getState() == 4) && tab[i + 9].getState() == 0)) { setFlag(false); return; }
	}
	// dla czarnego w dol, dla skrajnych pól, dla pierwszego wierszja; a = 0; x = 3
	set(0, 3);
	if (i == a + 8 || i == a + 2 * 8) {
		if ((tab[i + 5].getState() == 2 || tab[i + 5].getState() == 4) && tab[i + 9].getState() == 0) { setFlag(false); return; }
	}
	else if (i == x + 8 || i == x + 2 * 8)
	{
		if ((tab[i + 4].getState() == 2 || tab[i + 4].getState() == 4) && tab[i + 7].getState() == 0) { setFlag(false); return; }
	}
	// dla czarnego w dół, drugi wiersz, dla srodkowych pól; a = 5; x = 6
	set(5, 6);
	if (i == a || i == x || i == a + 8 || i == x + 8 || i == a + 2 * 8 || i == x + 2 * 8) {
		if (((tab[i + 3].getState() == 2 || tab[i + 3].getState() == 4) && tab[i + 7].getState() == 0) || ((tab[i + 4].getState() == 2 || tab[i + 4].getState() == 4) && tab[i + 9].getState() == 0)) { setFlag(false); return; }
	}
	// dla czarnego w dol, drugi wiersz, skrajne pola; a = 4; x = 7
	set(4, 7);
	if (i == a || i == a + 8 || i == a + 2 * 8) {
		if ((tab[i + 4].getState() == 2 || tab[i + 4].getState() == 4) && tab[i + 9].getState() == 0) { setFlag(false); return; }
	}
	else if (i == x || i == x + 8 || i == x + 2 * 8) {
		if ((tab[i + 3].getState() == 2 || tab[i + 3].getState() == 4) && tab[i + 7].getState() == 0) { setFlag(false); return; }
	}
	return;
}
