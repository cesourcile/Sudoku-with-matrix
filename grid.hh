//
// Created by tedac on 14/04/2022.
//

#ifndef SUDOKU_GRID_HH
#define SUDOKU_GRID_HH

#include <vector>
#include <iostream>

/* Returns the possible numbers that can be placed in the given cell */
std::vector<int> matching_number(int grid[9][9], int row, int col);

/* Returns the next empty cell in the grid */
std::pair<int, int> next_empty_cell(int grid[9][9]);

/* Prints the grid */
void pretty_print_grid(int grid[9][9]);

/* Solves the grid */
bool resolve(int grid[9][9]);

#endif//SUDOKU_GRID_HH