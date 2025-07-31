#include "library_data.h"

USER users[MAX_USERS];

int number_users = 0;

BOOK books[MAX_BOOKS];

int number_books = 0;

BORROWED_BOOK borrowed_books[MAX_BORROWED_BOOKS];

int number_borrowed_books = 0;

int current_user_index = -1;
char current_user_name[100];
TYPE current_user_type;