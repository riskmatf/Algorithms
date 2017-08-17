#ifndef _AVL_
#define _AVL_
typedef struct node{
	int value;
	struct node* left;
	struct node* right;
}Node;


Node* make_node(int value);

Node* insert(Node* root, int value);
Node* remove_element(Node* root, int value);

Node* left_rotation(Node* root);
Node* right_rotation(Node* root);
Node* minimal_element(Node* root);

int height(Node *root);
int calculate_balance_factor(Node* root);
void preorder(Node* root);
void print_debug(char* string, int value);

#endif
