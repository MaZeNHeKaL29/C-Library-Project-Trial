#include "add_book.h"
#include "read_write_files.h"
#include "library_data.h"
#include "main_menu.h"

void add_new_book()
{
    int isbn;
    char title[100];
    char author[100];
    int published_year;
    int number_copies;

    BOOK new_book;

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

    if(number_books >= MAX_BOOKS)
    {
        gotoxy(5,3);
        printf("Number of Books is Maximum");
        return;
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
            printf("Book already exists");
            break;
        }
    }

    fflush(stdin);

    if(isbn_exists && book_exists_index != -1)
    {
        printf("Enter Number of Copies of Book : ");
        scanf("%d", &number_copies);
        books[book_exists_index].number_copies += number_copies;
        return;
    }

    fflush(stdin);

    printf("Enter Title of Book : ");
    gets(title);

    fflush(stdin);

    printf("Enter Author of Book : ");
    gets(author);

    fflush(stdin);

    printf("Enter Published Year of Book : ");
    scanf("%d", &published_year);

    fflush(stdin);

    printf("Enter Number of Copies of Book : ");
    scanf("%d", &number_copies);

    fflush(stdin);
    
    new_book.isbn = isbn;
    strcpy(new_book.title,title);
    strcpy(new_book.author,author);
    new_book.published_year = published_year;
    new_book.number_copies = number_copies;
    books[number_books] = new_book;
    number_books++;

    update_book_file();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");

    gotoxy(5,3);
    printf("%s Book is added",title);



    display_main_menu();
}