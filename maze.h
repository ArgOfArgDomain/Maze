#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>
#include "mazeblock.h"
#include "mazepoint.h"

using namespace std;

class Maze
{    
    public:
        Maze();
        virtual ~Maze();
        bool loadFromFile(const string& fileName);
        bool solve();        
        friend ostream& operator<<(ostream& output, const Maze& maze);
        void clear();
        
    private:
        MazeBlock** mazeBlocks;
        int mazeWidth;
        int mazeHeight;
        MazePoint startDoor;
        MazePoint endDoor;
};

#endif
