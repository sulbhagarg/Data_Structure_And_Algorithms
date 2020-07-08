/* Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.

Input:
First line consists of an integer T denoting the number of test cases. First line consists of two integers N and W, denoting number of items and weight respectively. Second line of every test case consists of 2*N spaced integers denoting Values and weight respectively. (Value1 Weight1 Value2 Weight2.... ValueN WeightN)

Output:
Print the maximum value possible to put items in a knapsack, upto 2 decimal place.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= W <= 100 */

bool sortcol(const vector<float>& v1, const vector<float>& v2){
    return v1[2]>v2[2];
}

float round1(float var) 
{ 
    float value = (int)(var * 100 + .5); 
    return (float)value / 100; 
} 

float fractionalKnapsack(vector<vector<float>>& v, int n, int w){
    float ans=0;
    sort(v.begin(), v.end(), sortcol);
    for(int i=0;i<n;i++){
        if(w<v[i][1]){
            ans+=(w/(float)v[i][1])*v[i][0];
            w = w - (w/(float)v[i][1])*v[i][1];
        }
        else{
            ans+=v[i][0];
            w = w - v[i][1];
        }
        if(w==0)
            return round1(ans);
    }
    return round1(ans);
}
