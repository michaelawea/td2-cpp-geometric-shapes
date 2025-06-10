# TD2 - C++/UML 完整解答文档

## 概述

本文档包含了TD2 C++/UML练习的完整解答，涵盖了Point类、Triangle类的实现，以及使用继承机制的Forme基类及其派生类（Triangle、Quadri、Cercle）的设计与实现。

## 练习1：准备工作，UML建模

### 1-a 程序分析

**分析程序：**
```cpp
#include <iostream>
#include "TD_Point.h"
using namespace std;

int main(void)
{
    cout << " #### exo 1 #### " << endl;
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
    cout << "Appuyer sur Entree pour continuer" << endl;
    cin.get();
    return 0;
}
```

**代码分析：**
1. `Point pt1(1,1);` - 创建点pt1，坐标(1,1)
2. `Point pt2;` - 创建默认点pt2，坐标(0,0)
3. `Point * _pt;` - 声明Point类型指针
4. `pt2 = Point(3,1);` - 创建临时点(3,1)赋值给pt2
5. `_pt = new Point();` - 动态分配默认点(0,0)
6. `pt1.Afficher();` - 输出pt1：(1,1)
7. `pt1.SetX(2); pt1.SetY(3);` - 修改pt1为(2,3)
8. `pt1.Afficher();` - 输出修改后的pt1：(2,3)
9. `pt2.Afficher();` - 输出pt2：(3,1)
10. `*_pt = pt1.Add(pt2);` - 计算(2,3)+(3,1)=(5,4)，存储在_pt指向的对象
11. `_pt->Afficher();` - 输出结果：(5,4)
12. `delete _pt;` - 释放动态分配的内存

**程序输出：**
```
 #### exo 1 #### 
Position de pt1 : (1 ,1 )(2 ,3 )
Position de pt2 : (3 ,1 )
Position de pt3 : (5 ,4 )
Appuyer sur Entree pour continuer
```

### 1-b Distance函数实现

**在TD_Point.h中添加声明：**
```cpp
double Distance(const Point &pt) const;
```

**在TD_Point.cpp中添加实现：**
```cpp
double Point::Distance(const Point &pt) const
{
    double dx = X - pt.X;
    double dy = Y - pt.Y;
    return sqrt(dx * dx + dy * dy);
}
```

该函数使用欧几里得距离公式：d = √((x₂ - x₁)² + (y₂ - y₁)²)

### 1-c Triangle类的UML建模

**Triangle类UML图：**
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

**Triangle类实现：**

*TD_Triangle.h:*
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

#endif
```

*TD_Triangle.cpp:*
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

// Getter函数
Point Triangle::GetPoint1() const { return pt1; }
Point Triangle::GetPoint2() const { return pt2; }
Point Triangle::GetPoint3() const { return pt3; }

// Setter函数
void Triangle::SetPoint1(const Point &p) { pt1 = p; }
void Triangle::SetPoint2(const Point &p) { pt2 = p; }
void Triangle::SetPoint3(const Point &p) { pt3 = p; }

// 显示三角形
void Triangle::Afficher() const
{
    cout << "Triangle: ";
    cout << "Point 1: "; pt1.Afficher();
    cout << ", Point 2: "; pt2.Afficher();
    cout << ", Point 3: "; pt3.Afficher();
    cout << endl;
}

// 计算周长
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
    pt1 = pt1.Add(v);
    pt2 = pt2.Add(v);
    pt3 = pt3.Add(v);
}

// 计算面积（海伦公式）
double Triangle::Aire() const
{
    double side1 = pt1.Distance(pt2);
    double side2 = pt2.Distance(pt3);
    double side3 = pt3.Distance(pt1);
    
    double p = (side1 + side2 + side3) / 2.0;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}
```

### 1-d Quadri类的UML建模

**Quadri类UML图：**
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
```

### 1-e Cercle类的UML建模

**Cercle类UML图：**
```
Cercle
-center: Point
-rayon: double
+Cercle(center: Point, r: double)
+GetCenter(): Point
+GetRayon(): double
+SetCenter(p: Point): void
+SetRayon(r: double): void
+Afficher(): void
+Perimetre(): double
+Translation(v: Point): void
+Aire(): double
```

### 1-f 共同点识别

**共同字段：**
- 都有用于定位的Point类型字段
- 都需要存储几何形状的基本信息

**共同成员函数：**
- `Afficher()`: 显示几何形状信息
- `Perimetre()`: 计算周长
- `Translation()`: 平移操作
- `Aire()`: 计算面积
- 访问器函数（getter/setter）

**不兼容的函数：**
- 访问器函数的数量不同（Triangle有3个点，Quadri有4个点，Cercle有1个中心点+半径）
- 但核心算法（面积、周长、平移）可以统一

### 1-g 分层建模方案

**继承层次结构：**
```
Forme (抽象基类)
├── Triangle
├── Quadri  
└── Cercle
```

**Forme基类应包含：**
- 虚函数：`Aire()`, `Perimetre()`, `Translation()`, `Afficher()`
- 通用的点存储机制（动态数组）
- 公共的基本操作

## 练习2：实现，第一批类

### 2-a 验证与项目创建

项目已创建，包含以下文件：
- `TD_Point.h` / `TD_Point.cpp`: Point类的定义和实现
- `TD_Triangle.h` / `TD_Triangle.cpp`: Triangle类的定义和实现  
- `TD_main.cpp`: 主程序
- 各种测试文件

### 2-b Distance函数测试

Distance函数已实现并测试，计算两点间的欧几里得距离。

### 2-c Triangle类实现

Triangle类已完整实现，包括所有要求的功能。

### 2-d 继承实现

**Forme基类设计：**

*TD_Forme.h:*
```cpp
#ifndef _Forme_h_
#define _Forme_h_

