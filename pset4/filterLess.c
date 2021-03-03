#include "helpers.h"
#include <math.h>


// Convert image to grayscale
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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Converting each pixel to sepia
            sepiaRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            sepiaGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            sepiaBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;
            
            // Check if red is greater than 255
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = round(sepiaRed);
            }
            
            // Check if green is greater than 255
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(sepiaGreen);
            }
            
            // Check if blue is greater than 255
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(sepiaBlue);
            }
            
        }
    }
    return;
}

// Reflect image horizontally
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
