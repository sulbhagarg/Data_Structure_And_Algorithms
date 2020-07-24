/* There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case, if the either of predecessor or successor is not found print -1. */

/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

void inorder(Node* root, vector<Node*>& v){
    if(!root)
        return;
    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Your code goes here
    vector<Node*> v;
    inorder(root, v);
    int i=0;
    for(i=0;i<v.size();i++)
        if(v[i]->key>=key)
            break;
    if(i>0)
        pre=v[i-1];
    if(i<v.size()-1)
        suc=v[i+1];
    if(i<v.size() && v[i]->key>key)
        suc=v[i];
}
