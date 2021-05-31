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


Man* newElement(Man** phoneBook){
    Man* new=(Man *) malloc(sizeof(Man));
    Man *iter = *phoneBook;
    if(iter==NULL){
        *phoneBook=new;
        new->next=NULL;
        new->previous=NULL;
    }
    else {
        while (iter->next != NULL) {
            iter = iter->next;
        }
        iter->next = new;
        new->next = NULL;
        new->previous=iter;
    }
    new->name = (char *) malloc(51);
    new->job = (char *) malloc(26);
    new->phoneNumber = (char *) malloc(12);
    new->address = (char *) malloc(51);
    return new;
}
void addElement(Man **phoneBook) {
    Man* new = newElement(phoneBook);
    printf("Adja meg az adatokat!/\n");
    printf("Nev:");
    scanf("%50s", new->name);
    clearCMD();

    printf("Foglalkozas:");
    scanf("%25s", new->job);
    clearCMD();

    printf("Telefonszam:");
    scanf("%11s", new->phoneNumber);
    clearCMD();

    printf("Cim:(telepules, utca)");
    scanf("%50s", new->address);
    clearCMD();
    printf("Sikeresen hozzaadott egy elemet az adatbazishoz\n");
}
void deleteElement(Man* element,Man** phoneBook) {
    if(element->next!=NULL)
        element->next->previous=element->previous;
    if(element->previous==NULL) {
        element->next->previous = NULL;
        *phoneBook=element->next;
    }
    else
        element->previous->next=element->next;
    free(element->name);
    free(element->job);
    free(element->phoneNumber);
    free(element->address);
    free(element);
    printf("Az elemet sikeresen torolte\n");
}
void modifyElement(Man* element){
    char field;
    do{
        printf("Melyik mezot szeretne modositani?((n)ev/(f)oglalkozas/(t)elefonszam/(c)im)\n");
    }while (!scanf("%c%*c", &field));
    if (field == 'n' || field == 'N'){
        printf("Irja be a nevet!\n");
        scanf("%50s",element->name);
        clearCMD();
    }
    else if (field == 'f' || field == 'F'){
        printf("Irja be a foglalkozast!\n");
        scanf("%25s",element->job);
        clearCMD();
    }
    else if (field == 't' || field == 'T'){
        printf("Irja be a telefonszamot!\n");
        scanf("%12s",element->phoneNumber);
        clearCMD();
    }
    else if (field == 'c' || field == 'C'){
        printf("Irja be a cimet!\n");
        scanf("%50s",element->address);
        clearCMD();
    }

}
void modifyOrDeleteElement(Man** phoneBook) {
    printf("Elobb keresse meg a rekordot amit modositani szeretne!\n");
    Result *results = NULL;
    bool firsttry=true;
    do {
        if(!firsttry)
            printf("Pontositsa a keresest!\n");
        freeResults(results);
        results = search(*phoneBook);
        firsttry=false;
    } while (results->next != NULL);
    if (results->next == NULL) {
        char field;
        do {
            printf("Modositani vagy torolni szeretne?((m)odosit,(t)orol)\n");
        } while (!scanf("%c%*c", &field));
        if (field == 'm' || field == 'M')
            modifyElement(results->man);
        if (field == 't' || field == 'T')
            deleteElement(results->man, phoneBook);
    }
    freeResults(results);
}