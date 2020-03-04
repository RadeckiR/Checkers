#include "plansza.h"
#include "pionek.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <ctime>
#include <vector> 
#include <string>

//
//void pole::draw(sf::RenderTarget& target, sf::RenderStates state) const // nie bedzie zmieniac zadnych pol naszej klasy
//{
//	target.draw(this->rshape, state);
//}

void plansza::createwindow() {
	
	window.setFramerateLimit(10);
	
	board.loadFromFile("plansza.JPG");
	
	boardSprite.setTexture(board);
}


void plansza::createplansza() {
	
	

	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0) {
			for (float j1 = 68.75; j1 <= 550 - 68.75 / 2; j1 += 2 * 68.75)
			{
				tab[number].poleRead(j1, p);
				number++;
			}
		}
		else {
			for (float j2 = 0; j2 <= 550 - 68.75 / 2; j2 += 2 * 68.75)
			{
				tab[number].poleRead(j2, p);
				number++;
			}
		}
		p += 68.75;
	}
}


void plansza::ustawpionki() {
	

	for (int i = 0; i < 32; i++)
	{
		if (i < 12) {
			pionekBlack[i].setPos(tab[i].poleX(), tab[i].poleY());
			tab[i].setState(2); // 2 - czarny, 1 - bialy, 4 - czarna damka, 3 - biala damka
			tab[i].setPionek(i);
			pionekBlack[i].setCol(Color::Black);
		}
		else if (i > 19
			) {
			pionekWhite[i].setPos(tab[i].poleX(), tab[i].poleY());
			tab[i].setState(1);
			tab[i].setPionek(i);
			pionekWhite[i].setCol(Color::White);
		}
		else {
			tab[i].setState(0);
			tab[i].setPionek(NULL);
		}
	}
}


