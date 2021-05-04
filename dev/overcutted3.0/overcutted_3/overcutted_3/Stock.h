#pragma once
#include "Tuile.h"

class Stock : public Tuile
{
private:
	int type_aliment //0 poisson, 1 crevette

public:
	Stock(int quoi) { type_aliment = quoi; }

	*Aliment void destocker()
	{
		Aliment* a;
		if(type_aliment==0) a=new Poisson()
		if (type_aliment == 1) a = new Crevette()
		
			Aliment->setPosition....

			Return a;
	}

};

