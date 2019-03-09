#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* buildBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
    }
    else if (root->data > d)
    {
        root->left = buildBST(root->left, d);
    }
    else
    {
        root->right = buildBST(root->right, d);
    }
    return root;
}
void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node *deleteInBST(Node *root, int key)
{
    if (root == NULL)
    {
        delete root;
        return NULL;
    }
    if (root->data < key)
    {
        root->right = deleteInBST(root->right, key);
        return root;
    }
    if (root->data > key)
    {
        root->left = deleteInBST(root->left, key);
        return root;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteInBST(root->right, temp->data);
            return root;
        }
    }
}
int main()
{
    int a[] = {3, 2, 1, 4, 5};
    Node *root = NULL;
    for (int i = 0;i < 5;i++)
    {
        root = buildBST(root, a[i]);
    }
    inorder(root);
    cout << endl;
    root = deleteInBST(root, 1);
    inorder(root);
}
