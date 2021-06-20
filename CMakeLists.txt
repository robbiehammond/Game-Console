# !!! WARNING !!! AUTO-GENERATED FILE, PLEASE DO NOT MODIFY IT AND USE
# https://docs.platformio.org/page/projectconf/section_env_build.html#build-flags
#
# If you need to override existing CMake configuration or add extra,
# please create `CMakeListsUser.txt` in the root of project.
# The `CMakeListsUser.txt` will not be overwritten by PlatformIO.

cmake_minimum_required(VERSION 3.13)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)


project("Game Console" C CXX)

include(CMakeListsPrivate.txt)


if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeListsUser.txt)
include(CMakeListsUser.txt)
endif()

add_custom_target(
    Production ALL
    COMMAND platformio -c clion run "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    Debug ALL
    COMMAND platformio -c clion run --target debug "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(Z_DUMMY_TARGET ${SRC_LIST} src/Objects/Circle.cpp src/Objects/Circle.h src/Objects/Entity.cpp src/Objects/Entity.h src/Objects/Rect.cpp src/Objects/Rect.h src/Engine/Physics/PhysicsHandler.cpp src/Engine/Physics/PhysicsHandler.h src/Engine/Render/RenderHandler.cpp src/Engine/Render/RenderHandler.h src/Games/Game.cpp src/Games/Game.h src/Engine/RealEngine.cpp src/Engine/RealEngine.h src/Engine/IO/IOHandler.cpp src/Engine/IO/IOHandler.h src/Objects/Triangle.cpp src/Objects/Triangle.h test/Engine_Test.cpp src/Games/Snake.cpp src/Games/Snake.h src/Engine/Exception/ExceptionHandler.cpp src/Engine/Exception/ExceptionHandler.h "src/Objects/Static Objects/Terrain.cpp" "src/Objects/Static Objects/Terrain.h" "src/Objects/Static Objects/SObject.cpp" "src/Objects/Static Objects/SObject.h" src/Games/Test_Game.cpp src/Games/Test_Game.h src/Games/Pong.cpp src/Games/Pong.h)
