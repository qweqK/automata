

add_subdirectory(smc)
add_subdirectory(generator)
add_subdirectory(readAndWrite)
target_include_directories(smc PUBLIC /home/kqweqk/smc2/smc_7_6_0/lib/C++)

include_directories(smc)
include_directories(generator)
include_directories(readAndWrite)

add_executable(LAB1 main.cpp )
add_executable(GENERATE mainG.cpp )

target_link_libraries(LAB1 smc writer)
target_link_libraries(GENERATE generator)