/* Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'. 

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9. */

// It is a very good question. Highly recommended to practice more than once.

class Solution {
public:
    bool dfs(int x, int y, vector<vector<char>>& board, vector<vector<int>>& mp1, vector<vector<int>>& mp2, vector<vector<int>>&mp3){
        if(y==9){
            ++x;
            y=0;
        }
        if(x==9)
            return true;
        if(board[x][y]=='.'){
            for(int num=0;num<9;num++){
                if(!(mp1[x][num] || mp2[y][num] || mp3[3*(x/3)+y/3][num])){
                    mp1[x][num]=1;
                    mp2[y][num]=1;
                    mp3[3*(x/3)+y/3][num]=1;
                    
                    board[x][y]=num+'1';
                    
                    if(dfs(x,y+1,board,mp1,mp2,mp3))
                        return true;
                    
                    mp1[x][num]=0;
                    mp2[y][num]=0;
                    mp3[3*(x/3)+y/3][num]=0;
                    
                    board[x][y]='.';
                }
            }       
        }
        else{
            if(dfs(x,y+1,board,mp1,mp2,mp3))
                return true;   
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> mp1(9, vector<int>(9,0)), mp2(9, vector<int>(9,0)), mp3(9, vector<int>(9,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num = board[i][j]-'0'-1;
                    int k = i/3*3+j/3;
                    mp1[i][num] = mp2[j][num] = mp3[k][num] = 1;
                }
            }
        }
        dfs(0,0,board,mp1,mp2,mp3);
    }
};
