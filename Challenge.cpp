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
sf::RectangleShape ch11;
sf::RectangleShape ch12;
sf::RectangleShape ch13;
sf::RectangleShape ch14;
sf::RectangleShape ch15;
sf::RectangleShape ch16;
sf::RectangleShape ch17;
sf::RectangleShape ch18;
sf::RectangleShape ch19;
sf::RectangleShape ch20;
sf::RectangleShape ch21;
sf::RectangleShape ch22;
sf::RectangleShape ch23;
sf::RectangleShape ch24;
sf::RectangleShape ch25;
sf::RectangleShape ch26;
sf::RectangleShape ch27;
sf::RectangleShape ch28;
sf::RectangleShape ch29;
sf::RectangleShape ch30;

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
sf::Sprite Stele11;
sf::Sprite Stele12;
sf::Sprite Stele13;
sf::Sprite Stele14;
sf::Sprite Stele15;
sf::Sprite Stele16;
sf::Sprite Stele17;
sf::Sprite Stele18;
sf::Sprite Stele19;
sf::Sprite Stele20;
sf::Sprite Stele21;
sf::Sprite Stele22;
sf::Sprite Stele23;
sf::Sprite Stele24;
sf::Sprite Stele25;
sf::Sprite Stele26;
sf::Sprite Stele27;
sf::Sprite Stele28;
sf::Sprite Stele29;
sf::Sprite Stele30;

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

	sf::Text text11;
	text11.setFont(font);
	text11.setString("11");
	text11.setCharacterSize(100);
	text11.setOutlineThickness(5);
	text11.setPosition(125, 425);

	sf::Text text12;
	text12.setFont(font);
	text12.setString("12");
	text12.setCharacterSize(100);
	text12.setOutlineThickness(5);
	text12.setPosition(300, 425);

	sf::Text text13;
	text13.setFont(font);
	text13.setString("13");
	text13.setCharacterSize(100);
	text13.setOutlineThickness(5);
	text13.setPosition(475, 425);

	sf::Text text14;
	text14.setFont(font);
	text14.setString("14");
	text14.setCharacterSize(100);
	text14.setOutlineThickness(5);
	text14.setPosition(650, 425);

	sf::Text text15;
	text15.setFont(font);
	text15.setString("15");
	text15.setCharacterSize(100);
	text15.setOutlineThickness(5);
	text15.setPosition(825, 425);

	sf::Text text16;
	text16.setFont(font);
	text16.setString("16");
	text16.setCharacterSize(100);
	text16.setOutlineThickness(5);
	text16.setPosition(1000, 425);

	sf::Text text17;
	text17.setFont(font);
	text17.setString("17");
	text17.setCharacterSize(100);
	text17.setOutlineThickness(5);
	text17.setPosition(1175, 425);

	sf::Text text18;
	text18.setFont(font);
	text18.setString("18");
	text18.setCharacterSize(100);
	text18.setOutlineThickness(5);
	text18.setPosition(1350, 425);

	sf::Text text19;
	text19.setFont(font);
	text19.setString("19");
	text19.setCharacterSize(100);
	text19.setOutlineThickness(5);
	text19.setPosition(1525, 425);

	sf::Text text20;
	text20.setFont(font);
	text20.setString("20");
	text20.setCharacterSize(100);
	text20.setOutlineThickness(5);
	text20.setPosition(1700, 425);

	sf::Text text21;
	text21.setFont(font);
	text21.setString("21");
	text21.setCharacterSize(100);
	text21.setOutlineThickness(5);
	text21.setPosition(125, 725);

	sf::Text text22;
	text22.setFont(font);
	text22.setString("22");
	text22.setCharacterSize(100);
	text22.setOutlineThickness(5);
	text22.setPosition(300, 725);

	sf::Text text23;
	text23.setFont(font);
	text23.setString("23");
	text23.setCharacterSize(100);
	text23.setOutlineThickness(5);
	text23.setPosition(475, 725);

	sf::Text text24;
	text24.setFont(font);
	text24.setString("24");
	text24.setCharacterSize(100);
	text24.setOutlineThickness(5);
	text24.setPosition(650, 725);

	sf::Text text25;
	text25.setFont(font);
	text25.setString("25");
	text25.setCharacterSize(100);
	text25.setOutlineThickness(5);
	text25.setPosition(825, 725);

	sf::Text text26;
	text26.setFont(font);
	text26.setString("26");
	text26.setCharacterSize(100);
	text26.setOutlineThickness(5);
	text26.setPosition(1000, 725);

	sf::Text text27;
	text27.setFont(font);
	text27.setString("27");
	text27.setCharacterSize(100);
	text27.setOutlineThickness(5);
	text27.setPosition(1175, 725);

	sf::Text text28;
	text28.setFont(font);
	text28.setString("28");
	text28.setCharacterSize(100);
	text28.setOutlineThickness(5);
	text28.setPosition(1350, 725);

	sf::Text text29;
	text29.setFont(font);
	text29.setString("29");
	text29.setCharacterSize(100);
	text29.setOutlineThickness(5);
	text29.setPosition(1525, 725);

	sf::Text text30;
	text30.setFont(font);
	text30.setString("30");
	text30.setCharacterSize(100);
	text30.setOutlineThickness(5);
	text30.setPosition(1700, 725);

