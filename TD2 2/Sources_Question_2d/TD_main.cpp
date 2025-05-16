#include <iostream>

#include "TD_Point.h"
#include "TD_Triangle.h"

using namespace std;

int main( )
{

// definition de qq points
Point pt1(0,0);
Point pt2(1,0); 
Point pt3(-1,1);

// point pour la translation
Point trans(5,1);

// triangle avec un angle aigu
Triangle  tri_obt( pt1, pt2, pt3); // initialisation des points du triangle
cout << " -> Triangle obt" << endl;
tri_obt.Afficher();  // on affiche les points
cout << " Perimetre obt = " << tri_obt.Perimetre() << endl; // Calcul et affichage du perimetre

// un triangle rectagle
Triangle  tri_rect( Point(-1,0), pt3, pt2);
cout << " -> Triangle rect" << endl;
tri_rect.Afficher();
cout << " a = " << tri_rect.GetPoint(1).Distance( tri_rect.GetPoint(2) ) << endl; // longueur des cotes
cout << " b = " << tri_rect.GetPoint(0).Distance( tri_rect.GetPoint(1) ) << endl;
cout << " c = " << tri_rect.GetPoint(2).Distance( tri_rect.GetPoint(0) ) << endl;
cout << " Perimetre rect = " << tri_rect.Perimetre() << endl;

//un petit triangle
Triangle  tri_small( Point(-1,0), pt3, pt1);
cout << " -> Triangle small" << endl;
tri_small.Afficher();
cout << " Perimetre small = " << tri_small.Perimetre() << endl;

// Calcul des aires
cout << " Aire obt    = " << tri_obt.Aire() << endl;
cout << " Aire rect   = " << tri_rect.Aire() << endl;
cout << " Aire small  = " << tri_small.Aire() << endl;
cout << " Preuve        " << tri_rect.Aire() - tri_small.Aire() << endl;

// Translation
cout << " -> Transalation de obt" << endl;
tri_obt.Translation( trans );
tri_obt.Afficher();
cout << " Aire de obt translate = " << tri_obt.Aire() << endl;
 
// produit vectoriel
cout << " -> Produit vectoriel dans un sens : " << pt1.Vectoriel( pt2, pt3) << endl;
cout << " -> Produit vectoriel dans l'autre sens : " << pt1.Vectoriel( pt3, pt2) << endl;

cout << "Appuyer sur Entree pour continuer" << endl;
cin.get();
return 0;
}
