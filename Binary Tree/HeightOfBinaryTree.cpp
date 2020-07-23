/* Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.
Example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its depth = 3. */

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
    int maximum_depth(TreeNode* root, int depth) {
        if(!root)
            return depth;
        int left = maximum_depth(root->left, depth+1);
        int right = maximum_depth(root->right, depth+1);
        return max(left, right);
    }
    int maxDepth(TreeNode* root) {
        int depth=0;
        return maximum_depth(root, depth);
    }
};
