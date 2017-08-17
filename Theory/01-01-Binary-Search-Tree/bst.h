
typedef struct node Node;

struct node{
	int val;
	Node* left;
	Node* right;
};

Node* create_node(int value);
int insert(Node** root, int value);
void delete(Node** root, int value);

Node* find_max(Node* root);
Node* find_min(Node* root);

void preorder(Node* root);
void postorder(Node* root);
void inorder(Node* root);
/*
	This function is used to traverse a tree and, insetad of just typing the value of node, it calls a function on
	that node. Change it to get better results, square is just demo.
 */
void inorder_custom_function(Node* root, void (*do_stuff)(Node* curr));
void square(Node* curr);
int height(Node* root);
