# C++/UML 练习1解答文档

## 1-a 程序分析

分析以下程序，理解每一行代码，并给出产生的输出。

```cpp
#include <iostream>
#include "TD_Point.h"
using namespace std;

int main(void)
{
    cout << " #### exo 1 #### " << endl;  // 输出标题
    Point pt1(1,1);  // 创建一个点pt1，坐标为(1,1)
    Point pt2;  // 创建一个默认点pt2，坐标为(0,0)
    Point * _pt;  // 声明一个Point类型的指针
    pt2 = Point(3,1);  // 创建一个临时点(3,1)并赋值给pt2
    _pt = new Point();  // 动态分配一个新的默认点(0,0)，_pt指向它
    cout << "Position de pt1 : ";  // 输出提示
    pt1.Afficher();  // 输出pt1的位置：(1,1)
    pt1.SetX(2); pt1.SetY(3);  // 修改pt1的坐标为(2,3)
    pt1.Afficher();  // 输出修改后的pt1：(2,3)
    cout << endl;
    cout << "Position de pt2 : ";  // 输出提示
    pt2.Afficher();  // 输出pt2的位置：(3,1)
    cout << endl;
    *_pt = pt1.Add(pt2);  // 计算pt1和pt2的和，并存储在_pt指向的对象中
    cout << "Position de pt3 : ";  // 输出提示
    _pt->Afficher();  // 输出_pt指向的对象位置：(5,4)
    cout << endl;
    delete _pt;  // 释放_pt指向的内存
    cout << "Appuyer sur Entree pour continuer" << endl;  // 提示按Enter继续
    cin.get();  // 等待用户输入
    return 0;  // 返回0，程序结束
}
```

程序输出：
```
 #### exo 1 #### 
Position de pt1 : (1 ,1 )(2 ,3 )
Position de pt2 : (3 ,1 )
Position de pt3 : (5 ,4 )
Appuyer sur Entree pour continuer
```

## 1-b Distance函数实现

为Point类添加计算两点间距离的成员函数：

```cpp
// 在TD_Point.h中添加声明
double Distance(const Point &pt) const;

// 在TD_Point.cpp中添加实现
double Point::Distance(const Point &pt) const
{
    double dx = X - pt.X;
    double dy = Y - pt.Y;
    return sqrt(dx * dx + dy * dy);
}
```

这个函数使用欧几里得距离公式：d = √((x₂ - x₁)² + (y₂ - y₁)²)

## 1-c Triangle类的UML建模与实现

### Triangle类的UML图

```
Triangle
-pt1: Point
-pt2: Point
-pt3: Point
+Triangle(p1: Point, p2: Point, p3: Point)
+GetPoint1(): Point
+GetPoint2(): Point
+GetPoint3(): Point
+SetPoint1(p: Point): void
+SetPoint2(p: Point): void
+SetPoint3(p: Point): void
+Afficher(): void
+Perimetre(): double
+Translation(v: Point): void
+Aire(): double
```

### Triangle类的实现

头文件 (TD_Triangle.h):
```cpp
#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "TD_Point.h"

class Triangle
{
private:
    Point pt1;
    Point pt2;
    Point pt3;

public:
    // 构造函数
    Triangle(const Point &p1 = Point(0,0), const Point &p2 = Point(0,0), const Point &p3 = Point(0,0));

    // 访问函数
    Point GetPoint1() const;
    Point GetPoint2() const;
    Point GetPoint3() const;
    void SetPoint1(const Point &p);
    void SetPoint2(const Point &p);
    void SetPoint3(const Point &p);

    // 其他成员函数
    void Afficher() const;
    double Perimetre() const;
    void Translation(const Point &v);
    double Aire() const;
};

#endif // _TRIANGLE_H_
```

实现文件 (TD_Triangle.cpp):
```cpp
#include <iostream>
#include <cmath>
#include "TD_Triangle.h"

using namespace std;

// 构造函数
Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3)
    : pt1(p1), pt2(p2), pt3(p3)
{
}

// Getter 函数
Point Triangle::GetPoint1() const
{
    return pt1;
}

Point Triangle::GetPoint2() const
{
    return pt2;
}

Point Triangle::GetPoint3() const
{
    return pt3;
}

// Setter 函数
void Triangle::SetPoint1(const Point &p)
{
    pt1 = p;
}

void Triangle::SetPoint2(const Point &p)
{
    pt2 = p;
}

void Triangle::SetPoint3(const Point &p)
{
    pt3 = p;
}

// 显示三角形的三个顶点
void Triangle::Afficher() const
{
    cout << "Triangle: ";
    cout << "Point 1: ";
    pt1.Afficher();
    cout << ", Point 2: ";
    pt2.Afficher();
    cout << ", Point 3: ";
    pt3.Afficher();
    cout << endl;
}

// 计算三角形周长
double Triangle::Perimetre() const
{
    double side1 = pt1.Distance(pt2);
    double side2 = pt2.Distance(pt3);
    double side3 = pt3.Distance(pt1);
    
    return side1 + side2 + side3;
}

// 平移三角形
void Triangle::Translation(const Point &v)
{
    // 创建新点，加上向量v
    Point newPt1 = pt1.Add(v);
    Point newPt2 = pt2.Add(v);
    Point newPt3 = pt3.Add(v);
    
    // 更新三角形顶点
    pt1 = newPt1;
    pt2 = newPt2;
    pt3 = newPt3;
}

// 计算三角形面积（使用海伦公式）
double Triangle::Aire() const
{
    double side1 = pt1.Distance(pt2);
    double side2 = pt2.Distance(pt3);
    double side3 = pt3.Distance(pt1);
    
    // 半周长
    double p = (side1 + side2 + side3) / 2.0;
    
    // 海伦公式：Area = √(p(p-a)(p-b)(p-c))
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}
```

