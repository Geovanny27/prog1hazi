#ifndef TELEFONKONYV_FILEMANAGEMENT_H
#define TELEFONKONYV_FILEMANAGEMENT_H
#include "structs.h"

void addElementFromFile(Man** phoneBook);
void writeToFile(Man* phoneBook);
void vCardExport(Result* result);
void vCardImport(Man** phoneBook);

#endif //TELEFONKONYV_FILEMANAGEMENT_H
