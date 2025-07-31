#include "read_write_files.h"
#include "library_data.h"

void read_user_file()
{
    FILE* user_file;
    int read;
    unsigned int len;
    char* line = NULL;

    read = 0;
    len = 0;

    user_file = fopen("users.txt","r");
    if(user_file == NULL)
    {
        printf("Could Not Open Users File\n");
        exit(1);
    }
    else
    {
        int line_index = 0;
        int user_index = 0;
        fseek(user_file, 0, SEEK_END);
        long size = ftell(user_file);

        if (size == 0)
        {
            printf("File is empty.\n");
            fclose(user_file);
            return;
        }
        rewind(user_file);
        while ((read = getline(&line, &len, user_file)) != -1)
        {
            int element_no = 1;
            int string_index = 0;
            line_index = 0;
            while(line[line_index] != '\0')
            {
                char string[100];
                while(line[line_index] != ',' && line[line_index] != '\0')
                {
                    if(line[line_index] != '\r' && line[line_index] != '\n')
                    {
                        string[string_index] = line[line_index];
                        string_index++;
                    }
                    line_index++;
                }
                if(line[line_index] != '\0')
                {
                    line_index++;
                }
                string[string_index] = '\0';
                string_index = 0;
                switch(element_no)
                {
                    case 1:
                        while(string[string_index] != '\0')
                        {
                            users[user_index].code[string_index] = string[string_index];
                            string_index++;
                        }
                        users[user_index].code[string_index] = '\0';
                        printf("%s\n", users[user_index].code);
                        break;
                    case 2:
                        while(string[string_index] != '\0')
                        {
                            users[user_index].name[string_index] = string[string_index];
                            string_index++;
                        }
                        users[user_index].name[string_index] = '\0';
                        printf("%s\n", users[user_index].name);
                        break;
                    case 3:
                        while(string[string_index] != '\0')
                        {
                            users[user_index].password[string_index] = string[string_index];
                            string_index++;
                        }
                        users[user_index].password[string_index] = '\0';
                        printf("%s\n", users[user_index].password);
                        break;
                    case 4:
                        printf("%s\n",string);
                        if(strcmp(string,"admin") == 0)
                        {
                            users[user_index].user_type= admin;
                        }
                        else
                        {
                            users[user_index].user_type= user;
                        }
                        if(users[user_index].user_type== admin)
                        {
                            printf("admin\n");
                        }
                        else
                        {
                            printf("user\n");
                        }
                        break;
                }
                element_no++;
                string_index = 0;
            }
            printf("User[%d] Finished\n", user_index);
            user_index++;
        }

        printf("Users loaded:\n");
        for (int i = 0; i < user_index; i++)
        {
            printf("Code: %s, Name: %s, Password: %s, Type: %s\n",
                users[i].code,
                users[i].name,
                users[i].password,
                users[i].user_type == admin ? "admin" : "user");
        }

        number_users = user_index;
    }
}

void read_book_file()
{
    FILE* book_file;
    int read;
    unsigned int len;
    char* line = NULL;

    read = 0;
    len = 0;

    book_file = fopen("books.txt","r");
    if(book_file == NULL)
    {
        printf("Could Not Open Books File\n");
        exit(1);
    }
    else
    {
        int line_index = 0;
        int book_index = 0;
        fseek(book_file, 0, SEEK_END);
        long size = ftell(book_file);

        if (size == 0)
        {
            printf("File is empty.\n");
            fclose(book_file);
            return;
        }
        rewind(book_file);
        while ((read = getline(&line, &len, book_file)) != -1)
        {
            int element_no = 1;
            int string_index = 0;
            line_index = 0;
            while(line[line_index] != '\0')
            {
                char string[100];
                while(line[line_index] != ',' && line[line_index] != '\0')
                {
                    if(line[line_index] != '\r' && line[line_index] != '\n')
                    {
                        string[string_index] = line[line_index];
                        string_index++;
                    }
                    line_index++;
                }
                if(line[line_index] != '\0')
                {
                    line_index++;
                }
                string[string_index] = '\0';
                string_index = 0;
                switch(element_no)
                {
                    case 1:
                        books[book_index].isbn = atoi(string);
                        printf("%d\n", books[book_index].isbn);
                        break;
                    case 2:
                        while(string[string_index] != '\0')
                        {
                            books[book_index].title[string_index] = string[string_index];
                            string_index++;
                        }
                        books[book_index].title[string_index] = '\0';
                        printf("%s\n", books[book_index].title);
                        break;
                    case 3:
                        while(string[string_index] != '\0')
                        {
                            books[book_index].author[string_index] = string[string_index];
                            string_index++;
                        }
                        books[book_index].author[string_index] = '\0';
                        printf("%s\n", books[book_index].author);
                        break;
                    case 4:
                        books[book_index].published_year = atoi(string);
                        printf("%d\n", books[book_index].published_year);
                        break;
                    case 5:
                        books[book_index].number_copies = atoi(string);
                        printf("%d\n", books[book_index].number_copies);
                        break;
                }
                element_no++;
                string_index = 0;
            }
            printf("Book[%d] Finished\n", book_index);
            book_index++;
        }

        number_books = book_index;

        printf("Books Loaded:\n");
        for (int i = 0; i < number_books; i++)
        {
            printf("Book[%d]: ISBN: %d, Title: %s, Author: %s, Year: %d, Copies: %d\n",
                i,
                books[i].isbn,
                books[i].title,
                books[i].author,
                books[i].published_year,
                books[i].number_copies);
        }
    }
}

