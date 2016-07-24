project(Bitflow2x)

cmake_minimum_required(VERSION 2.8)
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_PREFIX}")
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fconcepts -std=c++1z" )
aux_source_directory(. SRC_LIST)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rd/N3888_RefImpl/N3888_RefImpl/src)

# Define sources and executable
set(EXECUTABLE_NAME ${PROJECT_NAME})
add_executable(${PROJECT_NAME} ${SRC_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/3rd/mathfu/dependencies/vectorial/include
        ${CMAKE_CURRENT_SOURCE_DIR}/3rd/mathfu/include
        ${CMAKE_CURRENT_SOURCE_DIR}/3rd/cmcstl2/include
        ${CMAKE_CURRENT_SOURCE_DIR}/3rd/N3888_RefImpl/cairo/src
        ${CMAKE_CURRENT_SOURCE_DIR}/3rd/N3888_RefImpl/N3888_RefImpl/src
)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} io2d X11 cairo)
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
