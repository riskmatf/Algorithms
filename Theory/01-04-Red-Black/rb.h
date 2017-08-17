#include <stdbool.h>

typedef struct node{
	int val;
	struct node* left;
	struct node* right;
	struct node* parrent;
	bool color;
}Node;
/*we have only two options for color, so bool fits well
macros are here just for better readability, values are not important*/

#define RED true
#define BLACK false

Node* new_node(int val);
int BST_insert(Node** root, Node* parrent, Node* new);
void insert_node(Node** root, int val);
void fix_tree_after_insert(Node** root, Node* curr);
void remove_node(Node** root, int val);
void fix_tree_after_remove(Node** root, Node* curr);

Node* rotate_left(Node*);
Node* rotate_right(Node*);

Node* find_min(Node* root);
Node* get_node(Node*root, int val);
Node* find_max(Node* root);

bool color_of(Node* node);
bool is_black(Node* node);
void swap_colors(Node* node1, Node* node2);
void set_color(Node* node, bool color);
bool is_red(Node* node);

void inorder(Node* root);

