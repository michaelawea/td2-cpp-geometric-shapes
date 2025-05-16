
#include <iostream>
#include <cmath>
#include "TD_Point.h"

using namespace std;

Point::Point(double x, double y)
{
 X=x;
 Y=y;
}

// addition avec un autre point, le point courant n'est pas modifié
Point Point::Add(const Point &pt) const
{
 Point result( pt.X + X, pt.Y + Y);
 return result;
}

double Point::Vectoriel(const Point &pt1, const Point &pt2) const
{

return (pt1.X - X)*(pt2.Y - Y) - (pt2.X - X)*(pt1.Y - Y);
}


// affichage simple des coordonnées
void Point::Afficher() const
{
 cout<< "(" << X << " ," << Y << " )";
}

// Permet d'obtenir les coordonnées de l'objet courant
double Point::GetX() const
{
 return X;
}

// Permet d'obtenir les coordonnées de l'objet courant
double Point::GetY() const
{
 return Y;
}

// Permet de modifier les coordonnées de l'objet courant
void Point::SetX(double x)
{
 X = x;
}

// Permet de modifier les coordonnées de l'objet courant
void Point::SetY(double y)
{
 Y = y;
}

// Calcul la distance entre point courant et un point passé en parametre
double Point::Distance(const Point &pt) const
{
double result;
	result = (pt.X - X) * (pt.X - X);
	result += (pt.Y - Y) * (pt.Y - Y);
return sqrt(result);
}
