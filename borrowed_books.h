#ifndef BORROWED_BOOKS_H_
#define BORROWED_BOOKS_H_

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "books.h"
#include "users.h"

typedef struct 
{
    char user_code[50];
    int book_isbn;
    char book_title[100];
    char book_author[100];
    int book_published_year;
}BORROWED_BOOK;


#endif //BORROWED_BOOKS_H_