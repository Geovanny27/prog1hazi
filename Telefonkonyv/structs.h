#ifndef TELEFONKONYV_STRUCTS_H
#define TELEFONKONYV_STRUCTS_H
#include <stdio.h>

typedef struct Man {
    char* name;
    char* job;
    char* phoneNumber;
    char* address;
    struct Man *next;
    struct Man* previous;
} Man;
typedef struct Result{
    Man* man;
    struct Result* next;
}Result;

#endif //TELEFONKONYV_STRUCTS_H
