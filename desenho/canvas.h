#pragma once
#include "color.h"



typedef struct Canvas
{
    unsigned x;
    unsigned y;
    unsigned width;
    unsigned height;
    color_t *pixels;
} canvas_t;



void FillCanvas(canvas_t *CanvasPtr, color_t color);

void ClearCanvas(canvas_t *CanvasPtr);

void ShowCanvas(canvas_t *CanvasPtr);

canvas_t *CreateCanvas(void);

void DestroyCanvas(canvas_t *CanvasPtr);