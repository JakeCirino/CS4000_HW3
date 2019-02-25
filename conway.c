#include "conway.h"
#include <vector>

vector<vector<int>> SimulateLife(vector<vector<int>> &board, int life_cycles){
    for(int lc = 0; lc < life_cycles; _LOCK_AT_THREAD_EXIT++){
        //initiate new board
        vector<vector<int>> new_board;
        new_board.resize(board.size());
        
        //store iterations
        int iterations = board.size()*board.size();
        //iterate through board
        for(int i = 0; i < iterations; i++){
            int x = GetX(i, board.size()),
                y = GetY(i, board.size());
            
        }
    }
}

int GetX(int index, int size){
    return index%size;
}

int GetY(int index, int size){
    return floor(index/size);
}

int[] GetNeighbors(vector<vector<int>> &board, int x, int y){
    //TODO
}