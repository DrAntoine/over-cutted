#include "Poubelle.h"

Poubelle::Poubelle(sf::Vector2u positionCarte, TextureManager* pointeurTexture) : Outil(pointeurTexture)
{
	std::cout << "Constructeur Poubelle (positionCarte)" << std::endl;
	m_positionMap = positionCarte;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_typeTuile = TuileType::Poubelle;
	m_marchable = false;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(5, 0));
	m_sprite.setPosition(m_position);
	std::cout << "Poubelle OK" << std::endl;
}

void Poubelle::DeposerSurTuile(Deplacable* ptrObjet)
{
	m_objetSurTuile = ptrObjet;
	//m_libre = false;
	m_objetSurTuile->setposition(m_position);
	//delete ptrObjet;
	
}
bool Poubelle::getLibre()
{
	return m_libre;
}
//void Poubelle::supprimer(Deplacable* alimentASupprimer)
//{
	//alimentASupprimer->~Aliment(); //risquy il semblerait 
	//delete alimentASupprimer; //supprime l'addresse ou l'objet ?
//}

//void Poubelle::Recevoir(Deplacable* current_objet)
//{
	//supprimer(current_objet);
	/*if (typeid(current_objet) == typeid(Aliment))
	{
		supprimer(current_objet);
	}
	else
	{
		m_currentAliment = current_objet;
		m_libre = false;
	}*/
//}

//Deplacable* Poubelle::Donner()
//{
	/*m_libre = true;
	Deplacable* item = m_currentAliment;
	m_currentAliment = nullptr;
	return item;*/
	//return nullptr;
//}