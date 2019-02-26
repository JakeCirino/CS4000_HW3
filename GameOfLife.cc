#include "GameOfLife.h"
#include <vector>
using namespace std;

int GetX(int index, int size){
    return index%size;
}

int GetY(int index, int size){
    return floor(index/size);
}

int ToIndex(int x, int y, int size){
    return x + y*size;
}

int Wrap(int val, int size){
    if(val < 0)
        return size;
    else if(val >= size)
        return 0;
    else
        return val;
}

int NeighborsAlive(vector<vector<int>> &board, int x, int y){
    int alive = 0;
    int size = board.size();
    for(int x1 = x-1; x1 <= x+1; x1++){
        for(int y1 = y - 1; y1 <= y+1; y1++){
            //get actual values in case we need to wrap around the world
            int actual_x = Wrap(x1, size);
            int actual_y = Wrap(y1, size);
            
            //check if the value is alive or dead
            if(board[actual_x][actual_y] != 0 && actual_x != x && actual_y != y)
                alive++;
        }
    }
    return alive;
}

vector<vector<int>> SimulateLife(vector<vector<int>> &board, int life_cycles){
    //loop through for the number of life cycles
    for(int lc = 0; lc < life_cycles; lc++){
        //initiate new board
        vector<vector<int>> new_board;
        new_board.resize(board.size());
        for(int i = 0; i < board.size(); i++){
            new_board[i].resize(board.size());
        }
        
        //store iterations
        int iterations = board.size()*board.size();
        //iterate through board
        for(int i = 0; i < iterations; i++){
            int x = GetX(i, board.size()),
                y = GetY(i, board.size());

            //calculate if cell should be alive or dead
            if(board[x][y] != 2){
                int alive = NeighborsAlive(board, x, y);
                if(alive >= 4 || alive <= 1){
                    new_board[x][y] = 0;
                }else if(board[x][y] == 1 && (alive == 2 || alive == 3)){
                    new_board[x][y] = 1;
                }else if(alive == 3){
                    new_board[x][y] = 1;
                }
            }else
                new_board[x][y] = 2;
        }
        board = new_board
    }
}