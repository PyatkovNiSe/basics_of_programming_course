add_library(data_structures vector/vector.c
        vector/test_vector.c
        vector/test_vector.h
        matrix/matrix.c matrix/test_matrix.c matrix/test_matrix.h)

target_link_libraries(data_structures algorithms)