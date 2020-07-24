/* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructBST(vector<int>& nums, int start, int end){
        if(start>=end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = constructBST(nums,start,mid);
        root->right = constructBST(nums, mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums,0,nums.size());
    }
};
