#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void writeAll(Man *phoneBook) {
    Man *iter = phoneBook;
    while (iter->next != NULL) {
        printf("\nNev: %s"
               "\nFoglalkozas: %s"
               "\nTelefonszam: %s"
               "\nCim: %s\n", iter->name, iter->job, iter->phoneNumber, iter->address);
        iter = iter->next;
    }
    printf("\nNev: %s"
           "\nFoglalkozas: %s"
           "\nTelefonszam: %s"
           "\nCim: %s\n\n", iter->name, iter->job, iter->phoneNumber, iter->address);
}
void clearCMD(){
    scanf("%*[^\n]");
    getchar();
}
void freePhoneBook(Man* phoneBook){
    while(phoneBook!=NULL){
        Man* tmp=phoneBook->next;
        free(phoneBook->name);
        free(phoneBook->job);
        free(phoneBook->phoneNumber);
        free(phoneBook->address);
        free(phoneBook);
        phoneBook=tmp;
    }
}


