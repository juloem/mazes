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

#include "cell.hpp"

Cell::Cell(int row, int column) : row_(row), column_(column),
                                north_(nullptr), south_(nullptr),
                                east_(nullptr), west_(nullptr) {}

Cell::~Cell() {
  delete north_;
  delete south_;
  delete east_;
  delete west_;
}

void Cell::link(Cell* cell, bool bidi) {
  links_[cell] = true;
  if (bidi) {
    cell->link(this, false);
  }
}

void Cell::unlink(Cell* cell, bool bidi) {
  links_[cell] = false;
  if (bidi) {
    cell->unlink(this, false);
  }
}

std::vector<Cell*> Cell::getLinks() {
  std::vector<Cell*> linkedCells;
  for (auto& link : links_) {
    linkedCells.push_back(link.first);
  }
  return linkedCells;
}

bool Cell::isLinked(Cell* cell) {
  return links_.count(cell) > 0;
}

std::vector<Cell*> Cell::getNeighbors() {
  std::vector<Cell*> neighbors;
  if (north_) neighbors.push_back(north_);
  if (south_) neighbors.push_back(south_);
  if (east_)  neighbors.push_back(east_);
  if (west_)  neighbors.push_back(west_);
  return neighbors;
}
