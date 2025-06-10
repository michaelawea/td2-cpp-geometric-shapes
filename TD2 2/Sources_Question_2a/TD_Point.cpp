#include <iostream>
#include <cmath>
#include "TD_Point.h"

using namespace std;

Point::Point(double x, double y)
{
 X=x;
 Y=y;
}

Point Point::Add(const Point &pt) const
{
 Point result(pt.X + X, pt.Y + Y);
 return result;
}

double Point::Distance(const Point &pt) const
{
 double dx = X - pt.X;
 double dy = Y - pt.Y;
 return sqrt(dx * dx + dy * dy);
}

double Point::Vectoriel(const Point &pt1, const Point &pt2) const
{
 return (pt1.X - X)*(pt2.Y - Y) - (pt2.X - X)*(pt1.Y - Y);
}

void Point::Afficher() const
{
 cout<< "(" << X << " ," << Y << " )";
}

double Point::GetX() const
{
 return X;
}

double Point::GetY() const
{
 return Y;
}

void Point::SetX(double x)
{
 X = x;
}

void Point::SetY(double y)
{
 Y = y;
}
