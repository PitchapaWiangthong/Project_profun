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
	player.setPosition(0, 0);
	sf::CircleShape enemy;
	window.setFramerateLimit(1000);

	int isShoot = false;

	enemy.setRadius(50);
	enemy.setFillColor(sf::Color::Blue);
	enemy.setOutlineColor(sf::Color::Yellow);
	enemy.setOutlineThickness(5);
	enemy.setPosition(400, 200);

	sf::CircleShape bulletPlayer;
	bulletPlayer.setRadius(10);
	bulletPlayer.setFillColor(sf::Color::Magenta);
	bulletPlayer.setPosition(-2000.f, -2000.f);

	sf::CircleShape bulletEnemy;
	bulletEnemy.setRadius(10);
	bulletEnemy.setFillColor(sf::Color::Red);
	bulletEnemy.setPosition(375, 246);


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

		if (1)
		{
			bulletEnemy.move(-0.05, 0);
			if (bulletEnemy.getPosition().x <= 0)
			{
				bulletEnemy.setPosition(375, 246);
			}
		}
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
			player.move(0.15, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) and player.getPosition().x > 0)
		{
			dx = -1.0;
			player.move(-0.15, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and player.getPosition().y > 0)
		{
			dy = -1.0;
			player.move(0,-0.15);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and player.getPosition().y < 443)
		{
			dy = 1.0;
			player.move(0, 0.15);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			shooteffect.play();
			bulletPlayer.setPosition(player.getPosition().x + 70, player.getPosition().y + 27);
			isShoot = true;
		}
			if (isShoot == true)
			{
				bulletPlayer.move(0.1, 0);
			}

			if (bulletPlayer.getGlobalBounds().intersects(enemy.getGlobalBounds()))
			{
				bulletPlayer.setPosition(100, -50);
			}
			if (bulletEnemy.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				bulletEnemy.setPosition(375, 246);
				shooteffect.play();
			}

		window.clear();		

		window.draw(bulletEnemy);
		window.draw(player);
		window.draw(bulletPlayer);
		window.draw(enemy);
		
		window.display();
		
	}
	return 0;
}
