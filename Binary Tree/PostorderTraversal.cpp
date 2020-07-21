/* Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1] */

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
        traverse(node->right, v);
        v.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        traverse(root, v);
        return v;
    }
};

// ITERATIVE

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* temp=root;
        int flag=0;
        TreeNode* last=NULL;
        while(!flag){
            if(temp){
                s.push(temp);
                temp=temp->left;
            } else {
                if(!s.empty()){
                    TreeNode* temp1=s.top();
                    if(temp1->right && temp1->right!=last){
                        temp=temp1->right;
                    } else {
                        v.push_back(temp1->val);
                        last=temp1;
                        s.pop();
                    }
                } else {
                    flag=1;
                }
            }
        }
        return v;
    }
};
