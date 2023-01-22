#include <string.h>
#include <time.h>
#include "sortHelper.h"
#include "stdlib.h"
#include "compareHelper.h"

void swap(Item *item1, Item *item2) {
    char temp[sizeof(Item)];
    memcpy(temp, item2, sizeof(Item));
    memcpy(item2, item1, sizeof(Item));
    memcpy(item1, temp, sizeof(Item));
}

void comb(Item **data, int size, int (*ptFuncCompare)(const void *, const void *)) {
    double factor = 1.2473309;
    int step = size - 1;

    while (step >= 1) {
        for (int i = 0; i + step < size; i++) {
            if (ptFuncCompare(&((*data)[i]), &((*data)[i + step])) > 0) {
                swap(&((*data)[i]), &((*data)[i + step]));
            }
        }
        step /= factor;
    }
}

void selection(Item **data, int size, int (*ptFuncCompare)(const void *, const void *)) {
    int minPosition;

    for (int i = 0; i < size; i++) {
        minPosition = i;
        for (int j = i + 1; j < size; j++) {
            if (ptFuncCompare(&((*data)[minPosition]), &((*data)[j])) > 0)
                minPosition = j;
        }
        swap(&((*data)[minPosition]), &((*data)[i]));
    }
}

long long sortData(Item **inputArray, int inputArraySize, int algorithm, int field, int direction) {

    clock_t begin = clock();
    if (algorithm == QSORT && field == FIO && direction == UP)
        qsort(*inputArray, inputArraySize, sizeof(Item), comparatorUpFio);
    else if (algorithm == QSORT && field == FIO && direction == DOWN)
        qsort(*inputArray, inputArraySize, sizeof(Item), comparatorDownFio);
    else if (algorithm == QSORT && field == GROUP_NUMBER && direction == UP)
        qsort(*inputArray, inputArraySize, sizeof(Item), comparatorUpGroup);
    else if (algorithm == QSORT && field == GROUP_NUMBER && direction == DOWN)
        qsort(*inputArray, inputArraySize, sizeof(Item), comparatorDownGroup);
    else if (algorithm == QSORT && field == AVG_MARK && direction == UP)
        qsort(*inputArray, inputArraySize, sizeof(Item), comparatorUpMark);
    else if (algorithm == QSORT && field == AVG_MARK && direction == DOWN)
        qsort(*inputArray, inputArraySize, sizeof(Item), comparatorDownMark);

    else if (algorithm == COMB && field == FIO && direction == UP)
        comb(inputArray, inputArraySize, comparatorUpFio);
    else if (algorithm == COMB && field == FIO && direction == DOWN)
        comb(inputArray, inputArraySize, comparatorDownFio);
    else if (algorithm == COMB && field == GROUP_NUMBER && direction == UP)
        comb(inputArray, inputArraySize, comparatorUpGroup);
    else if (algorithm == COMB && field == GROUP_NUMBER && direction == DOWN)
        comb(inputArray, inputArraySize, comparatorDownGroup);
    else if (algorithm == COMB && field == AVG_MARK && direction == UP)
        comb(inputArray, inputArraySize, comparatorUpMark);
    else if (algorithm == COMB && field == AVG_MARK && direction == DOWN)
        comb(inputArray, inputArraySize, comparatorDownMark);

    else if (algorithm == SELECTION && field == FIO && direction == UP)
        selection(inputArray, inputArraySize, comparatorUpFio);
    else if (algorithm == SELECTION && field == FIO && direction == DOWN)
        selection(inputArray, inputArraySize, comparatorDownFio);
    else if (algorithm == SELECTION && field == GROUP_NUMBER && direction == UP)
        selection(inputArray, inputArraySize, comparatorUpGroup);
    else if (algorithm == SELECTION && field == GROUP_NUMBER && direction == DOWN)
        selection(inputArray, inputArraySize, comparatorDownGroup);
    else if (algorithm == SELECTION && field == AVG_MARK && direction == UP)
        selection(inputArray, inputArraySize, comparatorUpMark);
    else if (algorithm == SELECTION && field == AVG_MARK && direction == DOWN)
        selection(inputArray, inputArraySize, comparatorDownMark);

    return clock() - begin;

}