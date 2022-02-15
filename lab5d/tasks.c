#include "tasks.h"
#include "C:\Users\oosko\CLionProjects\course\libs\data_structures\matrix\matrix.h"

void swapRowsIncludeMinAndMaxElement(matrix m) {
    position posMax = getMaxValuePos(m);
    position posMin = getMinValuePos(m);

    swapRows(m, posMax.rowIndex, posMin.rowIndex);
}
