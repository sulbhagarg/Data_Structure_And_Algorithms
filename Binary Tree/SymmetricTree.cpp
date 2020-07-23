/* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center). */

// iterative
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
    void bfs(TreeNode* node, vector<vector<TreeNode*>>& v, int i){
        vector<TreeNode*> v1;
        if(node==NULL)
            return;
        queue<TreeNode* > q;
        queue<int> q1;
        q.push(node);
        q1.push(i);
        while(q.empty()==false){
            TreeNode* node1 = q.front();
            v1.push_back(node1);
            q.pop();
            q1.pop();
            if(node1){
                q.push(node1->left);
                q1.push(i+1);    
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
    
    bool isSymmetric(TreeNode* root) {
        if(!root || (root->left==NULL && root->right==NULL))
            return true;
        vector<vector<TreeNode*>> v;
        bfs(root, v, 0);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size()/2;j++){
                if((v[i][j] && !v[i][v[i].size()-j-1]) || (!v[i][j] && v[i][v[i].size()-j-1]) || 
                   ((v[i][j] && v[i][v[i].size()-j-1] && v[i][j]->val!=v[i][v[i].size()-j-1]->val)))
                    return false;
            }
        }
        return true;
    }
};

// recursive

coming soon..
