cmake_minimum_required(VERSION 3.12)
project(course_approval_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(course_approval_system main.cpp model/course.cpp model/course.h model/student.cpp model/student.h model/registration.cpp model/registration.h model/cs_student.cpp model/cs_student.h)