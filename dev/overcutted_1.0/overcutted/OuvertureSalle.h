#pragma once

class OuvertureSalle : public Tuile
{
private:
	std::vector<Recettes *> recettes
	bool stateOuvSal;
public:
	void validation();
	void supprimer();

};

