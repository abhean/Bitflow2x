project(Bitflow2x)

cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_PREFIX}")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fconcepts -fext-numeric-literals")
set(EXECUTABLE_NAME ${PROJECT_NAME})

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rd/N3888_RefImpl/N3888_RefImpl/src)

# Define sources and executable

set(SRC_LIST
        main.cpp
        model/Types.h
        model/NetworkNode.cpp
        model/NetworkNode.h
        model/Network.h
        model/Network.cpp
        model/NetworkLink.cpp
        model/NetworkLink.h
        foundation/YedFileReader.h
        foundation/Memory.h
)

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.62.0 COMPONENTS graph ...)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/3rd/cmcstl2/include
        ${CMAKE_CURRENT_SOURCE_DIR}/3rd/N3888_RefImpl/cairo/src
        ${CMAKE_CURRENT_SOURCE_DIR}/3rd/N3888_RefImpl/N3888_RefImpl/src
)


target_link_libraries(${EXECUTABLE_NAME} io2d X11 cairo boost_graph stdc++fs)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
