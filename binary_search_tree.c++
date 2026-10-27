#include <iostream>
using namespace std;

// Definition of a Node in Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// 1. In-order Traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// 2. Pre-order Traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 3. Post-order Traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root == nullptr) return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int choice, val, n;

    cout << "------ Binary Search Tree Implementation ------\n";
    cout << "Enter the number of initial elements to insert: ";
    cin >> n;
    
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    do {
        cout << "\n-----------------------------\n";
        cout << "1. Insert an element\n";
        cout << "2. In-order Traversal\n";
        cout << "3. Pre-order Traversal\n";
        cout << "4. Post-order Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                cout << val << " inserted successfully.\n";
                break;
            case 2:
                cout << "In-order Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Pre-order Traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-order Traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please select correctly.\n";
        }
    } while(choice != 5);

    return 0;
}