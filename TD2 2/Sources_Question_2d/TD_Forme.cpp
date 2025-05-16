
#include <iostream>
#include <math.h>

#include "TD_Forme.h"

using namespace std;


Forme::Forme(int nbsommets)
   {
   Sommets = new Point[nbsommets]; // allocation dynamique
   NbSommets = nbsommets;
   }

// Destructeur obligatoire à cause de l'allocation dynamique
Forme::~Forme()
   {
   if( Sommets != nullptr )
       delete[] Sommets;
   }

// Modification du point "i", verification que i ne soit pas idiot...
void Forme::SetPoint(int i, const Point &pt)
   {
   if( (i>=0) && (i<NbSommets) )
       Sommets[i] = pt;
   }
// Lecture du point "i", verification que i ne soit pas idiot...
// on retourne une adesse vers un element de Sommets
Point & Forme::GetPoint(int i) const
   {
   if( (i>=0) && (i<NbSommets) )
       return Sommets[i];
   return Sommets[0]; // convention... pour l'exo
   }

int Forme::GetNbSommets() const
{
    return NbSommets;
}

// affichage de tous les Points
void Forme::Afficher() const
{
for(int i=0; i<NbSommets; i++)
	{
	cout << "Pt(" << i << ") = ";
	Sommets[i].Afficher();
	cout<< endl;
	}
}

// Calcul du perimetre
double Forme::Perimetre() const
{
double perim = Sommets[NbSommets-1].Distance( Sommets[0] );
	for(int i=1; i<NbSommets; i++)
		perim += Sommets[i].Distance( Sommets[i-1] );
return perim;
}
	
void Forme::Translation( const Point &pt)
{
	for(int i=0; i<NbSommets; i++)
		Sommets[i] = Sommets[i].Add( pt );
}


