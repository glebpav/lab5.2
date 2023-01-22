#ifndef UNTITLED_ARRAYHELPER_H
#define UNTITLED_ARRAYHELPER_H

#include "utils.h"

void generateAndFillArray(Item **array, int arrayLen);

void pushElement(Item **inputArray, int inputLen, Item newItem);
void pushStrElement(char ***inputArray, int inputLen, char *newItem);
void deleteElement(Item **inputArray, int inputLen, int idx);

#endif //UNTITLED_ARRAYHELPER_H
