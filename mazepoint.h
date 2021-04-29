#ifndef MAZEPOINT_H
#define MAZEPOINT_H

class MazePoint
{
    public:
        MazePoint(int x = -1, int y = -1);
        virtual ~MazePoint();
        int x;
        int y;
        bool operator!=(const MazePoint& mazePoint) const;
        bool operator==(const MazePoint& mazePoint) const;
};


#endif
