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

#include "wilsons.hpp"

Grid Wilsons::on(Grid* grid) {
    srand((unsigned int)time(NULL));
    std::vector<Cell*> unvisited;
    grid->eachCell([&](Cell* cell) {
      unvisited.push_back(cell);
    });

    Cell* first = unvisited[rand() % unvisited.size()];
    unvisited.erase(std::remove(unvisited.begin(), unvisited.end(), first), unvisited.end());

    while (!unvisited.empty()) {
      Cell* cell = unvisited[rand() % unvisited.size()];
      std::vector<Cell*> path;
      path.push_back(cell);

      while (std::find(unvisited.begin(), unvisited.end(), cell) != unvisited.end()) {
        cell = cell->getNeighbors()[rand() % cell->getNeighbors().size()];
        auto it = std::find(path.begin(), path.end(), cell);
        if (it != path.end()) {
          path.erase(it + 1, path.end());
        } else {
          path.push_back(cell);
        }
      }

      for (int i = 0; i < path.size() - 1; i++) {
        path[i]->link(path[i + 1]);
        unvisited.erase(std::remove(unvisited.begin(), unvisited.end(), path[i]), unvisited.end());
      }
    }

    return *grid;
}
