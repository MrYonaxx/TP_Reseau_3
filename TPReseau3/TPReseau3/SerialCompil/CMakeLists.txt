# CMakeList.txt : projet CMake pour NetworkLib, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

set(${PROJECT_NAME}_SRC "src/Deserializer.cpp" "src/FloatCompressor.cpp" "src/IntCompressor.cpp" "src/Player.cpp" "src/QuaternionCompressor.cpp" "src/Serializer.cpp" "src/Vector3.cpp")
set(${PROJECT_NAME}_HEADERS "include/Deserializer.h" "include/FloatCompressor.h" "include/IntCompressor.h" "include/Player.h" "include/Quaternion.h" "include/QuaternionCompressor.h" "include/Serializer.h" "include/Vector3.h")

add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC include)