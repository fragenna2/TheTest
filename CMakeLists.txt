cmake_minimum_required(VERSION 3.16)

# Project
project(TheTest)

# Build option
option(PRODUCTION_BUILD "Build for production (ON) or development (OFF)" OFF) #Change PRODUCTION_BUILD to ON if you want to make a release

# Include FetchContent
include(FetchContent)

#Set the Runtime library for MSVC compiler
#if (CMAKE_BUILD_TYPE STREQUAL "Debug")
#	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
#else()
#	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
#endif()

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

# Download and make available
FetchContent_MakeAvailable(SDL2 SDL2_image)

# Sources and headers
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE MY_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

# Executable
add_executable(${PROJECT_NAME} ${MY_SOURCES} ${MY_HEADERS})

set_property(TARGET ${PROJECT_NAME} PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)

# Includes
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Link libraries
target_link_libraries(${PROJECT_NAME}
    SDL2::SDL2
    SDL2_image::SDL2_image
)

if (WIN32)
    # Imposta il linker subsystem solo per la configurazione Release
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Release>:/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup>
    )
endif()

# Imposta RESOURCES_PATH in base alla build
target_compile_definitions(${PROJECT_NAME} PUBLIC
    $<$<CONFIG:Release>:RESOURCES_PATH="resources/">
    $<$<CONFIG:Debug>:RESOURCES_PATH="${CMAKE_SOURCE_DIR}/resources/">
)

# On Windows, also link SDL2main
if (WIN32)
    target_link_libraries(${PROJECT_NAME} SDL2::SDL2main)
endif()

# Copy resources after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/resources
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)