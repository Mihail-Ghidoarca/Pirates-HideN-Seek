#include "Challenge.h"
using namespace std;

sf::RectangleShape ch1;
sf::RectangleShape ch2;
sf::RectangleShape ch3;
sf::RectangleShape ch4;
sf::RectangleShape ch5;
sf::RectangleShape ch6;
sf::RectangleShape ch7;
sf::RectangleShape ch8;
sf::RectangleShape ch9;
sf::RectangleShape ch10;
sf::Sprite CHbackButton;
sf::Sprite Stele1;
sf::Sprite Stele2;
sf::Sprite Stele3;
sf::Sprite Stele4;
sf::Sprite Stele5;
sf::Sprite Stele6;
sf::Sprite Stele7;
sf::Sprite Stele8;
sf::Sprite Stele9;
sf::Sprite Stele10;
int x = 100;

static int isButtonPressed()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
	{
		sf::Vector2i pozitieCursor = sf::Mouse::getPosition();

		if ((CHbackButton.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			sf::sleep(sf::seconds(0.2f));
			
			return 100;
		}
		if ((ch1.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			//sf::sleep(sf::seconds(0.2f));
			return 1;
		}
		if ((ch2.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			//sf::sleep(sf::seconds(0.2f));
			return 2;
		}
		if ((ch3.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			//sf::sleep(sf::seconds(0.2f));
			return 3;
		}
		if ((ch4.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			//sf::sleep(sf::seconds(0.2f));
			return 4;
		}
		if ((ch5.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			//sf::sleep(sf::seconds(0.2f));
			return 5;
		}
		if ((ch6.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			//sf::sleep(sf::seconds(0.2f));
			return 6;
		}
		if ((ch7.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			//sf::sleep(sf::seconds(0.2f));
			return 7;
		}
		if ((ch8.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			//sf::sleep(sf::seconds(0.2f));
			return 8;
		}
		if ((ch9.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			//sf::sleep(sf::seconds(0.2f));
			return 9;
		}
		if ((ch10.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
		{
			if (SFX == 1)
				click.play();
			//sf::sleep(sf::seconds(0.2f));
			return 10;
		}
	}

	return 0;
}
int Challenge()
{
	sf::Event event;
	
	sf::Font font;
	font.loadFromFile("font.ttf");

	sf::Texture stele0;
	if (!stele0.loadFromFile("images/0stele.png"))
	{
		cout << "Eroare" << endl;
	}
	sf::Texture stele1;
	if (!stele1.loadFromFile("images/1stea.png"))
	{
		cout << "Eroare" << endl;
	}
	sf::Texture stele2;
	if (!stele2.loadFromFile("images/2stele.png"))
	{
		cout << "Eroare" << endl;
	}
	sf::Texture stele3;
	if (!stele3.loadFromFile("images/3stele.png"))
	{
		cout << "Eroare" << endl;
	}

	sf::Texture buton;
	if (!buton.loadFromFile("images/butoane.jpg"))
	{
		cout << "Eroare" << endl;
	}

	sf::Texture background;
	if (!background.loadFromFile("images/background.jpg"))
	{
		cout << "Eroare" << endl;
	}

	sf::Texture back;
	if (!back.loadFromFile("images/back.png"))
	{
		cout << "Eroare" << endl;
	}
	sf::Text text1;
	text1.setFont(font);
	text1.setString("1");
	text1.setCharacterSize(100);
	text1.setOutlineThickness(5);
	text1.setPosition(125, 125);

	sf::Text text2;
	text2.setFont(font);
	text2.setString("2");
	text2.setCharacterSize(100);
	text2.setOutlineThickness(5);
	text2.setPosition(300, 125);

	sf::Text text3;
	text3.setFont(font);
	text3.setString("3");
	text3.setCharacterSize(100);
	text3.setOutlineThickness(5);
	text3.setPosition(475, 125);

	sf::Text text4;
	text4.setFont(font);
	text4.setString("4");
	text4.setCharacterSize(100);
	text4.setOutlineThickness(5);
	text4.setPosition(650, 125);

	sf::Text text5;
	text5.setFont(font);
	text5.setString("5");
	text5.setCharacterSize(100);
	text5.setOutlineThickness(5);
	text5.setPosition(825, 125);

	sf::Text text6;
	text6.setFont(font);
	text6.setString("6");
	text6.setCharacterSize(100);
	text6.setOutlineThickness(5);
	text6.setPosition(1000, 125);

	sf::Text text7;
	text7.setFont(font);
	text7.setString("7");
	text7.setCharacterSize(100);
	text7.setOutlineThickness(5);
	text7.setPosition(1175, 125);

	sf::Text text8;
	text8.setFont(font);
	text8.setString("8");
	text8.setCharacterSize(100);
	text8.setOutlineThickness(5);
	text8.setPosition(1350, 125);
	
	sf::Text text9;
	text9.setFont(font);
	text9.setString("9");
	text9.setCharacterSize(100);
	text9.setOutlineThickness(5);
	text9.setPosition(1525, 125);

	sf::Text text10;
	text10.setFont(font);
	text10.setString("10");
	text10.setCharacterSize(100);
	text10.setOutlineThickness(5);
	text10.setPosition(1700, 125);

/////////////////////////////////////////////////////////////////////////////////////////////////////

	//sf::RectangleShape ch1;
	ch1.setSize(sf::Vector2f(100, 100));
	ch1.setTexture(&buton);
	ch1.setOutlineThickness(2);
	ch1.setOutlineColor(sf::Color::Black);
	ch1.setPosition(100, 150);

	//sf::RectangleShape ch2;
	ch2.setSize(sf::Vector2f(100, 100));
	ch2.setTexture(&buton);
	ch2.setOutlineThickness(2);
	ch2.setOutlineColor(sf::Color::Black);
	ch2.setPosition(275, 150);

	//sf::RectangleShape ch3;
	ch3.setSize(sf::Vector2f(100, 100));
	ch3.setTexture(&buton);
	ch3.setOutlineThickness(2);
	ch3.setOutlineColor(sf::Color::Black);
	ch3.setPosition(450, 150);

	//sf::RectangleShape ch4;
	ch4.setSize(sf::Vector2f(100, 100));
	ch4.setTexture(&buton);
	ch4.setOutlineThickness(2);
	ch4.setOutlineColor(sf::Color::Black);
	ch4.setPosition(625, 150);

	//sf::RectangleShape ch5;
	ch5.setSize(sf::Vector2f(100, 100));
	ch5.setTexture(&buton);
	ch5.setOutlineThickness(2);
	ch5.setOutlineColor(sf::Color::Black);
	ch5.setPosition(800, 150);

	//sf::RectangleShape ch6;
	ch6.setSize(sf::Vector2f(100, 100));
	ch6.setTexture(&buton);
	ch6.setOutlineThickness(2);
	ch6.setOutlineColor(sf::Color::Black);
	ch6.setPosition(975, 150);

	//sf::RectangleShape ch7;
	ch7.setSize(sf::Vector2f(100, 100));
	ch7.setTexture(&buton);
	ch7.setOutlineThickness(2);
	ch7.setOutlineColor(sf::Color::Black);
	ch7.setPosition(1150, 150);

	//sf::RectangleShape ch8;
	ch8.setSize(sf::Vector2f(100, 100));
	ch8.setTexture(&buton);
	ch8.setOutlineThickness(2);
	ch8.setOutlineColor(sf::Color::Black);
	ch8.setPosition(1325, 150);

	//sf::RectangleShape ch9;
	ch9.setSize(sf::Vector2f(100, 100));
	ch9.setTexture(&buton);
	ch9.setOutlineThickness(2);
	ch9.setOutlineColor(sf::Color::Black);
	ch9.setPosition(1500, 150);

	//sf::RectangleShape ch10;
	ch10.setSize(sf::Vector2f(100, 100));
	ch10.setTexture(&buton);
	ch10.setOutlineThickness(2);
	ch10.setOutlineColor(sf::Color::Black);
	ch10.setPosition(1675, 150);

	CHbackButton.setTexture(back);
	CHbackButton.setPosition(0, 0);
	CHbackButton.setScale(0.1f, 0.1f);

	sf::Sprite Stele1;
	Stele1.setTexture(stele0);
	Stele1.setPosition(100, 225);
	Stele1.setScale(0.1f, 0.1f);

	sf::Sprite Stele2;
	Stele2.setTexture(stele0);
	Stele2.setPosition(275, 225);
	Stele2.setScale(0.1f, 0.1f);

	sf::Sprite Stele3;
	Stele3.setTexture(stele0);
	Stele3.setPosition(450, 225);
	Stele3.setScale(0.1f, 0.1f);

	sf::Sprite Stele4;
	Stele4.setTexture(stele0);
	Stele4.setPosition(625, 225);
	Stele4.setScale(0.1f, 0.1f);

	sf::Sprite Stele5;
	Stele5.setTexture(stele0);
	Stele5.setPosition(800, 225);
	Stele5.setScale(0.1f, 0.1f);

	sf::Sprite Stele6;
	Stele6.setTexture(stele0);
	Stele6.setPosition(975, 225);
	Stele6.setScale(0.1f, 0.1f);

	sf::Sprite Stele7;
	Stele7.setTexture(stele0);
	Stele7.setPosition(1150, 225);
	Stele7.setScale(0.1f, 0.1f);

	sf::Sprite Stele8;
	Stele8.setTexture(stele0);
	Stele8.setPosition(1325, 225);
	Stele8.setScale(0.1f, 0.1f);

	sf::Sprite Stele9;
	Stele9.setTexture(stele0);
	Stele9.setPosition(1500, 225);
	Stele9.setScale(0.1f, 0.1f);

	sf::Sprite Stele10;
	Stele10.setTexture(stele0);
	Stele10.setPosition(1675, 225);
	Stele10.setScale(0.1f, 0.1f);

	sf::Sprite fundal;
	fundal.setTexture(background);
	fundal.setPosition(0, 0);

	/*for (int i = 1; i <= 30; i++)
	{
		if (vStele[i] == 3 && i == 1)
			Stele1.setTexture(stele3);
		else if (vStele[i] == 2 && i == 1)
			Stele1.setTexture(stele2);
		else if (vStele[i] == 1 && i == 1)
			Stele1.setTexture(stele1);
	}*/

	while (renderWindow.isOpen())
	{
		while (renderWindow.pollEvent(event))
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();

		for (int i = 1; i <= 30; i++)
		{
			if (vStele[i] == 3 && i == 1)
				Stele1.setTexture(stele3);
			else if (vStele[i] == 2 && i == 1)
				Stele1.setTexture(stele2);
			else if (vStele[i] == 1 && i == 1)
				Stele1.setTexture(stele1);
		}

		renderWindow.clear();

		renderWindow.draw(fundal);
		renderWindow.draw(CHbackButton);
		renderWindow.draw(ch1);
		renderWindow.draw(text1);
		renderWindow.draw(Stele1);
		renderWindow.draw(ch2);
		renderWindow.draw(text2);
		renderWindow.draw(Stele2);
		renderWindow.draw(ch3);
		renderWindow.draw(text3);
		renderWindow.draw(Stele3);
		renderWindow.draw(ch4);
		renderWindow.draw(text4);
		renderWindow.draw(Stele4);
		renderWindow.draw(ch5);
		renderWindow.draw(text5);
		renderWindow.draw(Stele5);
		renderWindow.draw(ch6);
		renderWindow.draw(text6);
		renderWindow.draw(Stele6);
		renderWindow.draw(ch7);
		renderWindow.draw(text7);
		renderWindow.draw(Stele7);
		renderWindow.draw(ch8);
		renderWindow.draw(text8);
		renderWindow.draw(Stele8);
		renderWindow.draw(ch9);
		renderWindow.draw(text9);
		renderWindow.draw(Stele9);
		renderWindow.draw(ch10);
		renderWindow.draw(text10);
		renderWindow.draw(Stele10);
		int nivel;
		switch (isButtonPressed())
		{
		case 100:
			return 0;

		case 1:
			renderWindow.clear();
			nivel = 1;
			Play(nivel);
			break;
		case 2:
			renderWindow.clear();
			nivel = 2;
			Play(nivel);
			break;
		case 3:
			renderWindow.clear();
			nivel = 3;
			Play(nivel);
			break;
		case 4:
			renderWindow.clear();
			nivel = 4;
			Play(nivel);
			break;
		case 5:
			renderWindow.clear();
			nivel = 5;
			Play(nivel);
			break;
		case 6:
			renderWindow.clear();
			nivel = 6;
			Play(nivel);
			break;
		case 7:
			renderWindow.clear();
			nivel = 7;
			Play(nivel);
			break;
		case 8:
			renderWindow.clear();
			nivel = 8;
			Play(nivel);
			break;
		case 9:
			renderWindow.clear();
			nivel = 9;
			Play(nivel);
			break;
		case 10:
			renderWindow.clear();
			nivel = 10;
			Play(nivel);
			break;
		default:
			break;
		}

		renderWindow.display();
	}

	return 0;
}