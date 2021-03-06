#include "DeplacableManager.h"

DeplacableManager::DeplacableManager()
{
	nombreInstance = 0;
}

int DeplacableManager::GetInstanceID()
{
    nombreInstance += 1;
    return nombreInstance;
}

void DeplacableManager::purgeVecteur(DeplacableType ressourceSupprime)
{
	std::vector<Deplacable*> m_elementsDeplacableTemp;
	std::vector<Assiette*> m_assiettesTemp;
	std::vector<Poisson*> m_poissonsTemp;
	std::vector<Crevette*> m_crevettesTemp;

	for (unsigned int i = 0; i < m_elementsDeplacable.size(); i++)
	{
		if (m_elementsDeplacable[i] != nullptr) m_elementsDeplacableTemp.push_back(m_elementsDeplacable[i]);
	}
	m_elementsDeplacable = m_elementsDeplacableTemp;
	switch (ressourceSupprime)
	{
	case DeplacableType::poisson:
		for (unsigned int l = 0; l < m_poissons.size(); l++)
		{
			if (m_poissons[l] != nullptr) m_poissonsTemp.push_back(m_poissons[l]);
		}
		m_poissons = m_poissonsTemp;
		break;
	case DeplacableType::crevette:
		for (unsigned int k = 0; k < m_crevettes.size(); k++)
		{
			if (m_crevettes[k] != nullptr) m_crevettesTemp.push_back(m_crevettes[k]);
		}
		m_crevettes = m_crevettesTemp;
		break;
	case DeplacableType::assiette:
		for (unsigned int j = 0; j < m_assiettes.size(); j++)
		{
			if (m_assiettes[j] != nullptr) m_assiettesTemp.push_back(m_assiettes[j]);
		}
		m_assiettes = m_assiettesTemp;
		break;
	default:
		break;
	}
}

DeplacableManager::~DeplacableManager()
{
	m_assiettes.clear();
	m_crevettes.clear();
	m_poissons.clear();
	for (unsigned int i = 0; i < m_elementsDeplacable.size(); i++)
	{
		delete m_elementsDeplacable[i];
	}
	m_elementsDeplacable.clear();
}

void DeplacableManager::DeleteElement(Deplacable* aDelete)
{
	DeplacableType type = aDelete->getType();
	int id_delete = aDelete->getId();
	if (type == DeplacableType::assiette)
	{
		Assiette* assietteTemp = nullptr;
		assietteTemp = getAssiette(id_delete);
		int nbAlim = assietteTemp->getNombreAliment();
		if (nbAlim > 0)
		{
			for (int i = 0; i < nbAlim; i++)
			{
				DeleteElement(assietteTemp->getAliment(i));
			}
		}
	}
	for (unsigned int i = 0; i < m_elementsDeplacable.size(); i++)
	{
		if (m_elementsDeplacable[i]->getId() == id_delete)
		{
			m_elementsDeplacable[i] = nullptr;
			break;
		}
	}
	switch (type)
	{
	case DeplacableType::poisson:
		for (unsigned int j = 0; j < m_poissons.size(); j++)
		{
			if (m_poissons[j]->getId() == id_delete)
			{
				m_poissons[j] = nullptr;
				break;
			}
		}
		break;
	case DeplacableType::crevette:
		for (unsigned int k = 0; k < m_crevettes.size(); k++)
		{
			if (m_crevettes[k]->getId() == id_delete)
			{
				m_crevettes[k] = nullptr;
				break;
			}
		}
		break;
	case DeplacableType::assiette:
		for (unsigned int l = 0; l < m_assiettes.size(); l++)
		{
			if (m_assiettes[l]->getId() == id_delete)
			{
				m_assiettes[l] = nullptr;
				break;
			}
		}
		break;
	default:
		break;
	}
	delete aDelete;
	purgeVecteur(type);
}

Deplacable* DeplacableManager::CreateElement(DeplacableType type, sf::Vector2f position, TextureManager* textureManager)
{
    Deplacable* nouvelleElement = nullptr;
	int instanceID = GetInstanceID();
	Poisson* poisson = nullptr;
	Crevette* crevette = nullptr;
	Assiette* assiette = nullptr;
	switch (type)
	{
	case DeplacableType::none:
		break;
	case DeplacableType::poisson:
		poisson = new Poisson(position, textureManager, instanceID);
		nouvelleElement = poisson;
		m_poissons.push_back(poisson);
		break;
	case DeplacableType::crevette:
		crevette = new Crevette(position, textureManager, instanceID);
		nouvelleElement = crevette;
		m_crevettes.push_back(crevette);
		break;
	case DeplacableType::assiette:
		assiette = new Assiette(position, textureManager, instanceID);
		nouvelleElement = assiette;
		m_assiettes.push_back(assiette);
		break;
	}
	m_elementsDeplacable.push_back(nouvelleElement);
    return nouvelleElement;
}

Assiette* DeplacableManager::getAssiette(int idAssiette)
{
	if (m_assiettes.size() > 0)
	{
		for (int i = 0; i < m_assiettes.size(); i++)
		{
			if (m_assiettes[i]->getId() == idAssiette) return m_assiettes[i];
		}
	}
}

Crevette* DeplacableManager::getCrevette(int idCrevette)
{
	if (m_crevettes.size() > 0)
	{
		for (int i = 0; i < m_crevettes.size(); i++)
		{
			if (m_crevettes[i]->getId() == idCrevette) return m_crevettes[i];
		}
	}
	return nullptr;
}

Poisson* DeplacableManager::getPoisson(int idPoisson)
{
	if (m_poissons.size() > 0)
	{
		for (int i = 0; i < m_poissons.size(); i++)
		{
			if (m_poissons[i]->getId() == idPoisson) return m_poissons[i];
		}
	}
}

void DeplacableManager::DrawDeplacable(sf::RenderWindow* pointeurFenetre)
{
	unsigned int m_elementSize = m_elementsDeplacable.size();
	if (m_elementSize > 0)
	{
		for (unsigned int i = 0; i < m_elementSize; i++)
		{
			if(m_elementsDeplacable[i]->getVisible()) m_elementsDeplacable[i]->draw(pointeurFenetre);
		}
	}
}
