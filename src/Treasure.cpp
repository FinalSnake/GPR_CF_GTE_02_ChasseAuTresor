#include "Treasure.hpp"

#include <cstdlib>

#include "GameConfig.hpp"

int randomCoordinate()
{
    return std::rand() % (GRID_SIZE + 5) + 5;
}

int distanceToTreasure(int column, int row, int treasureColumn, int treasureRow)
{
    const int horizontal = std::abs(column - treasureColumn);
    const int vertical = std::abs(row - treasureRow);
    return horizontal + vertical;
}
