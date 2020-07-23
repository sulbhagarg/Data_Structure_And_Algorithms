/* Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root. */

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
    int maxPathSum1(TreeNode* root, int &ans){
        if(!root)
            return 0; 
        int left =  max(0, maxPathSum1(root->left, ans));
        int right = max(0, maxPathSum1(root->right, ans));
        ans = max(ans, root->val+left+right);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSum1(root,ans);
        return ans;
    }
};
