#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <cstdlib>

#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"



int main()
{	
	unsigned short myPort=5001;
	unsigned short enemyPort = 5002;

	std::cout << "Your local address:\t" <<sf::IpAddress::getLocalAddress()
		<<"\nYour public address:\t"<< sf::IpAddress::getPublicAddress() << std::endl;
	
	std::cout << "Pass enemy's IP:\t";
	sf::IpAddress enemyIp;
	std::cin >> enemyIp;
	sf::UdpSocket socket;
	
	socket.setBlocking(false);
	std::cout << "Wpisz your port :\t";
	std::cin >> myPort;
	socket.bind(myPort);
	std::cout << "Pass enemy's port:\t";
	std::cin >> enemyPort;
	std::cout << "Socket succesfully bound to " << myPort << std::endl;
	
	sf::Packet sendPacket,receivePacket;
	
	std::cin.get();

	sf::RenderWindow window(sf::VideoMode(800, 600),
		"Shooting Range", sf::Style::Default);
	window.setFramerateLimit(60);
	Enemy enemy(sf::Vector2f(window.getSize().x - 100, 50));
	Player player(sf::Vector2f(50, 100));
	player.setEnemy(&enemy);
	enemy.setEnemy(&player);
	//int enemy_y=0;
	//int player_y;
	sf::Uint16 enemy_y=2;
	sf::Uint16 player_y;

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
				if (event.key.code == sf::Keyboard::B)
				{
					enemy.setY(200);
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}	

		player.move();
		player_y = player.getY();
		sendPacket << player_y;
		std::cout << player_y << std::endl;
		socket.send(sendPacket, enemyIp, enemyPort);
		
		socket.receive(receivePacket, enemyIp, myPort);
		if (receivePacket >> enemy_y)
			enemy.body.setPosition(window.getSize().x - 100,enemy_y);
		std::cout << enemy_y << std::endl;
		
		//sendPacket << l;
		//socket.send(sendPacket, enemyIp, port);
		//socket.receive(recievePacket,enemyIp,port);
		//receivePacket >> k;
		//enemy.setY(y);
		//std::cout << k << std::endl;
		//std::cout << "Pakiet odebrany!" << std::endl;

		window.clear();

		player.draw(window);
		enemy.draw(window);

		window.display();
	}
	return 0;
}