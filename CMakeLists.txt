project(Breakout)

cmake_minimum_required(VERSION 3.7.1)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_MODULE_PATH})

set (CMAKE_CXX_STANDARD 17)

include(KDEInstallDirs)
include(KDEPackageAppTemplates)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    if(DEFINED ENV{XDG_DATA_HOME})
        set(KDE_INSTALL_DATADIR "$ENV{XDG_DATA_HOME}" CACHE PATH "default install prefix" FORCE)
    else()
        set(KDE_INSTALL_DATADIR "$ENV{HOME}/.local/share" CACHE PATH "default install prefix" FORCE)
    endif()
endif()

kde_package_app_templates(TEMPLATES "Breakout" INSTALL_DIR "${KDE_INSTALL_DATADIR}/kdevfiletemplates/templates")

add_executable(Breakout 
main.cpp
background.cpp background.hpp
ball.cpp ball.hpp
brick.cpp brick.hpp
constants.hpp
entity.cpp entity.hpp
entity_manager.cpp entity_manager.hpp
game.cpp game.hpp
interactions.cpp interactions.hpp
moving_entity.hpp
paddle.cpp paddle.hpp
reset.cpp
run.cpp
set_text.cpp
)
target_link_libraries(Breakout
     -lsfml-graphics
     -lsfml-window
     -lsfml-system
)
