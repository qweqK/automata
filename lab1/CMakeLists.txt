

add_subdirectory(smc)
target_include_directories(smc PUBLIC /home/kqweqk/smc_7_6_0/lib/C++)
include_directories(smc)
add_executable(LAB1 main.cpp )
target_link_libraries(LAB1 smc)
