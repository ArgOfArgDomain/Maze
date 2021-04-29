#include "mazeblock.h"

// purpose: construct a new maze block
// parameters: none
// returns: none
MazeBlock::MazeBlock()
{
    // initialize some values
    displayCharacter = ' ';
    isExplored = false;
    type = WALKWAY;
}

// purpose: destroy maze block
// parameters: none
// returns: none
MazeBlock::~MazeBlock()
{
}
