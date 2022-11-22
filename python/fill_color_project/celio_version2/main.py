from PIL import Image
from functions import *
import sys

sys.setrecursionlimit(10 ** 8)

with Image.open("world_map.bmp", "r") as infile:
    height = infile.height
    width = infile.width
    pixels = infile.load()

    new_color = (ColorStructure.red, ColorStructure.green, ColorStructure.blue)

    for i in range(0, width, 1):
        for j in range(0, height, 1):
            # print(i, j)
            check(pixels, width, height, i, j, new_color)

    infile.save('colored_world_map.bmp')
