#ifndef _FORME_QUADRI_H_
#define _FORME_QUADRI_H_

#include "TD_Forme.h"
#include "TD_Point.h"
#include "TD_Triangle.h"

class Quadri : public Forme // 继承自Forme类
{
public:
    // 默认构造函数
    Quadri() : Forme(4) {}; // 调用Forme构造函数，指定4个顶点
    
    // 带4个点的构造函数
    Quadri(const Point &pt1, const Point &pt2, const Point &pt3, const Point &pt4);
    
    // 计算面积
    double Aire() const override;
    
private:
    // 辅助函数，用于计算三点的向量积
    double VectorProduct(const Point &p1, const Point &p2, const Point &p3) const;
};

#endif // _FORME_QUADRI_H_
