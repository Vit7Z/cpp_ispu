cmake_minimum_required(VERSION 3.5)

project(inventory_app VERSION 0.1)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Charts)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 COMPONENTS Charts REQUIRED)

set(PROJECT_SOURCES
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui

  file_handler.h
  file_handler.cpp
  list_inventory.h
  list_inventory.cpp
  list_operations.h
  list_operations.cpp
)

add_executable(inventory_app
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui

  file_handler.h
  file_handler.cpp
  list_inventory.h
  list_inventory.cpp
  list_operations.h
  list_operations.cpp
  histogram.h
  histogram.cpp
  mainwindow.cpp
)

target_link_libraries(inventory_app PRIVATE
  Qt6::Core
  Qt6::Widgets
  Qt6::Charts
)

target_link_libraries(inventory_app PRIVATE Qt6::Core)
target_link_libraries(inventory_app PRIVATE Qt6::Core)

set_target_properties(inventory_app PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
