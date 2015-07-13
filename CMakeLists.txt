cmake_minimum_required(VERSION 2.8)

find_package(Geant4 REQUIRED vis_all)

include(${Geant4_USE_FILE})
include_directories("include" ${Geant4_INCLUDE_DIRS})
add_definitions(${Geant4_DEFINITIONS})

FILE(GLOB sources src/*.cc)
FILE(GLOB headers include/*.hh)

add_executable(G4-ex.exe Geant4-example.cc ${sources} ${headers})
target_link_libraries(G4-ex.exe ${Geant4_LIBRARIES})


