#include "borrow_book.h"
#include "read_write_files.h"
#include "library_data.h"
#include "main_menu.h"

void borrow_book()
{
    char key;
    int exit = 0;
    int x = START_POS;

    if(current_user_index == -1)
    {
        gotoxy(5,3);
        printf("You must login first");
        return;
    }

    if(number_books <= 0)
    {
        gotoxy(5,3);
        printf("No Books Available");
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
    printf("Choose Book you want to borrow");

    gotoxy(5,x);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    printf("%s", books[x-START_POS].title);

    for(x = x + 1; x - START_POS < number_books; x++)
    {
        gotoxy(5,x);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("%s", books[x-START_POS].title);
    }

    x=START_POS;

    do
    {
        do
        {
            gotoxy(5,4);
            key = getch();
            if(key == -32 || key == 0)
            {
                key = getch();
                switch(key)
                {
                    case 80:
                        gotoxy(5,4);
                        if(x < number_books - 1 + START_POS)
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
                            x = number_books - 1 + START_POS;
                        }
                        break;
                }
            }

            display_books();

            gotoxy(5,x);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
            printf("%s", books[x-START_POS].title);
        }while(key != 13);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("cls");

        display_books();

        exit = 1;
        
    }while(exit != 1);  

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");

    
    gotoxy(5,3);
    printf("You Choosed %s to borrow", books[x-START_POS].title);

    books[x-START_POS].number_copies--;

    if(books[x-START_POS].number_copies <= 0)
    {
        for(int i = x-START_POS; i < number_books;i++)
        {
            books[i] = books[i+1];
        }
        number_books--;
    }

    BORROWED_BOOK borrow_book;

    strcpy(borrow_book.user_code,users[current_user_index].code);
    borrow_book.book_isbn = books[x-START_POS].isbn;
    strcpy(borrow_book.book_title,books[x-START_POS].title);
    strcpy(borrow_book.book_author,books[x-START_POS].author);
    borrow_book.book_published_year = books[x-START_POS].published_year;


    borrowed_books[number_borrowed_books] = borrow_book;

    number_borrowed_books++;

    update_borrow_books_file();

    update_book_file();

    display_main_menu();

}


void display_books()
{
    int x;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");


    if(current_user_index != -1)
    {
        gotoxy(5,1);
        printf("Username : %-30sType : %-30s", current_user_name,(current_user_type == admin)?"admin":"user");
    }

    if(number_books <= 0)
    {
        gotoxy(5,3);
        printf("No Books Available");
        return;
    }

    gotoxy(5,3);
    printf("Choose Book you want to borrow");

    

    for(x = START_POS; x - START_POS < number_books; x++)
    {
        gotoxy(5,x);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("%s", books[x-START_POS].title);
    }

}
