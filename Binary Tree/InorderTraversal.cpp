/* Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2] */

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
 
// RECURSIVE

class Solution {
public:
    void traverse(TreeNode* node, vector<int>& v){
        if(node==NULL)
            return;
        traverse(node->left, v);
        v.push_back(node->val);
        traverse(node->right, v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        traverse(root, v);
        return v;
    }
};

// ITERATIVE

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root)
            return v;
        int flag=0;
        stack<TreeNode*> s;
        TreeNode* temp=root;
        while(!flag){
            if(temp){
                s.push(temp);
                temp=temp->left;
            } else {
                if(!s.empty()){
                    temp=s.top();
                    v.push_back(temp->val);
                    s.pop();
                    temp=temp->right;
                } else {
                    flag=1;
                }
            }
        }
        return v;
    }
};
