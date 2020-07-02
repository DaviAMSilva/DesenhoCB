#include <windows.h>
#include <stdbool.h>
#include "color.h"



unsigned ConsoleX = -1;
unsigned ConsoleY = -1;



void ClearConsole(void) { system("cls"); }



_Bool InitConsole(void)
{
    ClearConsole();

    // chcp 65001 = UTF-8
    BOOL a = SetConsoleOutputCP(CP_UTF8);

    BOOL b = ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); // Maximizar
    // --- SetWindowLong(hCW, GWL_STYLE, GetWindowLong(hCW, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX); // Fixar tamanho

    // Definir cor padrão
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    BOOL c = SetConsoleTextAttribute(hConsole, DEFAULT);

    // Conseguir tamanho do console
    CONSOLE_SCREEN_BUFFER_INFO info;
    BOOL d = GetConsoleScreenBufferInfo(hConsole, &info);
    ConsoleX = info.srWindow.Right - info.srWindow.Left + 1;
    ConsoleY = info.srWindow.Bottom - info.srWindow.Top + 1 - 3; // !!! PRESTAR ATENÇÃO

    return a && b && c && d;
}
