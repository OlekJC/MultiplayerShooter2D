#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "Player.hpp"
#include "Bullet.hpp"

using namespace sf;

int main()
{
	size_t b_size=0;
	sf::RenderWindow window(sf::VideoMode(800, 600),
		"Shooting Range", sf::Style::Default);
	window.setFramerateLimit(60);

	Player p1(Vector2f(50, window.getSize().y - 100));
	Player p2(Vector2f(window.getSize().x - 100, 50));
	std::vector<Bullet> clip;
	//bool isFiring = false;

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
					Bullet bullet(p1.getPosition());
					clip.push_back(bullet);
					b_size++;
					std::cout << "Liczba kul : "<<clip.size()<<": "<< b_size*sizeof(Bullet)  << std::endl;
				}
				break;
			case Event::Closed:
				window.close();
				break;
			}
		}

		/*
		for (auto& x : clip)
		{
			x.fire();
			x.draw(window);
		}
			*/
			/*
			for (auto& x : p1.getClip())
			{
				x.setPosition(p1.getPosition());
				x.fire();
				x.draw(window);
			}*/
		p1.move();
		//p2.move();

		window.clear();
		for (int i = 0; i < clip.size(); i++)
		{
			clip[i].fire();
			clip[i].draw(window);
		}
		
		p1.draw(window);
		p2.draw(window);
		window.display();
	}
	return 0;
}
	
