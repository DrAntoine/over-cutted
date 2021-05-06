#include "Assiette.h"
Assiette::Assiette()
{
    this->mytexture.loadFromFile("textures/assiette.png");
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
    Type typeDeA_Ajouter=aAjouter->getType();
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