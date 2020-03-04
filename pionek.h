#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class pionek : public sf::Drawable
{
private:
	sf::CircleShape shape; // (sf::Vector2f(200, 200));
	const float pionekRadius{ 30.0f };
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const override; // sam wymyslil, ale jest tez jakis wbudowany draw
public:
	pionek();
	virtual void setPos(float x1, float y1);
	virtual void setCol(sf::Color col);
	~pionek() = default; // domyslny dekonstruktor
};

