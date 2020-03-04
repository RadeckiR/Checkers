#include "PionekWhite.h"
PionekWhite::PionekWhite()
{
	shape.setRadius(this->pionekRadius);
	shape.setOrigin(this->pionekRadius, this->pionekRadius);
}

void PionekWhite::setPos(float x, float y)
{
	shape.setPosition(x, y);
}

void PionekWhite::draw(sf::RenderTarget& target, sf::RenderStates state) const // nie bedzie zmieniac zadnych pol naszej klasy
{
	target.draw(this->shape, state);
}

void PionekWhite::setCol(sf::Color col)
{
	shape.setFillColor(col);
}