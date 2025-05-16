#include <iostream>
#include "TD_Point.h"
#include "TD_Triangle.h"

using namespace std;

int main()
{
    cout << "===== 测试Point类的Distance函数 =====" << endl;
    Point p1(0, 0);
    Point p2(3, 4);
    cout << "点(0,0)和点(3,4)之间的距离是: " << p1.Distance(p2) << endl; // 应该是5
    
    cout << "\n===== 测试Triangle类 =====" << endl;
    // 创建一个三角形
    Triangle t(Point(0, 0), Point(3, 0), Point(0, 4));
    
    // 显示三角形
    cout << "原始";
    t.Afficher();
    
    // 计算周长
    cout << "周长: " << t.Perimetre() << endl; // 应该是12
    
    // 计算面积
    cout << "面积: " << t.Aire() << endl; // 应该是6
    
    // 平移三角形
    cout << "平移后";
    t.Translation(Point(1, 1));
    t.Afficher();
    
    return 0;
}
