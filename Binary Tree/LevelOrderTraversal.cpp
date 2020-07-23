/* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
] */

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
    void bfs(TreeNode* node, vector<vector<int>>& v, int i){
        vector<int> v1;
        if(node==NULL)
            return;
        queue<TreeNode* > q;
        queue<int> q1;
        q.push(node);
        q1.push(i);
        while(q.empty()==false){
            TreeNode* node1 = q.front();
            v1.push_back(node1->val);
            // cout << i << " " << node1->val << endl;
            q.pop();
            q1.pop();
            
            if(node1->left!=NULL){
                q.push(node1->left);
                q1.push(i+1);
            }
            if(node1->right!=NULL){
                q.push(node1->right);
                q1.push(i+1);
            }
            if(q1.front()!=i){
                i++;
                v.push_back(v1);
                v1.clear();
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        bfs(root, v, 0);
        return v;
    }
};
