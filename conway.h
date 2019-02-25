#ifndef CONWAY_H
#define CONWAY_H
class GameOfLife{
public:
    vector<vector<int>> SimulateLife(vector<vector<int>> &board, int life_cycles);

private:
    //gets the x location based off the index/size of the world
    int GetX(int index, int size);
    //gets the y location based off the index/size of the world
    int GetY(int index, int size);
    //returns an array of the neighbors of an index
    int[] GetNeighbors(vector<vector<int>> &board, int x, int y);
};
#endif