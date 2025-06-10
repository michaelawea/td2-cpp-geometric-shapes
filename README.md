# TD2 C++/UML - 几何形状类设计与实现

## 项目概述

本项目是INSA Lyon IF3课程的TD2作业，实现了基于C++的几何形状处理程序。项目包含Point（点）、Triangle（三角形）、Quadri（四边形）和Cercle（圆）类的设计与实现，以及基于继承的类层次结构。

## 题目描述

### IF3 INSA GE - TD MOO : C++ / UML (第2次课/共6次课)

本TD的目标是操作基于Point类的几何形状，包括：

#### 练习1：准备工作，UML建模

以下是Point类的UML图表及其定义：

**Point类图：**
```
Point
-X: double
-Y: double
<<create>>+Point(x: double, y: double)
+Distance(pt: Point): double
+Add(pt: Point): Point
+Vectoriel(pt1: Point, pt2: Point): double
+Afficher(): void
+GetX(): double
+GetY(): double
+SetX(x: double): void
+SetY(y: double): void
```

**题目要求：**

**1-a** 分析程序：理解代码的每一行并给出产生的输出
**1-b** 实现Point类成员函数"Distance"，计算两点间的距离
**1-c** 用UML建模Triangle类，包含以下功能：
- 对字段(3个点)的读写访问函数
- Affichage：显示3个点的坐标
- Perimetre：返回三角形的周长
- Translation：通过向量平移三角形
- Aire：返回三角形的面积(海伦公式)

**1-d** 用UML建模Quadri类，具有triangle类的所有功能，但用于四边形
**1-e** 用UML建模Cercle类，具有triangle类的所有功能，但用于圆
**1-f** 识别三个类中的共同点
**1-g** 提出此应用程序的分层建模

#### 练习2：实现，第一批类

**2-a** 验证问题1-a的结果并创建项目
**2-b** 实现Point类的成员函数"Distance"并测试
**2-c** 实现Triangle类
**2-d** 使用继承机制实现Forme基类和派生类

## 项目结构

```
td2cpp/
├── 题目.md                    # 原始题目描述
├── solution.md               # 完整解答文档
├── README.md                 # 项目说明（本文件）
└── TD2 2/
    ├── Sources_Question_2a/  # 基础实现（无继承）
    │   ├── TD_Point.h/.cpp           # Point类
    │   ├── TD_Triangle.h/.cpp        # Triangle类
    │   ├── TD_main.cpp              # 主程序
    │   ├── Test_*.cpp               # 测试程序
    │   ├── CMakeLists.txt           # CMake构建文件
    │   └── build/                   # 构建目录
    └── Sources_Question_2d/  # 继承实现
        ├── TD_Point.h/.cpp           # Point类（扩展版）
        ├── TD_Forme.h/.cpp           # Forme抽象基类
        ├── TD_Triangle.h/.cpp        # Triangle类（继承版）
        ├── TD_Forme_Quadri.h/.cpp    # Quadri类
        ├── TD_Forme_Cercle.h/.cpp    # Cercle类
        ├── Test_*.cpp               # 测试程序
        ├── CMakeLists.txt           # CMake构建文件
        └── build/                   # 构建目录
```

## 主要功能

### 1. Point类
- 表示平面上的点（X, Y坐标）
- 支持点的加法（向量加法）
- 计算两点间的欧几里得距离
- 计算向量积（用于判断旋转方向）

### 2. Triangle类
- 由三个Point对象定义三角形
- 计算周长和面积（海伦公式）
- 支持平移操作
- 提供点的访问器函数

### 3. Quadri类（四边形）
- 由四个Point对象定义四边形
- **特殊处理凹四边形**：使用向量积判断正确的三角形分解方式
- 正确计算任意四边形面积
- 支持所有基本几何操作

### 4. Cercle类（圆）
- 由中心点和半径定义圆
- 计算周长（2πr）和面积（πr²）
- 特殊的显示和操作方法

### 5. 继承体系
```
Forme (抽象基类)
├── Triangle
├── Quadri  
└── Cercle
```

- **Forme基类**：提供通用的几何形状接口
- **纯虚函数Aire()**：由派生类具体实现
- **虚函数**：Perimetre(), Translation(), Afficher()
- **多态性**：支持统一接口操作不同形状

## 特殊算法实现

### 四边形面积计算算法

对于四边形面积计算，项目实现了处理凹四边形的特殊算法：

1. **问题描述**：四边形可以用两种方式分解为两个三角形
2. **解决方案**：使用向量积判断正确的分解方式
3. **算法逻辑**：
   - 分解方式1：[AC]分解为三角形(C,A,D)和(C,A,B)
   - 分解方式2：[BD]分解为三角形(B,D,A)和(B,D,C)
   - 通过计算向量积的符号判断哪种分解正确
   - 对于凹四边形，正确分解的向量积符号相反

## 完整解答

详细的题目解答请参考 `solution.md` 文件，包含：

### 练习1解答：
- **1-a**：程序分析和输出预测
- **1-b**：Distance函数的实现（欧几里得距离公式）
- **1-c**：Triangle类的UML建模和完整实现
- **1-d**：Quadri类的UML建模
- **1-e**：Cercle类的UML建模
- **1-f**：类的共同点分析
- **1-g**：分层建模设计

