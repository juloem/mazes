#include <cassert>
#include "../src/cell.cpp"

int main() {
  // Create cells
  Cell cell1(0, 0);
  Cell cell2(1, 0);
  Cell cell3(0, 1);

  // Link cells
  cell1.link(&cell2);
  cell1.link(&cell3);

  // Check if cells are linked
  assert(cell1.isLinked(&cell2));
  assert(cell1.isLinked(&cell3));
  assert(!cell2.isLinked(&cell3));

  // Get linked cells
  std::vector<Cell*> linkedCells = cell1.getLinks();
  assert(linkedCells.size() == 2);
  assert(linkedCells[0] == &cell2);
  assert(linkedCells[1] == &cell3);

  // Get neighboring cells
  std::vector<Cell*> neighbors = cell1.getNeighbors();
  assert(neighbors.size() == 0);

  cell1.north_ = &cell2;
  cell1.south_ = &cell3;

  neighbors = cell1.getNeighbors();
  assert(neighbors.size() == 2);
  assert(neighbors[0] == &cell2);
  assert(neighbors[1] == &cell3);

  return 0;
}