#include <stdlib.h>
#include <math.h>
#include "canvas.h"

void Circle(canvas_t *CanvasPtr, float centerX, float centerY, float radius, sample_color_t color)
{
    int startI = centerX - radius - 2;
    int startJ = centerY / 2 - radius - 2;
    int stopI = centerX + radius + 2;
    int stopJ = centerY / 2 + radius + 2;
    startI = startI < 0 ? 0 : startI;
    startJ = startJ < 0 ? 0 : startJ;
    stopI = stopI > CanvasPtr->x ? CanvasPtr->x : stopI;
    stopJ = stopJ > CanvasPtr->y ? CanvasPtr->y : stopJ;

    for (size_t i = startI; i < stopI; ++i)
        for (size_t j = startJ; j < stopJ; ++j)
        {
            unsigned index = j * CanvasPtr->x + i;

            // Alto
            if (sqrtf(powf(i - centerX, 2) + powf(j * 2 - centerY, 2)) - radius <= 0)
                CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0x0F) | color << 4;
            // Baixo
            if (sqrtf(powf(i - centerX, 2) + powf(j * 2 + 1 - centerY, 2)) - radius <= 0)
                CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0xF0) | color;
        }
}

void CircleOutline(canvas_t *CanvasPtr, float centerX, float centerY, float radius, sample_color_t color, float stroke)
{
    int startI = centerX - radius - stroke / 2 - 2;
    int startJ = centerY / 2 - radius - 2;
    int stopI = centerX + radius + stroke / 2 + 2;
    int stopJ = centerY / 2 + radius + stroke / 2 + 2;
    startI = startI < 0 ? 0 : startI;
    startJ = startJ < 0 ? 0 : startJ;
    stopI = stopI > CanvasPtr->x ? CanvasPtr->x : stopI;
    stopJ = stopJ > CanvasPtr->y ? CanvasPtr->y : stopJ;

    for (size_t i = startI; i < stopI; ++i)
        for (size_t j = startJ; j < stopJ; ++j)
        {
            unsigned index = j * CanvasPtr->x + i;

            // Alto
            if (fabsf(sqrtf(powf(i - centerX, 2) + powf(j * 2 - centerY, 2)) - radius) <= stroke / 2)
                CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0x0F) | color << 4;
            // Baixo
            if (fabsf(sqrtf(powf(i - centerX, 2) + powf(j * 2 + 1 - centerY, 2)) - radius) <= stroke / 2)
                CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0xF0) | color;
        }
}

void Rectangle(canvas_t *CanvasPtr, float cornerX, float cornerY, float width, float height, sample_color_t color)
{
    int startI = cornerX - 2;
    int startJ = cornerY / 2 - 2;
    int stopI = cornerX + width + 2;
    int stopJ = cornerY / 2 + height + 2;
    startI = startI < 0 ? 0 : startI;
    startJ = startJ < 0 ? 0 : startJ;
    stopI = stopI > CanvasPtr->x ? CanvasPtr->x : stopI;
    stopJ = stopJ > CanvasPtr->y ? CanvasPtr->y : stopJ;

    for (size_t i = startI; i < stopI; ++i)
        for (size_t j = startJ; j < stopJ; ++j)
        {
            unsigned index = j * CanvasPtr->x + i;

            // Alto
            if (fmaxf(fmaxf(cornerX - i, i - cornerX - width), fmaxf(cornerY - j * 2, j * 2 - cornerY - height)) <= 0)
                CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0x0F) | color << 4;
            // Baixo
            if (fmaxf(fmaxf(cornerX - i, i - cornerX - width), fmaxf(cornerY - (j * 2 + 1), j * 2 + 1 - cornerY - height)) <= 0)
                CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0xF0) | color;
        }
}

void RectangleOutline(canvas_t *CanvasPtr, float cornerX, float cornerY, float width, float height, sample_color_t color, float stroke)
{
    int startI = cornerX - stroke / 2 - 2;
    int startJ = cornerY / 2 - stroke / 2 - 2;
    int stopI = cornerX + width + stroke / 2 + 2;
    int stopJ = cornerY / 2 + height + stroke / 2 + 2;
    startI = startI < 0 ? 0 : startI;
    startJ = startJ < 0 ? 0 : startJ;
    stopI = stopI > CanvasPtr->x ? CanvasPtr->x : stopI;
    stopJ = stopJ > CanvasPtr->y ? CanvasPtr->y : stopJ;

    for (size_t i = startI; i < stopI; ++i)
        for (size_t j = startJ; j < stopJ; ++j)
        {
            unsigned index = j * CanvasPtr->x + i;

            // Alto
            if (fabsf(fmaxf(fmaxf(cornerX - i, i - cornerX - width), fmaxf(cornerY - j * 2, j * 2 - cornerY - height))) <= stroke / 2)
                CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0x0F) | color << 4;
            // Baixo
            if (fabsf(fmaxf(fmaxf(cornerX - i, i - cornerX - width), fmaxf(cornerY - (j * 2 + 1), j * 2 + 1 - cornerY - height))) <= stroke / 2)
                CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0xF0) | color;
        }
}

