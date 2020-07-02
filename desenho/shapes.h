#pragma once

#include "canvas.h"
#include "color.h"



void Circle(canvas_t *CanvasPtr, float centerX, float centerY, float radius, sample_color_t color);

void CircleOutline(canvas_t *CanvasPtr, float centerX, float centerY, float radius, sample_color_t color, float stroke);

void Rectangle(canvas_t *CanvasPtr, float cornerX, float cornerY, float width, float height, sample_color_t color);

void RectangleOutline(canvas_t *CanvasPtr, float cornerX, float cornerY, float width, float height, sample_color_t color, float stroke);

void Segment(canvas_t * CanvasPtr, float x1, float y1, float x2, float y2, sample_color_t color, float stroke);

void TriangleOutline(canvas_t *CanvasPtr, float x1, float y1, float x2, float y2, float x3, float y3, sample_color_t color, float stroke);

void Triangle(canvas_t *CanvasPtr, float x1, float y1, float x2, float y2, float x3, float y3, sample_color_t color);