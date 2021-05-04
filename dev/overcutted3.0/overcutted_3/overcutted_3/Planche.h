#pragma once
#include "Outil.h"

/*class Outil : public Tuile
{

	public
		virtual void utiliser(std::vector<Aliment *> aliments);
		virtual void utiliser(Aliment * aliment);
		virtual void utiliser();

};*/


class Planche: public Outil
{
private:
	
	virtual void utiliser(std::vector<Aliment *> aliments)
	{
		//anim...
		if(anim terminee) aliment[0]->setCoupe();
	}
public:

};


class Casserole : public Outil
{
private:

public:
	virtual void utiliser(std::vector<Aliment *> aliments)
	{
		//anim...
		if (anim terminee)
		{
			for(aliments) aliment[i]->setCuit();
		}
	}
};
