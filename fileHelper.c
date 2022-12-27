#include "fileHelper.h"
#include "arrayHelper.h"
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


char **readFile(char *fileName, int *inputArraySize) {
    FILE *fp;

    char *prefix = "files/";
    char *filePath = concatenate(prefix, fileName);

    if ((fp = fopen(filePath, "r+")) == NULL) {
        puts("Error: No such file\n");
        exit(1);
    }

    char *item = malloc(80 * sizeof(char));
    *inputArraySize = 0;
    char **outputArray = malloc(0 * sizeof(char *));
    while (true) {

        int ret = fscanf(fp, "%s ", item);
        if (ret == 1) {
            pushStrElement(&outputArray, *inputArraySize, item);
            *inputArraySize += 1;
        } else if (errno != 0) {
            perror("scanf:");
            break;
        } else if (ret == EOF) {
            break;
        } else {
            puts("No or partial match.\n");
        }
    }
    if (feof(fp)) {
        fclose(fp);
    }

    return outputArray;
}

void writeFile(char *fileName, Item *dataArray, int dataArraySize) {
    FILE *f;

    char *prefix = "files/";
    char *filePath = concatenate(prefix, fileName);

    if ((f = fopen(filePath, "w")) == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\n --- sorted array --- \n");
    for (int i = 0; i < dataArraySize; i++) {
        printf("%s , %s , %f ;\n", dataArray[i].fio, dataArray[i].groupNumber, dataArray[i].avgMark);
        fprintf(f, "%s , %s , %f ;\n", dataArray[i].fio, dataArray[i].groupNumber, dataArray[i].avgMark);
    }

    fclose(f);
}

Item *getArrayFromFile(char *fileName, int *arraySize) {

    int inputArraySize = 0;
    char **inputArray = readFile(fileName, &inputArraySize);

//    for (int i = 0; i < inputArraySize; i++) {
//        printf("[%d] - %s\n", i, inputArray[i]);
//    }

    int dataArrayLen = 0;
    int dataCursor = 0;
    Item *dataArray;
    Item arrayItem;
    clearItem(&arrayItem);

    for (int i = 0; i < inputArraySize; i++) {
        if (dataCursor == 3) errorHandler("Error: invalid text file format");
        if (strcmp(inputArray[i], ";") == 0) {
            if ((dataCursor != 2 || arrayItem.fio == NULL || arrayItem.groupNumber == NULL) != 0)
                errorHandler("Error: invalid text file format");

//            printf("\nfio - %s\n", arrayItem.fio);
//            printf("group - %s\n", arrayItem.groupNumber);
//            printf("mark - %f\n\n", arrayItem.avgMark);

            pushElement(&dataArray, dataArrayLen, arrayItem);
            clearItem(&arrayItem);
            dataCursor = 0;
            dataArrayLen += 1;
        } else if (strcmp(inputArray[i], ",") == 0) {
            dataCursor += 1;
        } else if (dataCursor == 0) {
            inputArray[i] = concatenate(" ", inputArray[i]);
            arrayItem.fio = concatenate(arrayItem.fio, inputArray[i]);
        } else if (dataCursor == 1) {
            arrayItem.groupNumber = concatenate(arrayItem.groupNumber, inputArray[i]);
        } else if (dataCursor == 2) {
            arrayItem.avgMark = atof(inputArray[i]);
        }
    }

//    printf("end of creating array\n");
//    for (int i = 0; i < dataArrayLen; i++) {
//        printf("\nfio - %s\n", dataArray[i].fio);
//        printf("group - %s\n", dataArray[i].groupNumber);
//        printf("mark - %f\n\n", dataArray[i].avgMark);
//    }

    printf("\n --- input array --- \n");
    for (int i = 0; i < dataArrayLen; i++) {
        printf("%s , %s , %f ;\n", dataArray[i].fio, dataArray[i].groupNumber, dataArray[i].avgMark);
    }

    *arraySize = dataArrayLen;
    return dataArray;
}