/* Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:
    3
   / \
  9  20
    /  \
   15   7 */
   
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
    TreeNode* buildTreeHelper(vector<int>& preorder, int preorder_start, int preorder_end,
                             vector<int>& inorder, int inorder_start, int inorder_end){
        if(inorder_start>=inorder_end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preorder_start]);
        int i=inorder_start;
        for(i=inorder_start;i<inorder_end;i++)
            if(inorder[i]==root->val)
                break;
        root->left = buildTreeHelper(preorder, preorder_start+1, preorder_start+i-inorder_start+1,
                                    inorder, inorder_start, i);
        root->right = buildTreeHelper(preorder, preorder_start+i-inorder_start+1, preorder_end,
                                     inorder, i+1, inorder_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0 , inorder.size());
    }
};
