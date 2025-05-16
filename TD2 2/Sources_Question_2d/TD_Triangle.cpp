
#include <iostream>
#include <math.h>
#include "TD_Triangle.h"

using namespace std;

Triangle::Triangle( const Point &pt1, const Point &pt2, const Point &pt3):Forme(3)
{
   SetPoint(0, pt1);
   SetPoint(1, pt2);
   SetPoint(2, pt3);
}

// formule de Héron pour le calcul de l'aire d'un triangle
// ( http://perso.orange.fr/jean-paul.davalan/calc/triangle/aire/index.html )
double Triangle::Aire() const
{
	double a = Sommets[1].Distance( Sommets[2] );
	double b = Sommets[0].Distance( Sommets[1] ); 
	double c = Sommets[2].Distance( Sommets[0] );

	double dp = (a+b+c)/2;
	return sqrt(dp*(dp-a)*(dp-b)*(dp-c));

}
