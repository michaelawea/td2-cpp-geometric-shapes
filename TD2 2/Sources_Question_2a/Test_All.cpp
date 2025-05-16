#include <iostream>
#include "TD_Point.h"
#include "TD_Triangle.h"
#include "TD_Quadri.h"
#include "TD_Cercle.h"

using namespace std;

int main()
{
    cout << "===== 几何形状测试程序 =====" << endl;
    
    // 测试Point类
    cout << "\n--- Point类测试 ---" << endl;
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 4);
    Point p4(3, 4);
    
    cout << "点p1: ";
    p1.Afficher();
    cout << endl;
    
    cout << "点p2: ";
    p2.Afficher();
    cout << endl;
    
    cout << "p1和p2之间的距离: " << p1.Distance(p2) << endl;
    
    // 测试Triangle类
    cout << "\n--- Triangle类测试 ---" << endl;
    Triangle triangle(p1, p2, p3);
    
    cout << "三角形: ";
    triangle.Afficher();
    
    cout << "三角形周长: " << triangle.Perimetre() << endl;
    cout << "三角形面积: " << triangle.Aire() << endl;
    
    cout << "平移三角形: ";
    triangle.Translation(Point(1, 1));
    triangle.Afficher();
    
    // 测试Quadri类
    cout << "\n--- Quadri类测试 ---" << endl;
    Quadri quadri(p1, p2, p4, p3); // 正方形
    
    cout << "四边形: ";
    quadri.Afficher();
    
    cout << "四边形周长: " << quadri.Perimetre() << endl;
    cout << "四边形面积: " << quadri.Aire() << endl;
    
    cout << "平移四边形: ";
    quadri.Translation(Point(1, 1));
    quadri.Afficher();
    
    // 创建一个凹四边形进行测试
    Point p5(1, 1);
    Quadri concaveQuadri(p1, p2, p5, p3); // 凹四边形
    
    cout << "凹四边形: ";
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
    
    return 0;
}
