# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project ("TPReseau3")

# Incluez les sous-projets.
add_subdirectory ("TPReseau3")
add_subdirectory ("NetworkLib")
add_subdirectory ("SerialCompil")
add_subdirectory ("ClientServer")