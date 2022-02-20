add_library(lab5d tasks.c tasks_test.c tasks_test.h)

target_link_libraries(lab5d data_structures)
target_link_libraries(lab5d algorithms)