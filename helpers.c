#include "helpers.h"


COORD coord = {0,0};

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showConsoleCursor(BOOL show) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(consoleHandle, &info); // Get current cursor info
    info.bVisible = show; // Set visibility
    SetConsoleCursorInfo(consoleHandle, &info); // Apply changes
}
