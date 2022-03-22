#include <stdio.h>

#include "libs/data_structures/vector/test_vector.h"

#include "libs/data_structures/matrix/test_matrix.h"
#include "lab5d/tasks_test.h"

#include "string/tasks/string_test.h"
#include "lab5e/lab5e_test.h"

#include "lab5c/test_sorts.h"

int main() {
    //test_vector();
    //test_matrix();
    //tasks_test();
    //string_test();
    //lab5e_test();

    timeExperiment();
    comparesExperiment();

    return 0;
}