#pragma once
#include <SFML/Graphics.hpp>

class pionek : public sf::Drawable
{
private:
	sf::CircleShape shape; // (sf::Vector2f(200, 200));
	const float pionekRadius{ 30.0f };
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override; // sam wymyslil, ale jest tez jakis wbudowany draw
public:
	pionek();
	void setPos(float x1, float y1);
	void setCol(sf::Color col);
	~pionek() = default; // domyslny dekonstruktor
};

