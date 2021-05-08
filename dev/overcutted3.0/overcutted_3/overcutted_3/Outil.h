#pragma once
#include "Tuile.h"
#include "Aliments.h"

class Outil : public Tuile
{
protected:
	Deplacable* m_currentAliment;
	bool m_libre; //false si aliment/true si vide
public:
	//Retourne l'�tat de m_libre. A consulter avant d'utiliser Recevoir(Aliment*) ou Donner();
	bool Est_libre();

	//Recois un pointeur d'Aliment, l'affecte � m_current_aliment si m_libre = true et switch l'�tat de m_libre. Ne fait rien si m_libre est false.
	virtual void Recevoir(Deplacable*);
	
	//Recois rien, retourne un pointeur si m_libre = false. mets m_libre � true.
	virtual Deplacable* Donner();

	//Met � jour l'Aliment en lui communicant le type de l'action et le temps �coul� � chaque boucle. 
	virtual void Interaction(/*, game clock*/); //changera l'etat de l'objet sur l'outil
};

