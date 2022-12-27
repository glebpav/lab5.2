#include "compareHelper.h"
#include "utils.h"

int compareStrings(char *str1, char *str2) {
    while ( *str1 != '\0' && *str1 == *str2 ) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

int comparatorUpFio(const void *a, const void *b) {
    const Item *obj1 = a;
    const Item *obj2 = b;
    int res = compareStrings(obj1->fio, obj2->fio);
    return res;
}
int comparatorDownFio(const void *a, const void *b) {
    const Item *obj1 = a;
    const Item *obj2 = b;
    int res = compareStrings(obj1->fio, obj2->fio);
    return res * -1;
}

int comparatorUpGroup(const void *a, const void *b) {
    const Item *obj1 = a;
    const Item *obj2 = b;
    int res = compareStrings(obj1->groupNumber, obj2->groupNumber);
    return res;
}
int comparatorDownGroup(const void *a, const void *b) {
    const Item *obj1 = a;
    const Item *obj2 = b;
    int res = compareStrings(obj1->groupNumber, obj2->groupNumber);
    return res * -1;
}

int comparatorUpMark(const void *a, const void *b) {
    const Item *obj1 = a;
    const Item *obj2 = b;
    int res = (int) ((obj1->avgMark - obj2->avgMark) * 10000);
    return res;
}
int comparatorDownMark(const void *a, const void *b) {
    const Item *obj1 = a;
    const Item *obj2 = b;
    int res = (int) ((obj1->avgMark - obj2->avgMark) * 10000);
    return res * -1;
}