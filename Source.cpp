#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <iostream>

#include "Player.hpp"
#include "Bullet.hpp"

using namespace sf;

int main()
{	
	sf::RenderWindow window(sf::VideoMode(800, 600),
		"Shooting Range", sf::Style::Default);
	window.setFramerateLimit(60);

	Player enemy(Vector2f(window.getSize().x - 100, 50),nullptr);
	Player player(Vector2f(50, window.getSize().y - 100),&enemy);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Space)
				{
					player.shoot();
				}
				break;
			case Event::Closed:
				window.close();
				break;
			}
		}	

		player.move();
		//p2.move();
		std::cout << enemy.getHP() << std::endl;
		window.clear();

		player.draw(window);
		enemy.draw(window);

		window.display();
	}
	return 0;
}
	
