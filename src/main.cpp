#include <iostream>
#include <vector>

const int kGridWidth = 42;
const int kGridHeight = 25;
const int kWallBorder = 0;
const int kIntersectionSpacing = 8;
const int kHorizontalLineSpacing = 4;

int main() {
  std::vector<std::vector<char>> grid(kGridHeight, std::vector<char>(kGridWidth, ' '));

  // Initialize the grid
  for (size_t i = 0; i < grid.size(); ++i) {
    for (size_t j = 0; j < grid[0].size(); ++j) {
      if (i == kWallBorder || i == kGridHeight - 1 || j == kWallBorder || j == kGridWidth - 1) {
        grid[i][j] = '#';
      } else if (i % kHorizontalLineSpacing == 0 && j % kIntersectionSpacing == 0) {
        grid[i][j] = '+';  // Intersection
      } else if (i % kHorizontalLineSpacing == 0) {
        grid[i][j] = '-';  // Horizontal line
      } else if (j % kIntersectionSpacing == 0) {
        grid[i][j] = '|';  // Vertical line
      }
    }
  }

  // Print the grid
  for (size_t i = 0; i < grid.size(); ++i) {
    for (size_t j = 0; j < grid[0].size(); ++j) {
      std::cout << grid[i][j];
    }
    std::cout << '\n';
  }

  return 0;
}
