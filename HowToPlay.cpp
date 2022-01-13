#include "HowToPlay.h"
using namespace std;

int ecran = 1;
sf::Sprite HTPbackButton;
sf::Sprite HTPforwardButton;

int HTPisButtonPressed()
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
	{
		sf::Vector2i pozitieCursor = sf::Mouse::getPosition();

		if ((HTPbackButton.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (ecran == 2)
			{
				ecran = 1;
				if (SFX == 1)
					click.play();
				sf::sleep(sf::seconds(0.2f));
					click.play();
			}
			else
			{
				if (SFX == 1)
					click.play();
				sf::sleep(sf::seconds(0.2f));
				return 1;
			}
		}

		if ((HTPforwardButton.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			ecran = 2;
			if (SFX == 1)
				click.play();
			sf::sleep(sf::seconds(0.2f));
		}

	}
	return 0;
}

int HowToPlay()
{
	sf::Event event;

	sf::Texture background;
	if (!background.loadFromFile("images/background.jpg"))
	{
		cout << "Eroare" << endl;
	}

	sf::Texture nerezolvat;
	if (!nerezolvat.loadFromFile("images/howtonerezolvat.png"))
	{
		cout << "Eroare" << endl;
	}

	sf::Texture chall;
	if (!chall.loadFromFile("images/challenge.png"))
	{
		cout << "Eroare" << endl;
	}

	sf::Texture back;
	if (!back.loadFromFile("images/back.png"))
	{
		cout << "Eroare" << endl;
	}

	sf::Sprite nerez;
	nerez.setTexture(nerezolvat);
	nerez.setPosition(400, 500);
	nerez.setScale(0.6f, 0.6f);

	sf::Sprite challenge;
	challenge.setTexture(chall);
	challenge.setPosition(670, 350);

	sf::Texture rezolvat;
	if (!rezolvat.loadFromFile("images/howtorezolvat.png"))
	{
		cout << "Eroare" << endl;
	}

	sf::Sprite rez;
	rez.setTexture(rezolvat);
	rez.setPosition(1000, 500);
	rez.setScale(0.6f, 0.6f);

	sf::Font font;
	font.loadFromFile("font.ttf");

	sf::Text step1;
	step1.setFont(font);
	step1.setString("1. The point of Pirates Hide n' Seek is to cover the 4 quadrants with the adequate\n pieces such that the only images shown are the ones the challenge requires.");
	step1.setCharacterSize(45);
	step1.setOutlineThickness(5);
	step1.setPosition(50.0f, 75.0f);

	sf::Text step2;
	step2.setFont(font);
	step2.setString("2. Solving the challenges in certain amounts of time will award you with up to 3\n golden stars.");
	step2.setCharacterSize(45);
	step2.setOutlineThickness(5);
	step2.setPosition(50.0f, 250.0f);

	sf::Text secondscreen;
	secondscreen.setFont(font);
	secondscreen.setString("1. Left click a piece to select it, then left click the quadrant you want to cover with it.\n\n 2. Rotate the piece using the UP arrow and lay it off on the game board by using SPACE.\n\n 3. You can use the right click to undo and reset the selected piece to its starting location.\n\n 4. After you've placed all the pieces, tap ENTER to submit your solution.");
	secondscreen.setCharacterSize(45);
	secondscreen.setOutlineThickness(5);
	secondscreen.setPosition(50.0f, 100.0f);

	HTPbackButton.setTexture(back);
	HTPbackButton.setPosition(0, 0);
	HTPbackButton.setScale(0.1f, 0.1f);

	HTPforwardButton.setTexture(back);
	HTPforwardButton.setPosition(1920, 85);
	HTPforwardButton.setScale(0.1f, 0.1f);
	HTPforwardButton.setRotation(180);

	sf::Texture ssjoc;
	if(!ssjoc.loadFromFile("images/ssjoc.png"))
	{
		cout << "Eroare" << endl;
	}

	sf::Sprite ecran2;
	ecran2.setTexture(ssjoc);
	ecran2.setPosition(530, 575);
	ecran2.setScale(0.5f, 0.5f);

	sf::Sprite fundal;
	fundal.setTexture(background);
	fundal.setPosition(0, 0);

	while (renderWindow.isOpen())
	{
		while (renderWindow.pollEvent(event))
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();

		renderWindow.clear();

		//How To Play #1
		if(ecran==1)
		{
			renderWindow.clear();
			renderWindow.draw(fundal);
			renderWindow.draw(step1);
			renderWindow.draw(step2);
			renderWindow.draw(rez);
			renderWindow.draw(nerez);
			renderWindow.draw(challenge);
			renderWindow.draw(HTPforwardButton);
		}
		//How To Play #2
		else
		{
			renderWindow.clear();
			renderWindow.draw(fundal);
			renderWindow.draw(secondscreen);
			renderWindow.draw(ecran2);

		}
		renderWindow.draw(HTPbackButton);

		if (HTPisButtonPressed() == 1)
			return 0;

		renderWindow.display();

	}

	return 0;
}