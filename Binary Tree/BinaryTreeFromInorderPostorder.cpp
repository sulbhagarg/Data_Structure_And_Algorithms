/* Given inorder and postorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
For example, given
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
    TreeNode* buildTreeHelper(vector<int>& inorder, int inorder_start, int inorder_end, 
                              vector<int>& postorder, int postorder_start, int postorder_end){
        if(inorder_start>=inorder_end)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postorder_end-1]);
        int i=inorder_start;
        for(i=inorder_start;i<inorder_end;i++)
            if(inorder[i]==root->val)
                break;
        root->left = buildTreeHelper(inorder, inorder_start, i, postorder, 
                                     postorder_start, postorder_start+i-inorder_start);
        root->right = buildTreeHelper(inorder, i+1, inorder_end, postorder,
                                     postorder_start+i-inorder_start, postorder_end-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0 || inorder.size()==0)
            return NULL;
        return buildTreeHelper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
