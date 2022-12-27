#ifndef UNTITLED_FILEHELPER_H
#define UNTITLED_FILEHELPER_H

#include "utils.h"

Item *getArrayFromFile(char *fileName, int *arraySize);
char **readFile(char *fileName, int *inputArraySize);
void writeFile(char *fileName, Item *dataArray, int dataArraySize);



#endif //UNTITLED_FILEHELPER_H
