

add_subdirectory(smc)
add_subdirectory(generator)
target_include_directories(smc PUBLIC /home/kqweqk/smc2/smc_7_6_0/lib/C++)
include_directories(smc)
include_directories(generator)
add_executable(LAB1 main.cpp )
target_link_libraries(LAB1 smc generator)