void read_borrowed_book_file()
{
    FILE* borrowed_book_file;
    int read;
    unsigned int len;
    char* line = NULL;

    read = 0;
    len = 0;

    borrowed_book_file = fopen("borrowed_books.txt","r");
    if(borrowed_book_file == NULL)
    {
        printf("Could Not Open Borrowed Books File\n");
        exit(1);
    }
    else
    {
        int line_index = 0;
        int borrowed_book_index = 0;
        fseek(borrowed_book_file, 0, SEEK_END);
        long size = ftell(borrowed_book_file);

        if (size == 0)
        {
            printf("File is empty.\n");
            fclose(borrowed_book_file);
            return;
        }
        rewind(borrowed_book_file);
        while ((read = getline(&line, &len, borrowed_book_file)) != -1)
        {
            int element_no = 1;
            int string_index = 0;
            line_index = 0;
            while(line[line_index] != '\0')
            {
                char string[100];
                while(line[line_index] != ',' && line[line_index] != '\0')
                {
                    if(line[line_index] != '\r' && line[line_index] != '\n')
                    {
                        string[string_index] = line[line_index];
                        string_index++;
                    }
                    line_index++;
                }
                if(line[line_index] != '\0')
                {
                    line_index++;
                }
                string[string_index] = '\0';
                string_index = 0;
                switch(element_no)
                {
                    case 1:
                        while(string[string_index] != '\0')
                        {
                            borrowed_books[borrowed_book_index].user_code[string_index] = string[string_index];
                            string_index++;
                        }
                        borrowed_books[borrowed_book_index].user_code[string_index] = '\0';
                        printf("%s\n", borrowed_books[borrowed_book_index].user_code);
                        break;
                    case 2:
                        borrowed_books[borrowed_book_index].book_isbn = atoi(string);
                        printf("%d\n", borrowed_books[borrowed_book_index].book_isbn);
                        break;
                    case 3:
                        while(string[string_index] != '\0')
                        {
                            borrowed_books[borrowed_book_index].book_title[string_index] = string[string_index];
                            string_index++;
                        }
                        borrowed_books[borrowed_book_index].book_title[string_index] = '\0';
                        printf("%s\n", borrowed_books[borrowed_book_index].book_title);
                        break;
                    case 4:
                        while(string[string_index] != '\0')
                        {
                            borrowed_books[borrowed_book_index].book_author[string_index] = string[string_index];
                            string_index++;
                        }
                        borrowed_books[borrowed_book_index].book_author[string_index] = '\0';
                        printf("%s\n", borrowed_books[borrowed_book_index].book_author);
                        break;
                    case 5:
                        borrowed_books[borrowed_book_index].book_published_year = atoi(string);
                        printf("%d\n", borrowed_books[borrowed_book_index].book_published_year);
                        break;
                }
                element_no++;
                string_index = 0;
            }
            printf("Borrowed_Book[%d] Finished\n", borrowed_book_index);
            borrowed_book_index++;
        }

        number_borrowed_books = borrowed_book_index;
    }
}

void update_book_file()
{
    FILE* book_file = fopen("books.txt", "w");
    if (book_file == NULL)
    {
        printf("Could not open books file for writing\n");
        return;
    }

    for (int i = 0; i < number_books; i++)
    {
        fprintf(book_file, "%d,%s,%s,%d,%d\n",
            books[i].isbn,
            books[i].title,
            books[i].author,
            books[i].published_year,
            books[i].number_copies);
    }

    fclose(book_file);
}

void update_borrow_books_file()
{
    FILE* book_file = fopen("borrowed_books.txt", "w");
    if (book_file == NULL)
    {
        printf("Could not open books file for writing\n");
        return;
    }

    for (int i = 0; i < number_borrowed_books; i++)
    {
        fprintf(book_file, "%s,%d,%s,%s,%d\n",
            borrowed_books[i].user_code,
            borrowed_books[i].book_isbn,
            borrowed_books[i].book_title,
            borrowed_books[i].book_author,
            borrowed_books[i].book_published_year);
    }

    fclose(book_file);
}