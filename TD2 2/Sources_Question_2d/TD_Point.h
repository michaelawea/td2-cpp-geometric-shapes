#ifndef _Point_h_
#define _Point_h_


// Classe point
class Point
{
private:
    double X;
    double Y;

public:
	// Constructeur par defaut
	Point(double x = 0, double y = 0);

	// Calcul distance, cette fonction ne modifie pas l'objet courant
	// ni le point passé en parametre
	double Distance(const Point &pt) const;

	// Fonction qui crée un nouveau point
	Point Add(const Point &pt) const;

	// Fonction qui calcul le produit vectoriel avec 2 autres points
	//  le signe de ce produit permet de savoir dans quel sens tourne les vecteurs
	double Vectoriel(const Point &pt1, const Point &pt2) const;

	// Fonction d'affichage
	void Afficher() const;

	double GetX() const;
	double GetY() const;

	void SetX(double x);
	void SetY(double y);

};
#endif