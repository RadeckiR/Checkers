#include "damka.h"
#include <iostream>

bool damka::damkaCheck(int i, int color, pole* tab)
{
	if (color == 1 && i >= 0 && i <= 3) {
		tab[i].setState(3);
		return true;
	}
	else if (color == 2 && i >= 28 && i <= 31) {
		tab[i].setState(4);
		return true;
	}
	return false;
}

void damka::I_change_l(int even_odd)
{
	if (even_odd % 2 == 0)
		l += 4;
	else l += 3;
}

void damka::II_change_l(int even_odd)
{
	if (even_odd % 2 == 0)
		l += 5;
	else l += 4;
}

void damka::addPossibilityDamkaWhite(int i, pole* tab)
{
	// dla bialego, pierwszy rz¹d, œrodkowe pola
	set(1, 2);
	if (i == a || i == x) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 12) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 11) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		return;
	}

	// dla bia³ego, œrodkowe pola, od 3 rzêdu
	if (i == a + 8 || i == x + 8 || i == a + 2 * 8 || i == x + 2 * 8 || i == a + 3 * 8 || i == x + 3 * 8) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 29 || i + l == 20 || i + l == 28 || i + l == 30) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 31 || i + l == 19 || i + l == 27 || i + l == 29) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 4;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 0 || i - l == 4 || i - l == 12 || i - l == 1) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 3;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 2 || i - l == 19 || i - l == 11 || i - l == 3) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		return;
	}

	set(0, 3);
	if (i == a) {
		ruchydamka[0][0] = i;
		l = 4;
		if (tab[i + l].getState() == 0) ruchydamka[1][0] = i + l;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 27) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		return;
	}
	if (i == x) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 28) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		return;
	}
	if (i == a + 8 || i == a + 2 * 8 || i == a + 3 * 8) {
		ruchydamka[0][0] = i;
		l = 4;
		if (tab[i + l].getState() == 0) ruchydamka[1][0] = i + l;
		if (tab[i - l].getState() == 0) ruchydamka[3][0] = i + l;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 31 || i + l == 30 || i + l == 29) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 3;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 1 || i - l == 2 || i - l == 3) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		return;
	}

	if (i == x + 8 || i == x + 2 * 8 || i == x + 3 * 8) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 29 || i + l == 30 || i + l == 31) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 4;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 0 || i - l == 2 || i - l == 1) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		return;
	}

	set(29, 30);
	if (i == a || i == x) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 20 || i - l == 12) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 11 || i - l == 19) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		return;
	}

	if (i == a - 8 || i == x - 8 || i == a - 2 * 8 || i == x - 2 * 8 || i == a - 3 * 8 || i == x - 3 * 8) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 3;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 28 || i + l == 20 || i + l == 12 || i + l == 29) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 31 || i + l == 30 || i + l == 27 || i + l == 19) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
			// if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[2][numerator] = i + l; II_change_l(even_odd); even_odd++; check = 1; }
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 0 || i - l == 4 || i - l == 12 || i - l == 1) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 2 || i - l == 1 || i - l == 11 || i - l == 3) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		return;
	}

	set(28, 31);
	if (i == a) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 3) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		return;
	}
	if (i == x) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 4) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		l = 4;
		if (tab[i - l].getState() == 0) ruchydamka[4][0] = i - l;
		return;
	}

	if (i == a - 8 || i == a - 2 * 8 || i == a - 3 * 8) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 31 || i + l == 30 || i + l == 29) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 0 || i - l == 2 || i - l == 1) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		return;
	}

	if (i == x - 8 || i == x - 2 * 8 || i == x - 3 * 8) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 3;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 28 || i + l == 30 || i + l == 29) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		l = 4;
		if (tab[i + l].getState() == 0) ruchydamka[2][0] = i - l;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 2 || tab[i - l].getState() == 4) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 0 || i - l == 2 || i - l == 1) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		l = 4;
		if (tab[i - l].getState() == 0) ruchydamka[4][0] = i - l;
		return;
	}
}

