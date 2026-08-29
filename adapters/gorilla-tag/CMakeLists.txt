cmake_minimum_required(VERSION 3.22.1)

project(universalvr_gtag)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    universalvr_gtag
    SHARED
    src/main.cpp
)

target_link_libraries(
    universalvr_gtag
    android
    log
)
