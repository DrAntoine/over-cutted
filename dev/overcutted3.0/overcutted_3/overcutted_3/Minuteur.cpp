#include "Minuteur.h"
#include "iostream"
Minuteur::Minuteur()
{
	minutes = 5;
	secondes = 0;
	font.loadFromFile("font/Bebas-Regular.ttf");
	text.setFont(font);
	text1.setFont(font);
	text1.setString(" : ");
	text2.setFont(font);
	text.setCharacterSize(50);
	text1.setCharacterSize(50);
	text2.setCharacterSize(50);
	text.setPosition(sf::Vector2f(820, 740));
	text1.setPosition(sf::Vector2f(835, 740));
	text2.setPosition(sf::Vector2f(860, 740));

	
}

void Minuteur::décompte()
{
	duree = tempsJeu.getElapsedTime();
	if (duree.asSeconds() >= 1)
	{
		secondes -= 1;
		if (secondes < 0)
		{
			minutes -= 1;
			secondes = 59;
		}
		tempsJeu.restart();
	}
	text.setString(std::to_string(minutes));
	text2.setString(std::to_string(secondes));
	//std::cout << minutes << ":" << secondes << std::endl;
}

void Minuteur::drawMinuteur(sf::RenderWindow* ptrfenetre)
{

	m_ptrFenetre = ptrfenetre;
	m_ptrFenetre->draw(text);
	m_ptrFenetre->draw(text1);
	m_ptrFenetre->draw(text2);
}

