#include "return_book.h"
#include "read_write_files.h"
#include "library_data.h"
#include "main_menu.h"




void return_book()
{
    char key;
    int exit = 0;
    int x = START_POS;

    int user_borrowed_books_indexes[number_borrowed_books];

    if(current_user_index == -1)
    {
        gotoxy(5,3);
        printf("You must login first");
        return;
    }

    int number_user_borrowed_books = 0;

    for(int i = 0; i < number_borrowed_books; i++)
    {
        gotoxy(5,4);
        if(strcmp(borrowed_books[i].user_code,users[current_user_index].code) == 0)
        {
            user_borrowed_books_indexes[number_user_borrowed_books] = i;
            number_user_borrowed_books++;
        }
    }

    if(number_borrowed_books <= 0 || number_user_borrowed_books <= 0)
    {
        gotoxy(5,3);
        printf("No Borrowed Books Of User to return");
        return;
    }

    


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");


    if(current_user_index != -1)
    {
        gotoxy(5,1);
        printf("Username : %-30sType : %-30s", current_user_name,(current_user_type == admin)?"admin":"user");
    }


    gotoxy(5,3);
    printf("Choose Book you want to return");

    gotoxy(5,x);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    printf("%s", borrowed_books[user_borrowed_books_indexes[x-START_POS]].book_title);

    for(x = x + 1; x - START_POS < number_user_borrowed_books; x++)
    {
        gotoxy(5,x);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("%s", borrowed_books[user_borrowed_books_indexes[x-START_POS]].book_title);
    }

    x=START_POS;

    do
    {
        do
        {
            key = getch();
            if(key == -32 || key == 0)
            {
                key = getch();
                switch(key)
                {
                    case 80:
                        if(x < number_user_borrowed_books - 1 + START_POS)
                        {
                            x++;
                        }
                        else
                        {
                            x = START_POS;
                        }
                        break;
                    case 72:
                        gotoxy(5,4);
                        if(x > START_POS)
                        {
                            x--;
                        }
                        else
                        {
                            x = number_user_borrowed_books - 1 + START_POS;
                        }
                        break;
                }
            }

            display_user_borrowed_books(user_borrowed_books_indexes,number_user_borrowed_books);

            gotoxy(5,x);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
            printf("%s", borrowed_books[user_borrowed_books_indexes[x-START_POS]].book_title);
        }while(key != 13);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("cls");

        display_user_borrowed_books(user_borrowed_books_indexes,number_user_borrowed_books);

        exit = 1;
        
    }while(exit != 1);  

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");

    gotoxy(5,3);
    printf("You Choosed %s to return", borrowed_books[user_borrowed_books_indexes[x-START_POS]].book_title);
    
    int book_found = -1;

    for(int i = 0; i < number_books;i++)
    {
        if(books[i].isbn == borrowed_books[user_borrowed_books_indexes[x-START_POS]].book_isbn)
        {
            book_found = i;
            break;
        }
    }


    if(book_found != -1)
    {
        books[book_found].number_copies++;
    }
    else
    {
        BOOK new_book;
        new_book.isbn = borrowed_books[user_borrowed_books_indexes[x-START_POS]].book_isbn;
        strcpy(new_book.title,borrowed_books[user_borrowed_books_indexes[x-START_POS]].book_title);
        strcpy(new_book.author,borrowed_books[user_borrowed_books_indexes[x-START_POS]].book_author);
        new_book.published_year = borrowed_books[user_borrowed_books_indexes[x-START_POS]].book_published_year;
        new_book.number_copies = 1;
        books[number_books] = new_book;
        number_books++;
    }

    for(int i = user_borrowed_books_indexes[x-START_POS]; i < number_borrowed_books; i++)
    {
        borrowed_books[i] = borrowed_books[i+1];
    }
    number_borrowed_books--;

    update_book_file();

    update_borrow_books_file();



    display_main_menu();
}



void display_user_borrowed_books(int* user_borrowed_books_indexes,int number_user_borrowed_books)
{
    int x;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");



    if(current_user_index != -1)
    {
        gotoxy(5,1);
        printf("Username : %-30sType : %-30s", current_user_name,(current_user_type == admin)?"admin":"user");
    }

    if(number_user_borrowed_books <= 0)
    {
        gotoxy(5,3);
        printf("No Borrowed Books Of User to return %d", number_user_borrowed_books);
        return;
    }

    gotoxy(5,3);
    printf("Choose Book you want to return");

    

    for(x = START_POS; x - START_POS < number_user_borrowed_books; x++)
    {
        gotoxy(5,x);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("%s", borrowed_books[user_borrowed_books_indexes[x-START_POS]].book_title);
    }
}