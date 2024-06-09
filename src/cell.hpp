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

#ifndef SRC_CELL_HPP
#define SRC_CELL_HPP

#include <unordered_map>
#include <vector>

/**
 * @class Cell
 * @brief Represents a cell in a maze grid.
 */
class Cell {
 private:
   int row_; /**< The row index of the cell in the grid. */
   int column_; /**< The column index of the cell in the grid. */
   std::unordered_map<Cell*, bool> links_; /**< A map of linked cells and their link status. */

 public:
   Cell* north_; /**< Pointer to the cell to the north of this cell. */
   Cell* south_; /**< Pointer to the cell to the south of this cell. */
   Cell* east_; /**< Pointer to the cell to the east of this cell. */
   Cell* west_; /**< Pointer to the cell to the west of this cell. */

   /**
    * @brief Constructs a new Cell object.
    * @param row The row index of the cell in the grid.
    * @param column The column index of the cell in the grid.
    */
   Cell(int row, int column);

   /**
    * @brief Destroys the Cell object.
    */
   ~Cell();

   /**
    * @brief Links this cell to another cell.
    * @param cell The cell to be linked.
    * @param bidi Flag indicating whether the link should be bidirectional (default: true).
    */
   void link(Cell* cell, bool bidi = true);

   /**
    * @brief Unlinks this cell from another cell.
    * @param cell The cell to be unlinked.
    * @param bidi Flag indicating whether the unlink should be bidirectional (default: true).
    */
   void unlink(Cell* cell, bool bidi = true);

   /**
    * @brief Returns a vector of cells that are linked to this cell.
    * @return A vector of linked cells.
    */
   std::vector<Cell*> getLinks();

   /**
    * @brief Checks if this cell is linked to another cell.
    * @param cell The cell to check for a link.
    * @return True if the cells are linked, false otherwise.
    */
   bool isLinked(Cell* cell);

   /**
    * @brief Returns a vector of neighboring cells of this cell.
    * @return A vector of neighboring cells.
    */
   std::vector<Cell*> getNeighbors();
};

#endif  // SRC_CELL_HPP
