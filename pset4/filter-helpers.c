#include "helpers.h"
#include <math.h>
#include <stdio.h>

//Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avgColor;
    //sweep each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Finds average of RGB values and assigns the same value for each color
            avgColor = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = avgColor;
            image[i][j].rgbtBlue = avgColor;
            image[i][j].rgbtGreen = avgColor;
        }
    }
    return;
}

//Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp_w;
    int midle = width / 2;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < midle; j ++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // populate temporary image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // sweep each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // reset colors and count for each pixel
            float r = 0;
            float g = 0;
            float b = 0;
            int count = 0;

            // for each pixel sweep 3x3 grid around it
            for (int ii = -1; ii < 2; ii++)
            {
                for (int jj = -1; jj < 2; jj++)
                {
                    //condition to include only existing positions of 3x3 grid if the center pixel is at the edge or borders
                    if (i + ii >= 0 && i + ii < height && j + jj >= 0 && j + jj < width)
                    {
                        r += temp[i + ii][j + jj].rgbtRed;
                        g += temp[i + ii][j + jj].rgbtGreen;
                        b += temp[i + ii][j + jj].rgbtBlue;
                        count++;
                    }
                }
            }
            // insert new values of RGB color for blurred image
            image[i][j].rgbtRed = round(r / count);
            image[i][j].rgbtGreen = round(g / count);
            image[i][j].rgbtBlue = round(b / count);
        }
    }
    return;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width];
    // Populate temporary image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Create Gx and Gy grids for Sobel operator
    int grid[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    // Sweep each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // reset colors and count for each pixel
            float rx = 0;
            float gx = 0;
            float bx = 0;

            float ry = 0;
            float gy = 0;
            float by = 0;

            // for each pixel sweep 3x3 grid around it
            for (int ii = -1; ii < 2; ii++)
            {
                for (int jj = -1; jj < 2; jj++)
                {
                    //condition to include only existing positions of 3x3 grid if the center pixel is at the edge or borders
                    if (i + ii >= 0 && i + ii < height && j + jj >= 0 && j + jj < width)
                    {
                        rx += grid[ii + 1][jj + 1] * temp[i + ii][j + jj].rgbtRed;
                        gx += grid[ii + 1][jj + 1] * temp[i + ii][j + jj].rgbtGreen;
                        bx += grid[ii + 1][jj + 1] * temp[i + ii][j + jj].rgbtBlue;

                        ry += grid[jj + 1][ii + 1] * temp[i + ii][j + jj].rgbtRed;
                        gy += grid[jj + 1][ii + 1] * temp[i + ii][j + jj].rgbtGreen;
                        by += grid[jj + 1][ii + 1] * temp[i + ii][j + jj].rgbtBlue;
                    }
                }
            }

            float rxy = sqrt(pow(rx, 2) + pow(ry, 2));
            float gxy = sqrt(pow(gx, 2) + pow(gy, 2));
            float bxy = sqrt(pow(bx, 2) + pow(by, 2));

            if (rxy > 255)
            {
                rxy =  255;
            }
            if (gxy > 255)
            {
                gxy =  255;
            }
            if (bxy > 255)
            {
                bxy =  255;
            }

            image[i][j].rgbtRed = round(rxy);
            image[i][j].rgbtGreen = round(gxy);
            image[i][j].rgbtBlue = round(bxy);
        }
    }
    return;
}
