#include <iostream>
#include <cstdio>

using namespace std;

struct Node{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

void add_node(Node *root, int temp)
{
    Node *current = root;
    Node *next = root;

    if(temp >= current->data)
    {
        if(current->right == NULL)
        {
            current->right = new Node;
            current->right->data = temp;
            return ;
        }
        else
        {
            next = current->right;
            add_node(next, temp);
        }
    }
    else
    {
        if(current->left == NULL)
        {
            current->left = new Node;
            current->left->data = temp;
            return ;
        }
        else
        {
            next = current->left;
            add_node(next, temp);
        }
    }
    return ;
}

void print(Node *root)
{
    if(root == NULL)
        return ;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
    return;
}

void find_key(Node *root, int key)
{
    Node *current = root;
    if(key == root->data)
        return;
    else if(key < root->data)
    {
        if(root->left==NULL)
            return;
        cout << "L";
        find_key(root->left, key);
    }
    else
    {
        if(root->right==NULL)
            return;
        cout << "R";
        find_key(root->right, key);
    }
    return;
}

int main()
{
    int num, key;
    while(cin >> num)
    {
        cin >> key;
        Node root;
        cin >> root.data;
        for(int i = 1; i < num; i++)
        {
            int temp;
            cin >> temp;
            add_node(&root, temp);
        }
        //print(&root);
        find_key(&root, key);
        cout << endl;
    }

    return 0;
}
