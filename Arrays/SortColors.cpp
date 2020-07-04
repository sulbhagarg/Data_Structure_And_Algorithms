// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// Note: You are not suppose to use the library's sort function for this problem.

// The Naive Approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_zero=0,count_one=0,count_two=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count_zero++;
            }
            else if(nums[i]==1){
                count_one++;
            }
            else{
                count_two++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(count_zero>0){
                nums[i]=0;
                count_zero--;
            }
            else if(count_one>0){
                nums[i]=1;
                count_one--;
            }
            else{
                nums[i]=2;
            }
        }
    }
};

// Optimised Approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        for(int i=0;i<=r;i++){
            if(nums[i]==0 && i!=l){
                swap(nums[i--],nums[l++]);
            }
            else if(nums[i]==2 && i!=r){
                swap(nums[i--],nums[r--]);
            }
        }
    }
};
