#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f vec)
{
	bullet.setSize(sf::Vector2f(30, 5));
	bullet.setFillColor(sf::Color::Red);
	bullet.setPosition(vec);
}