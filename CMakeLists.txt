cmake_minimum_required(VERSION 3.16)

option(PRODUCTION_BUILD "This makes a production build" OFF)

project(TheTest)

include(FetchContent)

# SDL2
set(SDL2_DISABLE_INSTALL ON CACHE BOOL "" FORCE)
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.28.5
)

# SDL2_image
set(SDL2IMAGE_DISABLE_INSTALL ON CACHE BOOL "" FORCE)
FetchContent_Declare(
    SDL2_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-2.8.2
)

# Fetch
FetchContent_MakeAvailable(SDL2 SDL2_image)

# Sorgenti
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE MY_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Executable
add_executable(${PROJECT_NAME} ${MY_SOURCES} ${MY_HEADERS})

# Resource path
if (PRODUCTION_BUILD)
    target_compile_definitions(${PROJECT_NAME} PUBLIC RESOURCES_PATH="./resources/")
else()
    target_compile_definitions(${PROJECT_NAME} PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
endif()

# Includes
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Link
target_link_libraries(${PROJECT_NAME}
    SDL2::SDL2
    SDL2_image::SDL2_image
)

# Windows: link SDL2main
if (WIN32)
    target_link_libraries(${PROJECT_NAME} SDL2::SDL2main)
endif()
