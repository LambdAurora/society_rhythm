cmake_minimum_required(VERSION 3.8)
project(society_rhythm)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)

find_package(lambdacommon REQUIRED)
find_package(GLFW REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
find_package(Freetype REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenAL REQUIRED)
find_package(IonicEngine REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(DiscordRPC)

include_directories(${LAMBDACOMMON_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS} ${FREETYPE_INCLUDE_DIRS} ${OPENAL_INCLUDE_DIR} ${IONICENGINE_INCLUDE_DIRS} ${NLOHMANN_JSON_INCLUDE_DIRS} ${DISCORDRPC_INCLUDE_DIRS})

add_executable(society_rhythm src/main.cpp include/society_rhythm/game.h include/society_rhythm/constants.h src/game.cpp include/society_rhythm/screens/starting_screen.h src/screens/starting_screen.cpp include/society_rhythm/screens/debug_overlay.h src/screens/debug_overlay.cpp include/society_rhythm/screens/main_menu_screen.h src/screens/main_menu_screen.cpp include/society_rhythm/screens/ingame_screen.h src/screens/ingame_screen.cpp include/society_rhythm/game/level.h src/game/level.cpp)
target_link_libraries(society_rhythm AperLambda::lambdacommon AperLambda::IonicEngine GLFW::GLFW OpenGL::GL GLEW::GLEW Freetype::Freetype ${OPENAL_LIBRARY})
target_compile_definitions(society_rhythm PUBLIC DISCORD_DYNAMIC_LIB)

if(DiscordRPC_FOUND)
	target_compile_definitions(society_rhythm PUBLIC DISCORD_RPC_LINKED)
	target_link_libraries(society_rhythm Discord::DiscordRPC)
endif()