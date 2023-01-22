#include "arrayHelper.h"
#include <stdlib.h>
#include <string.h>
#include "stdio.h"

void generateAndFillArray(Item **array, int arrayLen) {
    // *array = calloc(arrayLen, sizeof(Item));
    Item item;
    for (int i = 0; i < arrayLen; i++) {
        item.avgMark = rand();
        item.groupNumber = randSting(16);
        item.fio = randSting(16);
        (*array) [i] = item;

        // printf("~%s\n", (*array)[i].groupNumber);
    }
}

void pushElement(Item **inputArray, int inputLen, Item newItem) {
    if (inputLen == 0) (*inputArray) = calloc(1, sizeof (Item));
    else (*inputArray) = realloc(*inputArray, (inputLen + 1) * sizeof(Item));
    (*inputArray)[inputLen].fio = concatenate(newItem.fio, "");
    (*inputArray)[inputLen].avgMark = newItem.avgMark;
    (*inputArray)[inputLen].groupNumber = concatenate(newItem.groupNumber, "");
}

void pushStrElement(char ***inputArray, int inputLen, char *newItem) {
    size_t newLen = strlen(newItem);
    if (*inputArray == NULL) (*inputArray) = calloc(1, sizeof(char*));
    // else *inputArray = realloc((*inputArray), (inputLen + 1) * sizeof(char*));
    if (inputLen != 0) *inputArray = realloc((*inputArray), (inputLen + 1) * sizeof(char*));
    (*inputArray)[inputLen] = calloc(newLen + 1, sizeof(char));
    for (int i = 0; i < newLen; i++) (*inputArray)[inputLen][i] = newItem[i];
    (*inputArray)[inputLen][strlen(newItem)] = '\0';
}