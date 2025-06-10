cmake_minimum_required(VERSION 3.10)
project(TD2_cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

ADD_EXECUTABLE(TD_Geom TD_main.cpp TD_Point.cpp TD_Point.h TD_Forme.cpp TD_Forme.h TD_Triangle.cpp TD_Triangle.h)
ADD_EXECUTABLE(Test_Forme Test_Forme.cpp TD_Point.cpp TD_Forme.cpp TD_Triangle.cpp TD_Forme_Quadri.cpp TD_Forme_Cercle.cpp TD_Point.h TD_Forme.h TD_Triangle.h TD_Forme_Quadri.h TD_Forme_Cercle.h)
ADD_EXECUTABLE(Test_Complete Test_Complete.cpp TD_Point.cpp TD_Forme.cpp TD_Triangle.cpp TD_Forme_Quadri.cpp TD_Forme_Cercle.cpp TD_Point.h TD_Forme.h TD_Triangle.h TD_Forme_Quadri.h TD_Forme_Cercle.h)

# 链接数学库
target_link_libraries(TD_Geom m)
target_link_libraries(Test_Forme m)
target_link_libraries(Test_Complete m)
