#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

void clearItem(Item *item) {
    item->fio = "";
    item->groupNumber = "";
    item->avgMark = 0.;
}

char *concatenate(char *str1, char *str2) {
    if (str1 == NULL) str1 = "";
    if (str2 == NULL) str2 = "";
    int outputStrLen = strlen(str1) + strlen(str2) + 1;
    char *outputStr = calloc(outputStrLen, sizeof(char));
    for (int i = 0; i < outputStrLen - 1; i++) {
        if (i < strlen(str1)) outputStr[i] = str1[i];
        else outputStr[i] = str2[i - strlen(str1)];
    }
    outputStr[outputStrLen - 1] = '\0';
    return outputStr;
}

void errorHandler(char *msg) {
    printf("%s\n", msg);
    exit(1);
}
