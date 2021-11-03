# CMakeList.txt : projet CMake pour NetworkLib, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

set(${PROJECT_NAME}_SRC "src/NetworkLib.cpp" "src/Terminal.cpp" "src/ConnectionUDP.cpp" "src/ConnectionTCP.cpp" "src/Connection.cpp")
set(${PROJECT_NAME}_HEADERS "include/NetworkLib.h" "include/Terminal.h" "include/ConnectionUDP.h" "include/ConnectionTCP.h" "include/Connection.h")

add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC include)