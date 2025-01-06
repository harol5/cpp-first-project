cmake_minimum_required(VERSION 3.30)
project(first_cpp_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(first_cpp_project main.cpp CheckingAccount.cpp Account.cpp)
