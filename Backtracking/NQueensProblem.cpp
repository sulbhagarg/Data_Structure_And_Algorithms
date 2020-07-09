/* The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively. */

// HARD CATEGORY

class Solution {
public:
    bool isValid(vector<string>& temp, int row, int col, int n){
        if(row<0 && col<0)
            return true;
        for(int i=0;i<col;i++){
            if(temp[row][i]=='Q')
                return false;
        }
        for(int i=0;i<row;i++){
            if(temp[i][col]=='Q')
                return false;
        }
        int i=row-1,j=col-1;
        while(i>=0 && j>=0){
            if(temp[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        i=row-1;
        j=col+1;
        while(i>=0 && j<n){
            if(temp[i][j]=='Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    
    void solve(int n, int row,vector<vector<string>>& ans, vector<string>& temp){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(temp,row,i,n)){
                temp[row][i]='Q';
                solve(n,row+1,ans, temp);
                temp[row][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i].push_back('.');
            }
        }
        solve(n,0,ans,temp);
        return ans;
    }
};
