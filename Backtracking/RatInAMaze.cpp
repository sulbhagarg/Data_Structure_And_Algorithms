/* Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (n-1, n-1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be travelled through.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line contains an integer N denoting the size of the square matrix. The next line contains N*N space separated values of the matrix m where 0's represents blocked paths and 1 represent valid paths.

Output:
For each test case, the output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination. Print -1 if no such path exists.

User Task:
Your task is to complete the function printPath() which returns a sorted array of strings denoting all the possible paths which the rat can take to reach the destination at (n-1, n-1). If no such path exists the function should return an empty array.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L*X), L = length of the path, X = number of paths.


Constraints:
1 <= T <= 100
2 <= N <= 5
0 <= matrix[i][j] <= 1 */

void solve(int x, int y, int m[MAX][MAX], int n, vector<string>& s, string temp){
    if(x<0 || y<0 || x>=n || y>=n || m[x][y]==0 || m[x][y]==-1){
        return;
    }
    if(x==n-1 && y==n-1){
        s.push_back(temp);
        return;
    }
    m[x][y]=-1;
    solve(x+1,y,m,n,s,temp+"D");
    solve(x-1,y,m,n,s,temp+"U");
    solve(x,y+1,m,n,s,temp+"R");
    solve(x,y-1,m,n,s,temp+"L");
    m[x][y]=1;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    string temp="";
    vector<string> ans;
    solve(0,0,m,n,ans, temp);
    sort(ans.begin(), ans.end());
    return ans;
}
