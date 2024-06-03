cmake_minimum_required(VERSION 3.27)

set(ULTIMATETTT_PROJECT_NAME
    UltimateTTT
)
set(ULTIMATETTT_SOURCE_DIR
    src
)

set(ULTIMATETTT_SOURCE
    ${ULTIMATETTT_SOURCE_DIR}/main.cpp
)
set(ULTIMATETTT_LIBRARIES_DIR
    libs
)
set(ULTIMATETTT_LIBRARIES
    Core
    FSM
)

project(${ULTIMATETTT_PROJECT_NAME})

#########
# GTest #
#########
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

###########
# Project #
###########
add_executable(${ULTIMATETTT_PROJECT_NAME} ${ULTIMATETTT_SOURCE})

foreach(LIBRARY ${ULTIMATETTT_LIBRARIES})
    add_subdirectory("${ULTIMATETTT_LIBRARIES_DIR}/${LIBRARY}")
endforeach(LIBRARY)
target_link_libraries(${ULTIMATETTT_PROJECT_NAME} ${ULTIMATETTT_LIBRARIES})
