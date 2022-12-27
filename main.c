#include "terminalReader.h"
#include "fileHelper.h"
#include "sortHelper.h"

int main(int argc, char **argv) {
    int dataArraySize = 0;

    TerminalInput terminalInput = getTerminalInput(argc, argv);
    Item *dataArray = getArrayFromFile(terminalInput.inputFile, &dataArraySize);

    dataArray = sortData(dataArray,
                         dataArraySize,
                         terminalInput.algorithmOfSorting,
                         terminalInput.fieldOfSorting,
                         terminalInput.directionOfSorting);

    writeFile(terminalInput.outputFile, dataArray, dataArraySize);
    return 0;
}

/*
 *
 * gcc main.c -o main terminalReader.c fileHelper.c utils.c arrayHelper.c compareHelper.c sortHelper.c
 * .\main.exe -a 0 -v 0 -d 1 "input.txt" "output.txt"
 *
 */
