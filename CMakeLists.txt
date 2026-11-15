cmake_minimum_required(VERSION 3.16)
project(dp_club CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# raylib-г GitHub-аас автоматаар татна (суулгах шаардлагагүй)
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        5.5
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(raylib)

# Долоо хоног 2: алхам алхмаар жишээнүүд
add_executable(w02_hello  week02/01_hello_cpp/main.cpp)        # raylib хэрэггүй
add_executable(w02_window week02/02_window/main.cpp)
add_executable(w02_move   week02/03_move/main.cpp)
add_executable(w02_delta  week02/04_delta_time/main.cpp)
target_link_libraries(w02_window raylib)
target_link_libraries(w02_move   raylib)
target_link_libraries(w02_delta  raylib)

# Улирлын турш томрох тоглоом
file(GLOB GAME_SOURCES CONFIGURE_DEPENDS game/src/*.cpp)
add_executable(game ${GAME_SOURCES})
target_link_libraries(game raylib)

if (APPLE)
  foreach(t w02_window w02_move w02_delta game)
    target_link_libraries(${t} "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
  endforeach()
endif()
