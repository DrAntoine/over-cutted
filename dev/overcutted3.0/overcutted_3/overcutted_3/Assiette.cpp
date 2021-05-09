#include "Assiette.h"
Assiette::Assiette()
{
    m_type = DeplacableType::assiette;
    //m_sprite = m_textureManager->getTexture(TextureType::Aliments,);
}

void Assiette::deposer(Aliment* x)
{
    if (checkAliment(x))
    {
        m_contenu.push_back(x);
    }

}

bool Assiette::checkAliment(Aliment* aAjouter)
{
    DeplacableType typeDeA_Ajouter=aAjouter->getType();
    {
        for (int i = 0 ;i<m_contenu.size();i++)
        {
            if (m_contenu[i]->getType() == typeDeA_Ajouter)
            {
                return false;
            }
            return true;
        }
    }
}