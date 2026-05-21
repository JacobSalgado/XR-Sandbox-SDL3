cmake_minimum_required(VERSION 3.10)
project(SI-XR)

# Set the standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Required the SDL3 library
find_package(SDL3 REQUIRED)
find_package(SDL3_ttf REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_mixer REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
	SDL3::SDL3
	SDL3_ttf::SDL3_ttf
	SDL3_image::SDL3_image
	SDL3_mixer::SDL3_mixer
)

# Copies SDL3.dll next to the exe after every build
add_custom_command(TARGET SI-XR POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:SDL3::SDL3>
	$<TARGET_FILE_DIR:SI-XR>
)