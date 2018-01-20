#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <iostream>
#include <Windows.h>

#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

//using namespace sf;

bool help;

int main()
{	
	sf::IpAddress yourIp;
	//std::cout << yourIp << std::endl;
	/*
	unsigned int port = 5001;
	IpAddress playerIp;
	playerIp.getPublicAddress(sf::Time(sf::seconds(5)));
	std::cout << "Twoj numer IP to" << playerIp 
		<< "\n" <<"Podaj numer IP przeciwnika :";
	std::string enemyIp("");
	std::getline(std::cin, enemyIp);
	*/

	sf::RenderWindow window(sf::VideoMode(800, 600),
		"Shooting Range", sf::Style::Default);
	window.setFramerateLimit(60);
	Enemy enemy(sf::Vector2f(window.getSize().x - 100, 50));
	Player player(sf::Vector2f(50, window.getSize().y - 100));
	player.setEnemy(&enemy);
	enemy.setEnemy(&player);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Space)
				{
					player.shoot();
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}	

		player.move();
		if (enemy.getBody().getPosition().y < 540 && help)
			enemy.move();
		else
			enemy.move();
		//p2.move();
		//system("cls");
		//std::cout << enemy.getHP() << std::endl;
		window.clear();

		player.draw(window);
		enemy.draw(window);

		window.display();
	}
	return 0;
}
	
