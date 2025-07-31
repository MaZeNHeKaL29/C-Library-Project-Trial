#include "main_menu.h"
#include "login.h"
#include "add_book.h"
#include "delete_book.h"
#include "borrow_book.h"
#include "search_book.h"
#include "return_book.h"
#include "library_data.h"

#define LOGIN_POS       5
#define ADD_BOOK_POS    6
#define DELETE_BOOK_POS 7
#define BORROW_BOOK_POS 8
#define SEARCH_BOOK_POS 9
#define RETURN_BOOK_POS 10
#define EXIT_POS        11

void main_menu()
{
    char key = 0;
    int x = LOGIN_POS;
    int exit = 0;
    system("cls");

    showConsoleCursor(FALSE);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(5,1);
    printf("Not Logged in");
    
    gotoxy(5,LOGIN_POS);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    printf("0) Login");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(5,ADD_BOOK_POS);
    printf("1) Add a new Book");
    gotoxy(5,DELETE_BOOK_POS);
    printf("2) Delete a Book");
    gotoxy(5,BORROW_BOOK_POS);
    printf("3) Borrow a Book");
    gotoxy(5,SEARCH_BOOK_POS);
    printf("4) Search a Book");
    gotoxy(5,RETURN_BOOK_POS);
    printf("5) Return a Book");
    gotoxy(5,EXIT_POS);
    printf("6) Exit");



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
                        if(x < 11)
                        {
                            x++;
                        }
                        else
                        {
                            x = 5;
                        }
                        break;
                    case 72:
                        if(x > 5)
                        {
                            x--;
                        }
                        else
                        {
                            x = 11;
                        }
                        break;
                }
            }

            display_main_menu();

            switch(x)
            {
                case LOGIN_POS:
                    gotoxy(5,x);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("0) Login");
                    break;
                case ADD_BOOK_POS:
                    gotoxy(5,x);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("1) Add a new Book");
                    break;
                case DELETE_BOOK_POS:
                    gotoxy(5,x);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("2) Delete a Book");
                    break;
                case BORROW_BOOK_POS:
                    gotoxy(5,x);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("3) Borrow a Book");
                    break;
                case SEARCH_BOOK_POS:
                    gotoxy(5,x);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("4) Search a Book");
                    break;
                case RETURN_BOOK_POS:
                    gotoxy(5,x);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("5) Return a Book");
                    break;
                case EXIT_POS:
                    gotoxy(5,x);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("6) Exit");
                    break;
            }
        }while(key != 13);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("cls");

        display_main_menu();

        
        switch(x)
        {
            case LOGIN_POS:
                gotoxy(5,1);
                login();
                gotoxy(5,x);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                printf("0) Login");
                break;
            case ADD_BOOK_POS:
                add_new_book();
                gotoxy(5,x);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                printf("1) Add a new Book");
                break;
            case DELETE_BOOK_POS:
                delete_book();
                gotoxy(5,x);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                printf("2) Delete a Book");
                break;
            case BORROW_BOOK_POS:
                borrow_book();
                gotoxy(5,x);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                printf("3) Borrow a Book");
                break;
            case SEARCH_BOOK_POS:
                search_book();
                gotoxy(5,x);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                printf("4) Search a Book");
                break;
            case RETURN_BOOK_POS:
                return_book();
                gotoxy(5,x);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                printf("5) Return a Book");
                break;
            case EXIT_POS:
                gotoxy(5,3);
                printf("You Select Choice No. %d (Exit)\n\n", 6);
                exit = 1;
                break;
        }
    }while(exit != 1);  

    gotoxy(5,EXIT_POS);
    printf("\n\n\n\n\n\n");
    showConsoleCursor(TRUE);
}

void display_main_menu()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    if(current_user_index != -1)
    {
        gotoxy(5,1);
        printf("Username : %-30sType : %-30s", current_user_name,(current_user_type == admin)?"admin":"user");
    }
    else
    {
        gotoxy(5,1);
        printf("Not Logged in");
    }
    gotoxy(5,LOGIN_POS);
    printf("0) Login");
    gotoxy(5,ADD_BOOK_POS);
    printf("1) Add a new Book");
    gotoxy(5,DELETE_BOOK_POS);
    printf("2) Delete a Book");
    gotoxy(5,BORROW_BOOK_POS);
    printf("3) Borrow a Book");
    gotoxy(5,SEARCH_BOOK_POS);
    printf("4) Search a Book");
    gotoxy(5,RETURN_BOOK_POS);
    printf("5) Return a Book");
    gotoxy(5,EXIT_POS);
    printf("6) Exit");
}