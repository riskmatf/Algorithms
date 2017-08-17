#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rb.h"

Node* create_node(int val){
	Node* new_node = malloc(sizeof(Node));
	if(new_node == NULL)
		return new_node;
	new_node->val=val;
	new_node->left=new_node->right=new_node->parrent=NULL;
	new_node->color=RED;
	return new_node;
}

//this is classic insert into BST, with addition of parrent pointer
int BST_insert(Node** root, Node* parrent, Node* new){
	if(*root == NULL){
		new->parrent=parrent;
		*root=new;
		return 0;
	}
	if(new->val > (*root)->val){
		return BST_insert(&(*root)->right, *root, new);
	}
	else if(new->val < (*root)->val){
		return BST_insert(&(*root)->left, *root, new);
	}
	else
		return -1;//Value allready in BST

}

void insert_node(Node** root, int val){
	Node* new=create_node(val);
	if(BST_insert(root, NULL, new)!=0)
		printf("Value allready in BST.\n");
	else
		fix_tree_after_insert(root, new);
}

void fix_tree_after_insert(Node** root, Node* curr){
	Node* parrent_ptr=NULL;
	Node* g_parrent_ptr=NULL;

	while(curr!=*root && is_red(curr) && is_red(curr->parrent)){
		parrent_ptr=curr->parrent;
		g_parrent_ptr=parrent_ptr->parrent;
		/*  Case : A
		Parent of pt is left child of Grand-parent of pt */
		if(parrent_ptr==g_parrent_ptr->left){
			Node* uncle = g_parrent_ptr->right;
			/*
			 Case A1: uncle is red
			 Only recoloring is required
			 */
			if(uncle!=NULL && uncle->color==RED){
				g_parrent_ptr->color=RED;
				uncle->color=BLACK;
				parrent_ptr->color=BLACK;
				curr=g_parrent_ptr;//since we are in a loop, we do this so that we could check up if any problem occurred
			}
			/*
			 CaseA2
			 uncle is either NULL or BLACK, we do rotations
			 */
			else{
				if(curr==parrent_ptr->right){
					curr=rotate_left(parrent_ptr);
					g_parrent_ptr->left=curr;
					curr->parrent=g_parrent_ptr;
				}
				if(g_parrent_ptr == *root){
				*root=rotate_right(g_parrent_ptr);
				swap_colors(*root, g_parrent_ptr);
				}
				else{
					curr=rotate_right(g_parrent_ptr);
					if(curr->val>curr->parrent->val)
						curr->parrent->right=curr;
					else
						curr->parrent->left=curr;
					swap_colors(curr, g_parrent_ptr);
				}
			}
		}

		else{
			/*Case B:
			  we are in right subtree, so uncle is left
			 */
			Node* uncle = g_parrent_ptr->left;
			/*Case B1:
			uncle is red, only recoloring is required*/
			if(is_red(uncle)){
				set_color(g_parrent_ptr, RED);
				set_color(uncle, BLACK);
				set_color(parrent_ptr, BLACK);
				curr=g_parrent_ptr;
			}
			else{
				/*
				 Case B2:
				 uncle is either black or NULL, we do rotations
				 */
				if(curr==parrent_ptr->left){
					curr=rotate_right(parrent_ptr);
					g_parrent_ptr->right=curr;
				}
				if(g_parrent_ptr == *root){
					*root=rotate_left(g_parrent_ptr);
					swap_colors(*root, g_parrent_ptr);
				}
				else{
					curr=rotate_left(g_parrent_ptr);
					if(curr->val>curr->parrent->val)
						curr->parrent->right=curr;
					else
						curr->parrent->left=curr;
					swap_colors(curr, g_parrent_ptr);
					}
				}

			}
		}

	set_color(*root, BLACK);
}

void remove_node(Node** root, int val){
	Node* to_remove = get_node(*root, val);
	if(to_remove == NULL){
		printf("Value is not in BST!\n");
		return;
	}
	/*if we are deleting node with both children we copy the successor and then remove the succesor, so we
	only deal with cases when we are deletiong leaf or node that has one child*/
	else if(to_remove->left!=NULL && to_remove->right!=NULL){//case when node has both children
/*		Node* tmp = find_min(to_remove->right);
		it does not matter if we are replacing it with minimum in right subtree or maximum in left subtree
		both versions are here, test them as you like*/

		Node* tmp = find_max(to_remove->left);
		to_remove->val = tmp->val;
		to_remove=tmp;
	}
	/*if node had 0 or 1 child, we skip straight to here, if not, previous block made sure that is the case now
	so we continue to remove that one node that has 0 or 1 child*/
	Node* change = (to_remove->left == NULL) ? to_remove->right : to_remove->left;

	if(change != NULL){
		Node* parrent_ptr = to_remove->parrent;
		change->parrent = parrent_ptr;
		if(to_remove == *root){
			*root=change;
		}
		else if(parrent_ptr->left == to_remove){
			parrent_ptr->left = change;
		}
		else{
			parrent_ptr->right = change;
		}
		if(to_remove->color == BLACK)
			fix_tree_after_remove(root, change);
	}
	else if(to_remove == *root){
		*root = NULL;
	}
	else{
		if(to_remove->color == BLACK)
			fix_tree_after_remove(root, to_remove);
	}
	/*
	 *You will notice that this block is similar to one above
	The reason that these are two different cases is the implementation of fix function
	it wouldnt work properly if this was done ignoring existance of change node
	*/
	if(to_remove != *root && change == NULL){
		if(to_remove->parrent->left == to_remove)
			to_remove->parrent->left = NULL;
		else
			to_remove->parrent->right=NULL;
	}

	free(to_remove);

}

