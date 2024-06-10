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

#ifndef ALDOUS_BRODER_HPP
#define ALDOUS_BRODER_HPP

#include <vector>
#include <algorithm>

#include "grid.hpp"

/**
 * @class AldousBroder
 * @brief Class representing the Aldous-Broder algorithm for generating mazes.
 *
 * The Aldous-Broder algorithm is a maze generation algorithm that generates a maze by
 * performing a random walk through the grid until all cells have been visited.
 * It works by selecting a random cell as the starting point and then moving to a random
 * neighboring cell. If the neighboring cell has not been visited, the algorithm carves a
 * passage between the current cell and the neighboring cell. This process continues until
 * all cells have been visited.
 *
 * The AldousBroder class provides a static method `on` that takes a Grid object as input
 * and generates a maze using the Aldous-Broder algorithm. The generated maze is returned
 * as a Grid object.
 */
class AldousBroder {
 public:
    /**
    * Generates a maze using the Aldous-Broder algorithm on the given grid.
    *
    * @param grid The grid on which the maze is generated.
    * @return The grid with the generated maze.
    */
    static Grid on(Grid *grid);
 private:
    Cell unvisited_cells;
  };

#endif // ALDOUS_BRODER_HPP
