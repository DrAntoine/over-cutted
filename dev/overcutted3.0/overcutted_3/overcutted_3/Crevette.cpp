#include "Crevette.h"

Crevette::Crevette()
{
	this->mytexture.loadFromFile("textures/crevette.png");
	m_type = Type::crevette;
}