## 1-d Quadri类的UML建模与实现

### Quadri类的UML图

```
Quadri
-pt1: Point
-pt2: Point
-pt3: Point
-pt4: Point
+Quadri(p1: Point, p2: Point, p3: Point, p4: Point)
+GetPoint1(): Point
+GetPoint2(): Point
+GetPoint3(): Point
+GetPoint4(): Point
+SetPoint1(p: Point): void
+SetPoint2(p: Point): void
+SetPoint3(p: Point): void
+SetPoint4(p: Point): void
+Afficher(): void
+Perimetre(): double
+Translation(v: Point): void
+Aire(): double
-VectorProduct(p1: Point, p2: Point, p3: Point): double
```

### Quadri类的实现

头文件 (TD_Quadri.h):
```cpp
#ifndef _QUADRI_H_
#define _QUADRI_H_

#include "TD_Point.h"
#include "TD_Triangle.h"

class Quadri
{
private:
    Point pt1;
    Point pt2;
    Point pt3;
    Point pt4;

public:
    // 构造函数
    Quadri(const Point &p1 = Point(0,0), const Point &p2 = Point(0,0), 
           const Point &p3 = Point(0,0), const Point &p4 = Point(0,0));

    // 访问函数
    Point GetPoint1() const;
    Point GetPoint2() const;
    Point GetPoint3() const;
    Point GetPoint4() const;
    void SetPoint1(const Point &p);
    void SetPoint2(const Point &p);
    void SetPoint3(const Point &p);
    void SetPoint4(const Point &p);

    // 其他成员函数
    void Afficher() const;
    double Perimetre() const;
    void Translation(const Point &v);
    double Aire() const;

private:
    // 辅助函数，用于计算三点的向量积
    double VectorProduct(const Point &p1, const Point &p2, const Point &p3) const;
};

#endif // _QUADRI_H_
```

四边形面积计算需要注意处理凹四边形的情况。根据题目描述，可以通过将四边形分解为两个三角形，然后选择正确的分解方法来计算面积。对于凹四边形，只有其中一种分解方法能正确计算面积。实现中需要使用向量积来判断正确的分解方法。

## 1-e Cercle类的UML建模与实现

### Cercle类的UML图

```
Cercle
-center: Point
-rayon: double
+Cercle(c: Point, r: double)
+GetCenter(): Point
+GetRayon(): double
+SetCenter(c: Point): void
+SetRayon(r: double): void
+Afficher(): void
+Perimetre(): double
+Translation(v: Point): void
+Aire(): double
```

### Cercle类的实现

头文件 (TD_Cercle.h):
```cpp
#ifndef _CERCLE_H_
#define _CERCLE_H_

#include "TD_Point.h"

class Cercle
{
private:
    Point center;
    double rayon;

public:
    // 构造函数
    Cercle(const Point &c = Point(0,0), double r = 0);

    // 访问函数
    Point GetCenter() const;
    double GetRayon() const;
    void SetCenter(const Point &c);
    void SetRayon(double r);

    // 其他成员函数
    void Afficher() const;
    double Perimetre() const;
    void Translation(const Point &v);
    double Aire() const;
};

#endif // _CERCLE_H_
```

圆的周长计算公式：2πr
圆的面积计算公式：πr²

## 1-f 共同点分析

### 共同字段：
- 所有类都表示几何形状
- 所有类都使用Point对象作为其基本组成部分

### 共同成员函数：
- 构造函数
- Getter和Setter方法
- Afficher()：显示形状
- Perimetre()：计算周长
- Translation()：平移操作
- Aire()：计算面积

### 不兼容的部分：
- 每个类的数据表示不同（三角形有3个点，四边形有4个点，圆有中心点和半径）
- 面积和周长的计算公式不同
- 内部数据结构的不同导致某些操作的实现方式不同

### 修改建议：
可以创建一个基类`Forme`（形状），包含所有共同的成员函数，然后让三个具体类继承这个基类，并各自实现特定的计算方法。

基类中的函数可以声明为虚函数，以便派生类可以根据自己的需要重写这些函数。这样可以实现多态性，使得统一的接口能够处理不同类型的形状。

## 1-g 应用程序的分层建模

```
       Forme (抽象基类)
       /    |    \
      /     |     \
Triangle  Quadri  Cercle
      \     |     /
       \    |    /
        使用Point类
```

基类`Forme`将包含：
- 纯虚函数Aire()：要求所有派生类必须实现
- 虚函数Afficher()：可被派生类重写
- 虚函数Perimetre()：可被派生类重写
- 虚函数Translation()：可被派生类重写

### 继承实现思路

1. Forme基类设计：
   - 使用动态数组存储形状的顶点
   - 提供顶点操作的通用方法
   - 声明虚函数以支持多态

2. Triangle类 (继承自Forme)：
   - 设置3个顶点
   - 实现Aire()方法计算三角形面积
   - 继承Perimetre()和Translation()通用实现

3. Quadri类 (继承自Forme)：
   - 设置4个顶点
   - 实现Aire()方法，处理凹四边形的情况
   - 继承Perimetre()和Translation()通用实现

4. Cercle类 (继承自Forme)：
   - 使用1个顶点表示圆心，额外存储半径
   - 重写Afficher()、Perimetre()和Aire()方法
   - 重写Translation()方法

这种设计使系统更加灵活，容易扩展，并支持多态操作，例如可以创建一个包含不同形状的数组，并对所有形状执行统一的操作。通过继承和多态，我们可以实现代码重用，同时保持接口的一致性。
