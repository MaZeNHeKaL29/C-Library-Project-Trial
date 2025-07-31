#include "search_book.h"
#include "read_write_files.h"
#include "library_data.h"
#include "main_menu.h"

void search_book()
{
    int isbn;
    char title[100];
    char author[100];
    int published_year;
    int number_books_found = 0;
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
        printf("No Books Available to Search");
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
    printf("Search By : ");

    gotoxy(5,x);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    printf("%s", "ISBN");

    for(int i = x; i < 4 + START_POS; i++)
    {
        switch(i)
        {
            case START_POS + 1:
                gotoxy(5,i);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf("%s", "Title");
                break;
            case START_POS + 2:
                gotoxy(5,i);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf("%s", "Author");
                break;
            case START_POS + 3:
                gotoxy(5,i);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf("%s", "Published Year");
                break;
        }
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    x = START_POS;

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
                        if(x < 4 - 1 + START_POS)
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
                            x = 4 - 1 + START_POS;
                        }
                        break;
                }
            }

            for(int i =START_POS; i < 4 + START_POS; i++)
            {
                switch(i)
                {
                    case START_POS:
                        gotoxy(5,i);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        printf("%s", "ISBN");
                        break;
                    case START_POS + 1:
                        gotoxy(5,i);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        printf("%s", "Title");
                        break;
                    case START_POS + 2:
                        gotoxy(5,i);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        printf("%s", "Author");
                        break;
                    case START_POS + 3:
                        gotoxy(5,i);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        printf("%s", "Published Year");
                        break;
                }
            }

            gotoxy(5,x);
            switch(x)
            {
                case START_POS:
                    gotoxy(5,x);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("%s", "ISBN");
                    break;
                case START_POS + 1:
                    gotoxy(5,x);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("%s", "Title");
                    break;
                case START_POS + 2:
                    gotoxy(5,x);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("%s", "Author");
                    break;
                case START_POS + 3:
                    gotoxy(5,x);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("%s", "Published Year");
                    break;
            }
        }while(key != 13);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("cls");
        exit = 1;
        
    }while(exit != 1);  

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");


    if(current_user_index != -1)
    {
        gotoxy(5,1);
        printf("Username : %-30sType : %-30s", current_user_name,(current_user_type == admin)?"admin":"user");
    }

    gotoxy(5,3);
    if(x == START_POS)
    {
        printf("Enter ISBN of Book : ");
        scanf("%d", &isbn);
        for(int i = 0; i < number_books; i++)
        {
            if(books[i].isbn == isbn)
            {
                number_books_found++;
            }
        }
    }
    else if(x == START_POS + 1)
    {
        printf("Enter Title of Book : ");
        gets(title);
        for(int i = 0; i < number_books; i++)
        {
            if(strcmp(books[i].title,title) == 0)
            {
                number_books_found++;
            }
        }
    }
    else if(x == START_POS + 2)
    {
        printf("Enter Author of Book : ");
        gets(author);
        for(int i = 0; i < number_books; i++)
        {
            if(strcmp(books[i].author,author) == 0)
            {
                number_books_found++;
            }
        }
    }
    else if(x == START_POS + 3)
    {
        printf("Enter Published Year of Book : ");
        scanf("%d", &published_year);
        for(int i = 0; i < number_books; i++)
        {
            if(books[i].published_year == published_year)
            {
                number_books_found++;
            }
        }
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");


    if(current_user_index != -1)
    {
        gotoxy(5,1);
        printf("Username : %-30sType : %-30s", current_user_name,(current_user_type == admin)?"admin":"user");
    }

    gotoxy(5,3);
    printf("Search Results : ");

    int y = START_POS;
    
    if(number_books_found == 0)
    {
        gotoxy(5,START_POS);
        printf("No Books Found");
        gotoxy(5,START_POS + 2);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
        printf("Back");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else
    {
       if(x == START_POS)
        {
            for(int i = 0; i < number_books; i++)
            {
                if(books[i].isbn == isbn)
                {
                    gotoxy(5,y);
                    printf("%s",books[i].title);
                    y++;
                }
            }
        }
        else if(x == START_POS + 1)
        {
            for(int i = 0; i < number_books; i++)
            {
                if(strcmp(books[i].title,title) == 0)
                {
                    gotoxy(5,y);
                    printf("%s",books[i].title);
                    y++;
                }
            }
        }
        else if(x == START_POS + 2)
        {

            for(int i = 0; i < number_books; i++)
            {
                if(strcmp(books[i].author,author) == 0)
                {
                    gotoxy(5,y);
                    printf("%s",books[i].title);
                    y++;
                }
            }
        }
        else if(x == START_POS + 3)
        {
            for(int i = 0; i < number_books; i++)
            {
                if(books[i].published_year == published_year)
                {
                    gotoxy(5,y);
                    printf("%s",books[i].title);
                    y++;
                }
            }
        } 
    }

    gotoxy(5,y + 2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    printf("Back");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    
    fflush(stdin);

    do
    {
        key = getch();
    } while (key != '\r');

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");
    

    display_main_menu();

}