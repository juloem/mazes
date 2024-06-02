#include <vector>
#include <cstdlib> // For rand()
#include "grid.hpp"
#include <iostream>
#include <ctime>

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
