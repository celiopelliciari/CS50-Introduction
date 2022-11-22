from constants import *


def check(pixels, width, height, i, j, new_color):
    recursions = 0

    old_color = new_color

    if (0 <= i <= width - 1 and 0 <= j <= height - 1) and (pixels[i, j] != old_color and pixels[i, j] != WATER_BLUE and
                                                           pixels[i, j] != BLACK) and pixels[i, j] == WHITE:
        new_color = color_function()
        fill(pixels, i, j, new_color, width, height, recursions)


def fill(pixels, i, j, new_color, width, height, recursions):
    recursions += 1

    pixels[i, j] = new_color

    if recursions > 1900:
        return

    if (0 <= i+1 <= width - 1 and 0 <= j <= height - 1) and \
            (pixels[i+1, j] != new_color and pixels[i+1, j] != WATER_BLUE and pixels[i+1, j] != BLACK):
        fill(pixels, i + 1, j, new_color, width, height, recursions)
    if (0 <= i-1 <= width - 1 and 0 <= j <= height - 1) and \
            (pixels[i-1, j] != new_color and pixels[i-1, j] != WATER_BLUE and pixels[i-1, j] != BLACK):
        fill(pixels, i - 1, j, new_color, width, height, recursions)
    if (0 <= i <= width - 1 and 0 <= j+1 <= height - 1) and \
            (pixels[i, j+1] != new_color and pixels[i, j+1] != WATER_BLUE and pixels[i, j+1] != BLACK):
        fill(pixels, i, j + 1, new_color, width, height, recursions)
    if (0 <= i <= width - 1 and 0 <= j-1 <= height - 1) and \
            (pixels[i, j-1] != new_color and pixels[i, j-1] != WATER_BLUE and pixels[i, j-1] != BLACK):
        fill(pixels, i, j - 1, new_color, width, height, recursions)


class ColorStructure:
    red = 0
    green = 20
    blue = 10


def color_function():
    ColorStructure.red += 20
    if ColorStructure.red >= 255:
        ColorStructure.red = 0
        ColorStructure.green += 10
    if ColorStructure.green >= 255:
        ColorStructure.green = 0
        ColorStructure.blue += 1
    new_color = (ColorStructure.red, ColorStructure.green, ColorStructure.blue)
    print(new_color)
    return new_color
