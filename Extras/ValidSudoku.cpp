/* Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition. 
The Sudoku board could be partially filled, where empty cells are filled with the character '.'. */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int mp1[9][9]={0}, mp2[9][9]={0}, mp3[9][9]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num = board[i][j]-'0'-1;
                    int k = i/3*3+j/3;
                    if(mp1[i][num] || mp2[j][num] || mp3[k][num])
                        return false;
                    mp1[i][num] = mp2[j][num] = mp3[k][num] = 1;
                }
            }
        }
        return true;
    }
};
