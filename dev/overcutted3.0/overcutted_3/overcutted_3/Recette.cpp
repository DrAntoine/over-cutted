#include "Recette.h"

Recette::Recette(TextureManager* textureptr, DeplacableManager* deplacableManager, typeRecette typeRecette, int idRecette) : Entite(textureptr)
{
	m_deplacableManager = deplacableManager;
	m_texturePointeur = textureptr;
	assietteAPresenter = nullptr;
	m_idRecette = idRecette;
	m_etatRecette = etatRecette::apparition;
	erreurTime = sf::seconds(0);
	m_erreur = false;
	m_reussi = false;
	m_position = sf::Vector2f(1125, 0);
	//m_sprite = textureptr->getTexture(TextureType::Recette, sf::ve );
	Deplacable* objetTemp = nullptr;
	Assiette* assietteTemp = nullptr;
	Crevette* crevetteTemp = nullptr;
	Poisson* poissonTemp = nullptr;
	switch (typeRecette)
	{
	case typeRecette::CarpacioPoisson:
		objetTemp = m_deplacableManager->CreateElement(DeplacableType::assiette, sf::Vector2f(0, 0), m_texturePointeur);
		assietteAPresenter = m_deplacableManager->getAssiette(objetTemp->getId());
		assietteAPresenter->Togglevisible();
		objetTemp = m_deplacableManager->CreateElement(DeplacableType::poisson, sf::Vector2f(0, 0), m_texturePointeur);
		poissonTemp = m_deplacableManager->getPoisson(objetTemp->getId());
		poissonTemp->setCoupe(); //pas besoin de le rendre invisible, des que on le met dans l'assiette il disparait :P
		assietteAPresenter->DeposerSurAssiette(poissonTemp);
		tempsDispoRecette = sf::seconds(60);
		m_positionSprite = sf::Vector2u(0, 0);
		break;
	case typeRecette::CarpacioCrevette:
		objetTemp = m_deplacableManager->CreateElement(DeplacableType::assiette, sf::Vector2f(0, 0), m_texturePointeur);
		assietteAPresenter = m_deplacableManager->getAssiette(objetTemp->getId());
		assietteAPresenter->Togglevisible();
		objetTemp = m_deplacableManager->CreateElement(DeplacableType::crevette, sf::Vector2f(0, 0), m_texturePointeur);
		crevetteTemp = m_deplacableManager->getCrevette(objetTemp->getId());
		crevetteTemp->setCoupe(); //pas besoin de le rendre invisible, des que on le met dans l'assiette il disparait :P
		assietteAPresenter->DeposerSurAssiette(crevetteTemp);
		tempsDispoRecette = sf::seconds(60);
		m_positionSprite = sf::Vector2u(0, 1);
		break;
	case typeRecette::CarpacioCrevettePoisson:
		objetTemp = m_deplacableManager->CreateElement(DeplacableType::assiette, sf::Vector2f(0, 0), m_texturePointeur);
		assietteAPresenter = m_deplacableManager->getAssiette(objetTemp->getId());
		assietteAPresenter->Togglevisible();
		objetTemp = m_deplacableManager->CreateElement(DeplacableType::poisson, sf::Vector2f(0, 0), m_texturePointeur);
		poissonTemp = m_deplacableManager->getPoisson(objetTemp->getId());
		poissonTemp->setCoupe(); //pas besoin de le rendre invisible, des que on le met dans l'assiette il disparait :P
		assietteAPresenter->DeposerSurAssiette(poissonTemp);
		objetTemp = m_deplacableManager->CreateElement(DeplacableType::crevette, sf::Vector2f(0, 0), m_texturePointeur);
		crevetteTemp = m_deplacableManager->getCrevette(objetTemp->getId());
		crevetteTemp->setCoupe(); //pas besoin de le rendre invisible, des que on le met dans l'assiette il disparait :P
		assietteAPresenter->DeposerSurAssiette(crevetteTemp);
		tempsDispoRecette = sf::seconds(70);
		m_positionSprite = sf::Vector2u(0, 2);
		break;
	default:
		objetTemp = m_deplacableManager->CreateElement(DeplacableType::assiette, sf::Vector2f(0, 0), m_texturePointeur);
		assietteAPresenter = m_deplacableManager->getAssiette(objetTemp->getId());
		assietteAPresenter->Togglevisible();
		break;
	}
	TempInitial = tempsDispoRecette;
}

