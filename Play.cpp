#include "Play.h"
#include <sstream>
using namespace std;

sf::Event event;
sf::Vector2i poz;
sf::FloatRect r1(0, 0, 20, 5);
sf::FloatRect r2(0, 0, 20, 5);
sf::FloatRect r3(0, 0, 20, 5);
sf::FloatRect r4(0, 0, 20, 5);
sf::Sprite PbackButton;
sf::RectangleShape bNext;

float X, Y;
char Butoi = '1', CorScuf = '2', CorAlb = '3', CorNgr = '4', Comoara = '5', Tentac = '6', Turn = '7', Stanca = '8';
char BusSus = '^', BusJos = '_', BusStg = '<', BusDr = '>';
char Piatra = 'a', Nisip = 'b', Insula = 'c', Gol = '*';
char StgSus[3][3], StgJos[3][3], DrSus[3][3], DrJos[3][3], CadranA[3][3], PiesaA[3][3];
char cStgSus[3][3], cStgJos[3][3], cDrSus[3][3], cDrJos[3][3];
char P1[3][3], P2[3][3], P3[3][3], P4[3][3];
int mut[5][5];
int ok1, ok2, ok31, ok32, ok33, ok34, ok41, ok42, ok43, ok44, ok51, ok52, ok53, ok54, castig=0;
int verif[10], cverif[10];
int tVictorie;
int nivUrm;
char vChallenge[8], bus;
FILE* fis;

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
    cStgSus[0][0] = Gol;
    cStgSus[0][1] = Butoi;
    cStgSus[0][2] = CorScuf;
    cStgSus[1][0] = CorAlb;
    cStgSus[1][1] = Gol;
    cStgSus[1][2] = Comoara;
    cStgSus[2][0] = Tentac;
    cStgSus[2][1] = Gol;
    cStgSus[2][2] = Gol;
    cStgJos[0][0] = Butoi;
    cStgJos[0][1] = CorScuf;
    cStgJos[0][2] = CorNgr;
    cStgJos[1][0] = CorAlb;
    cStgJos[1][1] = Comoara;
    cStgJos[1][2] = Gol;
    cStgJos[2][0] = CorNgr;
    cStgJos[2][1] = Turn;
    cStgJos[2][2] = Stanca;
    cDrSus[0][0] = Butoi;
    cDrSus[0][1] = Turn;
    cDrSus[0][2] = Gol;
    cDrSus[1][0] = Gol;
    cDrSus[1][1] = CorAlb;
    cDrSus[1][2] = Comoara;
    cDrSus[2][0] = Tentac;
    cDrSus[2][1] = CorNgr;
    cDrSus[2][2] = Gol;
    cDrJos[0][0] = Gol;
    cDrJos[0][1] = Gol;
    cDrJos[0][2] = Gol;
    cDrJos[1][0] = Turn;
    cDrJos[1][1] = Butoi;
    cDrJos[1][2] = Stanca;
    cDrJos[2][0] = CorAlb;
    cDrJos[2][1] = CorNgr;
    cDrJos[2][2] = Comoara;
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
void parcTabla()
{
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (StgSus[i][j] >= '1' && StgSus[i][j] <= '8')
                cverif[StgSus[i][j] - '0']++;
            if (DrSus[i][j] >= '1' && DrSus[i][j] <= '8')
                cverif[DrSus[i][j] - '0']++;
            if (DrJos[i][j] >= '1' && DrJos[i][j] <= '8')
                cverif[DrJos[i][j] - '0']++;
            if (StgJos[i][j] >= '1' && StgJos[i][j] <= '8')
                cverif[StgJos[i][j] - '0']++;
        }
    }

}
int Win()
{
    int ok = 1;
    for (int i = 1; i <= 8; i++)
    {
        if (verif[i] != cverif[i])
            ok = 0;
    }



    return ok;
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
void copiere(char CeC[3][3], char UndeC[3][3])
{
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
            UndeC[i][j] = CeC[i][j];
    }
}
void initNivel()
{
    char ch;
    while (1)
    {
        ch = getc(fis);
        if (ch >= '1' && ch <= '8')
            verif[ch - '0']++;
        if (ch == EOF)
            break;
    }


}
int PisButtonPressed()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
    {
        sf::Vector2i pozitieCursor = sf::Mouse::getPosition();

        if ((PbackButton.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
        {
            castig = 0;
            if (SFX == 1)
                click.play();
            sf::sleep(sf::seconds(0.2f));
            return 0;
        }
        if ((bNext.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))))
        {
            castig = 0;
            if (SFX == 1)
                click.play();
            sf::sleep(sf::seconds(0.2f));
            renderWindow.clear();
            Play(nivUrm);
            return 0;
        }

    }

    return 1;
}

