#include <iostream>
#include <cstdlib>
#include <ctime>

class Node
{
    public:
    unsigned int ID, hp, base_attack;
    Node* right = nullptr;
    Node* left = nullptr;

    Node(unsigned int ID, unsigned int hp, unsigned int base_attack) : hp(hp), base_attack(base_attack), ID(ID) {}
    Node() {}
};

class BST
{
    Node* root = nullptr;
    
    Node* insert(Node* node, unsigned int ID, unsigned int hp, unsigned int base_attack)
    {
        if (!node)
        return new Node(ID, hp, base_attack);

        if (node->ID > ID)
        node->right = insert(node->right, ID, hp, base_attack);

        else if (node->ID < ID)
        node->left = insert(node->left, ID, hp, base_attack);

        return node;
    }

    Node* deleteBSTNode(Node* node, int ID)
    {
        if (!node)
        return nullptr;

        if (node->ID < ID)
        node->right = deleteBSTNode(node->right, ID);

        else if (node->ID > ID)
        node->left = deleteBSTNode(node->left, ID);
        
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
            node->ID = new_node->ID;
            node->right = deleteBSTNode(node->right, new_node->ID);
        }

        return node;
    }

    Node* search(Node* node, int ID)
    {
        if (!node) return nullptr;
        
        if (node->ID == ID) return node;

        if (node->ID > ID) return search(node->left, ID);

        return search(node->right, ID);
    }

    void inOrder(Node* node)
    {
        if (!node)
        return;

        if (!node->right && !node->left)
        {
            std::cout << node->ID << std::endl;
            return;
        }

        inOrder(node->left);
        std::cout << node->ID << std::endl;
        inOrder(node->right);
    }

    Node* getMin(Node* node)
    {
        if (!node->left)
        return node;

        return getMin(node->left);
    }

    public:
    Node* searchNode(int ID)
    {
        return search(root, ID);
    }

    void insertNode(unsigned int ID, unsigned int hp, unsigned int base_attack)
    {
        Node* tmp = insert(root, ID, hp, base_attack);

        if (!root)
        root = tmp;
    }

    void deleteNode(int ID)
    {
        root = deleteBSTNode(root, ID);
    }

    Node* getMinNode()
    {
        return getMin(root);
    }

    void printInOrder()
    {
        inOrder(root);
    }
};

class Game
{
    BST player;
    BST enemy;
    Node* active_player;
    Node* active_enemy;
    int rand_num;

    public:
    Game()
    {   int k;
        srand(time(0));
        unsigned int IDs[5] = {3, 2, 4, 0, 5};

        //init player
        for (int i = 0; i < 5; i++)
        {
            rand_num = rand() % 20;
            player.insertNode(IDs[i], 100, 15 + rand_num);
        }
        
        active_player = player.searchNode(0);

        //init enemy
        for (int i = 0; i < 5; i++)
        {
            rand_num = rand() % 20;
            enemy.insertNode(IDs[i], 100, 15 + rand_num);
        }
        active_enemy = enemy.searchNode(0);
    }

    bool attack(Node*& attacker, Node*& defender, BST* defender_tree)
    {
        rand_num = rand() % 5;
        defender->hp -= (attacker->base_attack + rand_num);
        if (defender->hp <= 0) defender_tree->deleteNode(defender->ID);
        defender = defender_tree->getMinNode();
    }

    void simulateGame()
    {
        int round_num = 1;
        while(1)
        {
            
            if (round_num % 2) attack(active_player, active_enemy, &enemy);

            else attack(active_enemy, active_player, &player);

            if (!active_enemy || !active_player)
            break;

            round_num++;
        }
    }
};

int main ()
{

}