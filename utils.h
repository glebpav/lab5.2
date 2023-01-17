#ifndef UNTITLED_UTILS_H
#define UNTITLED_UTILS_H

enum StructFields {
    FIO = 0,
    GROUP_NUMBER = 1,
    AVG_MARK = 2
};

enum DirectionOfSorting {
    UP = 0,
    DOWN = 1
};

enum AlgorithmOfSorting {
    COMB = 0,
    SELECTION = 1,
    QSORT = 2
};

typedef struct TerminalInput {
    char *inputFile;
    char *outputFile;
    enum DirectionOfSorting directionOfSorting;
    enum AlgorithmOfSorting algorithmOfSorting;
    enum StructFields fieldOfSorting;
}TerminalInput;

typedef struct TerminalInput2 {
    int arrayLen;
    int countOfArrays;
    enum DirectionOfSorting directionOfSorting;
    enum AlgorithmOfSorting algorithmOfSorting;
    enum StructFields fieldOfSorting;
}TerminalInput2;

typedef struct Item {
    char *fio;
    char *groupNumber;
    double avgMark;
}Item;

void clearItem(Item *item);
char *concatenate(char *str1, char *str2);
void errorHandler(char *msg);

#endif //UNTITLED_UTILS_H
