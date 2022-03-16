include_directories(${HilevelDevelepment}/src/CMenu)
add_subdirectory(CMenu)

add_executable(Main main.cpp)
target_link_libraries(Main CMenu)