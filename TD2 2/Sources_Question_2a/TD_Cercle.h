#ifndef _CERCLE_H_
#define _CERCLE_H_

#include "TD_Point.h"

class Cercle
{
private:
    Point center;
    double rayon;

public:
    // 构造函数
    Cercle(const Point &c = Point(0,0), double r = 0);

    // 访问函数
    Point GetCenter() const;
    double GetRayon() const;
    void SetCenter(const Point &c);
    void SetRayon(double r);

    // 其他成员函数
    void Afficher() const;
    double Perimetre() const;
    void Translation(const Point &v);
    double Aire() const;
};

#endif // _CERCLE_H_
