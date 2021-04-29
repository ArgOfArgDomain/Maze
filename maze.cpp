#include <iostream>
#include <string>
#include <fstream>
#include "stack.h"
#include "maze.h"
#include "mazeblock.h"
#include "mazepoint.h"

using namespace std;

// purpose: initialize maze
// parameters: none
// returns: none
Maze::Maze()
{
    // initialize values
    mazeWidth = 0;
    mazeHeight = 0;
    mazeBlocks = NULL;    
}

// purpose: delete memory used by maze
// parameters: none
// returns: none
Maze::~Maze()
{
    // clear maze
    clear();
}

// purpose: load a maze from a file
// parameters: file name
// returns: success or fail (true/false)
bool Maze::loadFromFile(const string& fileName)
{
    ifstream inFile;
    mazeWidth = 0;
    mazeHeight = 0;
    
    inFile.open(fileName.c_str(), ios::in);
    if (!inFile.is_open()) return false;
    
    // read file to get max width and hight
    while (!inFile.eof()) {        
        string line;        
        
        // read a line and append to list
        getline(inFile, line);        
        
        // increment height
        mazeHeight++;
        
        // update width        
        mazeWidth = line.length();
    }
    
    // seek back to beginning of file
    inFile.clear();
    inFile.seekg(0, ios::beg);        
        
    // allocate memory to store maze
    mazeBlocks = new MazeBlock*[mazeWidth];
    for (int i=0; i<mazeWidth; i++) {
        mazeBlocks[i] = new MazeBlock[mazeHeight];
    }
    
    // loop until end of file or we hit maze height
    for (int i=0; i<mazeHeight && !inFile.eof(); i++) {    
        string line;        
        
        // read a line and append to list
        getline(inFile, line);                
                
        // go through each character in the line
        for (int j=0; j<mazeWidth; j++) {            
            // save maze block
            mazeBlocks[j][i].isExplored = false;
            mazeBlocks[j][i].displayCharacter = line[j];                        
            
            // save the type of maze block
            if (line[j] == ' ') {
                // check if its a door
                if (((j == 0) || (j == mazeWidth - 1))  
                    || ((i == 0) || (i == mazeHeight - 1))) {
                    // its a door
                    mazeBlocks[j][i].type = MazeBlock::DOOR;
                    
                    // store as either start location or end location
                    if (startDoor.x < 0) {
                        startDoor.x = j;
                        startDoor.y = i;
                    } else {
                        endDoor.x = j;
                        endDoor.y = i;
                    }
                } else {
                    // its part of the walk way
                    mazeBlocks[j][i].type = MazeBlock::WALKWAY;
                }
            } else {
                // its a wall
                mazeBlocks[j][i].type = MazeBlock::WALL;
            }
        }        
    }    
    
    // close file
    inFile.close();

    // return success
    return true;
}

// purpose: solve the maze
// parameters: none
// returns: whether the maze was solved (true/false)
bool Maze::solve()
{
    Stack<MazePoint> path;
    MazePoint currentPoint;
    
    // first make sure maze has a start and end door
    if ((startDoor.x < 0) || (endDoor.x < 0)) {
        return false;
    }
    
    // push start point on to stack
    path.push(startDoor);
    
    // set current point to start door
    currentPoint = startDoor;
    
    // loop while there are still points in the stack    
    while (!path.isEmpty() && currentPoint != endDoor) {    
        // set current block to explored
        mazeBlocks[currentPoint.x][currentPoint.y].isExplored = true;
        
        // check for an unexplored block above current block (if we are not
        // outside of the maze and are on a walkway)
        if ((currentPoint.y - 1 >= 0) 
            && (!mazeBlocks[currentPoint.x][currentPoint.y - 1].isExplored)
            && (mazeBlocks[currentPoint.x][currentPoint.y - 1].type 
            != MazeBlock::WALL)) {   
                    
            // push point back on to stack
            path.push(currentPoint);        
                     
            // move there
            currentPoint.y--;
            
            // push new point on to the stack
            path.push(currentPoint);
            
        // check for an unexplored block below current block (if we are not
        // outside of the maze and are on a walkway)
        } else if ((currentPoint.y + 1 < mazeHeight) 
            && (!mazeBlocks[currentPoint.x][currentPoint.y + 1].isExplored)
            && (mazeBlocks[currentPoint.x][currentPoint.y + 1].type
            != MazeBlock::WALL)) {
            
            // push point back on to stack
            path.push(currentPoint);
            
            // move there
            currentPoint.y++;
            
            // push new point on to the stack
            path.push(currentPoint); 
            
        // check for an unexplored block left current block (if we are not
        // outside of the maze and are on a walkway)           
        } else if ((currentPoint.x - 1 >= 0) 
            && (!mazeBlocks[currentPoint.x - 1][currentPoint.y].isExplored)
            && (mazeBlocks[currentPoint.x - 1][currentPoint.y].type 
            != MazeBlock::WALL)) {
            
            // push point back on to stack
            path.push(currentPoint);
            
            // move there
            currentPoint.x--;
            
            // push new point on to the stack
            path.push(currentPoint); 
            
        // check for an unexplored block left current block (if we are not
        // outside of the maze and are on a walkway)           
        } else if ((currentPoint.x + 1 >= 0)
            && (!mazeBlocks[currentPoint.x + 1][currentPoint.y].isExplored)
            && (mazeBlocks[currentPoint.x + 1][currentPoint.y].type 
            != MazeBlock::WALL)) {
            
            // push point back on to stack
            path.push(currentPoint);
            
            // move there
            currentPoint.x++;
            
            // push new point on to the stack
            path.push(currentPoint); 
        } else {
            // go back a block
            currentPoint = path.pop();
        }
    }
    
    // check that we found a path through the maze
    if (path.isEmpty()) {
        return false;
    }
    
    // "draw" the path through the maze
    while (!path.isEmpty()) {
        currentPoint = path.pop();
        mazeBlocks[currentPoint.x][currentPoint.y].displayCharacter = '#';        
    }
        
    // return success
    return true;
}

// purpose: output maze
// parameters: output stream, the maze to output
// returns: output stream
ostream& operator<<(ostream& output, const Maze& maze)
{
    // output all characters in maze block array
    for (int i=0; i<maze.mazeHeight; i++) {
        for (int j=0; j<maze.mazeWidth; j++) {
            output << maze.mazeBlocks[j][i].displayCharacter;
        }
        output << endl;
    }
    
    // return the stream
    return output;
}

// purpose: delete all memory used by maze
// parameters: none
// returns: none
void Maze::clear()
{
    // delete all the maze blocks
    for (int i=0; i<mazeWidth; i++) {
        delete[] mazeBlocks[i];
        mazeBlocks[i] = NULL;
    }
    
    // delete the array
    delete[] mazeBlocks;
    mazeBlocks = NULL;
}