void plansza::whilee(){
	Ruchy.setMovements();
	while (true)
	{
		// window.clear(Color::Blue);
		window.pollEvent(event); // do obslugi okienka wyskakujacego (zamnkiecie, minimalizacja)
		window.draw(boardSprite);

		// window.draw(pole1);
		// window.draw(k);

		for (int i = 0; i < 32; i++)
		{
			if (tab[i].getState() == 2) {
				window.draw(pionekBlack[tab[i].getPionek()]);
				Remaining_Black.push_back(tab[i].getPionek());
			}

			else if (tab[i].getState() == 1) {
				window.draw(pionekWhite[tab[i].getPionek()]);
				Remaining_White.push_back(tab[i].getPionek());
			}
			else if (tab[i].getState() == 4) {
				window.draw(pionekBlack[tab[i].getPionek()]);
				Remaining_Black.push_back(tab[i].getPionek());
			}
			else if (tab[i].getState() == 3) {
				window.draw(pionekWhite[tab[i].getPionek()]);
				Remaining_White.push_back(tab[i].getPionek());
			}
		}



		for (int i = 0; i < 32; i++)
		{
			switch (event.type)
			{
			case Event::Closed:
			{
				//window.close();
				break;
			}
			case Event::MouseButtonPressed:
			{
				if (event.mouseButton.button == Mouse::Left && notup == 1) {
					if (tab[i].poleCheck((float)event.mouseButton.x, (float)event.mouseButton.y) == true) {
						if (turn == true && tab[i].getState() == 1) {
							color = tab[i].getState();
							Ruchy.addPossibilityWhite(i, tab);
							cout << endl << "ruch: Bialy";
							notup = 0;
							numberPionek = tab[i].getPionek();
							tab[i].setState(0);
							tab[i].setPionek(-1);
							break;
						}
						else if (turn == false && tab[i].getState() == 2) {
							color = tab[i].getState();
							Ruchy.addPossibilityBlack(i, tab);
							cout << endl << "ruch: Czarny";
							notup = 0;
							numberPionek = tab[i].getPionek(); // zczytujemy do zmiennej numer  pionka podniesionego
							tab[i].setState(0);
							tab[i].setPionek(-1);
							break;
						}
						else if (turn == true && tab[i].getState() == 3) {
							color = tab[i].getState();
							Damka.addPossibilityDamkaWhite(i, tab);
							cout << endl << "podnoszê damkê";
							notup = 0;
							numberPionek = tab[i].getPionek();
							tab[i].setState(0);
							tab[i].setPionek(-1);
							break;
						}
						else if (turn == false && tab[i].getState() == 4) {
							color = tab[i].getState();
							Damka.addPossibilityDamkaBlack(i, tab);
							cout << endl << "podnoszê damkê";
							notup = 0;
							numberPionek = tab[i].getPionek();
							tab[i].setState(0);
							tab[i].setPionek(-1);
							break;
						}
					}
				}

				if (event.mouseButton.button == Mouse::Left && notup == 0) {
					if (tab[i].poleCheck((float)event.mouseButton.x, (float)event.mouseButton.y) == true) {
						if (color == 1 && tab[i].getState() == 0 && Ruchy.checkPossibility(i, tab, color) == true) {
							tab[i].setState(1);
							if (numberPionek == -1) { throw std::logic_error ("b³¹d przypisania pionka podniesionego"); }
							tab[i].setPionek(numberPionek);
							pionekWhite[numberPionek].setPos(tab[i].poleX(), tab[i].poleY()); // setPos
							pionekWhite[numberPionek].setCol(Color::White);
							notup = 1;
							if (Ruchy.getMovements() >= 2) { cout << "pionek zbity.";   Ruchy.CheckPossibilityTwoWhite(i, tab); };
							if (Ruchy.getFlag() == false) turn = true;
							else {
								if (Damka.damkaCheck(i, color, tab) == true)
									pionekWhite[numberPionek].setCol(Color::Yellow);
								Ruchy.setMovements(); turn = false;
							}
						}
						else if (color == 2 && tab[i].getState() == 0 && Ruchy.checkPossibility(i, tab, color) == true) {
							tab[i].setState(2);
							if (numberPionek == -1) { throw std::logic_error("b³¹d przypisania pionka podniesionego"); }
							tab[i].setPionek(numberPionek);
							pionekBlack[numberPionek].setPos(tab[i].poleX(), tab[i].poleY()); // setPos
							pionekBlack[numberPionek].setCol(Color::Black);
							notup = 1;
							if (Ruchy.getMovements() >= 2) Ruchy.CheckPossibilityTwoBlack(i, tab);
							if (Ruchy.getFlag() == false) turn = false;
							else {
								if (Damka.damkaCheck(i, color, tab) == true)
									pionekBlack[numberPionek].setCol(Color::Blue);
								Ruchy.setMovements(); turn = true;
							}
						}
						else if (color == 3 && tab[i].getState() == 0 && Damka.checkPossibilityDamka(i, color, tab) == true) {
							tab[i].setState(3);
							if (numberPionek == -1) { throw std::logic_error("b³¹d przypisania pionka podniesionego"); }
							tab[i].setPionek(numberPionek);
							pionekWhite[numberPionek].setPos(tab[i].poleX(), tab[i].poleY()); // setPos
							pionekWhite[numberPionek].setCol(Color::Yellow);
							notup = 1;
							if (Ruchy.getFlag() == false) turn = true;
							else turn = false;
						}
						else if (color == 4 && tab[i].getState() == 0 && Damka.checkPossibilityDamka(i, color, tab) == true) {
							tab[i].setState(4);
							if (numberPionek == -1) { throw std::logic_error("b³¹d przypisania pionka podniesionego"); }
							tab[i].setPionek(numberPionek);
							pionekBlack[numberPionek].setPos(tab[i].poleX(), tab[i].poleY()); // setPos
							pionekBlack[numberPionek].setCol(Color::Blue);
							notup = 1;
							if (Ruchy.getFlag() == false) turn = false;
							else turn = true;
						}
					}
					break;
				}
				break;
			}
			default: break;
			}
		}
		
		fstream plik;
		int a;

		if (Remaining_White.size() == 0 && notup == 1 && turn == true) {
			plik.open("wyniki.txt", std::ios_base::app);
			cout << endl << "KONIEC GRY! zwycieza gracz Czarny, ilosc pozostalych pionkow wynosi " << Remaining_Black.size() << "." << endl;
			plik << " zwyciezca: Gracz Czarny, iloscia " << Remaining_Black.size() << "pionkow." << "mecz odbyl sie: "; //<< dt;
			plik.close();

			window.close();
			cout << endl << "sprawdz plik wyniki.txt, aby zobaczyc historie wynikow";

			gra = false;

		}
		if (Remaining_Black.size() == 0 && notup == 1 && turn == false) {
			plik.open("wyniki.txt", std::ios_base::app);
			cout << endl << "KONIEC GRY! zwycieza gracz Bialy, ilosc pozostalych pionkow wynosi " << Remaining_White.size() << "." << endl;
			plik << " zwyciezca: Gracz Bialy, iloscia " << Remaining_White.size() << "pionkow. " << "mecz odbyl sie: "; // << dt;
			plik.close();
			window.close();

			cout << endl << "wpisz 1 aby zobaczyc historie wynikow" << endl << endl;
			cin >> a;
			if (a == 1) {
				string STRING;
				ifstream infile;
				infile.open("wyniki.txt");
				while (!infile.eof()) 
				{
					getline(infile, STRING);
					cout << STRING << endl; 
				}
				infile.close();
			}

			gra = false;

		}


		Remaining_White.clear();
		Remaining_Black.clear();
		
		window.display(); // do wyswietlania obiektow
		window.clear();

		/*while (oknoAplikacji.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				oknoAplikacji.close();

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				oknoAplikacji.close();

			if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle)
				oknoAplikacji.close();

		}*/

	} 
}