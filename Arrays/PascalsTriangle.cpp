// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

// P.S.: Faster thean 100% solution.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        for(int i=0;i<numRows;i++){
            for(int j=0;j<i+1;j++){
                if(i==0 || j==0 || j==i){
                    v[i].push_back(1);
                    continue;
                }
                v[i].push_back(v[i-1][j-1]+v[i-1][j]);
            }
        }
        return v;
    }
};
