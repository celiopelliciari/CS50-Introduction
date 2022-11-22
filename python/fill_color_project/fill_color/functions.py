from constants import *


def floodFill(pixels, x, y, new_color, width, height):
    # Check if pixel is frontier or ocean, do nothing
    if pixels[x, y] != BLACK or pixels[x, y] != WATER_BLUE or pixels[x, y] != new_color:
        floodFillUtil(pixels, x, y, new_color, width, height)
    else:
        return


def floodFillUtil(pixels, x, y, new_color, width, height):
    # Replace the color at (x, y)
    pixels[x, y] = new_color

    # Recur for north
    if x + 1 < 0 or x + 1 >= height or y < 0 or y >= width or pixels[x + 1, y] != BLACK or pixels[x + 1, y] != WATER_BLUE or pixels[x + 1, y] != new_color:
        floodFillUtil(pixels, x + 1, y, new_color, width, height)

    # Recur for east
    if x - 1 < 0 or x - 1 >= height or y < 0 or y >= width or pixels[x - 1, y] != BLACK or pixels[x - 1, y] != WATER_BLUE or pixels[x - 1, y] != new_color:
        floodFillUtil(pixels, x - 1, y, new_color, width, height)

    # Recur south
    if x < 0 or x >= height or y + 1 < 0 or y + 1 >= width or pixels[x, y + 1] != BLACK or pixels[x, y + 1] != WATER_BLUE or pixels[x, y + 1] != new_color:
        floodFillUtil(pixels, x, y + 1, new_color, width, height)

    # Recur west
    if x < 0 or x >= height or y - 1 < 0 or y - 1 >= width or pixels[x, y + 1] != BLACK or pixels[x, y + 1] != WATER_BLUE or pixels[x, y + 1] != new_color:
        floodFillUtil(pixels, x, y - 1, new_color, width, height)

    else:
        return
