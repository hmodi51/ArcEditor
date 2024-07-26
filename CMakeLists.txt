cmake_minimum_required(VERSION 3.10)  

project(ARC)  


add_executable(editor src/editor.c)


find_package(Curses REQUIRED)


include_directories(${CURSES_INCLUDE_DIR})


target_link_libraries(editor ${CURSES_LIBRARIES})
