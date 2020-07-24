/* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int inorder(TreeNode* root, int& curr, int k){
        if(!root)
            return -1;
        int left = inorder(root->left, curr, k);
        curr++;
        if(curr==k)
            return root->val;
        int right = inorder(root->right, curr, k);
        if(left!=-1)
            return left;
        if(right!=-1)
            return right;
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int curr=0;
        return inorder(root, curr, k);
    }
};
