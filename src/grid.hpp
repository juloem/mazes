/*
 * MIT License
 *
 * Copyright (C) 2024 juloem
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef GRID_HPP
#define GRID_HPP

#include <png.h>

#include <cstdlib>
#include <functional>
#include <string>
#include <iostream>
#include <vector>

#include "cell.hpp"

class Grid {
 private:
    int rows; /**< The number of rows in the grid. */
    int columns; /**< The number of columns in the grid. */
    std::vector<std::vector<Cell*>> grid; /**< The 2D vector representing the grid of cells. */

 public:
    /**
     * @brief Constructs a Grid object with the specified number of rows and columns.
     * @param rows The number of rows in the grid.
     * @param columns The number of columns in the grid.
     */
    Grid(int rows, int columns);

    /**
     * @brief Prepares the grid by creating and initializing the cells.
     * @return The 2D vector representing the grid of cells.
     */
    std::vector<std::vector<Cell*>> prepareGrid();

    /**
     * @brief Configures the cells in the grid.
     */
    void configureCells();

    /**
     * @brief Retrieves the cell at the specified row and column.
     * @param row The row index of the cell.
     * @param column The column index of the cell.
     * @return A pointer to the cell at the specified position, or nullptr if the position is out of bounds.
     */
    Cell* getCell(int row, int column);

    /**
     * @brief Retrieves a random cell from the grid.
     * @return A pointer to a randomly selected cell.
     */
    Cell* getRandomCell();

    /**
     * @brief Returns the total number of cells in the grid.
     * @return The total number of cells in the grid.
     */
    int size();

    /**
     * @brief Iterates over each row in the grid.
     * @return A vector of cell rows.
     */
    void eachRow(std::function<void(std::vector<Cell*>&)>);

    /**
     * @brief Iterates over each cell in the grid.
     * @return A vector of cells.
     */
    void eachCell(std::function<void(Cell*)>);

    /**
     * @brief Returns a string representation of the grid (version 1).
     * @return A string representation of the grid.
     */
    std::string to_s_v1();

    /**
     * Draws a wall on the grid.
     *
     * @param x1 The starting x-coordinate of the wall.
     * @param x2 The ending x-coordinate of the wall.
     * @param y1 The starting y-coordinate of the wall.
     * @param y2 The ending y-coordinate of the wall.
     * @param wallSize The size of the wall.
     * @param rowPointers The array of row pointers representing the grid.
     * @param isVertical Indicates whether the wall is vertical or horizontal.
     */
    void drawWall(int x1, int x2, int y1, int y2, int wallSize, png_bytep* rowPointers, bool isVertical);

    /**
     * @brief Generates a PNG image of the grid.
     * @param filename The name of the output image file.
     * @param cellSize The size of each cell in pixels.
     * @return True if the image was successfully generated, false otherwise.
     * @note This function requires the libpng library to be installed.
    */
    void generateImage(const std::string& filename, int cellSize, int wallSize = 1);
};

#endif  // GRID_HPP
