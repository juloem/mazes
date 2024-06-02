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

#include "grid.hpp"

Grid::Grid(int rows, int columns) : rows(rows), columns(columns) {
  grid = prepareGrid();
  configureCells();
}

std::vector<std::vector<Cell*>> Grid::prepareGrid() {
  std::vector<std::vector<Cell*>> newGrid(rows, std::vector<Cell*>(columns, nullptr));
  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
      newGrid[row][column] = new Cell(row, column);
    }
  }
  return newGrid;
}

void Grid::configureCells() {
  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
      Cell* cell = grid[row][column];
      cell->north_ = getCell(row - 1, column);
      cell->south_ = getCell(row + 1, column);
      cell->west_ = getCell(row, column - 1);
      cell->east_ = getCell(row, column + 1);
    }
  }
}

Cell* Grid::getCell(int row, int column) {
  if (row < 0 || row >= rows || column < 0 || column >= columns) {
    return nullptr;
  }
  return grid[row][column];
}

Cell* Grid::getRandomCell() {
  int row = rand() % rows;
  int column = rand() % columns;
  return getCell(row, column);
}

int Grid::size() {
  return rows * columns;
}

void Grid::eachRow(std::function<void(std::vector<Cell*>&)> callback) {
  for (int row = 0; row < rows; row++) {
    callback(grid[row]);
  }
}

void Grid::eachCell(std::function<void(Cell*)> callback) {
  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
      callback(grid[row][column]);
    }
  }
}

std::string Grid::to_s_v1() {
  std::string output = "+";
  for (int i = 0; i < columns; i++) {
    output += "---+";
  }
  output += "\n";

  for (auto row : grid) {
    std::string top = "|";
    std::string bottom = "+";

    for (auto cell : row) {
      if (!cell) {
        cell = new Cell(-1, -1);
      }

      std::string body = "   ";
      std::string east_boundary = (cell->isLinked(cell->east_) ? " " : "|");
      top += body + east_boundary;

      std::string south_boundary = (cell->isLinked(cell->south_) ? "   " : "---");
      std::string corner = "+";
      bottom += south_boundary + corner;
    }

    output += top + "\n";
    output += bottom + "\n";
  }

  std::cout << output;
  return output;
  }

void Grid::drawWall(int x1, int x2, int y1, int y2, int wallSize, png_bytep* rowPointers, bool isVertical) {
    if (isVertical) {
        for (int y = y1; y < y2; y++) {
            for (int t = 0; t < wallSize; t++) {
                if (x1 - t >= 0) {
                    rowPointers[y][(x1 - t - 1) * 3] = 0;
                    rowPointers[y][(x1 - t - 1) * 3 + 1] = 0;
                    rowPointers[y][(x1 - t - 1) * 3 + 2] = 0;
                }
            }
        }
    } else {
        for (int x = x1; x < x2; x++) {
            for (int t = 0; t < wallSize; t++) {
                rowPointers[y1 + t][x * 3] = 0;
                rowPointers[y1 + t][x * 3 + 1] = 0;
                rowPointers[y1 + t][x * 3 + 2] = 0;
            }
        }
    }
}

  void Grid::generateImage(const std::string& filename, int cellSize, int wallSize) {
    int imageWidth = columns * cellSize;
    int imageHeight = rows * cellSize;

    png_bytep* rowPointers = new png_bytep[imageHeight];
    for (int i = 0; i < imageHeight; i++) {
      rowPointers[i] = new png_byte[imageWidth * 3];
      // Initialize all pixels to white
      std::fill_n(rowPointers[i], imageWidth * 3, 255);
    }

    for (int row = 0; row < rows; row++) {
      for (int column = 0; column < columns; column++) {
        Cell* cell = grid[row][column];
        int x1 = column * cellSize;
        int y1 = row * cellSize;
        int x2 = (column + 1) * cellSize;
        int y2 = (row + 1) * cellSize;

        if (!cell->isLinked(cell->north_)) {
          drawWall(x1, x2, y1, y1 + wallSize, wallSize, rowPointers, false);
        }

        if (!cell->isLinked(cell->west_)) {
          drawWall(x1, x1 + wallSize, y1, y2, wallSize, rowPointers, true);
        }

        // Draw east wall only if it's the last column and if the cell is not linked to its eastern neighbor
        if (column == columns - 1 && !cell->isLinked(cell->east_)) {
          drawWall(x2, x2, y1, y2, wallSize, rowPointers, true);
        }

        // Draw south wall only if it's the last row and if the cell is not linked to its southern neighbor
        if (row == rows - 1 && !cell->isLinked(cell->south_)) {
          drawWall(x1, x2, y2 - wallSize, y2, wallSize, rowPointers, false);
        }
      }
    }

    // Error handling
    FILE* file = fopen(filename.c_str(), "wb");
    if (!file) {
      std::cerr << "Error opening file: " << filename << std::endl;
      return;
    }

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) {
      std::cerr << "Error creating PNG write struct" << std::endl;
      fclose(file);
      return;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
      std::cerr << "Error creating PNG info struct" << std::endl;
      png_destroy_write_struct(&png, nullptr);
      fclose(file);
      return;
    }

    if (setjmp(png_jmpbuf(png))) {
      std::cerr << "Error during PNG creation" << std::endl;
      png_destroy_write_struct(&png, &info);
      fclose(file);
      return;
    }

    // Write image data to file
    png_init_io(png, file);
    png_set_IHDR(png, info, imageWidth, imageHeight, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png, info);
    png_write_image(png, rowPointers);
    png_write_end(png, nullptr);

    // Clean up memory
    for (int i = 0; i < imageHeight; i++) {
      delete[] rowPointers[i];
    }
    delete[] rowPointers;

    png_destroy_write_struct(&png, &info);
    fclose(file);
  }
