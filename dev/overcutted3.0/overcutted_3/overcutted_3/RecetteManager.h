#pragma once
#include <stdlib.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Recette.h"
#include "DeplacableManager.h"
#include "TextureManager.h"

class RecetteManager
{
private:
	std::vector<Recette*> m_recettes;
	TextureManager* m_textureManager;
	DeplacableManager* m_deplacableManager;
	unsigned int m_lastID;
	int m_score;
	sf::Time m_temp_avant_pop;
	//================== score
	sf::Font font;
	sf::Text text;
	sf::Text text1;
	std::string score;
	sf::RenderWindow* m_ptrFenetre;
public:
	RecetteManager(TextureManager*, DeplacableManager*, int);
	~RecetteManager();
	void creationRecette(sf::Time);
	bool validationRecette(Assiette*);
	void setErreur();
	void updateRecette(sf::Time);
	void deleteRecette(int);
	void purgeVecteur();
	void drawRecette(sf::RenderWindow*);
};

