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

bool insCmp(char* str1p,char* str2p){
    int i=0;
    char* str1=(char*) malloc(50);
    char* str2=(char*) malloc(50);

    while(str1p[i]!='\0'){
        str1[i]=(char) tolower(str1p[i]);
        i++;
    }
    str1[i]='\0';
    i=0;
    while(str2p[i]!='\0'){
        str2[i]=(char) tolower(str2p[i]);
        i++;
    }
    str2[i]='\0';
    if(strstr(str1,str2)!=NULL){
        free(str1);
        free(str2);
        return true;
    }
    free(str1);
    free(str2);
    return false;
}
Result *newSearchResult(Result** results,Result* newResult,Man* iter){
    if(*results==NULL){
        newResult=(Result*) malloc(sizeof(Result));
        *results=newResult;
    }
    else{
        newResult->next=(Result*) malloc(sizeof(Result));
        newResult= newResult->next;
    }
    newResult->man=iter;
    newResult->next=NULL;
    return newResult;

}
void writeResults(Result* results){
    printf("Talalatok:\n");
    Result* tmp = results;
    if (results == NULL)
        printf("Nincs talalat\n");
    else {
        while(results!=NULL){
            printf("\nNev: %s\nFoglalkozas: %s\nTelefonszam: %s\nCim: %s\n", results->man->name, results->man->job,results->man->phoneNumber, results->man->address);
            results=results->next;
        }
    }
    freeResults(tmp);
}
void freeResults(Result* results){
    while(results!=NULL){
        Result* tmp = results->next;
        free(results);
        results=tmp;
    }
}
Result* search(Man *phoneBook) {
    char field;
    bool wrongInput;
    do {
        printf("Mi szerint keresunk?((n)ev/(f)oglalkozas/(t)elefonszam/(c)im)\n");//TODO rossz input
        scanf("%c",&field);
        clearCMD();
        if (field == 'n' || field == 'N'){
            printf("Melyik nevet keressuk?\n");
            wrongInput=false;
        }
        else if (field == 'f' || field == 'F'){
            printf("Milyen foglalkozasu embert keresunk?\n");
            wrongInput=false;
        }
        else if (field == 't' || field == 'T'){
            printf("Melyik telefonszam szerint keresunk?\n");
            wrongInput=false;
        }
        else if (field == 'c' || field == 'C'){
            printf("Melyik cim szerint keresunk?\n");
            wrongInput=false;
        }
        else {
            wrongInput=true;
            printf("Helytelen bemenet!\n");
        }
    } while (wrongInput);
    char sought[51];
    scanf("%50s", sought);
    clearCMD();
    Man* iter=phoneBook;
    Result* results=NULL;
    Result* newResult=NULL;
    while (iter!= NULL) {
        if (field == 'n' || field == 'N') {
            if (insCmp(iter->name,sought)) {
                newResult=newSearchResult(&results,newResult,iter);
            }
            else if (strchr(sought, '*') != NULL) {
                char* firstPart=strtok(sought,"*");
                char* secondPart=strtok(NULL,"*");
                if(secondPart==NULL&&insCmp(iter->name,firstPart)){
                    newResult=newSearchResult(&results,newResult,iter);
                }
                else if(insCmp(iter->name,firstPart)&&insCmp(iter->name,secondPart)){ //TODO lehet *valami-re nullt ad strtok?
                    newResult=newSearchResult(&results,newResult,iter);
                }

            }
        }
        else if (!strchr("Foglalkozas", field) && strstr(iter->job,sought)!=NULL)
            newResult=newSearchResult(&results,newResult,iter);
        else if (!strchr("Telefonszam", field) && strstr(iter->phoneNumber,sought)!=NULL)
            newResult=newSearchResult(&results,newResult,iter);
        else if (!strchr("Address", field) && strstr(iter->address,sought)!=NULL)
            newResult=newSearchResult(&results,newResult,iter);

        iter=iter->next;
    }
    return results;
}