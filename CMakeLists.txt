cmake_minimum_required(VERSION 3.27)
project(Software_engineering_principles_full_power)

set(CMAKE_CXX_STANDARD 17)

add_executable(Software_engineering_principles_full_power main.cpp
        DataBase.cpp
        DataBase.h
        User.cpp
        User.h
        Player.cpp
        Player.h
        Manager.cpp
        Manager.h
        Menu.cpp
        Menu.h)