void fix_tree_after_remove(Node** root, Node* curr){
	while(curr!=*root && is_black(curr)){
		if(curr == curr->parrent->left){
			Node* parrent_ptr = curr->parrent;
			Node* sibling = parrent_ptr->right;
			if(is_red(sibling)){
				set_color(parrent_ptr, RED);
				set_color(sibling, BLACK);
				if(parrent_ptr == *root)
					*root=rotate_left(parrent_ptr);
				else{
					sibling=rotate_left(parrent_ptr);
					sibling->parrent->right=sibling;//since we know that sibling is here right child we can safely do this
				}
				sibling=parrent_ptr->right;
			}
			if(is_black(sibling->left) && is_black(sibling->right)){
				set_color(sibling, RED);
				curr=curr->parrent;
			}
			else{
				/*one or both of siblings children is red
				sibling is right child, if the right child of sibling is black that means that left child is red
				that gives us right left case which we transform in right right case*/
				if(is_black(sibling->right)){
					set_color(sibling, RED);
					set_color(sibling->left, BLACK);
					
					sibling->parrent->right = rotate_right(sibling);//since sibling cant be root, no need to check that
					sibling=curr->parrent->right;
				}
				//right right case
				set_color(sibling, color_of(curr->parrent));
				set_color(curr->parrent, BLACK);
				set_color(sibling->right, BLACK);
				if(parrent_ptr == *root){
					*root=rotate_left(parrent_ptr);
				}
				else{
					sibling=rotate_left(parrent_ptr);
					if(parrent_ptr->parrent->parrent->left == parrent_ptr){
						parrent_ptr->parrent->parrent->left = sibling;
					}
					else
						parrent_ptr->parrent->parrent->right = sibling;
				}
				curr=*root;
			}

		}
		else{
			//case when current node is right child, mirror case of case above
			Node* parrent_ptr = curr->parrent;
			Node* sibling = parrent_ptr->left;
			if(is_red(sibling)){
				set_color(sibling, BLACK);
				set_color(parrent_ptr, RED);
				//right rotate
				if(*root == parrent_ptr)
					*root=rotate_right(parrent_ptr);
				else{
					sibling=rotate_right(parrent_ptr);
					sibling->parrent->left = sibling;//we know that sibling is left
				}
				sibling=parrent_ptr->left;
			}
			if(is_black(sibling->left) && is_black(sibling->right)){
				set_color(sibling, RED);
				curr=curr->parrent;
			}
			else{
				if(is_black(sibling->left)){
					set_color(sibling->right, BLACK);
					set_color(sibling, RED);
					sibling->parrent->left=rotate_left(sibling);
					sibling=curr->parrent->left;
				}
				set_color(sibling, color_of(curr->parrent));
				set_color(curr->parrent, BLACK);
				set_color(sibling->left, BLACK);
				if(parrent_ptr == *root){
					*root = rotate_right(parrent_ptr);
				}
				else{
					sibling=rotate_right(parrent_ptr);
					if(parrent_ptr->parrent->parrent->left == parrent_ptr)
						parrent_ptr->parrent->parrent->left = sibling;
					else
						parrent_ptr->parrent->parrent->right=sibling;
				}
				curr=*root;
			}
		}

	}
	set_color(curr, BLACK);
}



Node* rotate_left(Node* curr){
	Node* tmp1=curr->right;
	Node* tmp2=tmp1->left;
	curr->right=tmp2;
	if(tmp2!=NULL)
		tmp2->parrent=curr;
	tmp1->left=curr;
	tmp1->parrent=curr->parrent;
	curr->parrent=tmp1;
	curr=tmp1;
	return curr;
}
Node* rotate_right(Node* curr){
	Node* tmp1=curr->left;
	Node* tmp2=tmp1->right;
	curr->left=tmp2;
	if(tmp2!=NULL)
		tmp2->parrent=curr;
	tmp1->right=curr;
	tmp1->parrent=curr->parrent;
	curr->parrent=tmp1;
	curr=tmp1;
	return curr;
}


Node* find_min(Node* root){
	while(root->left != NULL)
		root=root->left;
	return root;
}

Node* get_node(Node* root, int val){
	if(root == NULL)
		return NULL;
	else if(val > root->val)
		return get_node(root->right, val);
	else if(val < root->val)
		return get_node(root->left, val);
	else
		return root;
}
Node* find_max(Node* root){
	if(root == NULL)
		return NULL;
	while(root->right)
		root=root->right;
	return root;
}
void swap_colors(Node* node1, Node* node2){
	bool tmp=node1->color;
	node1->color=node2->color;
	node2->color=tmp;
}
//helper functions, here so that code would be more pleasant to read, gets rid of all the NULL checks in conditions
void set_color(Node* node, bool color){
	if(node!=NULL)
		node->color=color;
}
bool is_black(Node* node){
	return (node == NULL) ? true : node->color == BLACK;
}

bool is_red(Node* node){
	return (node == NULL) ? false : node->color == RED;
}
bool color_of(Node* node){
	return (node == NULL) ? BLACK : node->color;
}

void inorder(Node* root){
	if(root == NULL)
		return;
	inorder(root->left);
	int color = (root->color == BLACK) ? 90 : 31;
	printf("\e[1;%d;107m%d \e[0;0m\n", color,root->val);//using escape codes for nicer output
	inorder(root->right);
}