void Segment(canvas_t *CanvasPtr, float x1, float y1, float x2, float y2, sample_color_t color, float stroke)
{
    int startI = fminf(x1, x2) - stroke / 2 - 2;
    int startJ = fminf(y1, y2) / 2 - stroke / 2 - 2;
    int stopI = fmaxf(x1, x2) + stroke / 2 + 2;
    int stopJ = fmaxf(y1, y2) / 2 + stroke / 2 + 2;
    startI = startI < 0 ? 0 : startI;
    startJ = startJ < 0 ? 0 : startJ;
    stopI = stopI > CanvasPtr->x ? CanvasPtr->x : stopI;
    stopJ = stopJ > CanvasPtr->y ? CanvasPtr->y : stopJ;

    for (size_t i = startI; i < stopI; ++i)
        for (size_t j = startJ; j < stopJ; ++j)
        {
            unsigned index = j * CanvasPtr->x + i;

            float dx = x2 - x1, dy = y2 - y1;
            { // Alto
                float lerp = (((i - x1) * dx + (j * 2 - y1) * dy) / (dx * dx + dy * dy));
                lerp = lerp > 1 ? 1 : lerp < 0 ? 0 : lerp;
                if (sqrtf(powf(lerp * dx + x1 - i, 2) + powf(lerp * dy + y1 - j * 2, 2)) <= stroke / 2)
                    CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0x0F) | color << 4;
            }
            { // Baixo
                float lerp = (((i - x1) * dx + ((j * 2 + 1) - y1) * dy) / (dx * dx + dy * dy));
                lerp = lerp > 1 ? 1 : lerp < 0 ? 0 : lerp;
                if (sqrtf(powf(lerp * dx + x1 - i, 2) + powf(lerp * dy + y1 - (j * 2 + 1), 2)) <= stroke / 2)
                    CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0xF0) | color;
            }
        }
}

void TriangleOutline(canvas_t *CanvasPtr, float x1, float y1, float x2, float y2, float x3, float y3, sample_color_t color, float stroke)
{
    Segment(CanvasPtr, x1, y1, x2, y2, color, stroke);
    Segment(CanvasPtr, x1, y1, x3, y3, color, stroke);
    Segment(CanvasPtr, x2, y2, x3, y3, color, stroke);
}

void Triangle(canvas_t *CanvasPtr, float x1, float y1, float x2, float y2, float x3, float y3, sample_color_t color)
{
    TriangleOutline(CanvasPtr, x1, y1, x2, y2, x3, y3, color, 1);
    int startI = fminf(x1, fminf(x2, x3)) - 2;
    int startJ = fminf(y1, fminf(y2, y3)) / 2 - 2;
    int stopI = fmaxf(x1, fmax(x2, x3)) + 2;
    int stopJ = fmaxf(y1, fmax(y2, y3)) / 2 + 2;
    startI = startI < 0 ? 0 : startI;
    startJ = startJ < 0 ? 0 : startJ;
    stopI = stopI > CanvasPtr->x ? CanvasPtr->x : stopI;
    stopJ = stopJ > CanvasPtr->y ? CanvasPtr->y : stopJ;

    for (size_t i = startI; i < stopI; ++i)
        for (size_t j = startJ; j < stopJ; ++j)
        {
            unsigned index = j * CanvasPtr->x + i;

            // Se a área total é igual à área dos três triângulos que saem do ponto atual
            float area = fabsl(x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3);
            if (fabsl(i * y2 - x2 * j * 2 + x2 * y3 - x3 * y2 + x3 * j * 2 - i * y3) +
                fabsl(x1 * j * 2 - i * y1 + i * y3 - x3 * j * 2 + x3 * y1 - x1 * y3) +
                fabsl(x1 * y2 - x2 * y1 + x2 * j * 2 - i * y2 + i * y1 - x1 * j * 2) <= area)
                CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0x0F) | color << 4;
            if (fabsl(i * y2 - x2 * (j * 2 + 1) + x2 * y3 - x3 * y2 + x3 * (j * 2 + 1) - i * y3) +
                fabsl(x1 * (j * 2 + 1) - i * y1 + i * y3 - x3 * (j * 2 + 1) + x3 * y1 - x1 * y3) +
                fabsl(x1 * y2 - x2 * y1 + x2 * (j * 2 + 1) - i * y2 + i * y1 - x1 * (j * 2 + 1)) <= area)
                CanvasPtr->pixels[index] = (CanvasPtr->pixels[index] & 0xF0) | color;
        }
}