#include "Perso.h"

Perso::Perso(*elements,*map)
{

}
void Perso::move()
{
	if (moveleft) mysprite.move(dureeItération.asSecondes() * -Speed);
	if (moveright) mysprite.move(dureeItération.asSecondes() * Speed);
	if (moveup) mysprite.move(dureeItération.asSecondes() * -Speed);
	if (movedown) mysprite.move(dureeItération.asSecondes() * Speed);
}
