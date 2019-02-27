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
    static int Wrap(int val, int size);

    /*
    * Returns the number of neighbors alive for a given square
    */
    static int NeighborsAlive(std::vector<std::vector<int>> &board, int i, int j);

    /*
    * Loops through and calculates a lifecycle for a board based on thread number
    */
    static void SimulateLifecycle(std::vector<std::vector<int>> &current_board, std::vector<std::vector<int>> &next_board, int thread_num, int total_threads);
};
#endif