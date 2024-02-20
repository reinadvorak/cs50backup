#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int average = round((float) (image[h][w].rgbtRed + image[h][w].rgbtBlue + image[h][w].rgbtGreen) / 3);
            image[h][w].rgbtRed = average;
            image[h][w].rgbtBlue = average;
            image[h][w].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaBlue;
    int sepiaGreen;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            sepiaRed = round(.393 * (float) image[h][w].rgbtRed + .769 * (float) image[h][w].rgbtGreen +
                             .189 * (float) image[h][w].rgbtBlue);
            sepiaGreen = round(.349 * (float) image[h][w].rgbtRed + .686 * (float) image[h][w].rgbtGreen +
                               .168 * (float) image[h][w].rgbtBlue);
            sepiaBlue = round(.272 * (float) image[h][w].rgbtRed + .534 * (float) image[h][w].rgbtGreen +
                              .131 * (float) image[h][w].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            temp = image[h][w];
            image[h][w] = image[h][width - 1 - w];
            image[h][width - 1 - w] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int blurRed[height][width];
    int blurGreen[height][width];
    int blurBlue[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            if (h == 0 || w == 0 || h == (height - 1) || w == (width - 1))
            {
                if (h == 0)
                {
                    if (w == 0 || w == (width - 1))
                    {
                        if (w == 0)
                        {
                            blurRed[h][w] = round((float) (image[h][w].rgbtRed + image[h][w + 1].rgbtRed + image[h + 1][w].rgbtRed +
                                                           image[h + 1][w + 1].rgbtRed) /
                                                  4);
                            blurGreen[h][w] = round((float) (image[h][w].rgbtGreen + image[h][w + 1].rgbtGreen +
                                                             image[h + 1][w].rgbtGreen + image[h + 1][w + 1].rgbtGreen) /
                                                    4);
                            blurBlue[h][w] = round((float) (image[h][w].rgbtBlue + image[h][w + 1].rgbtBlue +
                                                            image[h + 1][w].rgbtBlue + image[h + 1][w + 1].rgbtBlue) /
                                                   4);
                        }
                        if (w == (width - 1))
                        {
                            blurRed[h][w] = round((float) (image[h][w - 1].rgbtRed + image[h][w].rgbtRed +
                                                           image[h + 1][w - 1].rgbtRed + image[h + 1][w].rgbtRed) /
                                                  4);
                            blurGreen[h][w] = round((float) (image[h][w - 1].rgbtGreen + image[h][w].rgbtGreen +
                                                             image[h + 1][w - 1].rgbtGreen + image[h + 1][w].rgbtGreen) /
                                                    4);
                            blurBlue[h][w] = round((float) (image[h][w - 1].rgbtBlue + image[h][w].rgbtBlue +
                                                            image[h + 1][w - 1].rgbtBlue + image[h + 1][w].rgbtBlue) /
                                                   4);
                        }
                    }
                    else
                    {
                        blurRed[h][w] =
                            round((float) (image[h][w - 1].rgbtRed + image[h][w].rgbtRed + image[h][w + 1].rgbtRed +
                                           image[h + 1][w - 1].rgbtRed + image[h + 1][w].rgbtRed + image[h + 1][w + 1].rgbtRed) /
                                  6);
                        blurGreen[h][w] = round((float) (image[h][w - 1].rgbtGreen + image[h][w].rgbtGreen +
                                                         image[h][w + 1].rgbtGreen + image[h + 1][w - 1].rgbtGreen +
                                                         image[h + 1][w].rgbtGreen + image[h + 1][w + 1].rgbtGreen) /
                                                6);
                        blurBlue[h][w] =
                            round((float) (image[h][w - 1].rgbtBlue + image[h][w].rgbtBlue + image[h][w + 1].rgbtBlue +
                                           image[h + 1][w - 1].rgbtBlue + image[h + 1][w].rgbtBlue + image[h + 1][w + 1].rgbtBlue) /
                                  6);
                    }
                }
                else
                {
                    if (w == 0)
                    {
                        if (h == (height - 1))
                        {
                            blurRed[h][w] = round((float) (image[h - 1][w].rgbtRed + image[h - 1][w + 1].rgbtRed +
                                                           image[h][w].rgbtRed + image[h][w + 1].rgbtRed) /
                                                  4);
                            blurGreen[h][w] = round((float) (image[h - 1][w].rgbtGreen + image[h - 1][w + 1].rgbtGreen +
                                                             image[h][w].rgbtGreen + image[h][w + 1].rgbtGreen) /
                                                    4);
                            blurBlue[h][w] = round((float) (image[h - 1][w].rgbtBlue + image[h - 1][w + 1].rgbtBlue +
                                                            image[h][w].rgbtBlue + image[h][w + 1].rgbtBlue) /
                                                   4);
                        }
                        else
                        {
                            blurRed[h][w] =
                                round((float) (image[h - 1][w].rgbtRed + image[h - 1][w + 1].rgbtRed + image[h][w].rgbtRed +
                                               image[h][w + 1].rgbtRed + image[h + 1][w].rgbtRed + image[h + 1][w + 1].rgbtRed) /
                                      6);
                            blurGreen[h][w] = round((float) (image[h - 1][w].rgbtGreen + image[h - 1][w + 1].rgbtGreen +
                                                             image[h][w].rgbtGreen + image[h][w + 1].rgbtGreen +
                                                             image[h + 1][w].rgbtGreen + image[h + 1][w + 1].rgbtGreen) /
                                                    6);
                            blurBlue[h][w] =
                                round((float) (image[h - 1][w].rgbtBlue + image[h - 1][w + 1].rgbtBlue + image[h][w].rgbtBlue +
                                               image[h][w + 1].rgbtBlue + image[h + 1][w].rgbtBlue + image[h + 1][w + 1].rgbtBlue) /
                                      6);
                        }
                    }
                    else
                    {
                        if (h == (height - 1) && w == (width - 1))
                        {
                            blurRed[h][w] = round((float) (image[h - 1][w - 1].rgbtRed + image[h - 1][w].rgbtRed +
                                                           image[h][w - 1].rgbtRed + image[h][w].rgbtRed) /
                                                  4);
                            blurGreen[h][w] = round((float) (image[h - 1][w - 1].rgbtGreen + image[h - 1][w].rgbtGreen +
                                                             image[h][w - 1].rgbtGreen + image[h][w].rgbtGreen) /
                                                    4);
                            blurBlue[h][w] = round((float) (image[h - 1][w - 1].rgbtBlue + image[h - 1][w].rgbtBlue +
                                                            image[h][w - 1].rgbtBlue + image[h][w].rgbtBlue) /
                                                   4);
                        }
                        else
                        {
                            if (h == (height - 1))
                            {
                                blurRed[h][w] = round((float) (image[h - 1][w - 1].rgbtRed + image[h - 1][w].rgbtRed +
                                                               image[h - 1][w + 1].rgbtRed + image[h][w - 1].rgbtRed +
                                                               image[h][w].rgbtRed + image[h][w + 1].rgbtRed) /
                                                      6);
                                blurGreen[h][w] = round((float) (image[h - 1][w - 1].rgbtGreen + image[h - 1][w].rgbtGreen +
                                                                 image[h - 1][w + 1].rgbtGreen + image[h][w - 1].rgbtGreen +
                                                                 image[h][w].rgbtGreen + image[h][w + 1].rgbtGreen) /
                                                        6);
                                blurBlue[h][w] = round((float) (image[h - 1][w - 1].rgbtBlue + image[h - 1][w].rgbtBlue +
                                                                image[h - 1][w + 1].rgbtBlue + image[h][w - 1].rgbtBlue +
                                                                image[h][w].rgbtBlue + image[h][w + 1].rgbtBlue) /
                                                       6);
                            }
                            if (w == (width - 1))
                            {
                                blurRed[h][w] =
                                    round((float) (image[h - 1][w - 1].rgbtRed + image[h - 1][w].rgbtRed + image[h][w - 1].rgbtRed +
                                                   image[h][w].rgbtRed + image[h + 1][w - 1].rgbtRed + image[h + 1][w].rgbtRed) /
                                          6);
                                blurGreen[h][w] = round((float) (image[h - 1][w - 1].rgbtGreen + image[h - 1][w].rgbtGreen +
                                                                 image[h][w - 1].rgbtGreen + image[h][w].rgbtGreen +
                                                                 image[h + 1][w - 1].rgbtGreen + image[h + 1][w].rgbtGreen) /
                                                        6);
                                blurBlue[h][w] = round((float) (image[h - 1][w - 1].rgbtBlue + image[h - 1][w].rgbtBlue +
                                                                image[h][w - 1].rgbtBlue + image[h][w].rgbtBlue +
                                                                image[h + 1][w - 1].rgbtBlue + image[h + 1][w].rgbtBlue) /
                                                       6);
                            }
                        }
                    }
                }
            }
            else
            {
                blurRed[h][w] =
                    round((float) (image[h - 1][w - 1].rgbtRed + image[h - 1][w].rgbtRed + image[h - 1][w + 1].rgbtRed +
                                   image[h][w - 1].rgbtRed + image[h][w].rgbtRed + image[h][w + 1].rgbtRed +
                                   image[h + 1][w - 1].rgbtRed + image[h + 1][w].rgbtRed + image[h + 1][w + 1].rgbtRed) /
                          9);
                blurGreen[h][w] =
                    round((float) (image[h - 1][w - 1].rgbtGreen + image[h - 1][w].rgbtGreen + image[h - 1][w + 1].rgbtGreen +
                                   image[h][w - 1].rgbtGreen + image[h][w].rgbtGreen + image[h][w + 1].rgbtGreen +
                                   image[h + 1][w - 1].rgbtGreen + image[h + 1][w].rgbtGreen + image[h + 1][w + 1].rgbtGreen) /
                          9);
                blurBlue[h][w] =
                    round((float) (image[h - 1][w - 1].rgbtBlue + image[h - 1][w].rgbtBlue + image[h - 1][w + 1].rgbtBlue +
                                   image[h][w - 1].rgbtBlue + image[h][w].rgbtBlue + image[h][w + 1].rgbtBlue +
                                   image[h + 1][w - 1].rgbtBlue + image[h + 1][w].rgbtBlue + image[h + 1][w + 1].rgbtBlue) /
                          9);
            }
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtRed = blurRed[h][w];
            image[h][w].rgbtGreen = blurGreen[h][w];
            image[h][w].rgbtBlue = blurBlue[h][w];
        }
    }
    return;
}
