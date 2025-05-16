#ifndef _FORME_CERCLE_H_
#define _FORME_CERCLE_H_

#include "TD_Forme.h"
#include "TD_Point.h"

class Cercle : public Forme // 继承自Forme类
{
private:
    double rayon; // 圆的半径

public:
    // 默认构造函数
    Cercle() : Forme(1), rayon(0) {}; // 调用Forme构造函数，指定1个顶点（圆心）
    
    // 带中心点和半径的构造函数
    Cercle(const Point &center, double r);
    
    // Getter和Setter
    double GetRayon() const;
    void SetRayon(double r);
    
    // 显示函数（覆盖基类的方法）
    void Afficher() const override;
    
    // 计算周长（覆盖基类的方法）
    double Perimetre() const override;
    
    // 计算面积
    double Aire() const override;
};

#endif // _FORME_CERCLE_H_
