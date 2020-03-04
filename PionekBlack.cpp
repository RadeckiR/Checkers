#include "PionekBlack.h"

PionekBlack::PionekBlack()
{
	shape.setRadius(this->pionekRadius);
	shape.setOrigin(this->pionekRadius, this->pionekRadius);
}

void PionekBlack::setPos(float x, float y)
{
	shape.setPosition(x, y);
}

void PionekBlack::draw(sf::RenderTarget& target, sf::RenderStates state) const // nie bedzie zmieniac zadnych pol naszej klasy
{
	target.draw(this->shape, state);
}

void PionekBlack::setCol(sf::Color col)
{
	shape.setFillColor(col);
}

//sf::Color pionek::getCol() 
//{
//	return shape.getFillColor();
//}

