#include <bits/stdc++.h>
#define Fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define Fread freopen("input.txt", "r", stdin);
#define Fout freopen("output.txt", "w", stdout);
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define nn '\n'
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x = (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x >> k) & 1)

#define mod 998244353
#define N 300005
#define pi acos(-1.0)

// Node Structure for a binary Search Tree
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to create a new Node
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the BST
Node *insertNode(Node *root, int data)
{
    // If the tree is empty , return a new node
    if (root == nullptr)
    {
        return createNode(data);
    }
    // otherwise , recur down the tree
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    // return the (unchanged) node pointer
    return root;
}

// Function to do inorder traversal of BST (Left-Node-Right)
void inorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Function to do Preorder traversal of BST (Node-Left-Right)
void preorderTraveral(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorderTraveral(root->left);
        preorderTraveral(root->right);
    }
}
// Function to do postorder traversal of BST (Left-Right-Node)
void postorderTraveral(Node *root)
{
    if (root != nullptr)
    {
        postorderTraveral(root->left);
        postorderTraveral(root->right);
        cout << root->data << " ";
    }
}

// Function to search a given key in a given BST
Node *searchNode(Node *root, int key)
{
    // Base Case: root is null or key is present at root
    if (root == nullptr || root->data == key)
    {
        return root;
    }
    // key is greater than root's key
    if (root->data < key)
    {
        return searchNode(root->right, key);
    }
    // Key is smaller than root's key
    return searchNode(root->left, key);
}

// Function to find the inorder successor
Node *minValueNode(Node *node)
{
    Node *current = node;
    // loop down to find the leftmost leaf
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

// Function to delete a node
Node *deleteNode(Node *root, int data)
{
    if (root == nullptr)
        return root;
    // if the data to be deleted is smaller than the root's
    // data, then it lies in the left subtree
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    // if the data to be deleted is greater than the root's
    // data , then it lies in the right subtree
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    // if data is same as root's data, then this is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main()
{
    Fast
#ifndef ONLINE_JUDGE
        Fread
            Fout
#endif
        Node *root = nullptr;

    // create a BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print the inorder traversal of a BST
    cout << "Inorder traversal of the given Binary Search  Tree is: ";
    inorderTraversal(root);
    cout << endl;

    cout<<"Preorder Traversal: ";
    preorderTraveral(root);
    cout<<endl;

    cout<<"PostOrder traversal: ";
    postorderTraveral(root);
    cout<<endl;


    // Delete a node in BST
    root = deleteNode(root, 20);
    cout << "After deletionn of 20: ";
    inorderTraversal(root);
    cout << endl;

    // Insert a node in BST
    root = insertNode(root, 25);
    cout << "After insertion of 25: ";
    inorderTraversal(root);
    cout << endl;

    // Search a key in BST
    Node *found = searchNode(root, 25);

    // check if the key is found or not
    if (found != nullptr)
    {
        cout << "Node 25 found in the BST." << endl;
    }
    else
    {
        cout << "Node 25 not found in the BST." << endl;
    }
    return 0;
}
