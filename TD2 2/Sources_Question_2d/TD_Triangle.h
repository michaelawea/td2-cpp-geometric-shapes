#ifndef _Triangle_h_
#define _Triangle_h_

#include "TD_Forme.h"
#include "TD_Point.h"

class Triangle : public Forme // derivation public de la classe Forme
{

 public:
	// constructeur vide
	 Triangle():Forme(3) {}; // on appelle le constructeur de Forme avec 3 sommets
	 // un autre constructeur ou l'on passe les 3 points
     Triangle( const Point &pt1, const Point &pt2, const Point &pt3);
	// Calcul de l'aire
    double Aire() const;

};
#endif
