//#ifndef entite
#include "Entite.h"
//#endif // !entite


class Tuile : public Entite
{
public:
	Tuile();
	TuileType getTypeTuile();
protected:
	sf::Vector2u m_positionMap;
	bool m_libre; //deposer
	TuileType m_typeTuile;
	bool m_marchable;
};

