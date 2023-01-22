#include <time.h>
#include "terminalReader.h"
#include "fileHelper.h"
#include "sortHelper.h"
#include "stdlib.h"
#include "arrayHelper.h"
#include "stdio.h"

int main(int argc, char **argv) {

    TerminalInput2 terminalInput = getTerminalInput2(argc, argv);
    long double sortingTime = 0;
    double begin = clock();

    for (int i = 0; i < terminalInput.countOfArrays; i++) {
        Item *array = calloc(terminalInput.arrayLen, sizeof(Item));
        generateAndFillArray(&array, (int) terminalInput.arrayLen);

        /*
        printf("   --- before sorting ---\n");
        for (int q = 0; q < terminalInput.arrayLen; q++) {
            printf("[%d] - %f\n", q, array[q].avgMark);
            printf("[%d] - %s\n", q, array[q].groupNumber);
            printf("[%d] - %s\n\n", q, array[q].fio);
        }
*/

        sortingTime += sortData(&array,
                 terminalInput.arrayLen,
                 terminalInput.algorithmOfSorting,
                 terminalInput.fieldOfSorting,
                 terminalInput.directionOfSorting);
/*
        printf("   --- after sorting ---\n");
        for (int q = 0; q < terminalInput.arrayLen; q++) {
            printf("[%d] - %f\n", q, array[q].avgMark);
            printf("[%d] - %s\n", q, array[q].groupNumber);
            printf("[%d] - %s\n\n", q, array[q].fio);
        }
        */


        for (int q = 0; q < terminalInput.arrayLen; q++) {
            free(array[q].groupNumber);
            free(array[q].fio);
        }
        free(array);
    }

    printf("sortingTime: %LF\n", sortingTime / CLOCKS_PER_SEC);
    printf("time of full work: %F\n", (clock() - begin) / CLOCKS_PER_SEC);


}

/*
 * gcc main2.c -o main2 terminalReader.c fileHelper.c utils.c arrayHelper.c compareHelper.c sortHelper.c
 * valgrind --leak-check=full ./main2 -a 0 -v 2 -d 0 60 10000
 *
 */