#ifndef MAZEBLOCK_H
#define MAZEBLOCK_H

class MazeBlock
{
    public:        
        MazeBlock();
        virtual ~MazeBlock();
        char displayCharacter;
        bool isExplored;
        int type;
        
        static const int WALKWAY = 0;
        static const int WALL = 1;
        static const int DOOR = 2;        
};

#endif