/////////////////////////////////////////////////////////////////////////////////////////////////////

	ch1.setSize(sf::Vector2f(100, 100));
	ch1.setTexture(&buton);
	ch1.setOutlineThickness(2);
	ch1.setOutlineColor(sf::Color::Black);
	ch1.setPosition(100, 150);

	ch2.setSize(sf::Vector2f(100, 100));
	ch2.setTexture(&buton);
	ch2.setOutlineThickness(2);
	ch2.setOutlineColor(sf::Color::Black);
	ch2.setPosition(275, 150);

	ch3.setSize(sf::Vector2f(100, 100));
	ch3.setTexture(&buton);
	ch3.setOutlineThickness(2);
	ch3.setOutlineColor(sf::Color::Black);
	ch3.setPosition(450, 150);

	ch4.setSize(sf::Vector2f(100, 100));
	ch4.setTexture(&buton);
	ch4.setOutlineThickness(2);
	ch4.setOutlineColor(sf::Color::Black);
	ch4.setPosition(625, 150);

	ch5.setSize(sf::Vector2f(100, 100));
	ch5.setTexture(&buton);
	ch5.setOutlineThickness(2);
	ch5.setOutlineColor(sf::Color::Black);
	ch5.setPosition(800, 150);

	ch6.setSize(sf::Vector2f(100, 100));
	ch6.setTexture(&buton);
	ch6.setOutlineThickness(2);
	ch6.setOutlineColor(sf::Color::Black);
	ch6.setPosition(975, 150);

	ch7.setSize(sf::Vector2f(100, 100));
	ch7.setTexture(&buton);
	ch7.setOutlineThickness(2);
	ch7.setOutlineColor(sf::Color::Black);
	ch7.setPosition(1150, 150);

	ch8.setSize(sf::Vector2f(100, 100));
	ch8.setTexture(&buton);
	ch8.setOutlineThickness(2);
	ch8.setOutlineColor(sf::Color::Black);
	ch8.setPosition(1325, 150);

	ch9.setSize(sf::Vector2f(100, 100));
	ch9.setTexture(&buton);
	ch9.setOutlineThickness(2);
	ch9.setOutlineColor(sf::Color::Black);
	ch9.setPosition(1500, 150);

	ch10.setSize(sf::Vector2f(100, 100));
	ch10.setTexture(&buton);
	ch10.setOutlineThickness(2);
	ch10.setOutlineColor(sf::Color::Black);
	ch10.setPosition(1675, 150);

	ch11.setSize(sf::Vector2f(100, 100));
	ch11.setTexture(&buton);
	ch11.setOutlineThickness(2);
	ch11.setOutlineColor(sf::Color::Black);
	ch11.setPosition(100, 450);

	ch12.setSize(sf::Vector2f(100, 100));
	ch12.setTexture(&buton);
	ch12.setOutlineThickness(2);
	ch12.setOutlineColor(sf::Color::Black);
	ch12.setPosition(275, 450);

	ch13.setSize(sf::Vector2f(100, 100));
	ch13.setTexture(&buton);
	ch13.setOutlineThickness(2);
	ch13.setOutlineColor(sf::Color::Black);
	ch13.setPosition(450, 450);

	ch14.setSize(sf::Vector2f(100, 100));
	ch14.setTexture(&buton);
	ch14.setOutlineThickness(2);
	ch14.setOutlineColor(sf::Color::Black);
	ch14.setPosition(625, 450);

	ch15.setSize(sf::Vector2f(100, 100));
	ch15.setTexture(&buton);
	ch15.setOutlineThickness(2);
	ch15.setOutlineColor(sf::Color::Black);
	ch15.setPosition(800, 450);

	ch16.setSize(sf::Vector2f(100, 100));
	ch16.setTexture(&buton);
	ch16.setOutlineThickness(2);
	ch16.setOutlineColor(sf::Color::Black);
	ch16.setPosition(975, 450);

	ch17.setSize(sf::Vector2f(100, 100));
	ch17.setTexture(&buton);
	ch17.setOutlineThickness(2);
	ch17.setOutlineColor(sf::Color::Black);
	ch17.setPosition(1150, 450);

	ch18.setSize(sf::Vector2f(100, 100));
	ch18.setTexture(&buton);
	ch18.setOutlineThickness(2);
	ch18.setOutlineColor(sf::Color::Black);
	ch18.setPosition(1325, 450);

	ch19.setSize(sf::Vector2f(100, 100));
	ch19.setTexture(&buton);
	ch19.setOutlineThickness(2);
	ch19.setOutlineColor(sf::Color::Black);
	ch19.setPosition(1500, 450);

	ch20.setSize(sf::Vector2f(100, 100));
	ch20.setTexture(&buton);
	ch20.setOutlineThickness(2);
	ch20.setOutlineColor(sf::Color::Black);
	ch20.setPosition(1675, 450);

	ch21.setSize(sf::Vector2f(100, 100));
	ch21.setTexture(&buton);
	ch21.setOutlineThickness(2);
	ch21.setOutlineColor(sf::Color::Black);
	ch21.setPosition(100, 750);

	ch22.setSize(sf::Vector2f(100, 100));
	ch22.setTexture(&buton);
	ch22.setOutlineThickness(2);
	ch22.setOutlineColor(sf::Color::Black);
	ch22.setPosition(275, 750);

	ch23.setSize(sf::Vector2f(100, 100));
	ch23.setTexture(&buton);
	ch23.setOutlineThickness(2);
	ch23.setOutlineColor(sf::Color::Black);
	ch23.setPosition(450, 750);

	ch24.setSize(sf::Vector2f(100, 100));
	ch24.setTexture(&buton);
	ch24.setOutlineThickness(2);
	ch24.setOutlineColor(sf::Color::Black);
	ch24.setPosition(625, 750);

	ch25.setSize(sf::Vector2f(100, 100));
	ch25.setTexture(&buton);
	ch25.setOutlineThickness(2);
	ch25.setOutlineColor(sf::Color::Black);
	ch25.setPosition(800, 750);

	ch26.setSize(sf::Vector2f(100, 100));
	ch26.setTexture(&buton);
	ch26.setOutlineThickness(2);
	ch26.setOutlineColor(sf::Color::Black);
	ch26.setPosition(975, 750);

	ch27.setSize(sf::Vector2f(100, 100));
	ch27.setTexture(&buton);
	ch27.setOutlineThickness(2);
	ch27.setOutlineColor(sf::Color::Black);
	ch27.setPosition(1150, 750);

	ch28.setSize(sf::Vector2f(100, 100));
	ch28.setTexture(&buton);
	ch28.setOutlineThickness(2);
	ch28.setOutlineColor(sf::Color::Black);
	ch28.setPosition(1325, 750);

	ch29.setSize(sf::Vector2f(100, 100));
	ch29.setTexture(&buton);
	ch29.setOutlineThickness(2);
	ch29.setOutlineColor(sf::Color::Black);
	ch29.setPosition(1500, 750);

	ch30.setSize(sf::Vector2f(100, 100));
	ch30.setTexture(&buton);
	ch30.setOutlineThickness(2);
	ch30.setOutlineColor(sf::Color::Black);
	ch30.setPosition(1675, 750);

	CHbackButton.setTexture(back);
	CHbackButton.setPosition(0, 0);
	CHbackButton.setScale(0.1f, 0.1f);

	Stele1.setTexture(stele0);
	Stele1.setPosition(100, 225);
	Stele1.setScale(0.1f, 0.1f);

	Stele2.setTexture(stele0);
	Stele2.setPosition(275, 225);
	Stele2.setScale(0.1f, 0.1f);

	Stele3.setTexture(stele0);
	Stele3.setPosition(450, 225);
	Stele3.setScale(0.1f, 0.1f);

	Stele4.setTexture(stele0);
	Stele4.setPosition(625, 225);
	Stele4.setScale(0.1f, 0.1f);

	Stele5.setTexture(stele0);
	Stele5.setPosition(800, 225);
	Stele5.setScale(0.1f, 0.1f);

	Stele6.setTexture(stele0);
	Stele6.setPosition(975, 225);
	Stele6.setScale(0.1f, 0.1f);

	Stele7.setTexture(stele0);
	Stele7.setPosition(1150, 225);
	Stele7.setScale(0.1f, 0.1f);

	Stele8.setTexture(stele0);
	Stele8.setPosition(1325, 225);
	Stele8.setScale(0.1f, 0.1f);

	Stele9.setTexture(stele0);
	Stele9.setPosition(1500, 225);
	Stele9.setScale(0.1f, 0.1f);

	Stele10.setTexture(stele0);
	Stele10.setPosition(1675, 225);
	Stele10.setScale(0.1f, 0.1f);

	Stele11.setTexture(stele0);
	Stele11.setPosition(100, 525);
	Stele11.setScale(0.1f, 0.1f);

	Stele12.setTexture(stele0);
	Stele12.setPosition(275, 525);
	Stele12.setScale(0.1f, 0.1f);

	Stele13.setTexture(stele0);
	Stele13.setPosition(450, 525);
	Stele13.setScale(0.1f, 0.1f);
	
	Stele14.setTexture(stele0);
	Stele14.setPosition(625, 525);
	Stele14.setScale(0.1f, 0.1f);

	Stele15.setTexture(stele0);
	Stele15.setPosition(800, 525);
	Stele15.setScale(0.1f, 0.1f);

	Stele16.setTexture(stele0);
	Stele16.setPosition(975, 525);
	Stele16.setScale(0.1f, 0.1f);

	Stele17.setTexture(stele0);
	Stele17.setPosition(1150, 525);
	Stele17.setScale(0.1f, 0.1f);

	Stele18.setTexture(stele0);
	Stele18.setPosition(1325, 525);
	Stele18.setScale(0.1f, 0.1f);

	Stele19.setTexture(stele0);
	Stele19.setPosition(1500, 525);
	Stele19.setScale(0.1f, 0.1f);

	Stele20.setTexture(stele0);
	Stele20.setPosition(1675, 525);
	Stele20.setScale(0.1f, 0.1f);

	Stele21.setTexture(stele0);
	Stele21.setPosition(100, 825);
	Stele21.setScale(0.1f, 0.1f);

	Stele22.setTexture(stele0);
	Stele22.setPosition(275, 825);
	Stele22.setScale(0.1f, 0.1f);

	Stele23.setTexture(stele0);
	Stele23.setPosition(450, 825);
	Stele23.setScale(0.1f, 0.1f);

	Stele24.setTexture(stele0);
	Stele24.setPosition(625, 825);
	Stele24.setScale(0.1f, 0.1f);

	Stele25.setTexture(stele0);
	Stele25.setPosition(800, 825);
	Stele25.setScale(0.1f, 0.1f);

	Stele26.setTexture(stele0);
	Stele26.setPosition(975, 825);
	Stele26.setScale(0.1f, 0.1f);

	Stele27.setTexture(stele0);
	Stele27.setPosition(1150, 825);
	Stele27.setScale(0.1f, 0.1f);

	Stele28.setTexture(stele0);
	Stele28.setPosition(1325, 825);
	Stele28.setScale(0.1f, 0.1f);

	Stele29.setTexture(stele0);
	Stele29.setPosition(1500, 825);
	Stele29.setScale(0.1f, 0.1f);

	Stele30.setTexture(stele0);
	Stele30.setPosition(1675, 825);
	Stele30.setScale(0.1f, 0.1f);

	sf::Sprite fundal;
	fundal.setTexture(background);
	fundal.setPosition(0, 0);

	for (int i = 1; i <= 30; i++)
	{
		if (vStele[i] == 3 && i == 1)
			Stele1.setTexture(stele3);
		else if (vStele[i] == 2 && i == 1)
			Stele1.setTexture(stele2);
		else if (vStele[i] == 1 && i == 1)
			Stele1.setTexture(stele1);

		if (vStele[i] == 3 && i == 2)
			Stele2.setTexture(stele3);
		else if (vStele[i] == 2 && i == 2)
			Stele2.setTexture(stele2);
		else if (vStele[i] == 1 && i == 2)
			Stele2.setTexture(stele1);
	
		if (vStele[i] == 3 && i == 3)
			Stele3.setTexture(stele3);
		else if (vStele[i] == 2 && i == 3)
			Stele3.setTexture(stele2);
		else if (vStele[i] == 1 && i == 3)
			Stele3.setTexture(stele1);


		if (vStele[i] == 3 && i == 4)
			Stele4.setTexture(stele3);
		else if (vStele[i] == 2 && i == 4)
			Stele4.setTexture(stele2);
		else if (vStele[i] == 1 && i == 4)
			Stele4.setTexture(stele1);

		if (vStele[i] == 3 && i == 5)
			Stele5.setTexture(stele3);
		else if (vStele[i] == 2 && i == 5)
			Stele5.setTexture(stele2);
		else if (vStele[i] == 1 && i == 5)
			Stele5.setTexture(stele1);

		if (vStele[i] == 3 && i == 6)
			Stele6.setTexture(stele3);
		else if (vStele[i] == 2 && i == 6)
			Stele6.setTexture(stele2);
		else if (vStele[i] == 1 && i == 6)
			Stele6.setTexture(stele1);

		if (vStele[i] == 3 && i == 7)
			Stele7.setTexture(stele3);
		else if (vStele[i] == 2 && i == 7)
			Stele7.setTexture(stele2);
		else if (vStele[i] == 1 && i == 7)
			Stele7.setTexture(stele1);

		if (vStele[i] == 3 && i == 8)
			Stele8.setTexture(stele3);
		else if (vStele[i] == 2 && i == 8)
			Stele8.setTexture(stele2);
		else if (vStele[i] == 1 && i == 8)
			Stele8.setTexture(stele1);

		if (vStele[i] == 3 && i == 9)
			Stele9.setTexture(stele3);
		else if (vStele[i] == 2 && i == 9)
			Stele9.setTexture(stele2);
		else if (vStele[i] == 1 && i == 9)
			Stele9.setTexture(stele1);

		if (vStele[i] == 3 && i == 10)
			Stele10.setTexture(stele3);
		else if (vStele[i] == 2 && i == 10)
			Stele10.setTexture(stele2);
		else if (vStele[i] == 1 && i == 10)
			Stele10.setTexture(stele1);

		if (vStele[i] == 3 && i == 11)
			Stele11.setTexture(stele3);
		else if (vStele[i] == 2 && i == 11)
			Stele11.setTexture(stele2);
		else if (vStele[i] == 1 && i == 11)
			Stele11.setTexture(stele1);

		if (vStele[i] == 3 && i == 12)
			Stele12.setTexture(stele3);
		else if (vStele[i] == 2 && i == 12)
			Stele12.setTexture(stele2);
		else if (vStele[i] == 1 && i == 12)
			Stele12.setTexture(stele1);

		if (vStele[i] == 3 && i == 13)
			Stele13.setTexture(stele3);
		else if (vStele[i] == 2 && i == 13)
			Stele13.setTexture(stele2);
		else if (vStele[i] == 1 && i == 13)
			Stele13.setTexture(stele1);

		if (vStele[i] == 3 && i == 14)
			Stele14.setTexture(stele3);
		else if (vStele[i] == 2 && i == 14)
			Stele14.setTexture(stele2);
		else if (vStele[i] == 1 && i == 14)
			Stele14.setTexture(stele1);

		if (vStele[i] == 3 && i == 15)
			Stele15.setTexture(stele3);
		else if (vStele[i] == 2 && i == 15)
			Stele15.setTexture(stele2);
		else if (vStele[i] == 1 && i == 15)
			Stele15.setTexture(stele1);

		if (vStele[i] == 3 && i == 16)
			Stele16.setTexture(stele3);
		else if (vStele[i] == 2 && i == 16)
			Stele16.setTexture(stele2);
		else if (vStele[i] == 1 && i == 16)
			Stele16.setTexture(stele1);

		if (vStele[i] == 3 && i == 17)
			Stele17.setTexture(stele3);
		else if (vStele[i] == 2 && i == 17)
			Stele17.setTexture(stele2);
		else if (vStele[i] == 1 && i == 17)
			Stele17.setTexture(stele1);

		if (vStele[i] == 3 && i == 18)
			Stele18.setTexture(stele3);
		else if (vStele[i] == 2 && i == 18)
			Stele18.setTexture(stele2);
		else if (vStele[i] == 1 && i == 18)
			Stele18.setTexture(stele1);

		if (vStele[i] == 3 && i == 19)
			Stele19.setTexture(stele3);
		else if (vStele[i] == 2 && i == 19)
			Stele19.setTexture(stele2);
		else if (vStele[i] == 1 && i == 19)
			Stele19.setTexture(stele1);

		if (vStele[i] == 3 && i == 20)
			Stele20.setTexture(stele3);
		else if (vStele[i] == 2 && i == 20)
			Stele20.setTexture(stele2);
		else if (vStele[i] == 1 && i == 20)
			Stele20.setTexture(stele1);

		if (vStele[i] == 3 && i == 21)
			Stele21.setTexture(stele3);
		else if (vStele[i] == 2 && i == 21)
			Stele21.setTexture(stele2);
		else if (vStele[i] == 1 && i == 21)
			Stele21.setTexture(stele1);

		if (vStele[i] == 3 && i == 22)
			Stele22.setTexture(stele3);
		else if (vStele[i] == 2 && i == 22)
			Stele22.setTexture(stele2);
		else if (vStele[i] == 1 && i == 22)
			Stele22.setTexture(stele1);

		if (vStele[i] == 3 && i == 23)
			Stele23.setTexture(stele3);
		else if (vStele[i] == 2 && i == 23)
			Stele23.setTexture(stele2);
		else if (vStele[i] == 1 && i == 23)
			Stele23.setTexture(stele1);

		if (vStele[i] == 3 && i == 24)
			Stele24.setTexture(stele3);
		else if (vStele[i] == 2 && i == 24)
			Stele24.setTexture(stele2);
		else if (vStele[i] == 1 && i == 24)
			Stele24.setTexture(stele1);

		if (vStele[i] == 3 && i == 25)
			Stele25.setTexture(stele3);
		else if (vStele[i] == 2 && i == 25)
			Stele25.setTexture(stele2);
		else if (vStele[i] == 1 && i == 25)
			Stele25.setTexture(stele1);

		if (vStele[i] == 3 && i == 26)
			Stele26.setTexture(stele3);
		else if (vStele[i] == 2 && i == 26)
			Stele26.setTexture(stele2);
		else if (vStele[i] == 1 && i == 26)
			Stele26.setTexture(stele1);

		if (vStele[i] == 3 && i == 27)
			Stele27.setTexture(stele3);
		else if (vStele[i] == 2 && i == 27)
			Stele27.setTexture(stele2);
		else if (vStele[i] == 1 && i == 27)
			Stele27.setTexture(stele1);

		if (vStele[i] == 3 && i == 28)
			Stele28.setTexture(stele3);
		else if (vStele[i] == 2 && i == 28)
			Stele28.setTexture(stele2);
		else if (vStele[i] == 1 && i == 28)
			Stele28.setTexture(stele1);

		if (vStele[i] == 3 && i == 29)
			Stele29.setTexture(stele3);
		else if (vStele[i] == 2 && i == 29)
			Stele29.setTexture(stele2);
		else if (vStele[i] == 1 && i == 29)
			Stele29.setTexture(stele1);

		if (vStele[i] == 3 && i == 30)
			Stele30.setTexture(stele3);
		else if (vStele[i] == 2 && i == 30)
			Stele30.setTexture(stele2);
		else if (vStele[i] == 1 && i == 30)
			Stele30.setTexture(stele1);
	}

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
		
		renderWindow.draw(ch11);
		renderWindow.draw(text11);
		renderWindow.draw(Stele11);
		
		renderWindow.draw(ch12);
		renderWindow.draw(text12);
		renderWindow.draw(Stele12);
		
		renderWindow.draw(ch13);
		renderWindow.draw(text13);
		renderWindow.draw(Stele13);
		
		renderWindow.draw(ch14);
		renderWindow.draw(text14);
		renderWindow.draw(Stele14);
		
		renderWindow.draw(ch15);
		renderWindow.draw(text15);
		renderWindow.draw(Stele15);
		
		renderWindow.draw(ch16);
		renderWindow.draw(text16);
		renderWindow.draw(Stele16);
		
		renderWindow.draw(ch17);
		renderWindow.draw(text17);
		renderWindow.draw(Stele17);
		
		renderWindow.draw(ch18);
		renderWindow.draw(text18);
		renderWindow.draw(Stele18);
		
		renderWindow.draw(ch19);
		renderWindow.draw(text19);
		renderWindow.draw(Stele19);
		
		renderWindow.draw(ch20);
		renderWindow.draw(text20);
		renderWindow.draw(Stele20);
		
		renderWindow.draw(ch21);
		renderWindow.draw(text21);
		renderWindow.draw(Stele21);
		
		renderWindow.draw(ch22);
		renderWindow.draw(text22);
		renderWindow.draw(Stele22);
		
		renderWindow.draw(ch23);
		renderWindow.draw(text23);
		renderWindow.draw(Stele23);
		
		renderWindow.draw(ch24);
		renderWindow.draw(text24);
		renderWindow.draw(Stele24);
		
		renderWindow.draw(ch25);
		renderWindow.draw(text25);
		renderWindow.draw(Stele25);
		
		renderWindow.draw(ch26);
		renderWindow.draw(text26);
		renderWindow.draw(Stele26);

		renderWindow.draw(ch27);
		renderWindow.draw(text27);
		renderWindow.draw(Stele27);

		renderWindow.draw(ch28);
		renderWindow.draw(text28);
		renderWindow.draw(Stele28);

		renderWindow.draw(ch29);
		renderWindow.draw(text29);
		renderWindow.draw(Stele29);

		renderWindow.draw(ch30);
		renderWindow.draw(text30);
		renderWindow.draw(Stele30);

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