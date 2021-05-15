#include "Assiette.h"


Assiette::Assiette(sf::Vector2f position, TextureManager* pointeurTexture, int deplacableID) : Deplacable(pointeurTexture, deplacableID)
{
    std::cout << "Constructeur Assiette" << std::endl;
    m_type = DeplacableType::assiette;
    m_position = position;
    m_SpriteAssiette = typeSpriteAssiette::vide;
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

bool Assiette::DeposerSurAssiette(Aliment* x)
{
    if (checkAjoutAliment(x))
    {
        switch (x->getType())
        {
        case DeplacableType::crevette:
            if (x->estCouper())
            {
                if (m_SpriteAssiette == typeSpriteAssiette::poisson)
                {
                    m_SpriteAssiette = typeSpriteAssiette::poisson_crevette;
                }
                else
                {
                    m_SpriteAssiette = typeSpriteAssiette::crevette;
                }
            }
            else return false;
            break;
        case DeplacableType::poisson:
            if (x->estCouper())
            {
                if (m_SpriteAssiette == typeSpriteAssiette::crevette)
                {
                    m_SpriteAssiette = typeSpriteAssiette::poisson_crevette;
                }
                else
                {
                    m_SpriteAssiette = typeSpriteAssiette::poisson;
                }
            }
            else return false;
            break;
        }
        updateSprite();
        m_contenu.push_back(x);
        x->Togglevisible();
        return true;
    }
    else
    {
        return false;
    }
}




bool Assiette::checkAjoutAliment(Aliment* aAjouter)
{
    if (m_contenu.size() > 0)
    {
        for (int i = 0; i < m_contenu.size(); i++)
        {
            if (m_contenu[i]->getType() == aAjouter->getType())
            {
                return false;
            }
        }
        return true;
    }
    else
    {
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

void Assiette::updateSprite()
{
    switch (m_SpriteAssiette)
    {
    case typeSpriteAssiette::vide:
        m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(0, 2));
        break;
    case typeSpriteAssiette::poisson:
        m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(2, 1));
        break;
    case typeSpriteAssiette::crevette:
        m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(2, 0));
        break;
    case typeSpriteAssiette::poisson_crevette:
        m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(1, 2));
        break;
    default:
        break;
    }
    m_sprite.setPosition(m_position);
}