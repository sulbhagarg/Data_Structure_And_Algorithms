/* Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    void bfs(TreeNode* node, vector<vector<int>>& ans, vector<int>& temp){
        queue<TreeNode*> q;
        queue<int> q1;
        if(!node)
            return;
        int i=0;
        q.push(node);
        q1.push(i);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            q1.pop();
            temp.push_back(curr->val);
            if(curr->left){
                q.push(curr->left);
                q1.push(i+1);
            }
            if(curr->right){
                q.push(curr->right);
                q1.push(i+1);
            }
            if(q1.front()!=i){
                if(i%2)
                    reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                temp.clear();
                i++;
            }
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        bfs(root, ans, temp);
        return ans;
    }
};
