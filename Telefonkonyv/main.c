#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "functions.h"
#include "fileManagement.h"
#include "managingElements.h"
#include "functions.h"
#include "searching.h"
#include "structs.h"

int main() {
    int menu;
    Man* phoneBook=NULL;
    bool exit = false;
    while (!exit) {
        printf("Telefonkonyv\n"
               "\n1. Uj rekord letrehozasa"
               "\n2. Rekord modositasa/torlese"
               "\n3. Kereses"
               "\n4. Rekordok kiirasa"
               "\n5. Mentes fajlba"
               "\n6. Beolvasas fajlbol"
               "\n7. vCard fajl importalasa"
               "\n8. vCard fajl exportalasa"
               "\n9. Kilepes\n");
        if (scanf("%d", &menu) == 1) {
            clearCMD();
            switch (menu) {
                case 1:
                    addElement(&phoneBook);
                    break;
                case 2:
                    modifyOrDeleteElement(&phoneBook);
                    break;
                case 3:
                    writeResults(search(phoneBook));
                    break;
                case 4:
                    writeAll(phoneBook);
                    break;
                case 5:
                    writeToFile(phoneBook);
                    break;
                case 6:
                    addElementFromFile(&phoneBook);
                    break;
                case 7:
                    vCardImport(&phoneBook);
                    break;
                case 8:
                    printf("Elobb keresse meg az exportalando rekordot!\n");
                    vCardExport(search(phoneBook));
                    break;
                case 9:
                    exit = true;
                    break;
                default:
                    printf("Helytelen bemenet!\n");
                    break;
            }
        }
        else{
            printf("Helytelen bemenet!\n");
            clearCMD();
        }if(!exit) {
            printf("Nyomjon entert a folytatashoz!\n");
            clearCMD();
        }
    }
    freePhoneBook(phoneBook);
    return 0;
}