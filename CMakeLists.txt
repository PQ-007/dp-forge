# Энэ файлыг БАГШ засна. Сурагчид засах шаардлагагүй.
cmake_minimum_required(VERSION 3.16)
project(dp_club CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build төрөл сонгоогүй бол Debug (raylib-ийн "build type is not set" анхааруулгыг арилгана)
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

# raylib 5.5 нь cmake_minimum_required(VERSION 3.5) гэж бичсэн тул CMake 4.x
# "Compatibility with CMake < 3.10" гэсэн анхааруулга өгдөг. Алдаа биш, нууна.
set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE)

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

# Бүх програм build/ (Windows дээр build\Debug\) дотор үүснэ
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# raylib ашигладаг програм нэмэх туслах функц
function(dp_raylib_app name)
  add_executable(${name} ${ARGN})
  target_link_libraries(${name} PRIVATE raylib)
  if (APPLE)
    target_link_libraries(${name} PRIVATE "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
  endif()
endfunction()

# ===== lessons/ : долоо хоног бүрийн жишээ =====
# lessons/weekNN/CMakeLists.txt бүрийг автоматаар олно
file(GLOB LESSON_DIRS CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/lessons/week*)
foreach(dir ${LESSON_DIRS})
  if (EXISTS ${dir}/CMakeLists.txt)
    add_subdirectory(${dir})
  endif()
endforeach()

# ===== game/ : сурагч бүрийн өөрийн тоглоом =====
# game/src/ доторх бүх .cpp (дэд хавтас ч гэсэн) автоматаар build-д орно
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/game/src/*.cpp)
dp_raylib_app(game ${GAME_SOURCES})
target_include_directories(game PRIVATE ${CMAKE_SOURCE_DIR}/game/src)
# Зураг, дуу ачаалах: LoadTexture(ASSETS_DIR "hero.png")
target_compile_definitions(game PRIVATE ASSETS_DIR="${CMAKE_SOURCE_DIR}/game/assets/")
