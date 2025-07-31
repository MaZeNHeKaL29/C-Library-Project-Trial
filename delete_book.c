#include "delete_book.h"
#include "read_write_files.h"
#include "library_data.h"
#include "main_menu.h"

void delete_book()
{
    int isbn;
    char title[100];
    if(current_user_index == -1)
    {
        gotoxy(5,3);
        printf("You must login first");
        return;
    }
    if(current_user_type != admin)
    {
        gotoxy(5,3);
        printf("You must be admin to add a new book");
        return;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");


    if(current_user_index != -1)
    {
        gotoxy(5,1);
        printf("Username : %-30sType : %-30s", current_user_name,(current_user_type == admin)?"admin":"user");
    }

    gotoxy(0,START_POS);

    showConsoleCursor(TRUE);

    int isbn_exists = 0;
    int book_exists_index = -1;
    printf("Enter ISBN of Book : ");
    scanf("%d", &isbn);

    for(int i = 0; i < number_books; i++)
    {
        if(books[i].isbn == isbn)
        {
            isbn_exists = 1;
            book_exists_index = i;
            break;
        }
    }

    if(isbn_exists && book_exists_index != -1)
    {
        strcpy(title,books[book_exists_index].title);
        for(int i = book_exists_index; i < number_books;i++)
        {
            books[i] = books[i+1];
        }
        number_books--;
        update_book_file();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("cls");

        gotoxy(5,3);
        printf("%s Book is deleted",title);
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("cls");

        gotoxy(5,3);
        printf("Book Not Found");
    }

    display_main_menu();

}
