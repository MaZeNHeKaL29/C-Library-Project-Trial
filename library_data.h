#ifndef LIBRARY_DATA_H_
#define LIBRARY_DATA_H_

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "users.h"
#include "books.h"
#include "borrowed_books.h"

#define MAX_BOOKS   500
#define MAX_USERS   100
#define MAX_BORROWED_BOOKS  500

extern USER users[MAX_USERS];

extern int number_users;

extern BOOK books[MAX_BOOKS];

extern int number_books;

extern BORROWED_BOOK borrowed_books[MAX_BORROWED_BOOKS];

extern int number_borrowed_books;

extern int current_user_index;
extern char current_user_name[100];
extern TYPE current_user_type;




#endif /*LIBRARY_DATA_H_*/