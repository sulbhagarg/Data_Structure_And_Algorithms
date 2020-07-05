// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
// The Naive Approaches would require O(mn) or O(m+n) space.

// Following is the O(1) space sol.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int col0=1;
        if(n==0)
            return;
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0)
                col0=0;
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>0;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(col0==0)
                matrix[i][0]=0;
        }
    }
};
