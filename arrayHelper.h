#ifndef UNTITLED_ARRAYHELPER_H
#define UNTITLED_ARRAYHELPER_H

#include "utils.h"

void pushElement(Item **inputArray, int inputLen, Item newItem);
void pushStrElement(char ***inputArray, int inputLen, char *newItem);
void deleteElement(Item **inputArray, int inputLen, int idx);
void clearStr(char *str, int len);

#endif //UNTITLED_ARRAYHELPER_H
