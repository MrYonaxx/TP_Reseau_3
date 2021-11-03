# CMakeList.txt : projet CMake pour NetworkLib, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

set(${PROJECT_NAME}_NetworkLib_SRC "src/NetworkLib.cpp" "src/Terminal.cpp" "src/ConnectionUDP.cpp" "src/ConnectionTCP.cpp" "src/Connection.cpp")
set(${PROJECT_NAME}_NetworkLib_HEADERS "include/NetworkLib.h" "include/Terminal.h" "include/ConnectionUDP.h" "include/ConnectionTCP.h" "include/Connection.h")

add_library(${PROJECT_NAME}_NetworkLib STATIC ${${PROJECT_NAME}_NetworkLib_SRC} ${${PROJECT_NAME}_NetworkLib_HEADERS})

target_include_directories(${PROJECT_NAME}_NetworkLib PUBLIC include)