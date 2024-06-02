/**
 * @brief The main function of the program.
 *
 * This function creates a grid of size rowsxcolumns and applies sidewinder algorithm to generate a maze.
 * The maze is then printed to the console and an image of the maze is generated.
 *
 * @return 0 indicating successful execution of the program.
 */
#include "binary_tree.cpp"
#include "sidewinder.cpp"

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

  //BinaryTree::on(grid);

  // Generate a maze using the Sidewinder algorithm
  ouput_grid = Sidewinder::on(grid);

  // Print the maze to the console and generate an image of the maze
  ouput_grid.to_s_v1();
  std::cout << "Sidewinder Algorithm finished successfully" << std::endl;
  ouput_grid.generateImage(filename, cellSize, wallSize);
  std::cout << "Image generated successfully" << std::endl;

  return 0;
}