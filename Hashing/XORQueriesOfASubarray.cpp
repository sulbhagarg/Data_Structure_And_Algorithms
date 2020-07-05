/* Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array containing the result for the given queries. */

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> v;
        if(arr.size()<1)
            return v;
        int xortill[arr.size()];
        xortill[0]=0;
        for(int i=1;i<arr.size();i++)
            xortill[i]=xortill[i-1]^arr[i-1];
        for(int i=0;i<queries.size();i++)
            v.push_back(xortill[queries[i][0]]^xortill[queries[i][1]]^arr[queries[i][1]]);
        return v;
    }
};