void damka::addPossibilityDamkaBlack(int i, pole* tab)
{
	// dla czarnego, pierwszy rz¹d, œrodkowe pola
	set(1, 2);
	if (i == a || i == x) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 12) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 11) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		return;
	}

	// dla czarnego, œrodkowe pola, od 3 rzêdu
	if (i == a + 8 || i == x + 8 || i == a + 2 * 8 || i == x + 2 * 8 || i == a + 3 * 8 || i == x + 3 * 8) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 29 || i + l == 20 || i + l == 28 || i + l == 30) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 31 || i + l == 19 || i + l == 27 || i + l == 29) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 4;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0))) {
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 0 || i - l == 4 || i - l == 12 || i - l == 1) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 3;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 2 || i - l == 19 || i - l == 11 || i - l == 3) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
			//if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[1][numerator] = i + l; I_change_l(even_odd); even_odd++; check = 1; }
		}
		return;
	}

	set(0, 3);
	if (i == a) {
		ruchydamka[0][0] = i;
		l = 4;
		if (tab[i + l].getState() == 0) ruchydamka[1][0] = i + l;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 27) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
			// if ((tab[i + l].getState() == 2 || tab[i + l].getState() == 4) && check == 0) { ruchydamka[2][numerator] = i + l; II_change_l(even_odd); even_odd++; check = 1; }
			// if (tab[i + l].getState() == 1 || tab[i + l].getState() == 3) break;
		}
		return;
	}
	if (i == x) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 28) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		return;
	}
	if (i == a + 8 || i == a + 2 * 8 || i == a + 3 * 8) {
		ruchydamka[0][0] = i;
		l = 4;
		if (tab[i + l].getState() == 0) ruchydamka[1][0] = i + l;
		if (tab[i - l].getState() == 0) ruchydamka[3][0] = i + l;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 31 || i + l == 30 || i + l == 29) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 3;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0))) {
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 1 || i - l == 2 || i - l == 3) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		return;
	}

	if (i == x + 8 || i == x + 2 * 8 || i == x + 3 * 8) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 29 || i + l == 30 || i + l == 31) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 4;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0))) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 0 || i - l == 2 || i - l == 1) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		return;
	}

	set(29, 30);
	if (i == a || i == x) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0)) {
			std::cout << i << std::endl;
			std::cout << "jestem w while" << std::endl;
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 20 || i - l == 12) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0)) {
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 11 || i - l == 19) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		return;
	}

	if (i == a - 8 || i == x - 8 || i == a - 2 * 8 || i == x - 2 * 8 || i == a - 3 * 8 || i == x - 3 * 8) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 3;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 28 || i + l == 20 || i + l == 12 || i + l == 29) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 31 || i + l == 30 || i + l == 27 || i + l == 19) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0))) {
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 0 || i - l == 4 || i - l == 12 || i - l == 1) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0))) {
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 2 || i - l == 1 || i - l == 11 || i - l == 3) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		return;
	}

	set(28, 31);
	if (i == a) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0))) {
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 3) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		return;
	}
	if (i == x) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0))) {
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 4) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		l = 4;
		if (tab[i - l].getState() == 0) ruchydamka[4][0] = i - l;
		return;
	}

	if (i == a - 8 || i == a - 2 * 8 || i == a - 3 * 8) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 4;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[2][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 31 || i + l == 30 || i + l == 29) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 4;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0))) {
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[4][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 0 || i - l == 2 || i - l == 1) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		return;
	}

	if (i == x - 8 || i == x - 2 * 8 || i == x - 3 * 8) {
		ruchydamka[0][0] = i;
		check = 0;
		even_odd = 0;
		numerator = 0;
		l = 3;
		while (tab[i + l].getState() == 0 || ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0)) {
			if ((tab[i + l].getState() == 1 || tab[i + l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[1][numerator] = i + l;
			std::cout << i + l << std::endl;
			if (i + l == 28 || i + l == 30 || i + l == 29) break;
			numerator++;
			I_change_l(even_odd);
			even_odd++;
		}
		l = 4;
		if (tab[i + l].getState() == 0) ruchydamka[2][0] = i - l;
		check = 0;
		even_odd = 1;
		numerator = 0;
		l = 5;
		while (i - l >= 0 && (tab[i - l].getState() == 0 || ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0))) {
			if ((tab[i - l].getState() == 1 || tab[i - l].getState() == 3) && check == 0) { check = 1; }
			ruchydamka[3][numerator] = i - l;
			std::cout << i - l << std::endl;
			if (i - l == 0 || i - l == 2 || i - l == 1) break;
			numerator++;
			II_change_l(even_odd);
			even_odd++;
		}
		l = 4;
		if (tab[i - l].getState() == 0) ruchydamka[4][0] = i - l;
		return;
	}
}

bool damka::checkPossibilityDamka(int i, int color, pole* tab)
{
	int remember = -2;
	std::cout << i << std::endl;
	if (ruchydamka[0][0] == i) { setFlag(false);  return true; }
	if (color == 3) {
		for (int j = 1; j < 5; j++) {
			for (int m = 0; m < 8; m++) {
				std::cout << "sprawdzam" << std::endl;
				if (tab[ruchydamka[j][m]].getState() == 2 || tab[ruchydamka[j][m]].getState() == 4) remember = ruchydamka[j][m];
				if (ruchydamka[j][m] == i) { tab[remember].setState(0); setFlag(true); return true; }
			}
			remember = -2;
		}
	}
	remember = -2;
	if (color == 4) {
		for (int j = 3; j < 5; j++) {
			for (int m = 0; m < 8; m++) {
				std::cout << "sprawdzam" << std::endl;
				if (tab[ruchydamka[j][m]].getState() == 1 || tab[ruchydamka[j][m]].getState() == 3) remember = ruchydamka[j][m];
				if (ruchydamka[j][m] == i) { tab[remember].setState(0); setFlag(true); return true; }
			}
			remember = -2;
		}
		for (int j = 1; j < 3; j++) {
			for (int m = 0; m < 8; m++) {
				std::cout << "sprawdzam" << std::endl;
				if (tab[ruchydamka[j][m]].getState() == 1 || tab[ruchydamka[j][m]].getState() == 3) remember = ruchydamka[j][m];
				if (ruchydamka[j][m] == i) { tab[remember].setState(0); setFlag(true); return true; }
			}
			remember = -2;
		}
	}
	return false;
}


