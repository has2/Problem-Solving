#include <iostream>
#define RED 0
#define BLACK 1

struct _RBNode
{
	int key;
	int color;
	struct _RBNode* left;
	struct _RBNode* right;
	struct _RBNode* parent;
};
typedef _RBNode Node;

Node* LEFT_ROTATE(Node* root,Node* x) {
	Node* y = x->right;
	x->right = y->left;
	if (y->left != NULL) 
	y->left->parent = x->parent;
	if (x->parent == NULL) {
		root = y;
	}
	else if (x->parent->left == x) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}

	y->left = x;
	x->parent = y;

	return root;

}

Node* RIGHT_ROTATE(Node* root, Node* x) {
	Node* y = x->left;
	x->left = y->right;
	if (y->right != NULL)
	y->right->parent = x->parent;
	if (x->parent == NULL) {
		root = y;
	}
	else if (x->parent->left == x) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}

	y->right = x;
	x->parent = y;

	return root;

}

Node* Insert(Node* root, int key) {
	Node* x = root;
	Node* y = NULL;
	Node* z = new Node;
	z->key = key;
	z->left = NULL;
	z->right = NULL;
	z->parent = NULL;
	z->color = RED;
	while (x != NULL) {
		y = x;
		if (x->key < z->key) {
			x = x->right;
		}
		else {
			x = x->left;
		}
	}
	if (y==NULL) {
		root = z;
	}
	else if (z->key < y->key) {
		z->parent = y;
		y->left = z;
	}
	else {
		z->parent = y;
		y->right = z;
	}
	return root;
}




int main(void) {

	Node* root = NULL;
	
	root=Insert(root, 6);
	root=Insert(root, 4);
	root=Insert(root, 10);
	root=Insert(root, 8);
	root=Insert(root, 14);
	root = Insert(root, 7);
	root = Insert(root, 9);
	root=RIGHT_ROTATE(root, root->right);
	std::cout << root->right->right->left->key;

}