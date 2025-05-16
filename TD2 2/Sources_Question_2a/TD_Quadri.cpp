#include <iostream>
#include <cmath>
#include "TD_Quadri.h"

using namespace std;

// 构造函数
Quadri::Quadri(const Point &p1, const Point &p2, const Point &p3, const Point &p4)
    : pt1(p1), pt2(p2), pt3(p3), pt4(p4)
{
}

// Getter 函数
Point Quadri::GetPoint1() const
{
    return pt1;
}

Point Quadri::GetPoint2() const
{
    return pt2;
}

Point Quadri::GetPoint3() const
{
    return pt3;
}

Point Quadri::GetPoint4() const
{
    return pt4;
}

// Setter 函数
void Quadri::SetPoint1(const Point &p)
{
    pt1 = p;
}

void Quadri::SetPoint2(const Point &p)
{
    pt2 = p;
}

void Quadri::SetPoint3(const Point &p)
{
    pt3 = p;
}

void Quadri::SetPoint4(const Point &p)
{
    pt4 = p;
}

// 显示四边形的四个顶点
void Quadri::Afficher() const
{
    cout << "Quadrilateral: ";
    cout << "Point 1: ";
    pt1.Afficher();
    cout << ", Point 2: ";
    pt2.Afficher();
    cout << ", Point 3: ";
    pt3.Afficher();
    cout << ", Point 4: ";
    pt4.Afficher();
    cout << endl;
}

// 计算四边形周长
double Quadri::Perimetre() const
{
    double side1 = pt1.Distance(pt2);
    double side2 = pt2.Distance(pt3);
    double side3 = pt3.Distance(pt4);
    double side4 = pt4.Distance(pt1);
    
    return side1 + side2 + side3 + side4;
}

// 平移四边形
void Quadri::Translation(const Point &v)
{
    pt1 = pt1.Add(v);
    pt2 = pt2.Add(v);
    pt3 = pt3.Add(v);
    pt4 = pt4.Add(v);
}

// 计算三点的向量积
double Quadri::VectorProduct(const Point &p1, const Point &p2, const Point &p3) const
{
    // 计算向量 p1p2 和 p1p3
    double x1 = p2.GetX() - p1.GetX();
    double y1 = p2.GetY() - p1.GetY();
    double x2 = p3.GetX() - p1.GetX();
    double y2 = p3.GetY() - p1.GetY();
    
    // 计算向量积 (x1*y2 - x2*y1)
    return x1 * y2 - x2 * y1;
}

// 计算四边形面积
double Quadri::Aire() const
{
    // 根据题目要求，需要找到正确的分解方式
    // 检查分解方式1: [AC]分解为三角形(C,A,D)和(C,A,B)
    double vp1 = VectorProduct(pt3, pt1, pt4); // 三角形CAD的向量积
    double vp2 = VectorProduct(pt3, pt1, pt2); // 三角形CAB的向量积
    
    // 检查分解方式2: [BD]分解为三角形(B,D,A)和(B,D,C)
    double vp3 = VectorProduct(pt2, pt4, pt1); // 三角形BDA的向量积
    double vp4 = VectorProduct(pt2, pt4, pt3); // 三角形BDC的向量积
    
    // 判断哪种分解是正确的
    // 如果vp1和vp2符号相同，或者vp3和vp4符号相同，表示对应的分解是错误的
    bool decompose1_correct = (vp1 * vp2 < 0);
    bool decompose2_correct = (vp3 * vp4 < 0);
    
    double area = 0.0;
    
    if (decompose2_correct || (!decompose1_correct && !decompose2_correct)) {
        // 使用[BD]分解，或者如果两种分解都可以（凸四边形），使用第二种
        Triangle t1(pt2, pt4, pt1);
        Triangle t2(pt2, pt4, pt3);
        area = fabs(t1.Aire()) + fabs(t2.Aire());
    } else {
        // 使用[AC]分解
        Triangle t1(pt3, pt1, pt4);
        Triangle t2(pt3, pt1, pt2);
        area = fabs(t1.Aire()) + fabs(t2.Aire());
    }
    
    return area;
}
