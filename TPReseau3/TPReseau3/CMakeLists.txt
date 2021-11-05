# CMakeList.txt : projet CMake pour NetworkLib, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

set(${PROJECT_NAME}_TPRESEAU3_SRC "src/ClassRegistry.cpp" "src/Enemy.cpp" "src/Player.cpp" "src/GameObject.cpp" "src/LinkingContext.cpp" "src/ReplicationManager.cpp")
set(${PROJECT_NAME}_TPRESEAU3_HEADERS "include/ClassRegistry.h" "include/Enemy.h" "include/Player.h" "include/GameObject.h" "include/LinkingContext.h" "include/ReplicationManager.h")

add_library(${PROJECT_NAME}_TPRESEAU3 STATIC ${${PROJECT_NAME}_TPRESEAU3_SRC} ${${PROJECT_NAME}_TPRESEAU3_HEADERS})
target_link_libraries(${PROJECT_NAME}_TPRESEAU3 PUBLIC ${PROJECT_NAME}_SerialCompil)
target_link_libraries(${PROJECT_NAME}_TPRESEAU3 PUBLIC ${PROJECT_NAME}_NetworkLib)

target_include_directories(${PROJECT_NAME}_TPRESEAU3 PUBLIC include)