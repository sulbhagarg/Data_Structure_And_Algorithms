/* Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <--- */
  
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        vector<vector<int>> temp1;
        vector<int> temp2;
        if(!root)
            return v;
        queue<TreeNode*> q;
        queue<int> q1;
        int i=0;
        q.push(root);
        q1.push(i);
        while(!q.empty()){
            TreeNode* node=q.front();
            temp2.push_back(node->val);
            q.pop();
            q1.pop();
            if(node->left){
                q.push(node->left);
                q1.push(i+1);
            }
            if(node->right){
                q.push(node->right);
                q1.push(i+1);
            }
            if(q1.front()!=i){
                i++;
                temp1.push_back(temp2);
                temp2.clear();
            }
        }
        for(int i=0;i<temp1.size();i++){
            int x=temp1[i].size()-1;
            v.push_back(temp1[i][x]);
        }
        return v;
    }
};
