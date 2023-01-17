#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "terminalReader.h"


TerminalInput getTerminalInput(int argc, char **argv) {

    if (argc == 1) {
        printf("Data sorting Program\n\n");
        printf("optional args:\n");
        printf("    -a - algorithm of sorting (COMB = 0, SELECTION = 1, QSORT = 2)\n");
        printf("    -v - var (field) of sorting (FIO = 0, GROUP_NUMBER = 1, AVG_MARK = 2)\n");
        printf("    -d - direction of sorting (UP = 0, DOWN = 1)\n");
        printf("required args:\n");
        printf("    first - name of input file\n");
        printf("    second - name of output file\n");
        exit(0);
    }

    if (argc != 9) errorHandler("Error: incorrect count of args");

    int opt;
    TerminalInput terminalInput;

    while ((opt = getopt(argc, argv, "d:a:v:")) != -1) {
        int inputValue = atoi(optarg);
        switch (opt) {
            case 'a':
                printf("algorithm of sorting is: %s\n", optarg);
                if (inputValue < 0 || inputValue > 2) errorHandler("Error: incorrect type of sorting algorithm");
                terminalInput.algorithmOfSorting = inputValue;
                break;
            case 'v':
                printf("var (field of sorting) is: %s\n", optarg);
                if (inputValue < 0 || inputValue > 2) errorHandler("Error: incorrect type of field");
                terminalInput.fieldOfSorting = inputValue;
                break;
            case 'd':
                printf("directions of sorting: %s\n", optarg);
                if (inputValue < 0 || inputValue > 1) errorHandler("Error: incorrect type of direction");
                terminalInput.directionOfSorting = inputValue;
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
                break;
        }
    }

    for (; optind < argc; optind++) {
        printf("extra arguments: %s\n", argv[optind]);
        if (optind == 7) {
            terminalInput.inputFile = argv[optind];
        } else if (optind == 8) {
            terminalInput.outputFile = argv[optind];
        }
    }

    return terminalInput;
}