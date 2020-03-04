#include "pole.h"
#include <iostream>

void pole::poleRead(float x, float y)
{
	X = x;
	Y = y;
	state = 0;
	rshape.setSize(sf::Vector2f(size, size));
	rshape.setPosition(X, Y);
	rshape.setFillColor(sf::Color::Blue);
}

void pole::draw(sf::RenderTarget& target, sf::RenderStates state) const // nie bedzie zmieniac zadnych pol naszej klasy
{
	target.draw(this->rshape, state);
}

bool pole::poleCheck(float x1, float y1)
{
	if (X <= x1 && x1 <= (X + size) && Y <= y1 && y1 <= (Y + size))
		return true;
	else return false;
}

void pole::setState(int s) // state: 0 - wolny, 1 - biały, 2 - czarny
{
	state = s;
}

int pole::getState()
{
	return state;
}

void pole::setPionek(int p)
{
	pionekk = p;
}

int pole::getPionek()
{
	return pionekk;
}

float pole::poleX()
{
	// std::cout << X + 68.75 / 2 << std::endl;
	return (float)(X + 68.75 / 2);
}

float pole::poleY()
{
	// std::cout << Y + 68.75 / 2 << std::endl;
	return (float)(Y + 68.75 / 2);
}

