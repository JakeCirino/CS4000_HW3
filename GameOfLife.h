#ifndef CONWAY_H
#define CONWAY_H
#include <vector>
using namespace std;

class GameOfLife{
public:
    vector<vector<int>> SimulateLife(vector<vector<int>> &board, int life_cycles);

private:
    //gets the x location based off the index/size of the world
    int GetX(int index, int size);
    //gets the y location based off the index/size of the world
    int GetY(int index, int size);
    //returns coordinates to an index
    int ToIndex(int x, int y, int size);
    //wraps coordinate values based on width/height
    int Wrap(int val, int size);
    //returns the number of neighbors alive for a given square
    int NeighborsAlive(vector<vector<int>> &board, int x, int y);
};
#endif