void Recette::drawRecette(sf::RenderWindow* ptr_fenetre)
{
	switch (m_etatRecette)
	{
	case etatRecette::Neutre:
		m_positionSprite.x = 0;
		break;
	case etatRecette::Erreur:
		m_positionSprite.x = 4;
		break;
	case etatRecette::Temps_Reduit:
		m_positionSprite.x = 3;
		break;
	case etatRecette::Echec:
		m_positionSprite.x = 2;
		break;
	case etatRecette::Valide:
		m_positionSprite.x = 1;
		break;
	case etatRecette::disparue:
		m_positionSprite.x = 0;
		break;
	case etatRecette::apparition:
		m_positionSprite.x = 0;
		break;
	}
	m_sprite = m_textureManager->getTexture(TextureType::Recette, m_positionSprite);
	m_sprite.setPosition(m_position);
	ptr_fenetre->draw(m_sprite);
}

void Recette::updateRecette(sf::Time elapedTime)
{
	//if (tempsDispoRecette <= sf::seconds(0))
	//{
	//	bool a = (true == true);// debug comment
	//}
	if (m_etatRecette != etatRecette::Echec && m_etatRecette != etatRecette::Valide && m_etatRecette != etatRecette::disparue && m_etatRecette != etatRecette::apparition)
	{
		if (erreurTime > sf::seconds(0) && m_erreur)
		{
			erreurTime -= elapedTime;
			if (erreurTime <= sf::seconds(0)) 
			{
				m_etatRecette = etatRecette::Neutre;
				m_erreur = false;
			}
			int temps_erreur = erreurTime.asSeconds();
			if ((temps_erreur%2)) m_etatRecette = etatRecette::Neutre;
			else m_etatRecette = etatRecette::Erreur;
		}
		if (tempsDispoRecette <= sf::seconds(0)) m_etatRecette = etatRecette::Echec;
		if (tempsDispoRecette > sf::seconds(0) && m_etatRecette != etatRecette::Valide)
		{
			tempsDispoRecette -= elapedTime;
			if (tempsDispoRecette <= sf::seconds(15) && m_etatRecette!= etatRecette::Temps_Reduit)
			{
				m_etatRecette = etatRecette::Temps_Reduit;
			}
		}
	}
	if (m_position.x < (800 - 300 - 50) && m_etatRecette == etatRecette::Echec|| m_position.x >(800 + 300 + 50) && m_etatRecette == etatRecette::Valide)  //position origine recette +/- largeur bandeau recette + 50px marge
	{
		m_etatRecette = etatRecette::disparue;
	}
	if (m_etatRecette == etatRecette::apparition && m_position.x < 800)
	{
		m_etatRecette = etatRecette::Neutre;
		m_position.x = 800;
	}
}

bool Recette::ValidationRecette(Assiette* assietteAVerif)
{
	return *assietteAPresenter == *assietteAVerif;
}

etatRecette Recette::getEtat()
{
	return m_etatRecette;
}

void Recette::setEtat(etatRecette nouvelleEtat)
{
	if (nouvelleEtat == etatRecette::Erreur)
	{
		if (m_etatRecette != etatRecette::disparue && m_etatRecette != etatRecette::Echec && m_etatRecette!=etatRecette::apparition && m_etatRecette!=etatRecette::Valide)
		{
			m_etatRecette = etatRecette::Erreur;
			m_erreur = true;
			erreurTime = sf::seconds(5);
		}
	}
	if (nouvelleEtat == etatRecette::Valide) m_etatRecette = etatRecette::Valide;
	if (nouvelleEtat == etatRecette::Neutre) m_etatRecette = etatRecette::Neutre;
}

void Recette::setPos(sf::Vector2f nouvellePos)
{
	m_position = nouvellePos;
}

sf::Vector2f Recette::getPos()
{
	return m_position;
}

int Recette::getid()
{
	return m_idRecette;
}

bool Recette::getReussi()
{
	return m_reussi;
}

Recette::~Recette()
{
	m_deplacableManager->DeleteElement(assietteAPresenter);
}

bool Recette::getErreur()
{
	return m_erreur;
}

sf::Time Recette::tempsUtilise()
{
	return TempInitial-tempsDispoRecette;
}
