#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "color.h"
#include "console.h"





extern unsigned ConsoleX;
extern unsigned ConsoleY;



typedef struct Canvas
{
    unsigned x;
    unsigned y;
    unsigned width;
    unsigned height;
    color_t *pixels;
} canvas_t;





void FillCanvas(canvas_t *CanvasPtr, sample_color_t color)
{
    memset(CanvasPtr->pixels, (color & 0x0F) | ((color & 0x0F) << 4), sizeof(color_t) * CanvasPtr->x * CanvasPtr->y);
}



// void SetCanvasBackground(canvas_t * CanvasPtr, color_t bg_color)
// {
//     CanvasPtr->bg_color = bg_color;
// }



void ClearCanvas(canvas_t *CanvasPtr)
{
    FillCanvas(CanvasPtr, BLACK | (BLACK << 4));
}



void ShowCanvas(canvas_t *CanvasPtr)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color_t *PixelsPtr = CanvasPtr->pixels;
    color_t previous = DEFAULT;

    for (size_t i = 0; i < CanvasPtr->x * CanvasPtr->y; ++i)
    {
        if (PixelsPtr[i] != previous)
        {
            SetConsoleTextAttribute(hConsole, PixelsPtr[i]);
            previous = PixelsPtr[i];
        }
        printf("▄");
    }

    SetConsoleTextAttribute(hConsole, DEFAULT);
}





canvas_t *CreateCanvas(void)
{
    if (ConsoleX <= 0 || ConsoleY <= 0) return NULL;

    color_t *pixels = malloc(sizeof(color_t) * ConsoleX * ConsoleY);
    if (pixels == NULL) return NULL;

    canvas_t *CanvasPtr = malloc(sizeof(canvas_t));
    if (CanvasPtr == NULL) return NULL;

    CanvasPtr->x = ConsoleX;
    CanvasPtr->y = ConsoleY;
    CanvasPtr->width = ConsoleX;
    CanvasPtr->height = ConsoleY * 2;
    CanvasPtr->pixels = pixels;

    FillCanvas(CanvasPtr, BLACK);

    return CanvasPtr;
}

void DestroyCanvas(canvas_t *CanvasPtr)
{
    free(CanvasPtr->pixels);
    free(CanvasPtr);
}