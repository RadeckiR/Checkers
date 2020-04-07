#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class pole : public sf::Drawable
{
private:
	// sf::Vector2f v1(68.75f, 68.75f);
	float X, Y;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
protected:
	int state;
	int pionekk;
	sf::RectangleShape rshape;
	float size = 68.75;
public:
	void poleRead(float x, float y);
	bool poleCheck(float x1, float y1);
	float poleX();
	float poleY();
	void setState(int s);
	int getState();
	void setPionek(int p);
	int getPionek();
	~pole() = default;
};