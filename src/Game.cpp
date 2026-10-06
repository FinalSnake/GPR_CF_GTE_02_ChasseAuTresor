#include "Game.hpp"
#include "GameConfig.hpp"
#include "Messages.hpp"
#include "Treasure.hpp"

void playGame()
{
    const int treasureColumn = randomCoordinate();
    const int treasureRow = randomCoordinate();

    printWelcome();

    // changement des attempts >Sophie
    int attempts = 6;
    bool found = false;
    bool gaveUp = false;

    while (!found && !gaveUp && attempts < MAX_ATTEMPTS )
    {
        const int column = askColumn();
        if (column == 0)
        {
            gaveUp = true;
        }
        else
        {
            const int row = askRow();
            attempts = attempts + 1;

            const int distance = distanceToTreasure(column, row, treasureColumn, treasureRow);
            if (distance == 0)
            {
                found = true;
            }
            else
            {
                printHint(distance);
            }
        }
    }

    if (found)
    {
        printVictory(attempts);
    }
    else if (gaveUp)
    {
        printGiveUp(treasureColumn, treasureRow);
    }
    else
    {
        printDefeat(treasureColumn, treasureRow);
    }
}
