// Copies a BMP file

//biWidth: size without padding
//biHeight: height
//biSizeImage: XxY in bytes (pixels+padding)
//bfSize: size in bites. includes everything (pixels+padding+headers)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize factor, infile, outfile\n");
        return 1;
    }

    // remember filenames
    int resizeFactor = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    if (resizeFactor<0||resizeFactor>101)
    {
        fclose(inptr);
        fprintf(stderr, "First argument, %i, must be a positive number smaller than 100\n", resizeFactor);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    BITMAPFILEHEADER newBf;
    BITMAPINFOHEADER newBi;

    newBf = bf;
    newBi = bi;

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    newBi.biWidth *= resizeFactor;
    newBi.biHeight *= resizeFactor;
    int padding2 = (4 - (newBi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    newBi.biSizeImage = ((sizeof(RGBTRIPLE) * newBi.biWidth)+padding2)*abs(newBi.biHeight);
    newBf.bfSize = newBi.biSizeImage + sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    // write outfile's BITMAPINFOHEADER
    fwrite(&newBi, sizeof(BITMAPINFOHEADER), 1, outptr);


    int lineLength = (bi.biWidth*3)+padding;
    int total = 54; // initial cursor pointer for input file skipping the header info

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++){
        // iterate over pixels in scanline
        for (int ij = 0; ij < resizeFactor; ij++){
            fseek(inptr, total, SEEK_SET);
            for (int j = 0; j < bi.biWidth; j++){
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int k=0;k<resizeFactor;k++) {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            // fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < padding2; k++){
                fputc(0x00, outptr);
            }
        }
        total = total + bi.biWidth * 3  + padding; // cursor pointer moved to another row for input file
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
