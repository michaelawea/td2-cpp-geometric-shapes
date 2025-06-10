#include <iostream>
#include "TD_Point.h"
#include "TD_Triangle.h"
using namespace std;

int main()
{
    cout << "========== TD2 完整测试程序 ==========" << endl;
    
    // 测试 Point 类
    cout << "\n1. 测试 Point 类" << endl;
    Point p1(1, 1);
    Point p2(4, 5);
    Point p3;
    
    cout << "Point p1: ";
    p1.Afficher();
    cout << endl;
    
    cout << "Point p2: ";
    p2.Afficher();
    cout << endl;
    
    // 测试 Distance 函数
    double distance = p1.Distance(p2);
    cout << "Distance entre p1 et p2: " << distance << endl;
    
    // 测试 Add 函数
    Point p_sum = p1.Add(p2);
    cout << "p1 + p2 = ";
    p_sum.Afficher();
    cout << endl;
    
    // 测试 Vectoriel 函数
    Point origin(0, 0);
    double vectoriel = origin.Vectoriel(p1, p2);
    cout << "Produit vectoriel (origin, p1, p2): " << vectoriel << endl;
    
    // 测试 Triangle 类
    cout << "\n2. 测试 Triangle 类" << endl;
    Point t1(0, 0);
    Point t2(3, 0);
    Point t3(0, 4);
    
    Triangle triangle(t1, t2, t3);
    cout << "Triangle créé: ";
    triangle.Afficher();
    
    // 测试周长
    double perimetre = triangle.Perimetre();
    cout << "Périmètre du triangle: " << perimetre << endl;
    
    // 测试面积
    double aire = triangle.Aire();
    cout << "Aire du triangle: " << aire << endl;
    
    // 测试平移
    Point translation(1, 1);
    cout << "\nAvant translation: ";
    triangle.Afficher();
    triangle.Translation(translation);
    cout << "Après translation de (1,1): ";
    triangle.Afficher();
    
    // 测试动态分配（练习1-a的程序）
    cout << "\n3. 测试du programme de l'exercice 1-a" << endl;
    Point pt1(1,1);
    Point pt2;
    Point * _pt;
    pt2 = Point(3,1);
    _pt = new Point();
    cout << "Position de pt1 : ";
    pt1.Afficher();
    pt1.SetX(2); pt1.SetY(3);
    pt1.Afficher();
    cout << endl;
    cout << "Position de pt2 : ";
    pt2.Afficher();
    cout << endl;
    *_pt = pt1.Add(pt2);
    cout << "Position de pt3 : ";
    _pt->Afficher();
    cout << endl;
    delete _pt;
    
    cout << "\n========== Tests terminés ==========" << endl;
    return 0;
}
