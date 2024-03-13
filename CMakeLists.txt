cmake_minimum_required(VERSION 3.22.1)
project(lab01)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab01 main.cpp
        Animal.h
        Owner.h
        Animals/Dog.h
        Animals/Cat.h
        Animals/Parrot.h
        Animals/Fish.h
        Animal.cpp
        Owner.cpp
        Animals/Dog.cpp
        Animals/Cat.cpp
        Animals/Parrot.cpp
        Animals/Fish.cpp
        Factory.h
        Factory.cpp
        ClassicFactory.h
        ClassicFactory.cpp
        )
