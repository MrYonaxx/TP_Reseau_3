# CMakeList.txt : projet CMake pour NetworkLib, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

set(${PROJECT_NAME}_SerialCompil_SRC "src/Deserializer.cpp" "src/FloatCompressor.cpp" "src/IntCompressor.cpp"  "src/QuaternionCompressor.cpp" "src/Serializer.cpp" "src/Vector3.cpp")
set(${PROJECT_NAME}_SerialCompil_HEADERS "include/Deserializer.h" "include/FloatCompressor.h" "include/IntCompressor.h"  "include/Quaternion.h" "include/QuaternionCompressor.h" "include/Serializer.h" "include/Vector3.h")

add_library(${PROJECT_NAME}_SerialCompil STATIC ${${PROJECT_NAME}_SerialCompil_SRC} ${${PROJECT_NAME}_SerialCompil_HEADERS})

target_include_directories(${PROJECT_NAME}_SerialCompil PUBLIC include)