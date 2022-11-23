#include "helpers.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int t = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = t;
            image[i][j].rgbtGreen = t;
            image[i][j].rgbtRed = t;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width/2); j++)
        {
            // Create a temporary value for firsts pixels
            int t_Blue = image[i][j].rgbtBlue;
            int t_Green = image[i][j].rgbtGreen;
            int t_Red = image[i][j].rgbtRed;

            // Change lasts pixels to firsts
            image[i][j].rgbtBlue = image[i][width - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j].rgbtRed;

            // Use temporary value to replace lasts pixels
            image[i][width - j].rgbtBlue = t_Blue;
            image[i][width - j].rgbtGreen = t_Green;
            image[i][width - j].rgbtRed = t_Red;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0, t_Blue = 0, t_Green = 0, t_Red = 0;

            // top left diagonal pixel
            if (&image[i - 1][j - 1] >= &image[0][0] && &image[i - 1][j - 1] <= &image[height][width])
            {
                t_Blue += image[i - 1][j - 1].rgbtBlue;
                t_Green += image[i - 1][j - 1].rgbtGreen;
                t_Red += image[i - 1][j - 1].rgbtRed;

                count++;
                //printf("top left diagonal pixel \n");
            }
            // top pixel
            if (&image[i - 1][j] >= &image[0][0] && &image[i - 1][j - 1] <= &image[height][width])
            {
                t_Blue += image[i - 1][j].rgbtBlue;
                t_Green += image[i - 1][j].rgbtGreen;
                t_Red += image[i - 1][j].rgbtRed;

                count++;
                //printf("top pixel \n");
            }
            // top right diagonal pixel
            if (&image[i - 1][j + 1] >= &image[0][0] && &image[i - 1][j - 1] <= &image[height][width])
            {
                t_Blue += image[i - 1][j + 1].rgbtBlue;
                t_Green += image[i - 1][j + 1].rgbtGreen;
                t_Red += image[i - 1][j + 1].rgbtRed;

                count++;
                //printf("top right diagonal pixel \n");
            }
            // left pixel
            if (&image[i][j - 1] >= &image[0][0] && &image[i - 1][j - 1] <= &image[height][width])
            {
                t_Blue += image[i][j - 1].rgbtBlue;
                t_Green += image[i][j - 1].rgbtGreen;
                t_Red += image[i][j - 1].rgbtRed;

                count++;
                //printf("left pixel pixel \n");
            }
            // center pixel
            if (&image[i][j] >= &image[0][0] && &image[i - 1][j - 1] <= &image[height][width])
            {
                t_Blue += image[i][j].rgbtBlue;
                t_Green += image[i][j].rgbtGreen;
                t_Red += image[i][j].rgbtRed;

                count++;
                //printf("center pixel pixel \n");
            }
            // right pixel
            if (&image[i][j + 1] >= &image[0][0] && &image[i - 1][j - 1] <= &image[height][width])
            {
                t_Blue += image[i][j + 1].rgbtBlue;
                t_Green += image[i][j + 1].rgbtGreen;
                t_Red += image[i][j + 1].rgbtRed;

                count++;
            }
            // bottom left diagonal pixel
            if (&image[i + 1][j - 1] >= &image[0][0] && &image[i - 1][j - 1] <= &image[height][width])
            {
                t_Blue += image[i + 1][j - 1].rgbtBlue;
                t_Green += image[i + 1][j - 1].rgbtGreen;
                t_Red += image[i + 1][j - 1].rgbtRed;

                count++;
            }
            // bottom pixel
            if (&image[i + 1][j] >= &image[0][0] && &image[i - 1][j - 1] <= &image[height][width])
            {
                t_Blue += image[i + 1][j].rgbtBlue;
                t_Green += image[i + 1][j].rgbtGreen;
                t_Red += image[i + 1][j].rgbtRed;

                count++;
            }
            // bottom right diagonal pixel
            if (&image[i + 1][j + 1] >= &image[0][0] && &image[i - 1][j - 1] <= &image[height][width])
            {
                t_Blue += image[i + 1][j + 1].rgbtBlue;
                t_Green += image[i + 1][j + 1].rgbtGreen;
                t_Red += image[i + 1][j + 1].rgbtRed;

                count++;
            }

            //printf("count é %i \n", count);

            // Calculate blue pixel value
            image[i][j].rgbtBlue = t_Blue / count;
            if (image[i][j].rgbtBlue < 0)
            {
                image[i][j].rgbtBlue = 0;
            }
            else if (image[i][j].rgbtBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }

            // Calculate green pixel value
            image[i][j].rgbtGreen = t_Green / count;
            if (image[i][j].rgbtGreen < 0)
            {
                image[i][j].rgbtGreen = 0;
            }
            else if (image[i][j].rgbtGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }

            // Calculate red pixel value
            image[i][j].rgbtRed = t_Red / count;
             if (image[i][j].rgbtRed < 0)
            {
                image[i][j].rgbtRed = 0;
            }
            else if (image[i][j].rgbtRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            //printf("Valor do pixel azul é %i, do pixel verde é %i e do pixel vermelho %i \n", image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_buffer[height][width];

    // Gx top left diagonal pixel value
    int Gx_top_left_diagonal = - 1;
    // Gx top left diagonal pixel value
    int Gy_top_left_diagonal = - 1;
    // Gx top pixel value
    int Gx_top = 0;
    // Gy top pixel value
    int Gy_top = - 2;
    // Gx top right diagonal pixel value
    int Gx_top_right_diagonal = 1;
    // Gy top right diagonal pixel value
    int Gy_top_right_diagonal = - 1;
    // Gx left pixel value
    int Gx_left = - 2;
    // Gy left pixel value
    int Gy_left = 0;
    // Gx right pixel value
    int Gx_right = 2;
    // Gy right pixel value
    int Gy_right = 0;
    // Gx bottom left diagonal pixel value
    int Gx_bottom_left_diagonal = - 1;
    // Gy bottom left diagonal pixel value
    int Gy_bottom_left_diagonal = 1;
    // Gx bottom pixel value
    int Gx_bottom = 0;
    // Gy bottom pixel value
    int Gy_bottom = 2;
    // Gx bottom right diagonal pixel value
    int Gx_bottom_right_diagonal = 1;
    // Gy bottom right diagonal pixel value
    int Gy_bottom_right_diagonal = 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Gx_Blue = 0, Gy_Blue = 0, Gx_Green = 0, Gy_Green = 0, Gx_Red = 0, Gy_Red = 0;

            // top left diagonal pixel
            if (&image[i - 1][j - 1] >= &image[0][0] && &image[i + 1][j + 1] <= &image[height][width])
            {
                Gx_Blue += image[i - 1][j - 1].rgbtBlue * Gx_top_left_diagonal;
                Gx_Green += image[i - 1][j - 1].rgbtGreen * Gx_top_left_diagonal;
                Gx_Red += image[i - 1][j - 1].rgbtRed * Gx_top_left_diagonal;

                Gy_Blue =+ image[i - 1][j - 1].rgbtBlue * Gy_top_left_diagonal;
                Gy_Green =+ image[i - 1][j - 1].rgbtGreen * Gy_top_left_diagonal;
                Gy_Red =+ image[i - 1][j - 1].rgbtRed * Gy_top_left_diagonal;
            }

            // top pixel
            if (&image[i - 1][j - 1] >= &image[0][0] && &image[i + 1][j + 1] <= &image[height][width])
            {
                Gx_Blue += image[i - 1][j].rgbtBlue * Gx_top;
                Gx_Green += image[i - 1][j].rgbtGreen * Gx_top;
                Gx_Red += image[i - 1][j].rgbtRed * Gx_top;

                Gy_Blue =+ image[i - 1][j].rgbtBlue * Gy_top;
                Gy_Green =+ image[i - 1][j].rgbtGreen * Gy_top;
                Gy_Red =+ image[i - 1][j].rgbtRed * Gy_top;
            }

            // top right diagonal pixel
            if (&image[i - 1][j - 1] >= &image[0][0] && &image[i + 1][j + 1] <= &image[height][width])
            {
                Gx_Blue += image[i - 1][j + 1].rgbtBlue * Gx_top_right_diagonal;
                Gx_Green += image[i - 1][j + 1].rgbtGreen * Gx_top_right_diagonal;
                Gx_Red += image[i - 1][j + 1].rgbtRed * Gx_top_right_diagonal;

                Gy_Blue =+ image[i - 1][j + 1].rgbtBlue * Gy_top_right_diagonal;
                Gy_Green =+ image[i - 1][j + 1].rgbtGreen * Gy_top_right_diagonal;
                Gy_Red =+ image[i - 1][j + 1].rgbtRed * Gy_top_right_diagonal;
            }

            // left pixel
            if (&image[i - 1][j - 1] >= &image[0][0] && &image[i + 1][j + 1] <= &image[height][width])
            {
                Gx_Blue += image[i][j - 1].rgbtBlue * Gx_left;
                Gx_Green += image[i][j - 1].rgbtGreen * Gx_left;
                Gx_Red += image[i][j - 1].rgbtRed * Gx_left;

                Gy_Blue =+ image[i][j - 1].rgbtBlue * Gy_left;
                Gy_Green =+ image[i][j - 1].rgbtGreen * Gy_left;
                Gy_Red =+ image[i][j - 1].rgbtRed * Gy_left;
            }

            // right pixel
            if (&image[i - 1][j - 1] >= &image[0][0] && &image[i + 1][j + 1] <= &image[height][width])
            {
                Gx_Blue += image[i][j + 1].rgbtBlue * Gx_right;
                Gx_Green += image[i][j + 1].rgbtGreen * Gx_right;
                Gx_Red += image[i][j + 1].rgbtRed * Gx_right;

                Gy_Blue =+ image[i][j + 1].rgbtBlue * Gy_right;
                Gy_Green =+ image[i][j + 1].rgbtGreen * Gy_right;
                Gy_Red =+ image[i][j + 1].rgbtRed * Gy_right;
            }

            // bottom left diagonal pixel
            if (&image[i - 1][j - 1] >= &image[0][0] && &image[i + 1][j + 1] <= &image[height][width])
            {
                Gx_Blue += image[i + 1][j - 1].rgbtBlue * Gx_bottom_left_diagonal;
                Gx_Green += image[i + 1][j - 1].rgbtGreen * Gx_bottom_left_diagonal;
                Gx_Red += image[i + 1][j - 1].rgbtRed * Gx_bottom_left_diagonal;

                Gy_Blue =+ image[i + 1][j - 1].rgbtBlue * Gy_bottom_left_diagonal;
                Gy_Green =+ image[i + 1][j - 1].rgbtGreen * Gy_bottom_left_diagonal;
                Gy_Red =+ image[i + 1][j - 1].rgbtRed * Gy_bottom_left_diagonal;
            }

            // bottom pixel
            if (&image[i - 1][j - 1] >= &image[0][0] && &image[i + 1][j + 1] <= &image[height][width])
            {
                Gx_Blue += image[i + 1][j].rgbtBlue * Gx_bottom;
                Gx_Green += image[i + 1][j].rgbtGreen * Gx_bottom;
                Gx_Red += image[i + 1][j].rgbtRed * Gx_bottom;

                Gy_Blue =+ image[i + 1][j].rgbtBlue * Gy_bottom;
                Gy_Green =+ image[i + 1][j].rgbtGreen * Gy_bottom;
                Gy_Red =+ image[i + 1][j].rgbtRed * Gy_bottom;
            }

            // bottom right diagonal pixel
            if (&image[i - 1][j - 1] >= &image[0][0] && &image[i + 1][j + 1] <= &image[height][width])
            {
                Gx_Blue += image[i + 1][j + 1].rgbtBlue * Gx_bottom_right_diagonal;
                Gx_Green += image[i + 1][j + 1].rgbtGreen * Gx_bottom_right_diagonal;
                Gx_Red += image[i + 1][j + 1].rgbtRed * Gx_bottom_right_diagonal;

                Gy_Blue =+ image[i + 1][j + 1].rgbtBlue * Gy_bottom_right_diagonal;
                Gy_Green =+ image[i + 1][j + 1].rgbtGreen * Gy_bottom_right_diagonal;
                Gy_Red =+ image[i + 1][j + 1].rgbtRed * Gy_bottom_right_diagonal;
            }

            int avgRed = 0, avgGreen = 0, avgBlue = 0;

            // Calculate blue pixel value
            avgBlue = (Gx_Blue ^ 2 + Gy_Blue ^ 2) ^ (1/2);
            if ( avgBlue < 0)
            {
                 avgBlue = 0;
            }
            else if ( avgBlue > 255)
            {
                 avgBlue = 255;
            }

            // Calculate blue pixel value
            avgGreen = (Gx_Green ^ 2 + Gy_Green ^ 2) ^ (1/2);
            if (avgGreen < 0)
            {
                avgGreen = 0;
            }
            else if (avgGreen > 255)
            {
                avgGreen = 255;
            }

            // Calculate blue pixel value
            avgRed = (Gx_Red ^ 2 + Gy_Red ^ 2) ^ (1/2);
            if (avgRed < 0)
            {
                avgRed = 0;
            }
            else if (avgRed > 255)
            {
                avgRed = 255;
            }

            image_buffer[i][j].rgbtBlue = avgBlue;
            image_buffer[i][j].rgbtGreen = avgGreen;
            image_buffer[i][j].rgbtRed = avgRed;
        }
    }

    // Take buffer to final variable
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = image_buffer[i][j].rgbtBlue;
            image[i][j].rgbtGreen = image_buffer[i][j].rgbtGreen;
            image[i][j].rgbtRed = image_buffer[i][j].rgbtRed;
        }
    }

    return;
}