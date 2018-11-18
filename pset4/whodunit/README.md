# Questions

## What's `stdint.h`?

The <stdint.h> header shall declare sets of integer types having specified widths, and shall define corresponding sets of macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To let the program know the length of numbers we want to be dealing with (8 bits, 32 bits, etc). Further, by utilizing U (unsigned), we also define that a number will be positive. In the case of uint8, positive from 0 to 255 (a number we need to specify colors.)

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

`BYTE` - 1 byte
`DWORD` - 4 bytes
`LONG` - 4 bytes
`WORD` - 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

B and M

## What's the difference between `bfSize` and `biSize`?

bfSize - The size, in bytes, of the bitmap file.
biSize - bfSize - the headers

## What does it mean if `biHeight` is negative?

The height of the bitmap, in pixels. If biHeight is positive, the bitmap is a bottom-up DIB and its origin is the lower-left corner. If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

File could not be opened, file could not be created. Maybe worng file extension.

## Why is the third argument to `fread` always `1` in our code?

Indicates the number of times we want to read it. Only 1.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

int padding = 3


## What does `fseek` do?

Offsets the pointer where a file start to be read.

## What is `SEEK_CUR`?

It lets you offset the pointer counting away from the current pointer position.

## Whodunit?

It was professor Plum with the candlestick in the library
