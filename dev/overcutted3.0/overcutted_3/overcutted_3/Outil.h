#pragma once
#include "Tuile.h"
#include "Aliments.h"

class Outil : public Tuile
{
protected:
	Aliment* m_currentAliment;
	bool m_libre; //false si aliment/true si vide
public:
	//Retourne l'�tat de m_libre. A consulter avant d'utiliser Recevoir(Aliment*) ou Donner();
	bool Est_libre();

	//Recois un pointeur d'Aliment, l'affecte � m_current_aliment si m_libre = true et switch l'�tat de m_libre. Ne fait rien si m_libre est false.
	void Recevoir(Aliment*); 
	
	//Recois rien, retourne un pointeur si m_libre = false. mets m_libre � true.
	bool Donner();

	//Met � jour l'Aliment en lui communicant le type de l'action et le temps �coul� � chaque boucle. 
	void Interaction(Aliment* m_currentAliment/*, game clock*/); //changera l'etat de l'objet sur l'outil
};

