//
// Created by tedac on 14/04/2022.
//

#include "grid.hh"

/* Returns the possible numbers that can be placed in the given cell */
std::vector<int> matching_number(int grid[9][9], int row, int col) {

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Verification if the cell is empty
    if (grid[row][col] != 0) {
        numbers.push_back(grid[row][col]);
        return numbers;
    }

    /* Removing all the numbers that can't be placed in the cell from the numbers vector */

    // Row
    for (int c = 0; c < 9; c++) {
        if (grid[row][c] != 0) {
            auto pos = std::find(numbers.begin(), numbers.end(), grid[row][c]);
            if (pos != numbers.end()) {
                numbers.erase(pos);
            }
        }
    }

    // Column
    for (int r = 0; r < 9; r++) {
        if (grid[r][col] != 0) {
            auto pos = std::find(numbers.begin(), numbers.end(), grid[r][col]);
            if (pos != numbers.end()) {
                numbers.erase(pos);
            }
        }
    }

    // Square
    int square_row = row - (row % 3);
    int square_col = col - (col % 3);
    for (int r = square_row; r < square_row + 3; r++) {
        for (int c = square_col; c < square_col + 3; c++) {
            if (grid[r][c] != 0) {
                auto pos = std::find(numbers.begin(), numbers.end(), grid[r][c]);
                if (pos != numbers.end()) {
                    numbers.erase(pos);
                }
            }
        }
    }

    return numbers;
}

/* Returns the next empty cell in the grid */
std::pair<int, int> next_empty_cell(int grid[9][9]) {

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {

            if (grid[r][c] == 0) {
                return std::make_pair(r, c);
            }

        }
    }
    return std::make_pair(-1, -1);
}

/* Prints the grid */
void pretty_print_grid(int grid[9][9]) {

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {

            if (c % 3 == 2 && c != 8) {
                std::cout << grid[r][c] << " | ";
            }
            else {
                std::cout << grid[r][c] << " ";
            }
        }

        std::cout << std::endl;
        if (r % 3 == 2 && r != 8) {
            std::cout << "- - - | - - - | - - -" << std::endl;
        }
    }
}

/* Solves the grid */
bool resolve(int grid[9][9]) {

    int row = next_empty_cell(grid).first;
    int col = next_empty_cell(grid).second;

    // If the grid is full, we are done
    if (row == -1 && col == -1) {
        std::cout << "Grid is solved!" << std::endl;
        pretty_print_grid(grid);
        return true;
    }

    // If the cell is empty, we can place a number in it
    std::vector<int> numbers = matching_number(grid, row, col);

    if (numbers.empty()) {
        return false;
    }

    for (int n : numbers) {
        grid[row][col] = n;
        if (resolve(grid)) {
            return true;
        }
        else {
            grid[row][col] = 0;
        }
    }
    return false;
}