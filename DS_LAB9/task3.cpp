#include <iostream>

class IntNode
{
	public:
	int val, height;
	IntNode* right = nullptr;
	IntNode* left = nullptr;
	IntNode(int val) : val(val), height(0) {}
};

int max (int num1, int num2)
{
	if (num1 > num2)
    return num1;

	else
	return num2;
}

int height(IntNode* input)
{
    if (input)
    return input->height;

    return 0;
}

int balance(IntNode* input)
{
	return height(input->left) - height(input->right);
}

IntNode* rotateRight(IntNode* input)
{
	IntNode* left_sub = input->left;
	IntNode* left_right_sub = left_sub->right;

	left_sub->right = input;
	input->left = left_right_sub;

	input->height = max(height(input->left), height(input->right)) + 1;
	left_sub->height = max(height(left_sub->left), height(left_sub->right)) + 1;

	return left_sub;
};

IntNode* rotateLeft(IntNode* input)
{
	IntNode* right_sub = input->right;
	IntNode* right_left_sub = right_sub->left;

	right_sub->left = input;
	input->right = right_left_sub;

	input->height = max(height(input->right), height(input->left)) + 1;
	right_sub->height = max(height(right_sub->right), height(right_sub->left)) + 1;

	return right_sub;
}

IntNode* insertAVL(IntNode* input, int val)
{
	if (!input)
	return new IntNode(val);

	if (val < input->val)
	input->left = insertAVL(input->left, val);

	else if (val > input->val)
	input->right = insertAVL(input->right, val);

	else return input;

	input->height = max(height(input->left), height(input->right)) + 1;
	int bal = balance(input);

	if (bal > 1 && val < input->left->val)
	return rotateRight(input);

	if (bal < -1 && val > input->right->val)
	return rotateLeft(input);

	if (bal > 1 && val > input->left->val)
	{
		input->left = rotateLeft(input->left);
		return rotateRight(input);
	}
	
	if (bal < -1 && val < input->right->val)
	{
		input->right = rotateRight(input->right);
		return rotateLeft(input);
	}

	return input;
}

void displayInOrder(IntNode* root)
{
	if (!root)
	return;

    if (!root->right && !root->left)
    {
        std::cout << root->val << "     ";
        return;
    }

    displayInOrder(root->left);
    std::cout << root->val << "     ";
    displayInOrder(root->right);
}

int main ()
{
    IntNode* root = nullptr;

    //build tree
    root = insertAVL(root, 10);
    root = insertAVL(root, 5);
    root = insertAVL(root, 15);
    root = insertAVL(root, 3);
    root = insertAVL(root, 7);

    //insert 55
    insertAVL(root, 12);

    displayInOrder(root);
    std::cout << std::endl;
}