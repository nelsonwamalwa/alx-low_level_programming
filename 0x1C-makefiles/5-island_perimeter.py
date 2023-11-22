#!/usr/bin/python3
"""Defining an island perimeter measuring function"""


def island_perimeter(grid):
    """Returning the perimiter of an island

    The grid representing water by 0 while land by 1.

    Args:
        grid (list): A list of list of integers representing an island.
    Returns:
        The perimeter of island defined in grid.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    edges += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    edges += 1
    return size * 4 - edges * 2