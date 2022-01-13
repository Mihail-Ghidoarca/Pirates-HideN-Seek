/*#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
using namespace std;
sf::Event event;
sf::Vector2i poz;
sf::FloatRect r1(0, 0, 20, 5);
sf::FloatRect r2(0, 0, 20, 5);
sf::FloatRect r3(0, 0, 20, 5);
sf::FloatRect r4(0, 0, 20, 5);
float X, Y;
char Butoi = '1', CorScuf = '2', CorAlb = '3', CorNgr = '4', Comoara = '5', Tentac = '6', Turn = '7', Stanca = '8';
char BusSus = '^', BusJos = '_', BusStg = '<', BusDr = '>';
char Piatra = 'a', Nisip = 'b', Insula = 'c', Gol = '*';
char StgSus[3][3], StgJos[3][3], DrSus[3][3], DrJos[3][3], CadranA[3][3], PiesaA[3][3];
char P1[3][3], P2[3][3], P3[3][3], P4[3][3];
int mut[5][5];
int Challenge, ok1, ok2, ok31, ok32, ok33, ok34, ok41, ok42, ok43, ok44, ok51, ok52, ok53, ok54;
char vChallenge[8], bus;

void initTabla()
{
    StgSus[0][0] = Gol;
    StgSus[0][1] = Butoi;
    StgSus[0][2] = CorScuf;
    StgSus[1][0] = CorAlb;
    StgSus[1][1] = Gol;
    StgSus[1][2] = Comoara;
    StgSus[2][0] = Tentac;
    StgSus[2][1] = Gol;
    StgSus[2][2] = Gol;
    StgJos[0][0] = Butoi;
    StgJos[0][1] = CorScuf;
    StgJos[0][2] = CorNgr;
    StgJos[1][0] = CorAlb;
    StgJos[1][1] = Comoara;
    StgJos[1][2] = Gol;
    StgJos[2][0] = CorNgr;
    StgJos[2][1] = Turn;
    StgJos[2][2] = Stanca;
    DrSus[0][0] = Butoi;
    DrSus[0][1] = Turn;
    DrSus[0][2] = Gol;
    DrSus[1][0] = Gol;
    DrSus[1][1] = CorAlb;
    DrSus[1][2] = Comoara;
    DrSus[2][0] = Tentac;
    DrSus[2][1] = CorNgr;
    DrSus[2][2] = Gol;
    DrJos[0][0] = Gol;
    DrJos[0][1] = Gol;
    DrJos[0][2] = Gol;
    DrJos[1][0] = Turn;
    DrJos[1][1] = Butoi;
    DrJos[1][2] = Stanca;
    DrJos[2][0] = CorAlb;
    DrJos[2][1] = CorNgr;
    DrJos[2][2] = Comoara;
}
void initPiese()
{
    P1[0][0] = Insula;
    P1[0][1] = Gol;
    P1[0][2] = Insula;
    P1[1][0] = Nisip;
    P1[1][1] = Gol;
    P1[1][2] = Insula;
    P1[2][0] = Nisip;
    P1[2][1] = Nisip;
    P1[2][2] = Nisip;
    P2[0][0] = Insula;
    P2[0][1] = Nisip;
    P2[0][2] = Piatra;
    P2[1][0] = Gol;
    P2[1][1] = Nisip;
    P2[1][2] = Gol;
    P2[2][0] = Insula;
    P2[2][1] = Nisip;
    P2[2][2] = Nisip;
    P3[0][0] = BusSus;
    P3[0][1] = BusSus;
    P3[0][2] = Gol;
    P3[1][0] = BusSus;
    P3[1][1] = BusSus;
    P3[1][2] = Insula;
    P3[2][0] = Insula;
    P3[2][1] = Gol;
    P3[2][2] = Insula;
    P4[0][0] = Gol;
    P4[0][1] = Piatra;
    P4[0][2] = Piatra;
    P4[1][0] = Piatra;
    P4[1][1] = Nisip;
    P4[1][2] = Piatra;
    P4[2][0] = Insula;
    P4[2][1] = Nisip;
    P4[2][2] = Gol;
}
void suprapunere(char tabla[3][3], char piesa[3][3])
{
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (piesa[i][j] != Gol)
                tabla[i][j] = piesa[i][j];
        }
    }
}
void rotire(char piesa[3][3])
{
    char aux[3][3];
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            aux[i][j] = piesa[2 - j][i];
        }
    }
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            piesa[i][j] = aux[i][j];
        }
    }
}
void afisTabla()
{   
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
            cout << StgSus[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
            cout << StgJos[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
            cout << DrSus[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
            cout << DrJos[i][j] << ' ';
        cout << endl;
    }

}
int verifica(char peTabla[3][3], char aleasa[3][3])
{
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
            if (peTabla[i][j] != aleasa[i][j])
                return 0;
    }
    return 1;
}
void ceNivel(int Nivel)
{
    switch (Nivel)
    {
    case 1:
    {
        Challenge = 1;
        bus = '^';
        vChallenge[0] = '4';
        vChallenge[1] = '4';
        vChallenge[2] = '4';
        vChallenge[3] = '4';
        break;
    }
    case 2:
        Challenge = 2;
        bus = '<';
        vChallenge[0] = '5';
        vChallenge[1] = '5';
        vChallenge[2] = '5';
        vChallenge[3] = '5';
        break;
    case 3:
        Challenge = 3;
        bus = '>';
        vChallenge[0] = '3';
        vChallenge[1] = '3';
        vChallenge[2] = '3';
        vChallenge[3] = '3';
        break;
    case 4:
        Challenge = 4;
        bus = '<';
        vChallenge[0] = '1';
        vChallenge[1] = '1';
        vChallenge[2] = '1';
        vChallenge[3] = '1';
        break;
    case 5:
        Challenge = 5;
        bus = '^';
        vChallenge[0] = '2';
        vChallenge[1] = '3';
        vChallenge[2] = '3';
        vChallenge[3] = '3';
        break;
    case 6:
        Challenge = 6;
        bus = '_';
        vChallenge[0] = '3';
        vChallenge[1] = '3';
        vChallenge[2] = '3';
        vChallenge[3] = '6';
        break;
    case 7:
        Challenge = 7;
        bus = '^';
        vChallenge[0] = '2';
        vChallenge[1] = '2';
        vChallenge[2] = '1';
        vChallenge[3] = '1';
        vChallenge[4] = '7';
        break;
    case 8:
        Challenge = 8;
        bus = '_';
        vChallenge[0] = '3';
        vChallenge[1] = '3';
        vChallenge[2] = '3';
        vChallenge[3] = '7';
        break;
    case 9:
        Challenge = 9;
        bus = '>';
        vChallenge[0] = '4';
        vChallenge[1] = '4';
        vChallenge[2] = '4';
        vChallenge[3] = '4';
        vChallenge[4] = '3';
        break;
    case 10:
        Challenge = 10;
        bus = '^';
        vChallenge[0] = '2';
        vChallenge[1] = '2';
        vChallenge[2] = '3';
        vChallenge[3] = '3';
        vChallenge[4] = '7';
        break;
    }
}

/// Aici 
/// incepe
/// functia 
/// main

int main()
{
    initTabla();
    initPiese();
    suprapunere(StgSus, P1);
    afisTabla();
    
    //float width=1920, height=1080;

    sf::RenderWindow renderWindow(sf::VideoMode(1920, 1080), "Pirates Hide N' Seek");
    sf::Event event;

    sf::Text titlu;
    sf::Font font;
    font.loadFromFile("font.ttf");

    sf::Texture background;
    if (!background.loadFromFile("images/background.jpg"))
    {
        cout << "Eroare" << endl;
    }

    titlu.setFont(font);
    titlu.setString("Pirates Hide N' Seek");
    titlu.setCharacterSize(50);
    titlu.setFillColor(sf::Color::White);
    titlu.setPosition(750.0f, 0.0f);

    sf::Texture cadran1;
    sf::Texture cadran2;
    sf::Texture cadran3;
    sf::Texture cadran4;
 
    sf::Texture tabla;

    sf::Texture tButoi;
    sf::Texture tComoara;
    sf::Texture tCorAlb;
    sf::Texture tCorNgr; 
    sf::Texture tCorScuf;
    sf::Texture tStanca;
    sf::Texture tTentac;
    sf::Texture tTurn;

    sf::Texture piesa1;
    sf::Texture piesa2;
    sf::Texture piesa3;
    sf::Texture piesa4;

    sf::RectangleShape drept;
    drept.setSize(sf::Vector2f(300, 800));
    drept.setFillColor(sf::Color(255, 255, 255));
    drept.setPosition(75, 75);

    cadran1.loadFromFile("images/cadran1.png");
    cadran2.loadFromFile("images/cadran2.png");
    cadran3.loadFromFile("images/cadran3.png");
    cadran4.loadFromFile("images/cadran4.png");
    tabla.loadFromFile("images/fundal.jpg");

    piesa1.loadFromFile("images/piesa1.png");
    piesa2.loadFromFile("images/piesa2.png");
    piesa3.loadFromFile("images/piesa3.png");
    piesa4.loadFromFile("images/piesa4.png");

    sf::Sprite sprite1(cadran1);
    sprite1.setTexture(cadran1);
    sprite1.setPosition(675.0f, 200.0f);
    sprite1.setScale(0.17f, 0.17f);

    sf::Sprite sprite2(cadran2);
    sprite2.setTexture(cadran2);
    sprite2.setPosition(975.0f, 200.0f);
    sprite2.setScale(0.17f, 0.17f);

    sf::Sprite sprite3(cadran3);
    sprite3.setTexture(cadran3);
    sprite3.setPosition(675.0f, 500.0f);
    sprite3.setScale(0.17f, 0.17f);

    sf::Sprite sprite4(cadran4);
    sprite4.setTexture(cadran4);
    sprite4.setPosition(975.0f, 500.0f);
    sprite4.setScale(0.17f, 0.17f);

    sf::Sprite sTabla(tabla);
    sTabla.setTexture(tabla);
    sTabla.setPosition(500.0f, 75.0f);
    sTabla.setScale(1.5f, 1.5f);

    sf::Sprite sButoi;
    sButoi.setTexture(tButoi);
    
    sf::Sprite sComoara;
    sComoara.setTexture(tComoara);
    
    sf::Sprite sCorAlb;
    sCorAlb.setTexture(tCorAlb);
    
    sf::Sprite sCorNgr;
    sCorNgr.setTexture(tCorNgr);
    
    sf::Sprite sCorScuf;
    sCorScuf.setTexture(tCorScuf);
    
    sf::Sprite sStanca;
    sStanca.setTexture(tStanca);
    
    sf::Sprite sTentac;
    sTentac.setTexture(tTentac);
    
    sf::Sprite sTurn;
    sTurn.setTexture(tTurn);

    sf::Sprite spiesa1;
    spiesa1.setTexture(piesa1);
    spiesa1.setPosition(1600.0f, 75.0f);
    spiesa1.setScale(0.4f, 0.4f);

    sf::Sprite spiesa2;
    spiesa2.setTexture(piesa2);
    spiesa2.setPosition(1600.0f, 300.0f);
    spiesa2.setScale(0.4f, 0.4f);

    sf::Sprite spiesa3;
    spiesa3.setTexture(piesa3);
    spiesa3.setPosition(1600.0f, 525.0f);
    spiesa3.setScale(0.4f, 0.4f);

    sf::Sprite spiesa4;
    spiesa4.setTexture(piesa4);
    spiesa4.setPosition(1600.0f, 750.0f);
    spiesa4.setScale(0.4f, 0.4f);

    sf::Sprite fundal;
    fundal.setTexture(background);
    fundal.setPosition(0, 0);

    while (renderWindow.isOpen())
    {
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
        }

        renderWindow.clear();

        renderWindow.draw(fundal);
        renderWindow.draw(sTabla);
        renderWindow.draw(sprite1);
        renderWindow.draw(sprite2);
        renderWindow.draw(sprite3);
        renderWindow.draw(sprite4);
        renderWindow.draw(drept);
        renderWindow.draw(titlu);
        renderWindow.draw(spiesa1);
        renderWindow.draw(spiesa2);
        renderWindow.draw(spiesa3);
        renderWindow.draw(spiesa4);

        renderWindow.display();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (sprite1.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
            {
                for (int i = 0; i <= 2; i++)
                    for (int j = 0; j <= 2; j++)
                        CadranA[i][j] = StgSus[i][j];
            }
            else if (sprite2.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
            {
                for (int i = 0; i <= 2; i++)
                    for (int j = 0; j <= 2; j++)
                        CadranA[i][j] = DrSus[i][j];
            }
            else if (sprite3.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
            {
                for (int i = 0; i <= 2; i++)
                    for (int j = 0; j <= 2; j++)
                        CadranA[i][j] = StgJos[i][j];
            }
            else if (sprite4.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
            {
                for (int i = 0; i <= 2; i++)
                    for (int j = 0; j <= 2; j++)
                        CadranA[i][j] = DrJos[i][j];
            }
            else if (spiesa1.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
            {
                for (int i = 0; i <= 2; i++)
                    for (int j = 0; j <= 2; j++)
                        PiesaA[i][j] = P1[i][j];
            }
            else if (spiesa2.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
            {
                for (int i = 0; i <= 2; i++)
                    for (int j = 0; j <= 2; j++)
                        PiesaA[i][j] = P2[i][j];
            }
            else if (spiesa3.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
            {
                for (int i = 0; i <= 2; i++)
                    for (int j = 0; j <= 2; j++)
                        PiesaA[i][j] = P3[i][j];
            }
            else if (spiesa4.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
            {
                for (int i = 0; i <= 2; i++)
                    for (int j = 0; j <= 2; j++)
                        PiesaA[i][j] = P4[i][j];
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (verifica(StgSus, CadranA) && verifica(P1, PiesaA) && mut[1][1] == 0)
            {
                spiesa1.setPosition(675.0f, 200.0f);
                sf::Vector2f scale = spiesa1.getScale();
                spiesa1.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok41 == 0 && ok31 == 1)
                {
                    sf::Vector2f pos = spiesa1.getPosition();
                    spiesa1.setPosition(pos.x + 145, pos.y + 145);
                    ok41 = 1;
                }
                renderWindow.draw(spiesa1);
                mut[1][1] = 1;
            }
            else if (verifica(StgSus, CadranA) && verifica(P2, PiesaA) && mut[1][2] == 0)
            {
                spiesa2.setPosition(675.0f, 200.0f);
                sf::Vector2f scale = spiesa2.getScale();
                spiesa2.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok42 == 0 && ok32 == 1)
                {
                    sf::Vector2f pos = spiesa2.getPosition();
                    spiesa2.setPosition(pos.x + 145, pos.y + 145);
                    ok42 = 1;
                }
                renderWindow.draw(spiesa2);
                mut[1][2] = 1;
            }
            else if (verifica(StgSus, CadranA) && verifica(P3, PiesaA) && mut[1][3] == 0)
            {
                spiesa3.setPosition(675.0f, 200.0f);
                sf::Vector2f scale = spiesa3.getScale();
                if (ok43 == 0 && ok33 == 1)
                {
                    sf::Vector2f pos = spiesa3.getPosition();
                    spiesa3.setPosition(pos.x + 145, pos.y + 145);
                    ok43 = 1;
                }
                spiesa3.setScale(scale.x * 1.48f, scale.y * 1.48f);
                renderWindow.draw(spiesa3);
                mut[1][3] = 1;
            }
            else if (verifica(StgSus, CadranA) && verifica(P4, PiesaA) && mut[1][4] == 0)
            {
                spiesa4.setPosition(675.0f, 200.0f);
                sf::Vector2f scale = spiesa4.getScale();
                spiesa4.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok44 == 0 && ok34 == 1)
                {
                    sf::Vector2f pos = spiesa4.getPosition();
                    spiesa4.setPosition(pos.x + 145, pos.y + 145);
                    ok44 = 1;
                }
                renderWindow.draw(spiesa4);
                mut[1][4] = 1;
            }
            else if (verifica(DrSus, CadranA) && verifica(P1, PiesaA) && mut[2][1] == 0)
            {
                spiesa1.setPosition(975.0f, 200.0f);
                sf::Vector2f scale = spiesa1.getScale();
                spiesa1.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok41 == 0 && ok31 == 1)
                {
                    sf::Vector2f pos = spiesa1.getPosition();
                    spiesa1.setPosition(pos.x + 145, pos.y + 145);
                    ok41 = 1;
                }
                renderWindow.draw(spiesa1);
                mut[2][1] = 1;
            }
            else if (verifica(DrSus, CadranA) && verifica(P2, PiesaA) && mut[2][2] == 0)
            {
                spiesa2.setPosition(975.0f, 200.0f);
                sf::Vector2f scale = spiesa2.getScale();
                spiesa2.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok42 == 0 && ok32 == 1)
                {
                    sf::Vector2f pos = spiesa2.getPosition();
                    spiesa2.setPosition(pos.x + 145, pos.y + 145);
                    ok42 = 1;
                }
                renderWindow.draw(spiesa2);
                mut[2][2] = 1;
            }
            else if (verifica(DrSus, CadranA) && verifica(P3, PiesaA) && mut[2][3] == 0)
            {
                spiesa3.setPosition(975.0f, 200.0f);
                sf::Vector2f scale = spiesa3.getScale();
                spiesa3.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok43 == 0 && ok33 == 1)
                {
                    sf::Vector2f pos = spiesa3.getPosition();
                    spiesa3.setPosition(pos.x + 145, pos.y + 145);
                    ok43 = 1;
                }
                renderWindow.draw(spiesa3);
                mut[2][3] = 1;
            }
            else if (verifica(DrSus, CadranA) && verifica(P4, PiesaA) && mut[2][4] == 0)
            {
                spiesa4.setPosition(975.0f, 200.0f);
                sf::Vector2f scale = spiesa4.getScale();
                spiesa4.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok44 == 0 && ok34 == 1)
                {
                    sf::Vector2f pos = spiesa4.getPosition();
                    spiesa4.setPosition(pos.x + 145, pos.y + 145);
                    ok44 = 1;
                }
                renderWindow.draw(spiesa4);
                mut[2][4] = 1;
            }
            else if (verifica(StgJos, CadranA) && verifica(P1, PiesaA) && mut[3][1] == 0)
            {
                spiesa1.setPosition(675.0f, 500.0f);
                sf::Vector2f scale = spiesa1.getScale();
                spiesa1.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok41 == 0 && ok31 == 1)
                {
                    sf::Vector2f pos = spiesa1.getPosition();
                    spiesa1.setPosition(pos.x + 145, pos.y + 145);
                    ok41 = 1;
                }
                renderWindow.draw(spiesa1);
                mut[3][1] = 1;
            }
            else if (verifica(StgJos, CadranA) && verifica(P2, PiesaA) && mut[3][2] == 0)
            {
                spiesa2.setPosition(675.0f, 500.0f);
                sf::Vector2f scale = spiesa2.getScale();
                spiesa2.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok42 == 0 && ok32 == 1)
                {
                    sf::Vector2f pos = spiesa2.getPosition();
                    spiesa2.setPosition(pos.x + 145, pos.y + 145);
                    ok42 = 1;
                }
                renderWindow.draw(spiesa2);
                mut[3][2] = 1;
            }
            else if (verifica(StgJos, CadranA) && verifica(P3, PiesaA) && mut[3][3] == 0)
            {
                spiesa3.setPosition(675.0f, 500.0f);
                sf::Vector2f scale = spiesa3.getScale();
                spiesa3.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok43 == 0 && ok33 == 1)
                {
                    sf::Vector2f pos = spiesa3.getPosition();
                    spiesa3.setPosition(pos.x + 145, pos.y + 145);
                    ok43 = 1;
                }
                renderWindow.draw(spiesa3);
                mut[3][3] = 1;
            }
            else if (verifica(StgJos, CadranA) && verifica(P4, PiesaA) && mut[3][4] == 0)
            {
                spiesa4.setPosition(675.0f, 500.0f);
                sf::Vector2f scale = spiesa4.getScale();
                spiesa4.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok44 == 0 && ok34 == 1)
                {
                    sf::Vector2f pos = spiesa4.getPosition();
                    spiesa4.setPosition(pos.x + 145, pos.y + 145);
                    ok44 = 1;
                }
                renderWindow.draw(spiesa4);
                mut[3][4] = 1;
            }
            else if (verifica(DrJos, CadranA) && verifica(P1, PiesaA) && mut[4][1] == 0)
            {
                spiesa1.setPosition(975.0f, 500.0f);
                sf::Vector2f scale = spiesa1.getScale();
                spiesa1.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok41 == 0 && ok31 == 1)
                {
                    sf::Vector2f pos = spiesa1.getPosition();
                    spiesa1.setPosition(pos.x + 145, pos.y + 145);
                    ok41 = 1;
                }
                renderWindow.draw(spiesa1);
                mut[4][1] = 1;
            }
            else if (verifica(DrJos, CadranA) && verifica(P2, PiesaA) && mut[4][2] == 0)
            {
                spiesa2.setPosition(975.0f, 500.0f);
                sf::Vector2f scale = spiesa2.getScale();
                spiesa2.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok42 == 0 && ok32 == 1)
                {
                    sf::Vector2f pos = spiesa2.getPosition();
                    spiesa2.setPosition(pos.x + 145, pos.y + 145);
                    ok42 = 1;
                }
                renderWindow.draw(spiesa2);
                mut[4][2] = 1;
            }
            else if (verifica(DrJos, CadranA) && verifica(P3, PiesaA) && mut[4][3] == 0)
            {
                spiesa3.setPosition(975.0f, 500.0f);
                sf::Vector2f scale = spiesa3.getScale();
                spiesa3.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok43 == 0 && ok33 == 1)
                {
                    sf::Vector2f pos = spiesa3.getPosition();
                    spiesa3.setPosition(pos.x + 145, pos.y + 145);
                    ok43 = 1;
                }
                renderWindow.draw(spiesa3);
                mut[4][3] = 1;
            }
            else if (verifica(DrJos, CadranA) && verifica(P4, PiesaA) && mut[4][4] == 0)
            {
                spiesa4.setPosition(975.0f, 500.0f);
                sf::Vector2f scale = spiesa4.getScale();
                spiesa4.setScale(scale.x * 1.48f, scale.y * 1.48f);
                if (ok44 == 0 && ok34 == 1)
                {
                    sf::Vector2f pos = spiesa4.getPosition();
                    spiesa4.setPosition(pos.x + 145, pos.y + 145);
                    ok44 = 1;
                }
                renderWindow.draw(spiesa4);
                mut[4][4] = 1;
            }
        }
        if (ok2 >=1 && ok2<=399)ok2++;
        if (ok2 == 400)
        {
            ok1 = 0; ok2 = 0;
        }
        if (event.type == sf::Event::KeyPressed && ok1==0)
        {
            ok1 = 1;
            ok2++;
            if (event.key.code == sf::Keyboard::Up)
            {
                if (verifica(P1, PiesaA))
                {
                    sf::Rect<float> size = spiesa1.getLocalBounds();
                    spiesa1.setOrigin(248, 248);
                    spiesa1.rotate(90);
                    if (ok31 == 0)
                    {
                        sf::Vector2f pos = spiesa1.getPosition();
                        spiesa1.setPosition(pos.x + 100, pos.y + 100);
                        if((pos.x==675.0f && pos.y==200.0f) || (pos.x==975.0f && pos.y==200.0f) || (pos.x==675.0f && pos.y==500.0f) || (pos.x==975.0f && pos.y==500.0f))
                            spiesa1.setPosition(pos.x + 146, pos.y + 146);
                    }
                    ok31 = 1;
                    
                }
                if (verifica(P2, PiesaA))
                {
                    sf::Rect<float> size = spiesa2.getLocalBounds();
                    spiesa2.setOrigin(248, 248);
                    spiesa2.rotate(90);
                    if (ok32 == 0)
                    {
                        sf::Vector2f pos = spiesa2.getPosition();
                        spiesa2.setPosition(pos.x + 100, pos.y + 100);
                        if ((pos.x == 675.0f && pos.y == 200.0f) || (pos.x == 975.0f && pos.y == 200.0f) || (pos.x == 675.0f && pos.y == 500.0f) || (pos.x == 975.0f && pos.y == 500.0f))
                            spiesa2.setPosition(pos.x + 146, pos.y + 146);
                    }
                    ok32 = 1;

                }
                if (verifica(P3, PiesaA))
                {
                    sf::Rect<float> size = spiesa3.getLocalBounds();
                    spiesa3.setOrigin(248, 248);
                    spiesa3.rotate(90);
                    if (ok33 == 0)
                    {
                        sf::Vector2f pos = spiesa3.getPosition();
                        spiesa3.setPosition(pos.x + 100, pos.y + 100);
                        if ((pos.x == 675.0f && pos.y == 200.0f) || (pos.x == 975.0f && pos.y == 200.0f) || (pos.x == 675.0f && pos.y == 500.0f) || (pos.x == 975.0f && pos.y == 500.0f))
                            spiesa3.setPosition(pos.x + 146, pos.y + 146);
                    }
                    ok33 = 1;

                }
                if (verifica(P4, PiesaA))
                {
                    sf::Rect<float> size = spiesa4.getLocalBounds();
                    spiesa4.setOrigin(248, 248);
                    spiesa4.rotate(90);
                    if (ok34 == 0)
                    {
                        sf::Vector2f pos = spiesa4.getPosition();
                        spiesa4.setPosition(pos.x + 100, pos.y + 100);
                        if ((pos.x == 675.0f && pos.y == 200.0f) || (pos.x == 975.0f && pos.y == 200.0f) || (pos.x == 675.0f && pos.y == 500.0f) || (pos.x == 975.0f && pos.y == 500.0f))
                            spiesa4.setPosition(pos.x + 146, pos.y + 146);
                    }
                    ok34 = 1;

                }
            }
        }

    }
    return 0;
}
*/