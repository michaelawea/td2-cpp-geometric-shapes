#ifndef _QUADRI_H_
#define _QUADRI_H_

#include "TD_Point.h"
#include "TD_Triangle.h"

class Quadri
{
private:
    Point pt1;
    Point pt2;
    Point pt3;
    Point pt4;

public:
    // 构造函数
    Quadri(const Point &p1 = Point(0,0), const Point &p2 = Point(0,0), 
           const Point &p3 = Point(0,0), const Point &p4 = Point(0,0));

    // 访问函数
    Point GetPoint1() const;
    Point GetPoint2() const;
    Point GetPoint3() const;
    Point GetPoint4() const;
    void SetPoint1(const Point &p);
    void SetPoint2(const Point &p);
    void SetPoint3(const Point &p);
    void SetPoint4(const Point &p);

    // 其他成员函数
    void Afficher() const;
    double Perimetre() const;
    void Translation(const Point &v);
    double Aire() const;

private:
    // 辅助函数，用于计算三点的向量积
    double VectorProduct(const Point &p1, const Point &p2, const Point &p3) const;
};

#endif // _QUADRI_H_
