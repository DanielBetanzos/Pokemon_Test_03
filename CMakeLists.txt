cmake_minimum_required(VERSION 3.14)

project(Pokemon_Test_03 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Pokemon_Test_03
  main.cpp
  pokemon.h pokemon.cpp
  pokebola.h pokebola.cpp
  arena.h arena.cpp
  arena.h arena.cpp
  usuario.h usuario.cpp
)
target_link_libraries(Pokemon_Test_03 Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Pokemon_Test_03
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
