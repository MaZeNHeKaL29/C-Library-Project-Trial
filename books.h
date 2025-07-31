#ifndef BOOKS_H_
#define BOOKS_H_

#include <stdio.h>
#include <windows.h>
#include <conio.h>

typedef struct 
{
    int isbn;
    char title[100];
    char author[100];
    int published_year;
    int number_copies;
}BOOK;


#endif //BOOKS_H_