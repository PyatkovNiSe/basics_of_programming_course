#include <stdio.h>

#include "libs/data_structures/vector/test_vector.h"

#include "libs/data_structures/matrix/test_matrix.h"
#include "lab5d/tasks_test.h"

#include "string/tasks/string_test.h"
#include "lab5e/lab5e_test.h"

#include "lab5c/test_sorts.h"
#include <pthread.h>

void *timeExperimentThr(void *a) {
    timeExperiment();
}

int main() {
    //test_vector();
    //test_matrix();
    //tasks_test();
    //string_test();
    //lab5e_test();

    double time;
    pthread_t timeExperimentThread;
    getTime({
                      pthread_create(&timeExperimentThread, NULL,
                                     timeExperimentThr, NULL);
              }, time);

    comparesExperiment();

    pthread_join(timeExperimentThread, NULL);

    printf("TimeToCreateThread: %f\n", time);

    return 0;
}
