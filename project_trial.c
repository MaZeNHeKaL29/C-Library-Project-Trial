/*
    C Programming Project
*/

#include "helpers.h"
#include "library_data.h"
#include "read_write_files.h"
#include "main_menu.h"

void init();


int main()
{
    init();
    main_menu();
}

void init()
{
    read_user_file();
    read_book_file();
    read_borrowed_book_file();
}
