cmake_minimum_required(VERSION 3.21)

project(ugar_io_opengl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

find_package(OpenGL REQUIRED)

set(UGAR_IO_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/camera.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/food.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/GameWindow.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/GLBasics.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/line.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/RectF.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ugar.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ugarai.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ugarplayer.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Vector2.cpp"
)

if(WIN32)
    list(APPEND UGAR_IO_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/resources/Ugar.io OpenGL.rc")
endif()

if(WIN32)
    add_executable(ugar-io-opengl WIN32 ${UGAR_IO_SOURCES})
else()
    add_executable(ugar-io-opengl ${UGAR_IO_SOURCES})
endif()

target_include_directories(ugar-io-opengl PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}/resources")
target_link_libraries(ugar-io-opengl PRIVATE glfw OpenGL::GL)

if(WIN32)
    target_link_libraries(ugar-io-opengl PRIVATE opengl32)
elseif(APPLE)
    target_link_libraries(ugar-io-opengl PRIVATE "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
endif()
