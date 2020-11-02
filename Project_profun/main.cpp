#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<vector>

int main()
{
	//แสดงหน้าจอ
	sf::RenderWindow window(sf::VideoMode(512, 512), "Game><", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape player(sf::Vector2f(70.0f, 70.0f));
	sf::CircleShape enemy;
	enemy.setRadius(50);
	enemy.setFillColor(sf::Color::Blue);
	enemy.setOutlineColor(sf::Color::Yellow);
	enemy.setOutlineThickness(5);
	enemy.setPosition(400, 200);

	sf::CircleShape bullet;
	bullet.setRadius(5);
	bullet.setFillColor(sf::Color::White);
	
	int shipX = player.getSize().x;
	int shipY = player.getSize().y;
	
	float dx = 0;
	float dy = 0;

	sf::SoundBuffer soundeffect;
	soundeffect.loadFromFile("sound/shooting.WAV");
	sf::Sound shooteffect;
	shooteffect.setBuffer(soundeffect);


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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) and player.getPosition().x < 442)
		{
			dx = 1.0;
			player.move(0.1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) and player.getPosition().x > 0)
		{
			dx = -1.0;
			player.move(-0.1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and player.getPosition().y > 0)
		{
			dy = -1.0;
			player.move(0,-0.1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and player.getPosition().y < 443)
		{
			dy = 1.0;
			player.move(0, 0.1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			shooteffect.play();
		}
		window.clear();
		window.draw(player);
		window.draw(enemy);
		window.display();
		
	}
	return 0;
}
