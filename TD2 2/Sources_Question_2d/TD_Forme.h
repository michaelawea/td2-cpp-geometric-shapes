#ifndef _Forme_h_
#define _Forme_h_

#include "TD_Point.h"

// apres la creation d'un objet de type Forme, il n'est pas possible de modifier son nombre de sommets
class Forme
{
 protected:  // les classes dérivées ont accès au champs
    int NbSommets;
	Point *Sommets; 
 
  public:

	 // Constructeur par defaut, il fixe le nombre de sommets et 
	 // alloue l'espace memoire necessaire
     Forme(int nbsommets = 1);

	// Destructeur obligatoire à cause de l'allocation dynamique
     ~Forme();

	// Modification du point "i", verification que i ne soit pas idiot...
    void SetPoint(int i, const Point &pt);

	// Lecture du point "i", verification que i ne soit pas idiot...
	// on retourne une adesse vers un element de Sommets
    Point & GetPoint(int i) const;

    virtual void Afficher() const;

    // Fonction virutelle pure (abstraite) qui sera implementée (surchargée) par les classes dérivées
	// le mot clé virtual est rigoureux mais son utilité ne sera pas mise en évidence ici
	// dans le cadre de ce TP
    virtual double Aire() const = 0;

	// Fonction virutelle qui pourra être ré-implementée (ou surchargée) par les classes dérivées
	// le mot clé virtual est rigoureux mais son utilité ne sera pas mise en évidence
	// dans le cadre de ce TP
    virtual double Perimetre() const;
	
	// Permet de connaitre le nombre de sommets que possède la Forme
    int GetNbSommets() const;
	
	// Permet de translater une forme
	// le mot clé virtual est rigoureux mais son utilité ne sera pas mise en évidence
	// dans le cadre de ce TP
	virtual void Translation( const Point &pt);

};

#endif
