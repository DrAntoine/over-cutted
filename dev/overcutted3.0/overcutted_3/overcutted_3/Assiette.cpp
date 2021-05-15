#include "Assiette.h"


Assiette::Assiette(sf::Vector2f position, TextureManager* pointeurTexture, int deplacableID) : Deplacable(pointeurTexture, deplacableID)
{
    std::cout << "Constructeur Assiette" << std::endl;
    m_type = DeplacableType::assiette;
    m_position = position;
    m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(0,2));
    std::cout << "Assiette OK" << std::endl;
}

Assiette::~Assiette()
{
}

int Assiette::getNombreAliment()
{
    return m_contenu.size();
}

bool Assiette::estIdentique(Assiette &const B)
{
    if (getNombreAliment() == B.getNombreAliment())
    {
        for (int i = 0; i < m_contenu.size(); i++)
        {
            if (!B.checkAlimentTypeEtat(m_contenu[i])) return false;
        }
        return true;
    }
    else return false;
}

//void Assiette::DeposerSurAssiette(Deplacable* x)
//{
//    
//    Aliment* aliment = m_;
//
//    if (checkAliment(x))
//    {
//        m_contenu.push_back(x);
//    }
//    else
//    {
//
//    }
//}

bool Assiette::checkAjoutAliment(Aliment* aAjouter)
{
    DeplacableType typeDeA_Ajouter=aAjouter->getType();
    {
        for (unsigned int i = 0 ;i < m_contenu.size();i++)
        {
            if (m_contenu[i]->getType() == typeDeA_Ajouter)
            {
                return false;
            }
        }
        return true;
    }
}

bool Assiette::checkAlimentTypeEtat(Aliment* aVerif)
{
    for (int j = 0; j < m_contenu.size(); j++)
    {
        if (m_contenu[j] == aVerif) return true;
    }
    return false;
}

bool operator==(Assiette &const a, Assiette &const b)
{
    return a.estIdentique(b);
}
