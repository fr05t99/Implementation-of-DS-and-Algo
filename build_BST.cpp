#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
bool searcher(node *root, int element)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == element)
    {
        return true;
    }
    if (root->data < element)
    {
        return searcher(root->right, element);
    }
    else
    {
        return searcher(root->left, element);
    }
}
node* creator(node *root, int d)
{
    if (root == NULL)
    {
        return new node(d);
    }
    if (root->data >= d)
    {
        root->left = creator(root->left, d);
    }
    else
    {
        root->right = creator(root->right, d);
    }
    return root;
}
node* insertInBST()
{
    int d;
    cin >> d;
    node *root = NULL;
    while (d != -1)
    {
        root = creator(root, d);
        cin>>d;
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}
node* deleteInBST(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data > key)
    {
        root->left = deleteInBST(root->left, key);
        return root;
    }
    else if (root->data < key)
    {
        root->right = deleteInBST(root->right, key);
        return root;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        node* local = root->right;
        while (local->left != NULL)
        {
            local = local->left;
        }
        root->data = local->data;
        root->right = deleteInBST(root->right, local->data);
        return root;
    }
}
int main()
{
    node *root = insertInBST();
    inorder(root);
    cout << endl;
    bfs(root);
    //cout << endl;
    //int i;
    //cin >> i;
    //cout << searcher(root, i);
    root = deleteInBST(root, 3);
    bfs(root);
}

