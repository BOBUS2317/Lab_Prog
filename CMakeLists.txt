cmake_minimum_required(VERSION 3.10.0)
project(lab1 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(lab1_1 part1.cpp)
add_executable(lab1_2 part2.cpp)
add_executable(lab1_3 part3.cpp)
add_executable(lab2_1 part4.cpp)
add_executable(lab2_2 part5.cpp)
add_executable(lab2_3 part6.cpp)
add_executable(lab2_4 part7.cpp)
add_executable(lab2_5 part8.cpp)
add_executable(lab3_1 lab3_1.cpp)
add_executable(lab3_2 lab3_2.cpp)
add_executable(lab3_3 lab3_3.cpp)
add_executable(lab3_4 lab3_4.cpp)
add_executable(lab3_5 lab3_5.cpp)
add_executable(lab4_1 lab4_1.cpp)
add_executable(lab4_2 lab4_2.cpp)
add_executable(lab4_3 lab4_3.cpp)
add_executable(lab4_4 lab4_4.cpp)
add_executable(lab4_5 lab4_5.cpp)
add_executable(lab5_1 lab5_1.cpp)
add_executable(lab5_2 lab5_2.cpp)
add_executable(lab5_3 lab5_3.cpp)
add_executable(counter_app 
    Counter/Counter.h 
    Counter/Counter.cpp 
    Counter/main.cpp
)
add_executable(point_app
    Point/Point.h
    Point/Point.cpp
    Point/main.cpp
)
add_executable(digitalClock_app
    DigitalClock/DigitalClock.h
    DigitalClock/DigitalClock.cpp
    DigitalClock/main.cpp
)
add_executable(student_app
    Student/Student.h
    Student/Student.cpp
    Student/main.cpp
)
add_executable(smartArray_app
    SmartArray/SmartArray.h
    SmartArray/SmartArray.cpp
    SmartArray/main.cpp
)