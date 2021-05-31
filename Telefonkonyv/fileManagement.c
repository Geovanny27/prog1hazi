#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileManagement.h"
#include "managingElements.h"
#include "structs.h"
#include "searching.h"

void addElementFromFile(Man** phoneBook) {
    FILE *fp = fopen("telefonkonyv.txt", "rt");
    if (fp == NULL)
        perror("Hiba tortent a fajl megnyitasa soran!\n");
    else {
        while (!feof(fp)) {
            Man *new = newElement(phoneBook);
            fscanf(fp, " %[^;]%*c %[^;]%*c %[^;]%*c %[^\n]%*c", new->name,
                   new->job, new->phoneNumber,
                   new->address);
        }
        fclose(fp);
        printf("A beolvasas sikeresen lezarult\n");
    }
}
void writeToFile(Man* phoneBook){
    FILE *fp = fopen("telefonkonyv.txt", "w");
    Man* iter = phoneBook;
    while(iter->next!=NULL) {
        fprintf(fp, "%s; %s; %s; %s\n", iter->name, iter->job, iter->phoneNumber,
                iter->address);
        iter=iter->next;
    }
    fprintf(fp, "%s; %s; %s; %s", iter->name, iter->job, iter->phoneNumber,
            iter->address);
    fclose(fp);
    printf("A kiiratas sikeresen lezarult\n");
}
void vCardExport(Result* result){
    FILE* fp = fopen("vCard.vcf","wt");
    char* street = strtok(result->man->address,",");
    char* city = strtok(NULL,",");
    fprintf(fp,"BEGIN:VCARD\n"
               "VERSION:3.0\n"
               "FN:%s\n"
               "TITLE:%s\n"
               "TEL;TYPE=HOME,VOICE:%s\n"
               "ADR;TYPE=HOME:;;%s;%s\n"
               "END:VCARD",result->man->name,result->man->job,result->man->phoneNumber,city,street);
    fclose(fp);
    freeResults(result);
    printf("Sikeres exportalas\n");
}
void vCardImport(Man** phoneBook){
    FILE* fp = fopen("vCard.vcf","rt");
    if(fp==NULL)
        perror("Hiba tortent a fajl megnyitasa soran!\n");
    else{
        Man* new =newElement(phoneBook);
        char* address=(char*) malloc(50);
        fscanf(fp,"BEGIN:VCARD\n"
                  "VERSION:3.0\n"
                  "FN:%[^\n]\n"
                  "TITLE:%[^\n]\n"
                  "TEL;TYPE=HOME,VOICE:%[^\n]\n"
                  "ADR;TYPE=HOME:;;%[^\n]\n"
                  "END:VCARD",new->name,new->job,new->phoneNumber,address);
        fclose(fp);
        char* addr1=strtok(address,";");
        char* addr2=strtok(NULL,";");
        strcpy(new->address,addr1);
        strcat(new->address,", ");
        strcat(new->address,addr2);
        free(address);
        printf("Sikeres importalas\n");
    }
}