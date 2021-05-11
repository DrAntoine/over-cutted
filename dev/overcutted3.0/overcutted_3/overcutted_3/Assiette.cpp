#include "Assiette.h"


Assiette::Assiette()
{
    std::cout << "Constructeur Assiette" << std::endl;
    m_type = DeplacableType::assiette;
    //m_sprite = m_textureManager->getTexture(TextureType::Aliments,);
    std::cout << "Assiette OK" << std::endl;
}

void Assiette::deposer(Aliment* x)
{
    if (checkAliment(x))
    {
        m_contenu.push_back(x);
    }
    else
    {

    }
}

bool Assiette::checkAliment(Aliment* aAjouter)
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