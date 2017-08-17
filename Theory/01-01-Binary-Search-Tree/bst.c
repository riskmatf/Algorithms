#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Node* create_node(int value){
	Node* new_node = malloc(sizeof(Node));
	new_node->val = value;
	new_node->left = new_node->right = NULL;
	return new_node;
}
int insert(Node** root, int value){
	if(*root == NULL){
		Node* new_node = create_node(value);
		*root = new_node;
		return 0;
		}
	if(value > (*root)->val)
		return insert(&(*root)->right, value);
	else if(value < (*root)->val)
		return insert(&(*root)->left, value);
	else
		return -1;//value already in BST

}
Node* find_max(Node* root){
	while(root->right)
		root=root->right;
	return root;
}
Node* find_min(Node* root){
	while(root->left)
		root=root->left;
	return root;
}
void delete(Node** root, int value){
	if(*root == NULL)
		printf("Value is not in BST");
    else if(value > (*root)->val)
		delete(&(*root)->right, value);
	else if(value < (*root)->val)
		delete(&(*root)->left, value);
	else{//found node that has to be deleted
		if((*root)->left == NULL || (*root)->right == NULL){//node has 0 or 1 child
			Node* tmp = ((*root)->left == NULL) ? (*root)->right : (*root)->left;
			free(*root);
			*root = tmp;
		}
		else{//node has 2 children
			Node* tmp = find_max((*root)->left);
			(*root)->val = tmp->val;
			delete(&(*root)->left, tmp->val);
		}
	}
}
void inorder(Node* root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}
void preorder(Node* root){
	if(root == NULL)
		return;
	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node* root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->val);
}
void inorder_custom_function(Node* root, void (*do_stuff)(Node* curr)){
	if(root == NULL){
		return;
	}
	inorder_custom_function(root->left, do_stuff);
	do_stuff(root);
	inorder_custom_function(root->right, do_stuff);
}
void square(Node* curr){
	printf("%d ", curr->val*curr->val);
}
int height(Node* root){
	if(root == NULL)
		return 0;
	int l = height(root->left);
	int r = height(root->right);
	return 1+((l>r) ? l : r);
}