#include "TD_Point.h"

class Forme
{
protected:
    int NbSommets;
    Point *Sommets; 

public:
    Forme(int nbsommets = 1);
    ~Forme();
    
    void SetPoint(int i, const Point &pt);
    Point & GetPoint(int i) const;
    
    virtual void Afficher() const;
    virtual double Aire() const = 0;  // 纯虚函数
    virtual double Perimetre() const;
    virtual void Translation(const Point &pt);
    
    int GetNbSommets() const;
};

#endif
```

**Quadri类实现：**

*TD_Forme_Quadri.h:*
```cpp
#ifndef _FORME_QUADRI_H_
#define _FORME_QUADRI_H_

#include "TD_Forme.h"
#include "TD_Triangle.h"

class Quadri : public Forme
{
public:
    Quadri() : Forme(4) {};
    Quadri(const Point &pt1, const Point &pt2, const Point &pt3, const Point &pt4);
    
    double Aire() const override;
    
private:
    double VectorProduct(const Point &p1, const Point &p2, const Point &p3) const;
};

#endif
```

*TD_Forme_Quadri.cpp:*
```cpp
#include <iostream>
#include <cmath>
#include "TD_Forme_Quadri.h"

using namespace std;

Quadri::Quadri(const Point &pt1, const Point &pt2, const Point &pt3, const Point &pt4) : Forme(4)
{
    SetPoint(0, pt1);
    SetPoint(1, pt2);
    SetPoint(2, pt3);
    SetPoint(3, pt4);
}

double Quadri::VectorProduct(const Point &p1, const Point &p2, const Point &p3) const
{
    double x1 = p2.GetX() - p1.GetX();
    double y1 = p2.GetY() - p1.GetY();
    double x2 = p3.GetX() - p1.GetX();
    double y2 = p3.GetY() - p1.GetY();
    return x1 * y2 - x2 * y1;
}

double Quadri::Aire() const
{
    Point &p1 = GetPoint(0);
    Point &p2 = GetPoint(1);
    Point &p3 = GetPoint(2);
    Point &p4 = GetPoint(3);
    
    // 检查两种分解方式
    double vp1 = VectorProduct(p3, p1, p4);
    double vp2 = VectorProduct(p3, p1, p2);
    double vp3 = VectorProduct(p2, p4, p1);
    double vp4 = VectorProduct(p2, p4, p3);
    
    bool decompose1_correct = (vp1 * vp2 < 0);
    bool decompose2_correct = (vp3 * vp4 < 0);
    
    double area = 0.0;
    
    if (decompose2_correct || (!decompose1_correct && !decompose2_correct)) {
        Triangle t1(p2, p4, p1);
        Triangle t2(p2, p4, p3);
        area = fabs(t1.Aire()) + fabs(t2.Aire());
    } else {
        Triangle t1(p3, p1, p4);
        Triangle t2(p3, p1, p2);
        area = fabs(t1.Aire()) + fabs(t2.Aire());
    }
    
    return area;
}
```

**Cercle类实现：**

*TD_Forme_Cercle.h:*
```cpp
#ifndef _FORME_CERCLE_H_
#define _FORME_CERCLE_H_

#include "TD_Forme.h"

class Cercle : public Forme
{
private:
    double rayon;

public:
    Cercle() : Forme(1), rayon(0) {};
    Cercle(const Point &center, double r);
    
    double GetRayon() const;
    void SetRayon(double r);
    
    void Afficher() const override;
    double Perimetre() const override;
    double Aire() const override;
};

#endif
```

*TD_Forme_Cercle.cpp:*
```cpp
#include <iostream>
#include <cmath>
#include "TD_Forme_Cercle.h"

using namespace std;

Cercle::Cercle(const Point &center, double r) : Forme(1), rayon(r)
{
    if (rayon < 0) rayon = 0;
    SetPoint(0, center);
}

double Cercle::GetRayon() const { return rayon; }

void Cercle::SetRayon(double r)
{
    if (r >= 0) rayon = r;
}

void Cercle::Afficher() const
{
    cout << "Cercle: Center: ";
    GetPoint(0).Afficher();
    cout << ", Rayon: " << rayon << endl;
}

double Cercle::Perimetre() const
{
    return 2 * M_PI * rayon;
}

double Cercle::Aire() const
{
    return M_PI * rayon * rayon;
}
```

## 四边形面积计算的特殊处理

对于四边形面积计算，我们需要处理凹四边形的情况：

1. **分解方法**：四边形可以用两种方式分解为两个三角形
2. **正确分解的判断**：通过计算向量积的符号来判断
3. **实现逻辑**：
   - 计算两种分解方式的向量积
   - 选择向量积符号相反的分解方式
   - 对于凸四边形，两种方式结果相同

## 测试与验证

所有类都配有完整的测试程序：
- `Test_Complete.cpp`：基础类的完整测试
- `Test_Forme.cpp`：继承体系的测试
- 包含了所有功能的验证和边界情况的测试

## 编译与运行

使用CMake构建系统：
```bash
cd TD2\ 2/Sources_Question_2a/build
make
./TD_Geom
./Test_Complete
```

```bash
cd TD2\ 2/Sources_Question_2d/build  
make
./TD_Geom
./Test_Complete
```

## 总结

本TD通过实现点、三角形、四边形和圆形类，展示了：
1. 基础C++类的设计与实现
2. 继承机制的应用
3. 虚函数和多态性的使用
4. 复杂几何算法的实现（特别是凹四边形面积计算）
5. 良好的软件设计模式和代码组织结构
