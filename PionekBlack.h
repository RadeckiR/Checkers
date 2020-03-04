#pragma once
#include "pionek.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class PionekBlack :
	public pionek
{
private:
	sf::CircleShape shape; // (sf::Vector2f(200, 200));
	const float pionekRadius{ 30.0f };
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	PionekBlack();
	void setPos(float x1, float y1);
	void setCol(sf::Color col);
	~PionekBlack() = default;
};

