#!/usr/bin/python3
"""Contains function that returns the perimeter of the
island described in grid
"""


def determine_soroundings(array, y, x):
    """Determines whether soroundings has water or not
    also if it's next or previous is at the ends
    Args:
        array (list): grid
        y (int): current list index in `array`
        x (int): current index in the list in `array`
    """
    mask = 1
    top = array[y - 1][x] ^ mask if y > 0 else 1
    bottom = array[y + 1][x] ^ mask if y < (len(array) - 1) else 1
    left = array[y][x - 1] ^ mask if x > 0 else 1
    right = array[y][x + 1] ^ mask if x < (len(array[y]) - 1) else 1
    positions = top + bottom + right + left
    return positions


def island_perimeter(grid):
    """Gets the perimeter determined by sorounding.
    all sides that do not have water we increase perimeter.
    Args:
        grid (list): list of lists
    """
    land = 1
    perimeter = 0
    for i in range(len(grid)):
        for j, x in enumerate(grid[i]):
            if x == land:
                perimeter += determine_soroundings(grid, i, j)
    return perimeter
