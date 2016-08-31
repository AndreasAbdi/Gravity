#--------------------------------------------------
# FILE ORGANIZATION
#--------------------------------------------------

file (GLOB_RECURSE SRC_GRAPHICS
    "${CMAKE_CURRENT_SOURCE_DIR}/graphics/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/graphics/*.h"
)

file (GLOB_RECURSE SRC_GAME
    "${CMAKE_CURRENT_SOURCE_DIR}/game/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/game/*.h"
)


file (GLOB_RECURSE SRC_SDL
    "${CMAKE_CURRENT_SOURCE_DIR}/sdl/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/sdl/*.h"
)

file (GLOB_RECURSE SRC_UTILITY
    "${CMAKE_CURRENT_SOURCE_DIR}/utility/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/utility/*.h"
)

source_group("graphics" FILES ${SRC_GRAPHICS})
source_group("game" FILES ${SRC_GAME})
source_group("utility" FILES ${SRC_UTILITY})
source_group("sdl" FILES ${SRC_SDL})
#--------------------------------------------------
# EXECUTABLE BUILDING
#--------------------------------------------------
set(GRAVITY_SOURCES
    Main.cpp
    graphics/DoubleBuffer.cpp
    graphics/Screen.cpp
    graphics/Filter.cpp
    graphics/PositionConversion.cpp
    game/Character.cpp
    game/Component.cpp
    game/GraphicComponent.cpp
    game/SquareGraphicComponent.cpp
    game/Command.cpp
    game/InputManager.cpp
    game/GameLoop.cpp
    game/Particle.cpp
    game/ParticleCollection.cpp
    sdl/SDLWrapper.cpp
    utility/Configurations.cpp
    )

set(GRAVITY_HEADERS
    graphics/DoubleBuffer.h
    graphics/Filter.h
    graphics/Screen.h
    graphics/Point.h
    graphics/RGB.h
    graphics/Pixel.h
    graphics/PositionConversion.h
    game/Character.h
    game/Command.h
    game/Component.h
    game/GraphicComponent.h
    game/SquareGraphicComponent.h
    game/InputManager.h
    game/GameLoop.h
    game/Particle.h
    game/ParticleCollection.h
    sdl/SDLWrapper.h
    utility/vector2D.h
    utility/Configurations.h
    )

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
ADD_EXECUTABLE ( Gravity ${GRAVITY_SOURCES} ${GRAVITY_HEADERS})

#--------------------------------------------------
# BOOST
#--------------------------------------------------
set (BOOST_ROOT "C:/programming/libraries/boost_1_60_0")
#set (Boost_INCLUDE_DIR "C:/programming/libraries/boost_1_60_0/boost")
set(Boost_USE_STATIC_LIBS ON)

FIND_PACKAGE( Boost 1.60 REQUIRED COMPONENTS regex)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
LINK_DIRECTORIES(${Boost_LIBRARY_DIR})

TARGET_LINK_LIBRARIES( Gravity Boost::regex )

#--------------------------------------------------
# SDL
#--------------------------------------------------

set (SDL_INCLUDE_DIR "C:/programming/libraries/sdl_2_04/include")
set (SDL_LIBRARY "C:/programming/libraries/sdl_2_04/lib/x86/SDL2.lib")
set (SDL_MAIN_LIBRARY "C:/programming/libraries/sdl_2_04/lib/x86/SDL2main.lib")

INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR})
TARGET_LINK_LIBRARIES (Gravity ${SDL_LIBRARY} ${SDL_MAIN_LIBRARY})
