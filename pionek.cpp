#include "pionek.h"

pionek::pionek()
{
	shape.setRadius(this->pionekRadius);
	shape.setOrigin(this->pionekRadius, this->pionekRadius);
}

void pionek::setPos(float x, float y)
{
	shape.setPosition(x, y);
}

void pionek::draw(sf::RenderTarget& target, sf::RenderStates state) const // nie bedzie zmieniac zadnych pol naszej klasy
{
	target.draw(this->shape, state);
}

void pionek::setCol(sf::Color col) 
{
	shape.setFillColor(col);
}

