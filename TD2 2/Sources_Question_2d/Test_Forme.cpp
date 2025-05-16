#include <iostream>
#include "TD_Point.h"
#include "TD_Forme.h"
#include "TD_Triangle.h"
#include "TD_Forme_Quadri.h"
#include "TD_Forme_Cercle.h"

using namespace std;

int main()
{
    cout << "===== 继承形状测试程序 =====" << endl;
    
    // 创建一些点
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(3, 4);
    Point p4(0, 4);
    
    // 测试Triangle类
    cout << "\n--- Triangle类测试 ---" << endl;
    Triangle triangle(p1, p2, p3);
    
    cout << "三角形: " << endl;
    triangle.Afficher();
    
    cout << "三角形周长: " << triangle.Perimetre() << endl;
    cout << "三角形面积: " << triangle.Aire() << endl;
    
    cout << "平移三角形: " << endl;
    triangle.Translation(Point(1, 1));
    triangle.Afficher();
    
    // 测试Quadri类
    cout << "\n--- Quadri类测试 ---" << endl;
    Quadri quadri(p1, p2, p3, p4); // 矩形
    
    cout << "四边形: " << endl;
    quadri.Afficher();
    
    cout << "四边形周长: " << quadri.Perimetre() << endl;
    cout << "四边形面积: " << quadri.Aire() << endl;
    
    cout << "平移四边形: " << endl;
    quadri.Translation(Point(1, 1));
    quadri.Afficher();
    
    // 创建一个凹四边形进行测试
    Point p5(1, 1);
    Quadri concaveQuadri(p1, p2, p5, p4); // 凹四边形
    
    cout << "凹四边形: " << endl;
    concaveQuadri.Afficher();
    
    cout << "凹四边形周长: " << concaveQuadri.Perimetre() << endl;
    cout << "凹四边形面积: " << concaveQuadri.Aire() << endl;
    
    // 测试Cercle类
    cout << "\n--- Cercle类测试 ---" << endl;
    Cercle cercle(p1, 5);
    
    cout << "圆: ";
    cercle.Afficher();
    
    cout << "圆周长: " << cercle.Perimetre() << endl;
    cout << "圆面积: " << cercle.Aire() << endl;
    
    cout << "平移圆: ";
    cercle.Translation(Point(1, 1));
    cercle.Afficher();
    
    // 使用多态性测试
    cout << "\n--- 多态性测试 ---" << endl;
    Forme *shapes[3];
    shapes[0] = &triangle;
    shapes[1] = &quadri;
    shapes[2] = &cercle;
    
    double totalArea = 0;
    double totalPerimeter = 0;
    
    for (int i = 0; i < 3; i++) {
        cout << "Shape " << i+1 << ":" << endl;
        shapes[i]->Afficher();
        
        double area = shapes[i]->Aire();
        double perim = shapes[i]->Perimetre();
        
        cout << "面积: " << area << endl;
        cout << "周长: " << perim << endl;
        
        totalArea += area;
        totalPerimeter += perim;
    }
    
    cout << "\n所有形状的总面积: " << totalArea << endl;
    cout << "所有形状的总周长: " << totalPerimeter << endl;
    
    return 0;
}
