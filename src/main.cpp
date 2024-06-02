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

#include "binary_tree.cpp"
#include "sidewinder.cpp"

/**
 * @brief The main function of the program.
 *
 * This function creates a grid of size rowsxcolumns and applies sidewinder algorithm to generate a maze.
 * The maze is then printed to the console and an image of the maze is generated.
 *
 * @return 0 indicating successful execution of the program.
 */
int main() {
  // Predetermined values for the maze
  int rows = 5;
  int columns = 5;
  int cellSize = 100;
  int wallSize = 10;
  std::string filename = "maze.png";

  // Create a grid of size rowsxcolumns
  Grid grid(rows, columns);
  Grid ouput_grid(rows, columns);

  // BinaryTree::on(grid);

  // Generate a maze using the Sidewinder algorithm
  ouput_grid = Sidewinder::on(grid);

  // Print the maze to the console and generate an image of the maze
  ouput_grid.to_s_v1();
  std::cout << "Sidewinder Algorithm finished successfully" << std::endl;
  ouput_grid.generateImage(filename, cellSize, wallSize);
  std::cout << "Image generated successfully" << std::endl;

  return 0;
}
