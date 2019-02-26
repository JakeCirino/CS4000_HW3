//*****************************************************************************
//File: GameOfLife.h
//Author: Jake Cirino
//Date: Spring 2019
//Purpose:  Game of life implementation header file
//****************************************************************************
#include <vector>
#ifndef CONWAY_H
#define CONWAY_H

class GameOfLife{
public:
    /*
    * Simulates life for a number of lifcycles
    */
    std::vector<std::vector<int>> SimulateLife(std::vector<std::vector<int>> &board, int life_cycles);

private:
    /*
    * Wraps coordinate values based on width/height
    */
    int Wrap(int val, int size);

    /*
    * Returns the number of neighbors alive for a given square
    */
    int NeighborsAlive(std::vector<std::vector<int>> &board, int i, int j);
};
#endif