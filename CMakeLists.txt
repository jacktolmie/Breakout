cmake_minimum_required(VERSION 3.7.1)

project(Breakout)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_MODULE_PATH})

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Breakout 
src/main.cpp
src/background.cpp
src/ball.cpp
src/brick.cpp
src/bricks_reset.cpp
src/entity.cpp
src/entity_manager.cpp
src/game.cpp
src/handle_collision.cpp
src/interactions.cpp
src/paddle.cpp
src/paddle_moves.cpp
src/reset.cpp
src/run.cpp
src/textbox.cpp

include/background.hpp
include/ball.hpp
include/brick.hpp
include/constants.hpp
include/entity.hpp
include/entity_manager.hpp
include/game.hpp
include/game_state.hpp
include/interactions.hpp
include/moving_entity.hpp
include/paddle.hpp
include/textbox.hpp
include/variables.hpp
)

add_library(includes INTERFACE)
target_include_directories(includes INTERFACE
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(Breakout
     -lsfml-graphics
     -lsfml-window
     -lsfml-system
)

include_directories(${CMAKE_SOURCE_DIR})

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
