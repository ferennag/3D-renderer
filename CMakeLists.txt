cmake_minimum_required(VERSION 3.28)
project(3d_renderer C)
set(CMAKE_C_STANDARD 17)
include(FetchContent)

FetchContent_Declare(SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.30.2
)
FetchContent_MakeAvailable(SDL2)

add_executable(3d_renderer src/main.c
        src/application.c
        src/application.h
        src/game.h
        src/game.c
        src/defines.h
        src/core/memory.c
        src/core/memory.h
        src/engine/framebuffer.c
        src/engine/framebuffer.h
        src/engine/renderer.c
        src/engine/renderer.h
        src/core/color.h
        src/core/color.c
        src/math/math.h
        src/math/math.c
        src/core/rect.h
        src/math/vector.c
        src/math/vector.h
        src/engine/window.c
        src/engine/window.h
        src/engine/window.c
        src/engine/window.c
        src/engine/window.h
)
target_link_libraries(3d_renderer SDL2::SDL2)
target_include_directories(3d_renderer PRIVATE src)
target_compile_options(3d_renderer PUBLIC -Wall -g)
