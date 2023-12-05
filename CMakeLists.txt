cmake_minimum_required(VERSION 3.24)
project(extra_credit)

set(CMAKE_CXX_STANDARD 14)

include_directories(esep-extra-cred)

add_executable(extra_credit
        esep-extra-cred/InMemoryDB.cpp
        esep-extra-cred/InMemoryDB.h
        esep-extra-cred/main.cpp)
