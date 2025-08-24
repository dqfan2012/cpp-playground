/*
 * File: dijkstra_map.cpp
 * Author: Samuel Stidham
 * Date: 08/24/2025
 * C++ Formatting Style: https://google.github.io/styleguide/cppguide.html
 * Compiled with: g++ -std=c++20 -Wall -Wextra -Wconversion -Wpedantic -Wshadow -Werror -o test_map test_map.cpp
 *                clang++ -std=c++20 -Wall -Wextra -Wconversion -Wpedantic -Wshadow -Werror -o test_map test_map.cpp
 * Description:
 * A basic C++ implementation of a Dijkstra Map generator for a grid-based game map.
 * This program calculates and displays the shortest distance from a player character ('@')
 * to all other reachable, open cells on the map. It uses a Breadth-First Search
 * algorithm, which is suitable for unweighted graphs.
 */
#include <array>
#include <iostream>
#include <queue>
#include <vector>

const int kGridWidth = 42;          // Width of the grid
const int kGridHeight = 25;         // Height of the grid
const int kWallBorder = 0;          // Border index for walls
const int kWallValue = -1;          // Value representing a wall in the grid
const int kUnreachable = 999;       // Value representing an unreachable cell
const size_t kPlayerStartX = 5;     // Player's starting X position
const size_t kPlayerStartY = 5;     // Player's starting Y position

/**
 * Distance the player is from their starting position.
 * This value is used to calculate the distance from the starting position to every other cell.
 */
const int kPlayerStartDistance = 0;

struct Cell {
  size_t x, y;
};

namespace {
void printGrid(const std::vector<std::vector<int>> &grid) {
  for (size_t i = 0; i < grid.size(); ++i) {
    for (size_t j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == kWallValue) {
        std::cout << " # ";
      } else if (grid[i][j] == kPlayerStartDistance) {
        std::cout << " @ ";
      } else if (grid[i][j] == kUnreachable) {
        std::cout << "   ";
      } else {
        std::cout.width(3);
        std::cout << grid[i][j];
      }
    }
    std::cout << '\n';
  }
}
}  // namespace

int main() {
  // Define the Grid data structure
  // A 2D vector representing the game map, where each cell can hold a character indicating its type.
  std::vector<std::vector<int>> grid(kGridHeight, std::vector<int>(kGridWidth, kUnreachable));

  // Place the '@' character inside the border
  Cell start = {.x = kPlayerStartX, .y = kPlayerStartY};

  // Initialize the grid with the border and the character
  for (size_t i = 0; i < grid.size(); ++i) {
    for (size_t j = 0; j < grid[0].size(); ++j) {
      if (i == kWallBorder || i == grid.size() - 1 || j == kWallBorder || j == grid[0].size() - 1) {
        grid[i][j] = kWallValue;
      }
    }
  }
  // Set the player's starting position distance to kPlayerStartDistance
  grid[start.y][start.x] = kPlayerStartDistance;

  // Implement Dijkstra's Map Algorithm (Breadth-First search)
  std::queue<Cell> cell_queue;
  cell_queue.push(start);

  std::array<int, 4> delta_x = {0, 0, 1, -1};
  std::array<int, 4> delta_y = {1, -1, 0, 0};

  while (!cell_queue.empty()) {
    Cell current = cell_queue.front();
    cell_queue.pop();

    // Explore neighbors
    for (size_t i = 0; i < 4; ++i) {
      int neighbor_x = static_cast<int>(current.x) + delta_x[i];
      int neighbor_y = static_cast<int>(current.y) + delta_y[i];

      Cell neighbor = {.x = static_cast<size_t>(neighbor_x), .y = static_cast<size_t>(neighbor_y)};

      // Check if neighbor is within grid bounds
      if (neighbor_x >= 0 && neighbor_x < static_cast<int>(grid[0].size()) &&
          neighbor_y >= 0 && neighbor_y < static_cast<int>(grid.size()) &&
          grid[static_cast<size_t>(neighbor_y)][static_cast<size_t>(neighbor_x)] == kUnreachable) {
        // Update the distance and push it to the queue
        grid[static_cast<size_t>(neighbor_y)][static_cast<size_t>(neighbor_x)] = grid[current.y][current.x] + 1;
        cell_queue.push(neighbor);
      }
    }
  }

  // Print the final Dijkstra's map
  std::cout << "Dijkstra's Map from Player ('@')" << '\n';
  printGrid(grid);

  return 0;
}
