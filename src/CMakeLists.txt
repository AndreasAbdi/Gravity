
#boost
set (BOOST_ROOT "C:/programming/libraries/boost_1_60_0")
set(Boost_USE_STATIC_LIBS ON)

FIND_PACKAGE( Boost 1.60 REQUIRED COMPONENTS regex)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
LINK_DIRECTORIES (${Boost_LIBRARY_DIR})


ADD_EXECUTABLE ( Gravity main.cpp )

TARGET_LINK_LIBRARIES( Gravity Boost::regex )
