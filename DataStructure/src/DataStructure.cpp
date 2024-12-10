#include <iostream>
#include "SinglyLinkedList.h"
//------------------------------------------------------------------------------

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    //Default constructor
    Node() = default;

    //parameterized constructor
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

//------------------------------------------------------------------------------

Node* CreateNode(int data)
{
    Node* node = new Node(data);

    return node;
}

//------------------------------------------------------------------------------

void PreOrderTraversal(Node* root)
{
    if (!root)
        return;

    std::cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);

}

//------------------------------------------------------------------------------

void InOrderTraversal(Node* root)
{
    if (!root)
        return;

    InOrderTraversal(root->left);
    std::cout << root->data << " ";
    InOrderTraversal(root->right);
}

//------------------------------------------------------------------------------

void PostOrderTraversal(Node* root)
{
    if (!root)
        return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    std::cout << root->data << " ";

}

//------------------------------------------------------------------------------

Node* SearchInBinaryTree(Node* root, int key)
{
    if (!root)
        return nullptr;

    if (root->data = key)
        return root;
    else if (root->data > key)
        SearchInBinaryTree(root->left, key);
    else if (root->data < key)
        SearchInBinaryTree(root->right, key);


    return nullptr;
}

//------------------------------------------------------------------------------

Node* SearchUsingIter(Node* root, int key)
{
    while (root)
    {
        if (root->data == key)
            return root;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;

    }

    return nullptr;
}

//------------------------------------------------------------------------------

void Insert(Node* root, int key)
{
    Node* previous = nullptr;

    while (!root)
    {
        previous = root;

        if (root->data == key)
            return;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    if (!previous)
        return;

    if (previous->data > key)
        previous->left = new Node(key);
    else
        previous->right = new Node(key);

}

//------------------------------------------------------------------------------

Node* InOrderPredecessor(Node* root) {
    root = root->left;
    while (root->right)
        root = root->right;
    return root;
}

//------------------------------------------------------------------------------

Node* DeleteNode(Node* root, int key) {
    if (!root)
        return nullptr;

    if (root->data > key)
        root->left = DeleteNode(root->left, key);
    
    else if (root->data < key)
        root->right = DeleteNode(root->right, key);
    else {

        if (!root->left && !root->right) {

            delete root;
            return nullptr;
        }
        else if (root->left) {
            
            Node* iPre = InOrderPredecessor(root);
            root->data = iPre->data;
            root->left = DeleteNode(root->left, iPre->data);
        }
        else {
            
            Node* temp = root->right;
            delete root;
            return temp;
        }
    }
    return root;
}


//------------------------------------------------------------------------------


int main()
{


    return 0;
}
