#ifndef TELEFONKONYV_SEARCHING_H
#define TELEFONKONYV_SEARCHING_H
#include <stdbool.h>
#include "structs.h"

bool insCmp(char* str1p,char* str2p);
Result *newSearchResult(Result** results,Result* newResult,Man* iter);
void writeResults(Result* results);
void freeResults(Result* results);
Result* search(Man *phoneBook);

#endif //TELEFONKONYV_SEARCHING_H