int Play(int niv)
{
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                mut[i][j] = 0;

        for (int i = 1; i <= 8; i++)
        {
            cverif[i] = 0;
            verif[i] = 0;
        }

        ok31 = 0, ok32 = 0, ok33 = 0, ok34 = 0;

        initTabla();
        initPiese();
        if (niv == 1)
        {
            if (!fopen_s(&fis, "niv1.txt", "r"))
                initNivel();
        }
        else if (niv == 2)
        {
            if (!fopen_s(&fis, "niv2.txt", "r"))
                initNivel();
        }
        else if (niv == 3)
        {
            if (!fopen_s(&fis, "niv3.txt", "r"))
                initNivel();
        }
        else if (niv == 4)
        {
            if (!fopen_s(&fis, "niv4.txt", "r"))
                initNivel();
        }
        else if (niv == 5)
        {
            if (!fopen_s(&fis, "niv5.txt", "r"))
                initNivel();
        }
        else if (niv == 6)
        {
            if (!fopen_s(&fis, "niv6.txt", "r"))
                initNivel();
        }
        else if (niv == 7)
        {
            if (!fopen_s(&fis, "niv7.txt", "r"))
                initNivel();
        }
        else if (niv == 8)
        {
            if (!fopen_s(&fis, "niv8.txt", "r"))
                initNivel();
        }
        else if (niv == 9)
        {
            if (!fopen_s(&fis, "niv9.txt", "r"))
                initNivel();
        }
        else if (niv == 10)
        {
            if (!fopen_s(&fis, "niv10.txt", "r"))
                initNivel();
        }
        //float width=1920, height=1080;

        nivUrm = niv + 1;

        sf::Event event;

        sf::Text titlu;
        sf::Font font;
        font.loadFromFile("font.ttf");

        sf::Texture back;
        if (!back.loadFromFile("images/back.png"))
        {
            cout << "Eroare" << endl;
        }

        sf::Text timp("", font);
        timp.setPosition(100, 900);
        timp.setCharacterSize(100);
        timp.setOutlineColor(sf::Color::Black);
        timp.setOutlineThickness(5);
        timp.setFillColor(sf::Color::White);

        sf::Clock timer;
        sf::Time ceas;

        stringstream ss;
        int s = 0, m = 0, g=0;

        sf::Texture background;
        if (!background.loadFromFile("images/background.jpg"))
        {
            cout << "Eroare" << endl;
        }

        sf::Texture buton;
        if (!buton.loadFromFile("images/butoane.jpg"))
        {
            cout << "Eroare" << endl;
        }

        titlu.setFont(font);
        titlu.setString("Pirates Hide N' Seek");
        titlu.setCharacterSize(90);
        titlu.setOutlineColor(sf::Color::Black);
        titlu.setOutlineThickness(5);
        titlu.setFillColor(sf::Color::White);
        titlu.setPosition(575.0f, -10.0f);
        
        sf::Texture cadran1;
        sf::Texture cadran2;
        sf::Texture cadran3;
        sf::Texture cadran4;

        sf::Texture tabla;
        sf::Texture trofeu;

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
        drept.setPosition(75, 100);
        drept.setOutlineColor(sf::Color::Black);
        drept.setOutlineThickness(5);
        drept.setTexture(&buton);

        cadran1.loadFromFile("images/cadran1.png");
        cadran2.loadFromFile("images/cadran2.png");
        cadran3.loadFromFile("images/cadran3.png");
        cadran4.loadFromFile("images/cadran4.png");
        tabla.loadFromFile("images/fundal.jpg");
        trofeu.loadFromFile("images/cufar.png");

        piesa1.loadFromFile("images/piesa1.png");
        piesa2.loadFromFile("images/piesa2.png");
        piesa3.loadFromFile("images/piesa3.png");
        piesa4.loadFromFile("images/piesa4.png");

        PbackButton.setTexture(back);
        PbackButton.setPosition(0, 0);
        PbackButton.setScale(0.1f, 0.1f);

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

        sf::RectangleShape sTabla;
        sTabla.setSize(sf::Vector2f(900.0f, 900.0f));
        sTabla.setTexture(&tabla);
        sTabla.setOutlineColor(sf::Color::Black);
        sTabla.setOutlineThickness(5);
        sTabla.setPosition(515.0f, 100.0f);

        sf::Text tNext;
        tNext.setFont(font);
        tNext.setString("Next level");
        tNext.setCharacterSize(50);
        tNext.setOutlineColor(sf::Color::Black);
        tNext.setOutlineThickness(5);
        tNext.setPosition(840, 850);
        
        bNext.setTexture(&buton);
        bNext.setSize(sf::Vector2f(300, 125));
        bNext.setOutlineThickness(3);
        bNext.setOutlineColor(sf::Color::Black);
        bNext.setPosition(820, 820);

        sf::RectangleShape cufar;
        cufar.setSize(sf::Vector2f(750, 750));
        cufar.setTexture(&trofeu);
        cufar.setOutlineColor(sf::Color::Black);
        cufar.setOutlineThickness(10);
        cufar.setPosition(550.0f, 140.0f);
        cufar.setScale(1.1f, 1.1f);

        sf::Text victory;
        victory.setFont(font);
        victory.setCharacterSize(50);
        victory.setOutlineColor(sf::Color::Black);
        victory.setOutlineThickness(5);
        victory.setPosition(550.0f, 150.0f);
        victory.setString("                  YARRRR!\n  You managed to find the treasure!");
        victory.setFillColor(sf::Color::White);

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
            ///

            ss.str("");

            ceas = timer.getElapsedTime();
            s = ceas.asSeconds();
            g = s / 3600;
            m = (s - (g * 3600)) / 60;
            s = s - (g * 3600 + m * 60);

            /*if (g < 10)
            {
                ss << "0" << g;
            }
            else
            {
                ss << g;
            }
            */
            if (m < 10)
            {
                ss << "0" << m;
            }
            else
            {
                ss << m;
            }
            if (s < 10)
            {
                ss << " : " << "0" << s;
            }
            else
            {
                ss << " : " << s;
            }
            
            timp.setString(ss.str());

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
            renderWindow.draw(PbackButton);
            renderWindow.draw(timp);
            /*renderWindow.draw(cufar);
            renderWindow.draw(victory);
            renderWindow.draw(bNext);
            renderWindow.draw(tNext);*/

            if (PisButtonPressed() == 0)
                return 0;

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                if (sprite1.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
                {
                    for (int i = 0; i <= 2; i++)
                        for (int j = 0; j <= 2; j++)
                            CadranA[i][j] = StgSus[i][j];
                }
                if (sprite2.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
                {
                    for (int i = 0; i <= 2; i++)
                        for (int j = 0; j <= 2; j++)
                            CadranA[i][j] = DrSus[i][j];
                }
                if (sprite3.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
                {
                    for (int i = 0; i <= 2; i++)
                        for (int j = 0; j <= 2; j++)
                            CadranA[i][j] = StgJos[i][j];
                }
                if (sprite4.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
                {
                    for (int i = 0; i <= 2; i++)
                        for (int j = 0; j <= 2; j++)
                            CadranA[i][j] = DrJos[i][j];
                }
                if (spiesa1.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
                {
                    for (int i = 0; i <= 2; i++)
                        for (int j = 0; j <= 2; j++)
                            PiesaA[i][j] = P1[i][j];
                }
                if (spiesa2.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
                {
                    for (int i = 0; i <= 2; i++)
                        for (int j = 0; j <= 2; j++)
                            PiesaA[i][j] = P2[i][j];
                }
                if (spiesa3.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
                {
                    for (int i = 0; i <= 2; i++)
                        for (int j = 0; j <= 2; j++)
                            PiesaA[i][j] = P3[i][j];
                }
                if (spiesa4.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
                {
                    for (int i = 0; i <= 2; i++)
                        for (int j = 0; j <= 2; j++)
                            PiesaA[i][j] = P4[i][j];
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                if (verifica(PiesaA, P1))
                {
                    if (ok31 == 0)
                        spiesa1.setPosition(1605.0f, 80.0f);
                    else if (ok31 == 1)
                        spiesa1.setPosition(1700.0f, 175.0f);
                    spiesa1.setScale(0.4f, 0.4f);
                    renderWindow.draw(spiesa1);
                    if (verifica(StgSus, CadranA))
                    {
                        mut[1][1] = 0;
                        copiere(cStgSus, StgSus);
                    }
                    else if ((verifica(StgJos, CadranA)))
                    {
                        mut[3][1] = 0;
                        copiere(cStgJos, StgJos);
                    }
                    else if ((verifica(DrSus, CadranA)))
                    {
                        mut[2][1] = 0;
                        copiere(cDrSus, DrSus);
                    }
                    else if ((verifica(DrJos, CadranA)))
                    {
                        mut[4][1] = 0;
                        copiere(cDrJos, DrJos);
                    }
                }
                if (verifica(PiesaA, P2))
                {
                    if (ok32 == 0)
                        spiesa2.setPosition(1605.0f, 305.0f);
                    else if (ok32 == 1)
                        spiesa2.setPosition(1700.0f, 400.f);
                    spiesa2.setScale(0.4f, 0.4f);
                    renderWindow.draw(spiesa2);
                    if (verifica(StgSus, CadranA))
                    {
                        mut[1][2] = 0;
                        copiere(cStgSus, StgSus);
                    }
                    else if ((verifica(StgJos, CadranA)))
                    {
                        mut[3][2] = 0;
                        copiere(cStgJos, StgJos);
                    }
                    else if ((verifica(DrSus, CadranA)))
                    {
                        mut[2][2] = 0;
                        copiere(cDrSus, DrSus);
                    }
                    else if ((verifica(DrJos, CadranA)))
                    {
                        mut[4][2] = 0;
                        copiere(cDrJos, DrJos);
                    }
                }
                if (verifica(PiesaA, P3))
                {
                    if (ok33 == 0)
                        spiesa3.setPosition(1605.0f, 530.0f);
                    else if (ok33 == 1)
                        spiesa3.setPosition(1700.0f, 625.0f);
                    spiesa3.setScale(0.4f, 0.4f);
                    renderWindow.draw(spiesa3);
                    if (verifica(StgSus, CadranA))
                    {
                        mut[1][3] = 0;
                        copiere(cStgSus, StgSus);
                    }
                    else if ((verifica(StgJos, CadranA)))
                    {
                        mut[3][3] = 0;
                        copiere(cStgJos, StgJos);
                    }
                    else if ((verifica(DrSus, CadranA)))
                    {
                        mut[2][3] = 0;
                        copiere(cDrSus, DrSus);
                    }
                    else if ((verifica(DrJos, CadranA)))
                    {
                        mut[4][3] = 0;
                        copiere(cDrJos, DrJos);
                    }
                }
                if (verifica(PiesaA, P4))
                {
                    if (ok34 == 0)
                        spiesa4.setPosition(1605.0f, 755.0f);
                    else if (ok34 == 1)
                        spiesa4.setPosition(1700.0f, 850.0f);
                    spiesa4.setScale(0.4f, 0.4f);
                    renderWindow.draw(spiesa4);
                    if (verifica(StgSus, CadranA))
                    {
                        mut[1][4] = 0;
                        copiere(cStgSus, StgSus);
                    }
                    else if ((verifica(StgJos, CadranA)))
                    {
                        mut[3][4] = 0;
                        copiere(cStgJos, StgJos);
                    }
                    else if ((verifica(DrSus, CadranA)))
                    {
                        mut[2][4] = 0;
                        copiere(cDrSus, DrSus);
                    }
                    else if ((verifica(DrJos, CadranA)))
                    {
                        mut[4][4] = 0;
                        copiere(cDrJos, DrJos);
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if (verifica(StgSus, CadranA) && verifica(P1, PiesaA) && mut[1][1] == 0)
                {
                    spiesa1.setPosition(675.0f, 200.0f);
                    sf::Vector2f scale = spiesa1.getScale();
                    spiesa1.setScale(scale.x * 1.48f, scale.y * 1.48f);
                    if (mut[1][1] == 0 && ok31 == 1)
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
                    if (mut[1][2] == 0 && ok32 == 1)
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
                    if (mut[1][3] == 0 && ok33 == 1)
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
                    if (mut[1][4] == 0 && ok34 == 1)
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
                    if (mut[2][1] == 0 && ok31 == 1)
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
                    if (mut[2][2] == 0 && ok32 == 1)
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
                    if (mut[2][3] == 0 && ok33 == 1)
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
                    if (mut[2][4] == 0 && ok34 == 1)
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
                    if (mut[3][1] == 0 && ok31 == 1)
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
                    if (mut[3][2] == 0 && ok32 == 1)
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
                    if (mut[3][3] == 0 && ok33 == 1)
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
                    if (mut[3][4] == 0 && ok34 == 1)
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
                    if (mut[4][1] == 0 && ok31 == 1)
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
                    if (mut[4][2] == 0 && ok32 == 1)
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
                    if (mut[4][3] == 0 && ok33 == 1)
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
                    if (mut[4][4] == 0 && ok34 == 1)
                    {
                        sf::Vector2f pos = spiesa4.getPosition();
                        spiesa4.setPosition(pos.x + 145, pos.y + 145);
                        ok44 = 1;
                    }
                    renderWindow.draw(spiesa4);
                    mut[4][4] = 1;
                }
            }
            if (ok2 >= 1 && ok2 <= 399)ok2++;
            if (ok2 == 400)
            {
                ok1 = 0; ok2 = 0;
            }
            if (event.type == sf::Event::KeyPressed && ok1 == 0)
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
                            if ((pos.x == 675.0f && pos.y == 200.0f) || (pos.x == 975.0f && pos.y == 200.0f) || (pos.x == 675.0f && pos.y == 500.0f) || (pos.x == 975.0f && pos.y == 500.0f))
                                spiesa1.setPosition(pos.x + 146, pos.y + 146);
                        }
                        ok31 = 1;
                        rotire(P1);

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
                        rotire(P2);

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
                        rotire(P3);

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
                        rotire(P4);

                    }
                }
            }
            //if ((mut[1][1] == 1 || mut[1][2] == 1 || mut[1][3] == 1 || mut[1][4] == 1) && (mut[2][1] == 1 || mut[2][2] == 1 || mut[2][3] == 1 || mut[2][4] == 1) && (mut[3][1] == 1 || mut[3][2] == 1 || mut[3][3] == 1 || mut[3][4] == 1) && (mut[4][1] == 1 || mut[4][2] == 1 || mut[4][3] == 1 || mut[4][4] == 1))
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                if (mut[1][1] == 1)
                    suprapunere(StgSus, P1);
                else if (mut[1][2] == 1)
                    suprapunere(StgSus, P2);
                else if (mut[1][3] == 1)
                    suprapunere(StgSus, P3);
                else if (mut[1][4] == 1)
                    suprapunere(StgSus, P4);
                if (mut[2][1] == 1)
                    suprapunere(DrSus, P1);
                else if (mut[2][2] == 1)
                    suprapunere(DrSus, P2);
                else if (mut[2][3] == 1)
                    suprapunere(DrSus, P3);
                else if (mut[2][4] == 1)
                    suprapunere(DrSus, P4);
                if (mut[3][1] == 1)
                    suprapunere(StgJos, P1);
                else if (mut[3][2] == 1)
                    suprapunere(StgJos, P2);
                else if (mut[3][3] == 1)
                    suprapunere(StgJos, P3);
                else if (mut[3][4] == 1)
                    suprapunere(StgJos, P4);
                if (mut[4][1] == 1)
                    suprapunere(DrJos, P1);
                else if (mut[4][2] == 1)
                    suprapunere(DrJos, P2);
                else if (mut[4][3] == 1)
                    suprapunere(DrJos, P3);
                else if (mut[4][4] == 1)
                    suprapunere(DrJos, P4);
                parcTabla();
                if (Win() != 0 && castig == 0)
                {
                    castig = 1;
                    tVictorie = s;

                    cout << "You won in " << tVictorie << "seconds.";

                    for (int i = 1; i <= 8; i++)
                        cout << cverif[i] << " ";
                    cout << endl;
                    for (int i = 1; i <= 8; i++)
                        cout << verif[i] << " ";
                    cout << endl; 
                    cout << endl;
                }
                else if (Win() == 0 && castig == 0)
                {
                    cout << "you lose";
                    for (int i = 1; i <= 8; i++)
                        cout << cverif[i] << " ";
                    cout << endl;
                    for (int i = 1; i <= 8; i++)
                        cout << verif[i] << " ";
                }
                else if (Win() != 0 && castig == 1)
                    cout << "You already won.";
            }
            if (castig == 1)
            {
                renderWindow.draw(cufar);
                renderWindow.draw(victory);
                renderWindow.draw(bNext);
                renderWindow.draw(tNext);
                
                if (tVictorie <= 30)
                    vStele[niv] = 3;
                else if (tVictorie >= 30 && tVictorie <= 45)
                    vStele[niv] = 2;
                else
                    vStele[niv] = 1;

            }

            renderWindow.display();

        }


        return 0;
}