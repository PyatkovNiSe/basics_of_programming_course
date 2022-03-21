add_library(lab5c sorts.h sorts.c test_sorts.h test_sorts.c)

target_link_libraries(lab5c algorithms)
target_link_libraries(lab5c generating)