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

#include <vector>
#include <cstdlib>  // For rand()
#include <iostream>
#include <ctime>

#include "grid.hpp"

/**
 * @class BinaryTree
 * @brief Represents a binary tree maze generation algorithm.
 *
 * The BinaryTree class provides a static method `on` that generates a binary tree maze
 * on a given grid. The algorithm randomly selects either the north or east neighbor of
 * each cell and links it to the current cell. This results in a maze with a bias towards
 * passages that go north or east.
 */
class BinaryTree {
 public:
  /**
   * Generates a binary tree maze on the given grid.
   *
   * @param grid The grid on which the maze is generated.
   * @return The grid with the generated maze.
   */
  static Grid on(Grid grid) {
    srand((unsigned int)time(NULL));
    grid.eachCell([](Cell* cell) {
      std::vector<Cell*> neighbors;
      if (cell->north_ != nullptr) {
        neighbors.push_back(cell->north_);
      }
      if (cell->east_ != nullptr) {
        neighbors.push_back(cell->east_);
      }

      if (!neighbors.empty()) {
        int index = rand() % neighbors.size();
        Cell* neighbor = neighbors[index];
        cell->link(neighbor);
      }
    });
    return grid;
  }
};
