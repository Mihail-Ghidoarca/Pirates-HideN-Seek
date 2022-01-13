#include "Options.h"
using namespace std;

float p1x = 1000, p1y = 300, p1size = 150;
float p2x = 1000, p2y = 600, p2size = 150;
sf::Sprite backButton;
sf::RectangleShape patrat1;
sf::RectangleShape patrat2;

int isButtonPressed()
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
	{
		sf::Vector2i pozitieCursor = sf::Mouse::getPosition();

		if ((backButton.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			sf::sleep(sf::seconds(0.2f));
			return 3;
		}
		//Patrat1
		if ((patrat1.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			sf::sleep(sf::seconds(0.2f));
			return 1;
		}

		//Patrat2
		if ((patrat2.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			sf::sleep(sf::seconds(0.2f));
			return 2;
		}

	}
	return 0;
}


int Options()
{
	sf::Event event;

	sf::Texture background;
	if (!background.loadFromFile("images/background.jpg"))
	{
		cout << "Eroare" << endl;
	}

	sf::Texture X;
	if (!X.loadFromFile("images/bifat.png"))
	{
		cout << "Eroare" << endl;
	}

	sf::Texture buton;
	if (!buton.loadFromFile("images/butoane.jpg"))
	{
		cout << "Eroare" << endl;
	}
	
	sf::Texture back;
	if (!back.loadFromFile("images/back.png"))
	{
		cout << "Eroare" << endl;
	}

	sf::Text music;
	sf::Font font;
	font.loadFromFile("font.ttf");

	music.setFont(font);
	music.setString("Music");
	music.setCharacterSize(100);
	music.setOutlineThickness(5);
	music.setPosition(700.0f, 600.0f);

	sf::Text soundfx;

	soundfx.setFont(font);
	soundfx.setString("SFX");
	soundfx.setCharacterSize(100);
	soundfx.setOutlineThickness(5);
	soundfx.setPosition(700.0f, 300.0f);

	//sf::RectangleShape patrat1;
	patrat1.setSize(sf::Vector2f(p1size, p1size));
	patrat1.setTexture(&buton);
	patrat1.setOutlineThickness(3);
	patrat1.setOutlineColor(sf::Color::Black);
	patrat1.setPosition(p1x, p1y);

	//sf::RectangleShape patrat2;
	patrat2.setSize(sf::Vector2f(p2size, p2size));
	patrat2.setTexture(&buton);
	patrat2.setOutlineThickness(3);
	patrat2.setOutlineColor(sf::Color::Black);
	patrat2.setPosition(p2x, p2y);

	sf::Sprite bigX1(X);
	bigX1.setScale(0.45f, 0.45f);
	bigX1.setPosition(1000.0f, 310.0f);

	sf::Sprite bigX2(X);
	bigX2.setScale(0.45f, 0.45f);
	bigX2.setPosition(1000.0f, 610.0f);
	sf::Sprite fundal;
	fundal.setTexture(background);
	fundal.setPosition(0, 0);

	backButton.setTexture(back);
	backButton.setPosition(0, 0);
	backButton.setScale(0.1f, 0.1f);

	while (renderWindow.isOpen())
	{
		while (renderWindow.pollEvent(event))
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();

		renderWindow.clear(sf::Color::Black);

		renderWindow.draw(fundal);
		renderWindow.draw(music);
		renderWindow.draw(soundfx);
		renderWindow.draw(patrat1);
		renderWindow.draw(patrat2);
		renderWindow.draw(backButton);
		
		if(SFX==1)
			renderWindow.draw(bigX1);

		if (Music == 1)
			renderWindow.draw(bigX2);

		switch (isButtonPressed())
		{
		case 1:
			if (SFX == 1)
				SFX = 0;
			else if (SFX == 0)
				SFX = 1;
			break;
		case 2:
			if (Music == 1)
				Music = 0;
			else if (Music == 0)
				Music = 1;
			break;
		case 3:
			return 0;
		}

		renderWindow.display();
	}

	return 0;
}