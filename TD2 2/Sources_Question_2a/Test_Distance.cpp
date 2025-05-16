#include <iostream>
#include "TD_Point.h"

using namespace std;

int main()
{
    cout << "===== 测试Point类的Distance函数 =====" << endl;
    
    // 创建两个点
    Point p1(0, 0);
    Point p2(3, 4);
    
    // 计算并显示它们之间的距离
    cout << "点(0,0)和点(3,4)之间的距离是: " << p1.Distance(p2) << endl; // 应该是5
    
    // 测试对称性
    cout << "点(3,4)和点(0,0)之间的距离是: " << p2.Distance(p1) << endl; // 也应该是5
    
    // 测试同一点
    cout << "点(3,4)到自身的距离是: " << p2.Distance(p2) << endl; // 应该是0
    
    return 0;
}
