/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row. */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0)
            return false;
        int m=matrix[0].size();
        if(m==0)
            return false;
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(matrix[mid][0]==target)
                return true;
            if(l==r)
                break;
            if(matrix[mid][0]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        int row;
        if(matrix[l][0]>target && l>0)
            l--;
        row=l;
        l=0,r=m-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return false;
    }
};
