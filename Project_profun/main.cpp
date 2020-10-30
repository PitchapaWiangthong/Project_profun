#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<iostream>

int main()
{
	//แสดงหน้าจอ
	sf::RenderWindow window(sf::VideoMode(512, 512), "Game><", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape player(sf::Vector2f(70.0f, 70.0f));

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.draw(player);
		window.display();
		
	}
	return 0;
}
