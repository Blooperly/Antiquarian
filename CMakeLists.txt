project(Antiquarian)
cmake_minimum_required(VERSION 3.13)

add_executable(Antiquarian source/main.cpp)

#todo: Dynamic library/header location
target_include_directories(Antiquarian PRIVATE "C:\\SDL2-devel-2.26.2-mingw\\SDL2-2.26.2\\x86_64-w64-mingw32\\include\\SDL2\\")
find_library (LIB_SDL2 SDL2 HINTS "C:\\SDL2-devel-2.26.2-mingw\\SDL2-2.26.2\\x86_64-w64-mingw32\\lib")
find_library (LIB_SDL2main SDL2main HINTS "C:\\SDL2-devel-2.26.2-mingw\\SDL2-2.26.2\\x86_64-w64-mingw32\\lib")
target_link_libraries(Antiquarian mingw32 ${LIB_SDL2main} ${LIB_SDL2})