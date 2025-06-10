PROJECT(TD_CPP)

SET(CMAKE_BUILD_TYPE Debug)

ADD_EXECUTABLE( TD_Geom TD_main.cpp TD_Point.cpp TD_Point.h)
ADD_EXECUTABLE( Test_Triangle Test_Triangle.cpp TD_Point.cpp TD_Triangle.cpp TD_Point.h TD_Triangle.h)
ADD_EXECUTABLE( Test_Distance Test_Distance.cpp TD_Point.cpp TD_Point.h)
ADD_EXECUTABLE( Test_All Test_All.cpp TD_Point.cpp TD_Triangle.cpp TD_Quadri.cpp TD_Cercle.cpp TD_Point.h TD_Triangle.h TD_Quadri.h TD_Cercle.h)

# 链接数学库
target_link_libraries(TD_Geom m)
target_link_libraries(Test_Triangle m)
target_link_libraries(Test_Distance m)
target_link_libraries(Test_All m)

