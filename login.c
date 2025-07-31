#include "login.h"
#include "library_data.h"
#include "main_menu.h"

void login()
{
    char username[100];

    char password[20];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");

    printf("Enter Username and Password");

    gotoxy(0,START_POS);

    showConsoleCursor(TRUE);

    printf("Enter Username : ");
    gets(username);

    printf("Enter Password : ");
    gets(password);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");

    int user_found_index = -1;

    for(int i = 0; i < number_users; i++)
    {
        if(strcmp(users[i].name,username) == 0)
        {
            if(strcmp(users[i].password,password) == 0)
            {
                user_found_index = i;
                break;
            }
        }
    }


    if(user_found_index != -1)
    {
        gotoxy(5,1);
        printf("Username : %-30sType : %-30s", username,(users[user_found_index].user_type == admin)?"admin":"user");
        current_user_index = user_found_index;
        strcpy(current_user_name,username);
        current_user_type = users[user_found_index].user_type;
    }

    else
    {
        gotoxy(5,3);
        printf("Inalid Username or Password");
        current_user_index = -1;
    }

    showConsoleCursor(FALSE);

    display_main_menu();
}