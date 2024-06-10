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

#include "aldous_broder.hpp"

Grid AldousBroder::on(Grid *grid) {
  srand((unsigned int)time(NULL));
  Cell* cell = grid->getRandomCell();
  int unvisited = grid->size() - 1;

  while (unvisited > 0) {
    Cell* neighbor = cell->getNeighbors().at(rand() % cell->getNeighbors().size());
    if (neighbor->getLinks().empty()) {
      cell->link(neighbor);
      unvisited--;
    }
    cell = neighbor;
  }

  return *grid;
}