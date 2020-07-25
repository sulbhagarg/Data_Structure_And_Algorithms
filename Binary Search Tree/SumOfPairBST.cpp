/* Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target. */

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
    bool find(TreeNode* root, int k){
        if(!root)
            return false;
        if(root->val==k)
            return true;
        return find(root->left,k) || find(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
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
                    k-=temp->val;
                    if(k!=temp->val && find(root,k))
                        return true;
                    k+=temp->val;
                    s.pop();
                    temp=temp->right;
                } else {
                    flag=1;
                }
            }
        }
        return false;
    }
};
