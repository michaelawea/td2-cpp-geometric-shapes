#include <iostream>
#include <cmath>
#include "TD_Triangle.h"

using namespace std;

// 构造函数
Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3)
    : pt1(p1), pt2(p2), pt3(p3)
{
}

// Getter 函数
Point Triangle::GetPoint1() const
{
    return pt1;
}

Point Triangle::GetPoint2() const
{
    return pt2;
}

Point Triangle::GetPoint3() const
{
    return pt3;
}

// Setter 函数
void Triangle::SetPoint1(const Point &p)
{
    pt1 = p;
}

void Triangle::SetPoint2(const Point &p)
{
    pt2 = p;
}

void Triangle::SetPoint3(const Point &p)
{
    pt3 = p;
}

// 显示三角形的三个顶点
void Triangle::Afficher() const
{
    cout << "Triangle: ";
    cout << "Point 1: ";
    pt1.Afficher();
    cout << ", Point 2: ";
    pt2.Afficher();
    cout << ", Point 3: ";
    pt3.Afficher();
    cout << endl;
}

// 计算三角形周长
double Triangle::Perimetre() const
{
    double side1 = pt1.Distance(pt2);
    double side2 = pt2.Distance(pt3);
    double side3 = pt3.Distance(pt1);
    
    return side1 + side2 + side3;
}

// 平移三角形
void Triangle::Translation(const Point &v)
{
    // 创建新点，加上向量v
    Point newPt1 = pt1.Add(v);
    Point newPt2 = pt2.Add(v);
    Point newPt3 = pt3.Add(v);
    
    // 更新三角形顶点
    pt1 = newPt1;
    pt2 = newPt2;
    pt3 = newPt3;
}

// 计算三角形面积（使用海伦公式）
double Triangle::Aire() const
{
    double side1 = pt1.Distance(pt2);
    double side2 = pt2.Distance(pt3);
    double side3 = pt3.Distance(pt1);
    
    // 半周长
    double p = (side1 + side2 + side3) / 2.0;
    
    // 海伦公式：Area = √(p(p-a)(p-b)(p-c))
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}
