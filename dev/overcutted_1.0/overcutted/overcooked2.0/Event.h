#pragma once
#include "Map.h"
#include "Perso.h"
class Event
{
public:
	Event();
	Event(Perso* perso);
	void poisson();
private:
	Map map;
	Perso* perso;

};