#ifndef _Point_h_
#define _Point_h_


class Point
{
private:
    double X;
    double Y;

 public:

 Point(double x = 0, double y = 0);

 Point Add(const Point &pt) const;
 double Distance(const Point &pt) const;

 void Afficher() const;

 double GetX() const;
 double GetY() const;

 void SetX(double x);
 void SetY(double y);

};
#endif
