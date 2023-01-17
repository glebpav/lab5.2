#ifndef UNTITLED_SORTHELPER_H
#define UNTITLED_SORTHELPER_H

#include "utils.h"

void comb(Item **data, int size, int (*ptFuncCompare)(const void *,const void *));
void selection(Item **data, int size, int (*ptFuncCompare)(const void *,const void *));

void swap(Item *item1, Item *item2);
void sortData(Item **inputArray, int inputArraySize, int algorithm, int field, int direction);

#endif //UNTITLED_SORTHELPER_H
