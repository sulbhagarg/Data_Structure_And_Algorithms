/* Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   */
     
void dfs(Node* root, int level, int *maxlevel){
    if(!root)
        return;
    if(*maxlevel<level){
        cout << root->data << " ";
        *maxlevel = level;
    }
    dfs(root->left,level+1,maxlevel);
    dfs(root->right,level+1,maxlevel);
}
void leftView(Node *root)
{
   // Your code here
    int maxlevel=-1;
    dfs(root,0,&maxlevel);
}
