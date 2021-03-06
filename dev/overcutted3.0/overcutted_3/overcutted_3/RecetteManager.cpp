#include "RecetteManager.h"

RecetteManager::RecetteManager(TextureManager* textureManager, DeplacableManager* DeplacableManager, int* scorePtr)
{
	srand(time(NULL));
	m_score = scorePtr;
	m_lastID = 0;
	m_textureManager = textureManager;
	m_deplacableManager = DeplacableManager;
	m_temp_avant_pop = sf::seconds(1);
	//tempsAvantProchainPlat
	//faire un random parmi les recettes dispo
	//ajouter new recette (choix random) dans liste recette

 }

RecetteManager::~RecetteManager()
{
	int nb_recette = m_recettes.size();
	//std::cout << "Boucle destructeurTextureManager" << std::endl;
	for (int i = 0; i < nb_recette; i++)
	{
		delete m_recettes[i];
		m_recettes[i] = nullptr;
	}
}

void RecetteManager::creationRecette(sf::Time elapsedTime)
{
	m_temp_avant_pop -= elapsedTime;
	if (m_temp_avant_pop <= sf::seconds(0))
	{
		int recetteChoix = rand() % 3;
		m_lastID++;
		Recette* nouvelleRecette;
		switch (recetteChoix)
		{
		case 0: // Carpacio Poisson
			nouvelleRecette = new Recette(m_textureManager, m_deplacableManager, typeRecette::CarpacioPoisson, m_lastID);
			break;
		case 1: // Carpacio Crevette
			nouvelleRecette = new Recette(m_textureManager, m_deplacableManager, typeRecette::CarpacioCrevette, m_lastID);
			break;
		case 2: // Carpacio Crevette Poisson
			nouvelleRecette = new Recette(m_textureManager, m_deplacableManager, typeRecette::CarpacioCrevettePoisson, m_lastID);
			break;
		}
		m_recettes.push_back(nouvelleRecette);
		m_temp_avant_pop = sf::seconds((rand() % 10) + 5);
	}
}

bool RecetteManager::validationRecette(Assiette* assietteAVerif)
{
	int recettesSize = m_recettes.size();
	if (recettesSize > 0)
	{
		//std::cout << "Boucle Validation Recette" << std::endl;
		for (int i = 0; i < recettesSize; i++)
		{
			if (m_recettes[i]->getEtat() != etatRecette::Echec && m_recettes[i]->getEtat() != etatRecette::disparue && m_recettes[i]->getEtat()!= etatRecette::apparition)
			{
				if (m_recettes[i]->ValidationRecette(assietteAVerif))
				{
					if (m_recettes[i]->tempsUtilise() < sf::seconds(20)) *m_score += 150;
					else *m_score += 75;
					m_recettes[i]->setEtat(etatRecette::Valide);
					return true;
				}
			}
		}
		*m_score -= 25;
		setErreur();
		return false;
	}
	else return false;
}

void RecetteManager::setErreur()
{
	//std::cout << "Boucle setErreur" << std::endl;
	for (int i = 0; i < m_recettes.size(); i++)
	{
		m_recettes[i]->setEtat(etatRecette::Erreur);
	}
}

void RecetteManager::updateRecette(sf::Time elapsedTime)
{
	if (m_recettes.size() < 5) creationRecette(elapsedTime);
	int vitesseDeplacementSeconde = 75;
	if (m_recettes.size() > 0)
	//std::cout << "Boucle updateManager" << std::endl;
	{
		for (int i = 0; i < m_recettes.size(); i++)
		{
			sf::Vector2f positionTemp = m_recettes[i]->getPos();
			m_recettes[i]->updateRecette(elapsedTime);
			if (m_recettes[i]->getEtat() == etatRecette::Erreur && m_recettes[i]->getErreur() == false) m_recettes[i]->setEtat(etatRecette::Neutre);
			{
				if (m_recettes[i]->getEtat() == etatRecette::disparue)
				{
					deleteRecette(m_recettes[i]->getid());
				}
				else if (m_recettes[i]->getEtat() == etatRecette::Echec || m_recettes[i]->getEtat() == etatRecette::apparition)
				{
					positionTemp.x -= elapsedTime.asSeconds() * vitesseDeplacementSeconde;
					m_recettes[i]->setPos(positionTemp);
				}
				else if (m_recettes[i]->getEtat() == etatRecette::Valide)
				{
					positionTemp.x += elapsedTime.asSeconds() * vitesseDeplacementSeconde;
					m_recettes[i]->setPos(positionTemp);
				}
			}
		}
	}
}

void RecetteManager::deleteRecette(int idToDelete)
{
	//std::cout << "Boucle delete Recette" << std::endl;
	for (int i = 0; i < m_recettes.size(); i++)
	{
		if (m_recettes[i]->getid() == idToDelete) 
		{
			delete m_recettes[i];
			m_recettes[i] = nullptr;
			break;
		}
	}
	purgeVecteur();
}

void RecetteManager::purgeVecteur()
{
	bool needPurge = false;
	//std::cout << "Boucle check purge vecteur" << std::endl;
	for (int i = 0; i < m_recettes.size(); i++)
	{
		if (m_recettes[i] == nullptr)
		{
			needPurge = true;
			break;
		}
	}
	if (needPurge)
	{
		std::vector<Recette*> nouveauVecteur;
		//std::cout << "Boucle purge vecteur" << std::endl;
		for (int i = 0; i < m_recettes.size(); i++)
		{
			if (m_recettes[i] != nullptr) nouveauVecteur.push_back(m_recettes[i]);
		}
		m_recettes = nouveauVecteur;
	}
}

void RecetteManager::drawRecette(sf::RenderWindow* pointeurFenetre)
{
	//std::cout << "Boucle drawRecette" << std::endl;
	for (int i = 0; i < m_recettes.size(); i++)
	{
		sf::Vector2f positionTemp = m_recettes[i]->getPos();
		positionTemp.y = 100 * i;
		m_recettes[i]->setPos(positionTemp);
		m_recettes[i]->drawRecette(pointeurFenetre);
	}

}
