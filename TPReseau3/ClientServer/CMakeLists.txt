# CMakeList.txt : CMake project for Client, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (ClientServer "ClientServer.cpp")

target_link_libraries(ClientServer PUBLIC ${PROJECT_NAME}_NetworkLib)
target_link_libraries(ClientServer PUBLIC ${PROJECT_NAME}_SerialCompil)
target_link_libraries(ClientServer PUBLIC ${PROJECT_NAME}_TPRESEAU3)