#include "Recette.h"
Recette::Recette(TextureManager* pointeurText, sf::Vector2u position) :Entite(pointeurText)
{
    std::cout << "Constructeur Recette" << std::endl;
    m_positiontest = position;
    m_position= convert_posMap_to_pos(m_positiontest);
    //m_position = sf::Vector2f(800, 0);
    m_texturePointeur = pointeurText;
    
    m_sprite = m_textureManager->getTexture(TextureType::Recette, sf::Vector2u(0, 0));
    std::cout << "Recette OK" << std::endl;
}

void Recette::typeRecette()
{
    switch (choix)
    {
    case 0:
        m_sprite = m_textureManager->getTexture(TextureType::Recette, sf::Vector2u(0, 0));
        break;
    case 1:
        m_sprite = m_textureManager->getTexture(TextureType::Recette, sf::Vector2u(0, 1));
        break;
    case 2:
        m_sprite = m_textureManager->getTexture(TextureType::Recette, sf::Vector2u(0, 2));
        break;
    }
}


void Recette::CreationRecettes()
{
    if (m_Recettes.size() < 2)
    {
        //for(int i = 0; i < m_Recettes.size(); i++)
        //{
            m_Recettes.push_back(new Recette(m_texturePointeur, sf::Vector2u(16,0)));
        //}
    }

}
void Recette::drawRecette(sf::RenderWindow* ptrWindow)
{
    m_ptrwindow = ptrWindow;
    for (int i = 0; i < m_Recettes.size(); i++)
    {
        m_Recettes[i]->draw(m_ptrwindow);
    }
}

Recette::~Recette()
{
}

