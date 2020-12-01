cmake_minimum_required(VERSION 3.17)
project(SFML_tutorial)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML_tutorial main.cpp Entity.cpp Entity.h Player.cpp Player.h Projectile.cpp Projectile.h Enemy.cpp Enemy.h Random.cpp Random.h TextDisplay.cpp TextDisplay.h MeleeWeapon.cpp MeleeWeapon.h)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

target_link_libraries(SFML_tutorial sfml-graphics sfml-window sfml-system)