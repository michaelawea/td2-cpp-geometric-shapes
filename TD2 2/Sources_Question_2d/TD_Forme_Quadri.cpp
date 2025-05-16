#include <iostream>
#include <cmath>
#include "TD_Forme_Quadri.h"

using namespace std;

// 构造函数
Quadri::Quadri(const Point &pt1, const Point &pt2, const Point &pt3, const Point &pt4) : Forme(4)
{
    SetPoint(0, pt1);
    SetPoint(1, pt2);
    SetPoint(2, pt3);
    SetPoint(3, pt4);
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
    // 四边形的四个顶点
    Point &p1 = GetPoint(0);
    Point &p2 = GetPoint(1);
    Point &p3 = GetPoint(2);
    Point &p4 = GetPoint(3);
    
    // 检查分解方式1: [AC]分解为三角形(C,A,D)和(C,A,B)
    double vp1 = VectorProduct(p3, p1, p4); // 三角形CAD的向量积
    double vp2 = VectorProduct(p3, p1, p2); // 三角形CAB的向量积
    
    // 检查分解方式2: [BD]分解为三角形(B,D,A)和(B,D,C)
    double vp3 = VectorProduct(p2, p4, p1); // 三角形BDA的向量积
    double vp4 = VectorProduct(p2, p4, p3); // 三角形BDC的向量积
    
    // 判断哪种分解是正确的
    // 如果vp1和vp2符号相同，或者vp3和vp4符号相同，表示对应的分解是错误的
    bool decompose1_correct = (vp1 * vp2 < 0);
    bool decompose2_correct = (vp3 * vp4 < 0);
    
    double area = 0.0;
    
    if (decompose2_correct || (!decompose1_correct && !decompose2_correct)) {
        // 使用[BD]分解，或者如果两种分解都可以（凸四边形），使用第二种
        Triangle t1(p2, p4, p1);
        Triangle t2(p2, p4, p3);
        area = fabs(t1.Aire()) + fabs(t2.Aire());
    } else {
        // 使用[AC]分解
        Triangle t1(p3, p1, p4);
        Triangle t2(p3, p1, p2);
        area = fabs(t1.Aire()) + fabs(t2.Aire());
    }
    
    return area;
}
