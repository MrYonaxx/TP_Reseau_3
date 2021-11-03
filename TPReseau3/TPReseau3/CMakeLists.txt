# CMakeList.txt : projet CMake pour TPReseau3, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

# Ajoutez une source à l'exécutable de ce projet.
add_executable (TPReseau3 "TPReseau3.cpp" "TPReseau3.h" "LinkingContext.h" "LinkingContext.h" "GameObject.cpp" "GameObject.h" "ClassRegistry.h" "ReplicationManager.h" "ReplicationManager.cpp")

target_link_libraries(TPReseau3 PUBLIC ${PROJECT_NAME}_NetworkLib)
target_link_libraries(TPReseau3 PUBLIC ${PROJECT_NAME}_SerialCompil)
# TODO: Ajoutez des tests et installez des cibles si nécessaire.
