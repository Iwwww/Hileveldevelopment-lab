include_directories(${HilevelDevelepment}/src/CMenu)
add_subdirectory(CMenu)

include_directories(${HilevelDevelepment}/src/Models)
add_subdirectory(Models)

add_executable(Main main.cpp)
target_link_libraries(Main CMenu)
target_link_libraries(Main Models)