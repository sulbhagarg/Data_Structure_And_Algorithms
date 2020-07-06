/* Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself. */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        int n=digits.size();
        int flag=1;
        for(int i=n-1;i>=0;i--){
            int temp = digits[i]+flag;
            v.push_back(temp%10);
            flag=temp/10;
        }
        while(flag>0){
            v.push_back(flag);
            flag/=10;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
