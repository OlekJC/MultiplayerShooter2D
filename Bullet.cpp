#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f vec)
{
	bullet.setSize(sf::Vector2f(30, 5));
	bullet.setFillColor(sf::Color::Red);
	bullet.setPosition(vec.x+sidePlayerLength+1,vec.y);
}

void Bullet::draw(sf::RenderWindow& wnd) 
{
	wnd.draw(bullet); 
}

