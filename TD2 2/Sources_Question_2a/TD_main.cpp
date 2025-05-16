#include <iostream>

#include "TD_Point.h"

using namespace std;

int main( )
{
cout << " #### TD3 #### " << endl;

Point pt1(1,1);
Point pt2; 
Point * _pt;

pt2 = Point(3,1);

 _pt = new Point();

cout << "Position de pt1 : ";
pt1.Afficher();
pt1.SetX( 2 );
pt1.SetY( 3 );
pt1.Afficher();
cout << endl;

cout << "Position de pt2 : ";
pt2.Afficher();
cout << endl;

*_pt = pt1.Add(pt2);

cout << "Position de pt3 : ";
_pt->Afficher();
cout << endl;

delete _pt;

cout << "Appuyer sur Entree pour continuer" << endl;
cin.get();
return 0;
}
