#include "Poubelle.h"

Poubelle::Poubelle(sf::Vector2f position)
{
	m_position = position;
	m_type = TuileType::Poubelle;
	m_marchable = false;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0, 0)); //TODO definir la position dans le fichier.
}

void Poubelle::supprimer(Deplacable* alimentASupprimer)
{
	//alimentASupprimer->~Aliment(); //risquy il semblerait 
	delete alimentASupprimer; //supprime l'addresse ou l'objet ?
}

void Poubelle::Recevoir(Deplacable* current_objet)
{
	supprimer(current_objet);
	/*if (typeid(current_objet) == typeid(Aliment))
	{
		supprimer(current_objet);
	}
	else
	{
		m_currentAliment = current_objet;
		m_libre = false;
	}*/
}

Deplacable* Poubelle::Donner()
{
	/*m_libre = true;
	Deplacable* item = m_currentAliment;
	m_currentAliment = nullptr;
	return item;*/
	return nullptr;
}