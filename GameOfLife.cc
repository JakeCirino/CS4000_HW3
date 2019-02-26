#include "GameOfLife.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int GameOfLife::GetX(int index, int size){
    return index%size;
}

int GameOfLife::GetY(int index, int size){
    return floor(index/size);
}

int GameOfLife::ToIndex(int x, int y, int size){
    return x + y*size;
}

int GameOfLife::Wrap(int val, int size){
    if(val < 0)
        return size-1;
    else if(val >= size)
        return 0;
    else
        return val;
}

int GameOfLife::NeighborsAlive(vector<vector<int>> &board, int x, int y){
    int alive = 0;
    int size = board.size();
    for(int x1 = x - 1; x1 <= x+1; x1++){
        for(int y1 = y - 1; y1 <= y+1; y1++){
            //get actual values in case we need to wrap around the world
            int actual_x = Wrap(x1, size);
            int actual_y = Wrap(y1, size);
            
            //cout << actual_x << ", " << actual_y << ": " << board[actual_x][actual_y] << endl;

            //check if the value is alive or dead
            if(board[actual_x][actual_y] != 0 && actual_x != x && actual_y != y)
                alive++;
        }
    }
    return alive;
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
        
        //store iterations
        int iterations = board.size()*board.size();
        //iterate through board
        for(int i = 0; i < iterations; i++){
            int x = GetX(i, board.size()),
                y = GetY(i, board.size());

            //calculate if cell should be alive or dead
            if(current_board[x][y] != 2){
                int alive = NeighborsAlive(current_board, x, y);
                if(alive >= 4 || alive <= 1){
                    tmp_board[x][y] = 0;
                }else if(current_board[x][y] == 1 && (alive == 2 || alive == 3)){
                    tmp_board[x][y] = 1;
                }else if(alive == 3){
                    tmp_board[x][y] = 1;
                }
            }else
                tmp_board[x][y] = 2;
        }
        current_board = tmp_board;
    }
    return current_board;
}