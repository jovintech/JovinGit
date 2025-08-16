cmake_minimum_required(VERSION 3.10)
project(JovinGit CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  message(STATUS "Build para Windows (cross-compilation)")

  # Aqui não usamos gtkmm no Windows para simplificar
else()
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

  include_directories(${GTKMM_INCLUDE_DIRS})
  link_directories(${GTKMM_LIBRARY_DIRS})
  add_definitions(${GTKMM_CFLAGS_OTHER})
endif()



add_executable(JovinGit 
               src/main.cpp
               src/windows/MainWindow.cpp
               src/tools/Utils.cpp
               src/service/git/Commands.cpp
               src/service/git/Git.cpp)

if (NOT CMAKE_SYSTEM_NAME STREQUAL "Windows")
target_link_libraries(JovinGit ${GTKMM_LIBRARIES})
endif()
