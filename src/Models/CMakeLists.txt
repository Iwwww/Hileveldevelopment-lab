include_directories(${HilevelDevelepment}/src/Models/Employer)
add_subdirectory(Employer)

include_directories(${HilevelDevelepment}/src/Models/Provider)
add_subdirectory(Provider)

add_executable(User User.cpp)
add_executable(Product Product.cpp)