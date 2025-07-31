#ifndef HELPERS_H_
#define HELPERS_H_

#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define START_POS       5

extern COORD coord;

void gotoxy(int x, int y);

void showConsoleCursor(BOOL show);

#endif // HELPERS_H_
