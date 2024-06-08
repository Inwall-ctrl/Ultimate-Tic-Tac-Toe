cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ULTIMATETTT_PROJECT_NAME
    UltimateTTT
)
set(ULTIMATETTT_SOURCE_DIR
    src
)

set(ULTIMATETTT_SOURCE
    ${ULTIMATETTT_SOURCE_DIR}/main.cpp
        src/button.cpp
        src/saver.cpp
        src/saver.h
        src/game.cpp
        src/game.h
        src/menu.cpp
        src/menu.h
        src/aigame.cpp
        src/aigame.h
)
set(ULTIMATETTT_LIBRARIES_DIR
    libs
)
set(ULTIMATETTT_LIBRARIES
    Core
    FSM
    Scene
)

project(${ULTIMATETTT_PROJECT_NAME})

#########
# GTest #
#########
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#########
# raylib #
#########
set(RAYLIB_VERSION 4.5.0)
include(FetchContent)
FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
        FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)


###########
# Project #
###########
add_executable(${ULTIMATETTT_PROJECT_NAME} ${ULTIMATETTT_SOURCE})

foreach(LIBRARY ${ULTIMATETTT_LIBRARIES})
    add_subdirectory("${ULTIMATETTT_LIBRARIES_DIR}/${LIBRARY}")
endforeach(LIBRARY)
target_link_libraries(${ULTIMATETTT_PROJECT_NAME} ${ULTIMATETTT_LIBRARIES} raylib)
