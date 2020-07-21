/* Given a binary tree, find the leftmost value in the last row of the tree. */

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
    void dfs(TreeNode* root, int level, int *maxlevel, int *ans){
        if(!root)
            return;
        if(*maxlevel<level){
            *ans=root->val;
            *maxlevel=level;
        }
        dfs(root->left, level+1, maxlevel, ans);
        dfs(root->right, level+1, maxlevel, ans);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int maxlevel=0;
        int ans=root->val;
        dfs(root, 0, &maxlevel, &ans);
        return ans;
    }
};
