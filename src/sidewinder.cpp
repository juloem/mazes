#include <vector>
#include <cstdlib> // For rand()
#include "grid.hpp"
#include <iostream>
#include <ctime>

/**
 * @class Sidewinder
 * @brief Class representing the Sidewinder algorithm for generating mazes.
 *
 * The Sidewinder algorithm is a maze generation algorithm that creates mazes with a bias towards vertical passages.
 * It works by iterating over each row of cells in the grid and randomly carving passages either to the east or to the north.
 * When a passage is carved to the north, it forms a "run" of cells. At the end of each run, a random cell is chosen and linked to its northern neighbor.
 * This process continues until all cells have been visited.
 *
 * The Sidewinder class provides a static method `on` that takes a Grid object as input and generates a maze using the Sidewinder algorithm.
 * The generated maze is returned as a Grid object.
 */
class Sidewinder {
public:
  /**
   * Generates a maze using the Sidewinder algorithm on the given grid.
   *
   * @param grid The grid on which the maze is generated.
   * @return The grid with the generated maze.
   */
  static Grid on(Grid grid) {
    srand((unsigned int)time(NULL));
    grid.eachRow([&](std::vector<Cell*>& row) {
      std::vector<Cell*> run;

      for (Cell* cell : row) {
        run.push_back(cell);

        bool at_eastern_boundary = (cell->east_ == nullptr);
        bool at_northern_boundary = (cell->north_ == nullptr);

        bool should_close_out =
          at_eastern_boundary ||
          (!at_northern_boundary && rand() % 2 == 0);

        if (should_close_out) {
          Cell* member = run[rand() % run.size()];
          if (cell->north_ != nullptr) {
            cell->link(cell->north_);
          }
          run.clear();
        } else {
          cell->link(cell->east_);
        }
      }
    });
  return grid;
  }
};