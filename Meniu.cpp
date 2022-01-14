#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
sf::RenderWindow renderWindow(sf::VideoMode(1920, 1080), "Meniu", sf::Style::Fullscreen);
sf::Sound click;
bool SFX = 1;
bool Music = 1;
int vStele[31];
int culoare = 0;
#include "Meniu.h"

sf::RectangleShape sPlay;
sf::RectangleShape sHowToPlay;
sf::RectangleShape sOptions;
sf::RectangleShape sExit;
sf::SoundBuffer sButon;

using namespace std;

int MeniuIsButtonPressed()
{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
		{
			sf::Vector2i pozitieCursor = sf::Mouse::getPosition();

			//Buton Play
			if (sPlay.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
			{
				if(SFX==1)
					click.play();
				sf::sleep(sf::seconds(0.2f));
				return 1;
			}
			//Buton How to Play
			else if (sHowToPlay.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
			{
				if (SFX == 1)
					click.play();
				sf::sleep(sf::seconds(0.2f));
				return 2;
			}
			//Buton Options
			else if (sOptions.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
			{
				if (SFX == 1)
					click.play();
				sf::sleep(sf::seconds(0.2f));
				return 3;
			}

			//Buton Exit
			else if (sExit.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
			{
				if (SFX == 1)
					click.play();
				sf::sleep(sf::seconds(0.2f));
				return 4;
			}
		}
	return 0;
}

int main()
{
	sf::Event event;

	sf::Text titlu;
	sf::Font font;
	font.loadFromFile("font.ttf");

	sf::Texture background;
	if (!background.loadFromFile("images/background.jpg"))
	{
		cout << "Eroare" << endl;
	}

	if (!sButon.loadFromFile("images/click.wav"))
	{
		cout << "Eroare" << endl;
	}

	click.setBuffer(sButon);

	titlu.setFont(font);
	titlu.setString("Pirates Hide N' Seek");
	titlu.setCharacterSize(100);
	titlu.setOutlineThickness(5);
	titlu.setFillColor(sf::Color::White);
	titlu.setPosition(500.0f, 0.0f);

	sf::Text tPlay;
	tPlay.setFont(font);
	tPlay.setString("Play");
	tPlay.setCharacterSize(50);
	tPlay.setOutlineThickness(5);
	tPlay.setFillColor(sf::Color::White);
	tPlay.setPosition(910, 240);

	sf::Text tHowToPlay;
	tHowToPlay.setFont(font);
	tHowToPlay.setString("How to play");
	tHowToPlay.setCharacterSize(50);
	tHowToPlay.setOutlineThickness(5);
	tHowToPlay.setFillColor(sf::Color::White);
	tHowToPlay.setPosition(830, 440);

	sf::Text tOptions;
	tOptions.setFont(font);
	tOptions.setString("Options");
	tOptions.setCharacterSize(50);
	tOptions.setOutlineThickness(5);
	tOptions.setFillColor(sf::Color::White);
	tOptions.setPosition(880, 640);

	sf::Text tExit;
	tExit.setFont(font);
	tExit.setString("Exit");
	tExit.setCharacterSize(50);
	tExit.setOutlineThickness(5);
	tExit.setFillColor(sf::Color::White);
	tExit.setPosition(900, 840);

	sf::Texture buton;

	if (!buton.loadFromFile("images/butoane.jpg"))
	{
		cout << "Eroare" << endl;
	}

	sPlay.setSize(sf::Vector2f(400, 150));
	sPlay.setOutlineThickness(5);
	sPlay.setOutlineColor(sf::Color::Black);
	sPlay.setPosition(760, 200);
	sPlay.setTexture(&buton);

	sHowToPlay.setSize(sf::Vector2f(400, 150));
	sHowToPlay.setOutlineThickness(5);
	sHowToPlay.setOutlineColor(sf::Color::Black);
	sHowToPlay.setPosition(760, 400);
	sHowToPlay.setTexture(&buton);

	sOptions.setSize(sf::Vector2f(400, 150));
	sOptions.setOutlineThickness(5);
	sOptions.setOutlineColor(sf::Color::Black);
	sOptions.setPosition(760, 600);
	sOptions.setTexture(&buton);

	sExit.setSize(sf::Vector2f(400, 150));
	sExit.setOutlineThickness(5);
	sExit.setOutlineColor(sf::Color::Black);
	sExit.setPosition(760, 800);
	sExit.setTexture(&buton);

	sf::Sprite fundal;
	fundal.setTexture(background);
	fundal.setPosition(0, 0);

	while(renderWindow.isOpen())
	{
		while (renderWindow.pollEvent(event))
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();



		renderWindow.clear();

		renderWindow.draw(fundal);
		renderWindow.draw(sPlay);
		renderWindow.draw(sOptions);
		renderWindow.draw(sHowToPlay);
		renderWindow.draw(sExit);
		renderWindow.draw(titlu);
		renderWindow.draw(tPlay);
		renderWindow.draw(tOptions);
		renderWindow.draw(tHowToPlay);
		renderWindow.draw(tExit);

		switch (MeniuIsButtonPressed())
		{
			case 1:
				renderWindow.clear();
				renderWindow.setTitle("Challenges");
				Challenge();
				break;
			case 2:
				renderWindow.clear();
				renderWindow.setTitle("How to Play");
				HowToPlay();
				break;
			case 3:
				renderWindow.clear();
				renderWindow.setTitle("Options");
				Options();
				break;
			case 4:
				renderWindow.close();
				break;
		}

		renderWindow.display();
	}

	return 0;
}