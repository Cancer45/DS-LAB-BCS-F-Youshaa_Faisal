#include <iostream>

class Node
{
    public:
    int val;
    Node* right = nullptr;
    Node* left = nullptr;

    Node(int val) : val(val) {}
    Node() {}
};

class BST
{
    Node* root = nullptr;
    
    Node* insert(Node* node, int val)
    {
        if (!node)
        return new Node(val);

        if (node->val > val)
        node->right = insert(node->right, val);

        else if (node->val < val)
        node->left = insert(node->left, val);

        return node;
    }

    Node* search(Node* node, int val)
    {
        if (!node) return nullptr;
        
        if (node->val == val) return node;

        if (node->val > val) return search(node->left, val);

        return search(node->right, val);
    }

    void inOrder(Node* node)
    {
        if (!node)
        return;

        if (!node->right && !node->left)
        {
            std::cout << node->val << std::endl;
            return;
        }

        inOrder(node->left);
        std::cout << node->val << std::endl;
        inOrder(node->right);
    }

    void preOrder(Node* node)
    {
        if (!node)
        return;

        if (!node->right && !node->left)
        {
            std::cout << node->val << std::endl;
            return;
        }

        std::cout << node->val << std::endl;
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node)
    {
        if (!node)
        return;

        if (!node->right && !node->left)
        {
            std::cout << node->val << std::endl;
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->val << std::endl;
    }

    public:
    Node* searchNode(int val)
    {
        return search(root, val);
    }

    void insertNode(int val)
    {
        Node* tmp = insert(root, val);

        if (!root)
        root = tmp;
    }

    void printInOrder()
    {
        inOrder(root);
    }

    void printPreOrder()
    {
        preOrder(root);
    }

    void printPostOrder()
    {
        postOrder(root);
    }
    Node* deleteNode(Node* node, int val)
    {
        if (!node)
        return nullptr;

        if (node->val < val)
        node->right = deleteNode(node->right, val);

        else if (node->val > val)
        node->left = deleteNode(node->left, val);
        
        else
        {
            if (!node->right && !node->left)
            {
                delete node;
                return nullptr;
            }

            if (!node->right)
            {
                Node* tmp = node->left;
                delete node;
                return tmp;
            }

            if (!node->left)
            {
                Node* tmp = node->right;
                delete node;
                return tmp;
            }

            Node* new_node = node->right;
            while (new_node->left) new_node = new_node->left;
            node->val = new_node->val;
            node->right = deleteNode(node->right, new_node->val);
        }

        return node;
    }
};