cmake_minimum_required(VERSION 3.10)

# set the project name
project(HilevelDevelepment)

# add src/
add_subdirectory(src)
# add libs
# add_library(
#     CMenu
#     CMenu/CMenu.cpp
# )

# add_library(
#     CMenuItem
#     CMenu/CMenuItem.cpp
# )

# add the executable
# add_executable(HilevelDevelepment main.cpp)

# target_link_libraries(HilevelDevelepment PRIVATE CMenu)
# target_link_libraries(HilevelDevelepment PRIVATE CMenuItem)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)