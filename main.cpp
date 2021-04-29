#include <iostream>
#include <string>
#include "maze.h"

using namespace std;

int main()
{
    string fileName;
    Maze maze;
    
    // promt user for file name
    cout << "Enter maze file name: ";
    getline(cin, fileName);
    
    // try to load maze from file
    if (maze.loadFromFile(fileName)) {        
        // try to solve maze
        if (maze.solve()) {
            // output solved maze
            cout << endl << "Solved Maze: " << endl << endl;
            cout << maze << endl;
        } else {
            // output error
            cout << "Maze could not be solved." << endl;
        }
    } else {
        // output error
        cout << "Could not load maze." << endl;
    }    
    
    // return success
    return true;
}

