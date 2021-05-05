#include "Poisson.h"

Poisson::Poisson()
{
	this->mytexture.loadFromFile("textures/poisson.png");
	m_type = Type::poisson;
	m_coupable = true;
}
