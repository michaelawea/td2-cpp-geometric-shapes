#include <iostream>
#include "TD_Point.h"
#include "TD_Triangle.h"
#include "TD_Forme.h"
#include "TD_Forme_Quadri.h"
#include "TD_Forme_Cercle.h"
using namespace std;

int main()
{
    cout << "========== TD2 - Test des classes avec héritage ==========" << endl;
    
    // Test Triangle avec héritage
    cout << "\n1. Test Triangle (héritage de Forme)" << endl;
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 4);
    Triangle triangle(p1, p2, p3);
    
    triangle.Afficher();
    cout << "Périmètre: " << triangle.Perimetre() << endl;
    cout << "Aire: " << triangle.Aire() << endl;
    
    // Test Quadrilatère
    cout << "\n2. Test Quadrilatère" << endl;
    Point q1(0, 0);
    Point q2(4, 0);
    Point q3(4, 3);
    Point q4(0, 3);
    Quadri quadri(q1, q2, q3, q4);
    
    quadri.Afficher();
    cout << "Périmètre: " << quadri.Perimetre() << endl;
    cout << "Aire: " << quadri.Aire() << endl;
    
    // Test Quadrilatère concave
    cout << "\n3. Test Quadrilatère concave" << endl;
    Point c1(0, 0);
    Point c2(4, 0);
    Point c3(2, 2);  // Point intérieur pour créer un quadrilatère concave
    Point c4(0, 4);
    Quadri quadri_concave(c1, c2, c3, c4);
    
    quadri_concave.Afficher();
    cout << "Périmètre: " << quadri_concave.Perimetre() << endl;
    cout << "Aire: " << quadri_concave.Aire() << endl;
    
    // Test Cercle
    cout << "\n4. Test Cercle" << endl;
    Point center(0, 0);
    double rayon = 5.0;
    Cercle cercle(center, rayon);
    
    cercle.Afficher();
    cout << "Périmètre: " << cercle.Perimetre() << endl;
    cout << "Aire: " << cercle.Aire() << endl;
    
    // Test Translation
    cout << "\n5. Test Translation" << endl;
    Point vecteur(2, 3);
    cout << "Translation du triangle par le vecteur (2,3):" << endl;
    cout << "Avant: ";
    triangle.Afficher();
    triangle.Translation(vecteur);
    cout << "Après: ";
    triangle.Afficher();
    
    // Test polymorphisme
    cout << "\n6. Test Polymorphisme" << endl;
    Forme* formes[3];
    formes[0] = &triangle;
    formes[1] = &quadri;
    formes[2] = &cercle;
    
    for (int i = 0; i < 3; i++) {
        cout << "Forme " << i+1 << " - ";
        formes[i]->Afficher();
        cout << "Aire: " << formes[i]->Aire() << endl;
        cout << "Périmètre: " << formes[i]->Perimetre() << endl;
        cout << endl;
    }
    
    cout << "========== Tests terminés ==========" << endl;
    return 0;
}
