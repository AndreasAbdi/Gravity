set(GRAVITY_SOURCES
    Main.cpp
    graphics/Screen.cpp
    graphics/PositionConversion.cpp
    game/Particle.cpp
    game/ParticleCollection.cpp

    )

set(GRAVITY_HEADERS
    graphics/Screen.h
    graphics/Point.h
    graphics/RGB.h
    graphics/Pixel.h
    graphics/PositionConversion.h
    game/Particle.h
    game/ParticleCollection.h
    )


INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
ADD_EXECUTABLE ( Gravity ${GRAVITY_SOURCES} ${GRAVITY_HEADERS})

#--------------------------------------------------
# BOOST
#--------------------------------------------------
set (BOOST_ROOT "C:/programming/libraries/boost_1_60_0")
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
