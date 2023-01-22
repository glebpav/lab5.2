#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

void clearItem(Item *item) {

    // free(item->fio);
    // free(item->groupNumber);
    //printf("fio in this: %s\n", item->fio);
    if (item->fio != NULL) free(item->fio);
    if (item->groupNumber != NULL) free(item->groupNumber);


    item->fio = NULL;
    item->groupNumber = NULL;
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
    // free(str1);
    return outputStr;
}

void errorHandler(char *msg) {
    printf("%s\n", msg);
    exit(1);
}

char *randSting(int len) {
    char *str = calloc(len, sizeof(len));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzQWERTYUIOPASDFGHJKLZXCVBNM";

    for (size_t n = 0; n < len; n++) {
        int key = rand() % (int) (sizeof charset - 1);
        str[n] = charset[key];
    }
    // printf("\n rand str: %s\n", str);
    return str;
}
