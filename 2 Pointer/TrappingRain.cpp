/* Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. */

// It's a very good question.
// I have seen similar type of question in aptitude round, just at a little easy level.

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxLeft=0, maxRight=0;
        int ans=0;
        while(i<=j){
            if(height[i]<=height[j]){
                if(height[i]>=maxLeft)
                    maxLeft=height[i];
                else
                    ans+=maxLeft-height[i];
                i++;
            }
            else{
                if(height[j]>=maxRight)
                    maxRight=height[j];
                else
                    ans+=maxRight-height[j];
                j--;
            }
        }
        return ans;
    }
};
