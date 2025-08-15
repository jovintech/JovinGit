cmake_minimum_required(VERSION 3.10)
project(JovinGit CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Usar pkg-config para encontrar o gtkmm
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(JovinGit 
               src/main.cpp
               src/windows/MainWindow.cpp
               src/tools/Utils.cpp
               src/service/git/Commands.cpp
               src/service/git/Git.cpp)
target_link_libraries(JovinGit ${GTKMM_LIBRARIES})
