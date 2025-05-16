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
