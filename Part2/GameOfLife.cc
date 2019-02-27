//*****************************************************************************
//File: GameOfLife.cc
//Author: Jake Cirino
//Date: Spring 2019
//Purpose:  Code implementation of game of life simulation
//****************************************************************************
#include "GameOfLife.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <thread>
#include <functional>
using namespace std;

int GameOfLife::Wrap(int val, int size){
    if(val < 0)
        return size-1;
    else if(val >= size)
        return 0;
    else
        return val;
}

int GameOfLife::NeighborsAlive(vector<vector<int>> &board, int i, int j){
    int alive = 0;
    int size = board.size();
    for(int i1 = i - 1; i1 <= i+1; i1++){
        for(int j1 = j - 1; j1 <= j+1; j1++){
            //get actual values in case we need to wrap around the world
            int actual_i = Wrap(i1, size);
            int actual_j = Wrap(j1, size);

            //check if the value is alive or dead
            if(board[actual_i][actual_j] != 0 && !(actual_i == i && actual_j == j))
                alive++;
        }
    }
    return alive;
}

void GameOfLife::SimulateLifecycle(vector<vector<int>> &current_board, vector<vector<int>> &next_board, int thread_num, int total_threads){
    for(int i = thread_num; i < current_board.size(); i += total_threads){
        for(int j = 0; j < current_board.size(); j++){
            //calculate if cell should be alive or dead
            if(current_board[i][j] != 2){
                int alive = NeighborsAlive(current_board, i, j);
                if(alive >= 4 || alive <= 1){
                    next_board[i][j] = 0;
                }else if(current_board[i][j] == 1 && (alive == 2 || alive == 3)){
                    next_board[i][j] = 1;
                }else if(alive == 3){
                    next_board[i][j] = 1;
                }
            }else
                next_board[i][j] = 2;
        }   
    }
}

vector<vector<int>> GameOfLife::SimulateLife(vector<vector<int>> &board, int life_cycles){
    //create the current board
    vector<vector<int>> current_board = board;

    //loop through for the number of life cycles
    for(int lc = 0; lc < life_cycles; lc++){
        //initiate new board
        vector<vector<int>> tmp_board;
        tmp_board.resize(board.size());
        for(int i = 0; i < board.size(); i++){
            tmp_board[i].resize(board.size());
        }

        //declare threads
        int num_threads = thread::hardware_concurrency();
        thread threads[num_threads];
        for(int i = 0; i < num_threads; i++){
            threads[i] = thread(SimulateLifecycle, ref(current_board), ref(tmp_board), i, num_threads);
        }

        //wait for threads to complete
        for(thread& t: threads)
            t.join();

        current_board = tmp_board;
    }
    return current_board;
}