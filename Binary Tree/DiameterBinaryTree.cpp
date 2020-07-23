/* Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
Note: The length of path between two nodes is represented by the number of edges between them. */

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
    int height(TreeNode* root, int h){
        if(!root)
            return h;
        return max(height(root->left, h+1),height(root->right,h+1));
    }
    int maxDiameter(TreeNode* root){
        if(!root)
            return 0;
        int left_height = height(root->left,0);
        int right_heigth = height(root->right,0);
        int left_diameter = maxDiameter(root->left);
        int right_diameter = maxDiameter(root->right);
        return max(left_height+right_heigth, max(left_diameter, right_diameter));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans;
        ans = maxDiameter(root);
        return ans;
    }
};
