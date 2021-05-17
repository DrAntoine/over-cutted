#include "Minuteur.h"
#include "iostream"
//Minuteur::Minuteur()
//{
//	minutes = 5;
//	secondesUnite = 0;
//	secondesDizaine = 0;
//	font.loadFromFile("font/Bebas-Regular.ttf");
//	text.setFont(font);
//	text1.setFont(font);
//	text1.setString(" : ");
//	text2.setFont(font);
//	text3.setFont(font);
//	text.setCharacterSize(50);
//	text1.setCharacterSize(50);
//	text2.setCharacterSize(50);
//	text3.setCharacterSize(50);
//	text.setPosition(sf::Vector2f(820, 740));
//	text1.setPosition(sf::Vector2f(835, 735));
//	text2.setPosition(sf::Vector2f(885, 740));
//	text3.setPosition(sf::Vector2f(860, 740));
//
//	
//}

Minuteur::Minuteur(sf::Time* pointeurTemps)
{
	m_pointeurTemps = pointeurTemps;
	minutes, secondesDizaine, secondesUnite = 0, 0, 0;
	font.loadFromFile("font/Bebas-Regular.ttf");
	text.setFont(font);
	text1.setFont(font);
	text1.setString(" : ");
	text2.setFont(font);
	text3.setFont(font);
	text.setCharacterSize(45);
	text1.setCharacterSize(45);
	text2.setCharacterSize(45);
	text3.setCharacterSize(45);
	text.setPosition(sf::Vector2f(815, 740));
	text1.setPosition(sf::Vector2f(825, 735));
	text3.setPosition(sf::Vector2f(845, 740));
	text2.setPosition(sf::Vector2f(865, 740));
}

void Minuteur::decompte()
{
	int tempsSeconde = (int)m_pointeurTemps->asSeconds();
	minutes = tempsSeconde / 60;
	secondesDizaine = (tempsSeconde - (60 * minutes)) / 10;
	secondesUnite = (tempsSeconde - (60 * minutes)) % 10;
	text.setString(std::to_string(minutes));
	text2.setString(std::to_string(secondesUnite));
	text3.setString(std::to_string(secondesDizaine));
	//std::cout << minutes << ":" << secondes << std::endl;
}

void Minuteur::drawMinuteur(sf::RenderWindow* ptrfenetre)
{

	m_ptrFenetre = ptrfenetre;
	m_ptrFenetre->draw(text);
	m_ptrFenetre->draw(text1);
	m_ptrFenetre->draw(text2);
	m_ptrFenetre->draw(text3);
}
int Minuteur::finDuJeu()
{
	return minutes, secondesUnite,secondesDizaine;
}

