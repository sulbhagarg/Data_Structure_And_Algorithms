/* 
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3] */

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
        v.push_back(node->val);
        traverse(node->left, v);
        traverse(node->right, v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        traverse(root, v);
        return v;
    }
};

// ITERATIVE

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* temp=root;
        int flag=0;
        while(!flag){
            if(temp){
                v.push_back(temp->val);
                s.push(temp);
                temp=temp->left;
            } else {
                if(!s.empty()){
                    temp=s.top();
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
