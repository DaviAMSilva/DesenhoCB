#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>

#include "desenho/color.h"
#include "desenho/console.h"
#include "desenho/canvas.h"
#include "desenho/shapes.h"

int main(void)
{
    srand(time(NULL));

    if (!InitConsole()) return 1;

    canvas_t *CanvasPtr = CreateCanvas();
    if (CanvasPtr == NULL) return 1;

    const unsigned width = CanvasPtr->width;
    const unsigned height = CanvasPtr->height;



    // *** Formas aleatórias

    RectangleOutline(CanvasPtr, rand() % width, rand() % height, rand() % (width / 2), rand() % (height / 2), 1, rand() % 5 + 1);
    RectangleOutline(CanvasPtr, rand() % width, rand() % height, rand() % (width / 2), rand() % (height / 2), 2, rand() % 5 + 1);
    TriangleOutline(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, 3, rand() % 5 + 1);
    TriangleOutline(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, 4, rand() % 5 + 1);
    CircleOutline(CanvasPtr, rand() % width / 2, rand() % height, rand() % (height / 2), 5, rand() % 5 + 1);
    CircleOutline(CanvasPtr, rand() % width / 2, rand() % height, rand() % (height / 2), 6, rand() % 5 + 1);
    Rectangle(CanvasPtr, rand() % width, rand() % height, rand() % (width / 2), rand() % (height / 2), 7);
    Rectangle(CanvasPtr, rand() % width, rand() % height, rand() % (width / 2), rand() % (height / 2), 8);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, 9);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, 10);
    Circle(CanvasPtr, rand() % width / 2, rand() % height, rand() % (height / 2), 11);
    Circle(CanvasPtr, rand() % width / 2, rand() % height, rand() % (height / 2), 12);
    Segment(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, 13, rand() % 5 + 1);
    Segment(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, 14, rand() % 5 + 1);
    Segment(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, 15, rand() % 5 + 1);
    Segment(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height,  0, rand() % 5 + 1);

    ShowCanvas(CanvasPtr);



    // *** Triângulos
    /*
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, DARK_BLUE);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, DARK_GREEN);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, DARK_CYAN);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, DARK_RED);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, PURPLE);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, DARK_YELLOW);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, LIGHT_GRAY);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, GRAY);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, BLUE);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, GREEN);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, CYAN);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, RED);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, PINK);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, YELLOW);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, WHITE);
    Triangle(CanvasPtr, rand() % width, rand() % height, rand() % width, rand() % height, rand() % width, rand() % height, BLACK);

    ShowCanvas(CanvasPtr);
    */



    // *** Pixels aleatórios
    /*
    for (size_t i = 0; i < CanvasPtr->x * CanvasPtr->y; ++i)
    {
        CanvasPtr->pixels[i] = rand() % 256;
    }

    ShowCanvas(CanvasPtr);
    */



    // *** Logo das Olimpíadas
    /*
    int width = CanvasPtr->width, height = CanvasPtr->height;
    int r = width * 0.155;

    FillCanvas(CanvasPtr, WHITE);

    CircleOutline(CanvasPtr,   r,                             r,            r,   BLUE,     10);
    CircleOutline(CanvasPtr,   width / 2,                     r,            r,   BLACK,    10);
    CircleOutline(CanvasPtr,   width - r,                     r,            r,   RED,      10);

    CircleOutline(CanvasPtr,   (width + r * 2) / 4,           height - r,   r,   YELLOW,   10);
    CircleOutline(CanvasPtr,   width - (width + r * 2) / 4,   height - r,   r,   GREEN,    10);

    ShowCanvas(CanvasPtr);
    */



    DestroyCanvas(CanvasPtr);

    return 0;
}
