#include "Perso.h"

Perso::Perso(*elements,*map)
{

}
void Perso::move()
{
	if (moveleft) mysprite.move(dureeIt�ration.asSecondes() * -Speed);
	if (moveright) mysprite.move(dureeIt�ration.asSecondes() * Speed);
	if (moveup) mysprite.move(dureeIt�ration.asSecondes() * -Speed);
	if (movedown) mysprite.move(dureeIt�ration.asSecondes() * Speed);
}
