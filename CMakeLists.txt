cmake_minimum_required(VERSION 3.30)
project(first_cpp_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(first_cpp_project main.cpp CheckingAccount.cpp Account.cpp Deep.cpp
        Shape.cpp
        Shape.h
        OpenShape.cpp
        OpenShape.h
        ClosedShape.cpp
        ClosedShape.h
        Circle.cpp
        Circle.h
        Square.cpp
        Square.h
        Line.cpp
        Line.h)
