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

#ifndef WILSONS_HPP
#define WILSONS_HPP

#include <vector>

#include "grid.hpp"

/**
 * @class Wilsons
 * @brief Represents a Wilson's maze generation algorithm.
 *
 * The Wilsons class provides a static method `on` that generates a Wilson's maze
 * on a given grid. The algorithm starts with a grid where all cells are unvisited.
 * It then selects a random cell and marks it as visited. It then selects a random
 * unvisited cell and performs a loop erased random walk until it reaches a visited
 * cell. The path taken during the walk is then marked as part of the maze. This
 * process is repeated until all cells are visited.
 */
class Wilsons {
 public:
  /**
   * Generates a Wilson's maze on the given grid.
   *
   * @param grid The grid on which the maze is generated.
   * @return The grid with the generated maze.
   */
  static Grid on(Grid* grid);
};

#endif  // WILSONS_HPP