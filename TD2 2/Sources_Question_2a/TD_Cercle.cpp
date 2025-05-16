#include <iostream>
#include <cmath>
#include "TD_Cercle.h"

using namespace std;

// 构造函数
Cercle::Cercle(const Point &c, double r)
    : center(c), rayon(r)
{
    // 确保半径非负
    if (rayon < 0) {
        rayon = 0;
    }
}

// Getter 函数
Point Cercle::GetCenter() const
{
    return center;
}

double Cercle::GetRayon() const
{
    return rayon;
}

// Setter 函数
void Cercle::SetCenter(const Point &c)
{
    center = c;
}

void Cercle::SetRayon(double r)
{
    // 确保半径非负
    if (r >= 0) {
        rayon = r;
    }
}

// 显示圆的中心和半径
void Cercle::Afficher() const
{
    cout << "Cercle: Center: ";
    center.Afficher();
    cout << ", Rayon: " << rayon << endl;
}

// 计算圆的周长
double Cercle::Perimetre() const
{
    return 2 * M_PI * rayon;
}

// 平移圆
void Cercle::Translation(const Point &v)
{
    center = center.Add(v);
}

// 计算圆的面积
double Cercle::Aire() const
{
    return M_PI * rayon * rayon;
}
