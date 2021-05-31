#ifndef TELEFONKONYV_MANAGINGELEMENTS_H
#define TELEFONKONYV_MANAGINGELEMENTS_H

#include "structs.h"

Man* newElement(Man** phoneBook);
void addElement(Man **phoneBook);
void deleteElement(Man* element,Man** phoneBook);
void modifyElement(Man* element);
void modifyOrDeleteElement(Man** phoneBook);
#endif //TELEFONKONYV_MANAGINGELEMENTS_H
