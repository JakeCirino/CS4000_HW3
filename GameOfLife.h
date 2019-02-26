#include <vector>
#ifndef CONWAY_H
#define CONWAY_H

class GameOfLife{
public:
    std::vector<std::vector<int>> SimulateLife(std::vector<std::vector<int>> &board, int life_cycles);

private:
    //wraps coordinate values based on width/height
    int Wrap(int val, int size);
    //returns the number of neighbors alive for a given square
    int NeighborsAlive(std::vector<std::vector<int>> &board, int i, int j);
};
#endif