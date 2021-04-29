#include "mazepoint.h"

// purpose: construct new maze point
// parameters: x and y
// returns: none
MazePoint::MazePoint(int x, int y)
{
    // store values
    this->x = x;
    this->y = y;
}

// purpose: destroy maze point
// parameters: none
// returns: none
MazePoint::~MazePoint()
{
}

// purpose: compare maze point objects for inequality
// parameters: the maze point to compare against
// returns: true/false
bool MazePoint::operator!=(const MazePoint& mazePoint) const
{   
    // return whether they are not equal
    return !((x == mazePoint.x) && (y == mazePoint.y));
}

// purpose: compare maze point objects for equality
// parameters: the maze point to compare against
// returns: true/false
bool MazePoint::operator==(const MazePoint& mazePoint) const
{
    // return whether they are equal
    return ((x == mazePoint.x) && (y == mazePoint.y));
}


