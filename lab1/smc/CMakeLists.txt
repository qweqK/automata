add_library(smc STATIC Analyser.h Analyser_sm.cpp Analyser_sm.h Analyser.cpp)

target_link_libraries(smc abstractAnalys)