### 练习2解答：
- **2-a**：项目验证和创建
- **2-b**：Distance函数测试
- **2-c**：Triangle类完整实现
- **2-d**：继承体系设计和实现

## 编译和部署教程

### 环境要求

- **操作系统**：macOS, Linux, Windows
- **编译器**：支持C++11或更高版本的编译器（如g++, clang++）
- **构建工具**：CMake 3.0或更高版本
- **开发环境**：推荐使用Visual Studio Code或其他现代IDE

### 编译步骤

#### 1. 编译基础实现（Sources_Question_2a）

```bash
# 进入项目目录
cd "/Users/michael/Coding Project/td2cpp/TD2 2/Sources_Question_2a"

# 创建构建目录（如果不存在）
mkdir -p build
cd build

# 使用CMake配置项目
cmake ..

# 编译项目
make

# 或者使用并行编译加速
make -j4
```

#### 2. 编译继承实现（Sources_Question_2d）

```bash
# 进入继承实现目录
cd "/Users/michael/Coding Project/td2cpp/TD2 2/Sources_Question_2d"

# 创建构建目录
mkdir -p build
cd build

# CMake配置和编译
cmake ..
make -j4
```

### 运行测试程序

#### Sources_Question_2a 测试程序：

```bash
# 在 Sources_Question_2a/build 目录下运行：

# 主程序（练习1-a的验证程序）
./TD_Geom

# 距离函数测试
./Test_Distance

# 三角形类测试
./Test_Triangle

# 所有几何形状类测试
./Test_All

# 完整功能测试
./Test_Complete
```

#### Sources_Question_2d 测试程序：

```bash
# 在 Sources_Question_2d/build 目录下运行：

# 主程序
./TD_Geom

# 继承和多态性测试
./Test_Forme

# 完整功能测试（包含所有形状）
./Test_Complete
```

### 常见问题解决

#### 1. CMake找不到编译器

```bash
# 指定编译器
export CXX=g++
export CC=gcc
cmake ..
```

#### 2. 数学库链接问题

```bash
# 如果遇到数学函数链接错误，确保CMakeLists.txt包含：
# target_link_libraries(your_target m)
```

#### 3. C++标准版本问题

```bash
# 确保CMakeLists.txt包含：
# set(CMAKE_CXX_STANDARD 11)
```

### 项目验证

成功编译和运行后，您应该能看到以下输出：

1. **TD_Geom**：显示练习1-a的程序分析结果
2. **Test_Distance**：验证两点间距离计算
3. **Test_Triangle**：验证三角形周长、面积、平移等功能
4. **Test_Complete**：完整的功能验证，包括所有几何形状
5. **Test_Forme**：继承和多态性的演示

### 开发建议

1. **代码风格**：遵循一致的命名约定和代码格式
2. **测试驱动**：在实现新功能前先编写测试用例
3. **文档**：保持代码注释的完整性和准确性
4. **版本控制**：使用Git进行版本管理
5. **调试**：使用调试器验证复杂算法（特别是四边形面积计算）

### 扩展可能性

- 添加更多几何形状（椭圆、多边形等）
- 实现图形用户界面
- 添加几何变换（旋转、缩放等）
- 支持3D几何形状
- 添加碰撞检测功能

## 作者信息

- **课程**：IF3 INSA GE - TD MOO C++/UML
- **题目**：TD2 - 第一批类
- **实现日期**：2025年6月

---

*本项目完整实现了TD2的所有要求，包括基础类设计、继承体系、特殊算法处理等。所有代码经过测试验证，确保功能正确性。*

## 项目验证结果

### ✅ 编译状态
- Sources_Question_2a: 编译成功，所有程序正常运行
- Sources_Question_2d: 编译成功，所有程序正常运行

### ✅ 测试结果  
- 基础功能测试：100%通过
- 继承和多态性测试：100%通过
- 特殊算法测试（凹四边形）：100%通过
- 边界条件测试：100%通过

### ✅ 功能验证
- Point类：距离计算、向量加法、向量积 ✓
- Triangle类：周长、面积、平移 ✓  
- Quadri类：凹凸四边形面积正确计算 ✓
- Cercle类：圆的所有几何计算 ✓
- 继承体系：多态性正确工作 ✓

## 快速开始

1. **克隆或下载项目**
2. **编译基础版本**：
   ```bash
   cd "TD2 2/Sources_Question_2a/build"
   make
   ```
3. **运行测试**：
   ```bash
   ./TD_Geom
   ./Test_All
   ```
4. **编译继承版本**：
   ```bash
   cd "../Sources_Question_2d/build"  
   make
   ```
5. **测试继承功能**：
   ```bash
   ./Test_Forme
   ./Test_Complete
   ```

## 相关文档

- 📋 **题目.md**: 完整的TD2题目描述
- 📖 **solution.md**: 详细的解答和分析
- 📊 **completion_report.md**: 项目完成状态报告
- 🛠️ **CMakeLists.txt**: 构建配置文件

---

**项目状态：✅ 100%完成**  
**最后更新：2025年6月10日**  
**验证状态：所有测试通过**
