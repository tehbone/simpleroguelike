cmake_minimum_required (VERSION 2.6)
project (SimpleRogueLike)
add_executable(srl src/main.cpp)
set_target_properties(srl PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(srl tcod)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/arial10x10.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
