typedef struct l_node{//List node
	int val;
	struct l_node* next;
}L_node;

#define B 3


typedef struct b_node{
	int num_of_keys;//XXX do I need this?
	L_node* head;//list of keys
	struct b_node *p[2*B];//array of pointers to nodes
}B_node;

L_node* create_L_node(int val);
B_node* create_B_node(int val);//mozda:?!?!?!?!


/*List manipulation functions*/
void add_to_list(L_node** head, int val);//since we are in B tree, adding will be sirted by default!
L_node* find_insert_place(L_node* head, int val);//returns pointer one node before the requested one
void remove_from_list(L_node** head, int val);
void split_list(L_node* head, L_node** left_head, L_node** right_head, L_node** pulled);
void print_list(L_node* head);
int list_size(L_node* head);

/*Node manipulation functions*/





//
