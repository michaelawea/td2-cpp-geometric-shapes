#include <iostream>
#include <cmath>
#include "TD_Forme_Cercle.h"

using namespace std;

// 构造函数
Cercle::Cercle(const Point &center, double r) : Forme(1), rayon(r)
{
    // 确保半径非负
    if (rayon < 0) {
        rayon = 0;
    }
    
    SetPoint(0, center); // 设置圆心
}

// Getter和Setter
double Cercle::GetRayon() const
{
    return rayon;
}

void Cercle::SetRayon(double r)
{
    // 确保半径非负
    if (r >= 0) {
        rayon = r;
    }
}

// 显示函数（覆盖基类的方法）
void Cercle::Afficher() const
{
    cout << "Cercle: Center: ";
    GetPoint(0).Afficher();
    cout << ", Rayon: " << rayon << endl;
}

// 计算周长（覆盖基类的方法）
double Cercle::Perimetre() const
{
    return 2 * M_PI * rayon;
}

// 计算面积
double Cercle::Aire() const
{
    return M_PI * rayon * rayon;
}
