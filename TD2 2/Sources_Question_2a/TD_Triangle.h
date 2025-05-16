#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "TD_Point.h"

class Triangle
{
private:
    Point pt1;
    Point pt2;
    Point pt3;

public:
    // 构造函数
    Triangle(const Point &p1 = Point(0,0), const Point &p2 = Point(0,0), const Point &p3 = Point(0,0));

    // 访问函数
    Point GetPoint1() const;
    Point GetPoint2() const;
    Point GetPoint3() const;
    void SetPoint1(const Point &p);
    void SetPoint2(const Point &p);
    void SetPoint3(const Point &p);

    // 其他成员函数
    void Afficher() const;
    double Perimetre() const;
    void Translation(const Point &v);
    double Aire() const;
};

#endif // _TRIANGLE_H_
