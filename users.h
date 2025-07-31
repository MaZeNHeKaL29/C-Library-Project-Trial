#ifndef USERS_H_
#define USERS_H_

#include <stdio.h>
#include <windows.h>
#include <conio.h>


typedef enum
{
    admin = 1, user = 2
}TYPE;

typedef struct
{
    char code[50];
    char name[100];
    char password[20];
    TYPE user_type;
}USER;


#endif //USERS_H_