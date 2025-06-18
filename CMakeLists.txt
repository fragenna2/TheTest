cmake_minimum_required(VERSION 3.7)

option(PRODUCTION_BUILD "This make a production build" OFF)

project(TheTest)

find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)


include_directories(${SDL_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})


file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE MY_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(${CMAKE_PROJECT_NAME} "${MY_SOURCES}")

if (PRODUCTION_BUILD)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC RESOURCES_PATH="./resources/")
else()
    target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
endif()


target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})


