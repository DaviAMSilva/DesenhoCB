#pragma once

typedef enum Color
{
    BLACK       = 0x00,
    DARK_BLUE   = 0x01,
    DARK_GREEN  = 0x02,
    DARK_CYAN   = 0x03,
    DARK_RED    = 0x04,
    PURPLE      = 0x05,
    DARK_YELLOW = 0x06,
    LIGHT_GRAY  = 0x07,
    GRAY        = 0x08,
    BLUE        = 0x09,
    GREEN       = 0x0A,
    CYAN        = 0x0B,
    RED         = 0x0C,
    PINK        = 0x0D,
    YELLOW      = 0x0E,
    WHITE       = 0x0F,
    DEFAULT     = 0x0F
} sample_color_t;



typedef unsigned char color_t;



color_t GetFullColor(sample_color_t bg, sample_color_t fg);


// typedef enum Shape
// {
//     BLANK  = 0x00,
//     BOTTOM = 0x10,
//     TOP    = 0x20,
//     FULL   = 0x30
// } shape_t;
