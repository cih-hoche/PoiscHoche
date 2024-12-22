cmake_minimum_required(VERSION 3.6) 
project(PoiscHoche)

file(GLOB SOURCES "src/*.cpp" "src/*.h" "src/world/*.cpp" "src/world/*.h" "src/display/*.cpp" "src/display/*.h" "src/entities/*.cpp" "src/entities/*.h")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)
