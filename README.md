# C++/UML 练习1 - 几何形状类设计与实现

## 项目概述

本项目实现了基于C++的几何形状处理程序，包括Point（点）、Triangle（三角形）、Quadri（四边形）和Cercle（圆）类。此外，还实现了基于继承的类层次结构，使用Forme作为基类，派生出不同的具体形状类。

## 项目结构

项目分为两个部分：

### 1. 直接实现（Sources_Question_2a）

独立的类实现，没有使用继承关系：

- `TD_Point.h/cpp` - 点类实现
- `TD_Triangle.h/cpp` - 三角形类实现
- `TD_Quadri.h/cpp` - 四边形类实现
- `TD_Cercle.h/cpp` - 圆类实现
- `TD_main.cpp` - 主程序
- `Test_Distance.cpp` - 测试点距离函数
- `Test_Triangle.cpp` - 测试三角形类
- `Test_All.cpp` - 测试所有几何形状类

### 2. 继承实现（Sources_Question_2d）

基于继承关系的实现：

- `TD_Point.h/cpp` - 点类实现
- `TD_Forme.h/cpp` - 抽象形状基类
- `TD_Triangle.h/cpp` - 继承自Forme的三角形类
- `TD_Forme_Quadri.h/cpp` - 继承自Forme的四边形类
- `TD_Forme_Cercle.h/cpp` - 继承自Forme的圆类
- `TD_main.cpp` - 主程序
- `Test_Forme.cpp` - 测试所有形状类和多态性

## 主要功能

1. **Point类**：
   - 表示平面上的点
   - 支持添加点（向量加法）
   - 计算点之间的距离

2. **Triangle类**：
   - 三点定义三角形
   - 计算周长和面积
   - 支持平移操作

3. **Quadri类**：
   - 四点定义四边形
   - 处理凸四边形和凹四边形
   - 正确计算任意四边形面积

4. **Cercle类**：
   - 中心点和半径定义圆
   - 计算周长和面积

5. **继承关系**：
   - 抽象基类Forme定义共同接口
   - 派生类实现特定形状的计算方法
   - 多态性示例

## 编译和运行

### 编译 Sources_Question_2a

```bash
cd "/Users/michael/Coding Project/td2cpp/TD2 2/Sources_Question_2a"
mkdir build
cd build
cmake ..
make
```

### 运行 Sources_Question_2a 的测试程序

```bash
./TD_Geom         # 运行主程序
./Test_Distance   # 测试距离函数
./Test_Triangle   # 测试三角形类
./Test_All        # 测试所有几何形状类
```

### 编译 Sources_Question_2d

```bash
cd "/Users/michael/Coding Project/td2cpp/TD2 2/Sources_Question_2d"
mkdir build
cd build
cmake ..
make
```

### 运行 Sources_Question_2d 的测试程序

```bash
./TD_Geom         # 运行主程序
./Test_Forme      # 测试所有形状类和多态性
```

## 详细解答

详细的解答文档位于 `EX1_Solution.md`，包含以下内容：

1. 问题1-a的程序分析
2. 问题1-b中Distance函数的实现
3. 问题1-c中Triangle类的UML建模和实现
4. 问题1-d中Quadri类的UML建模和实现
5. 问题1-e中Cercle类的UML建模和实现
6. 问题1-f中共同点分析
7. 问题1-g中应用程序的分层建模

## 特殊实现说明

### 四边形面积计算

对于凹四边形，我们使用了向量积来确定正确的三角形分解方法，确保正确计算面积。

### 继承结构

我们通过以下方式设计继承结构：
- Forme类使用动态数组存储形状的顶点
- 抽象方法Aire()由派生类实现
- 通用方法Perimetre()和Translation()在基类中实现
- Cercle类特别处理并重写了所有方法
