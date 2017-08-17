#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

Node* make_node(int value){
	Node* new_node = malloc(sizeof(Node));
	if(new_node == NULL)
		return NULL;
	new_node->value = value;
	new_node->left = new_node->right = NULL;
	return new_node;
}



Node* insert(Node* root, int value){
	if(root == NULL)
		return make_node(value);
	if(root->value < value)
		root->right = insert(root->right, value);
	else if(root->value > value)
		root->left = insert(root->left, value);
	//BST does not allow insertions of values that are already in tree
	else
		return root;
	//calculate balance factor of current node
	int balance = calculate_balance_factor(root);
	/*
	 We have 4 cases:
	 left left = the critical node is in left subtree of left successor
	 right right = the critical node is in right subtree of right successor
	 left right = the critical node is in right subtree of left successor
	 right left = the critical node is in left subtree of right successor
	  */


	//left left
	if(balance > 1 && value < root->left->value){
		printf("\x1b[31mright rotate in %d\x1b[0m\n", root->value);
		return right_rotation(root);
	}
	//right right
	if(balance < -1 && value > root->right->value){
		printf("\x1b[34mleft rotate in %d\x1b[0m\n", root->value);
		return left_rotation(root);
	}
	//left right
	if(balance > 1 && value > root->left->value){

		printf("\x1b[34mleft rotate in %d\x1b[0m\n", root->value);
		root->left=left_rotation(root->left);
		printf("\x1b[31mright rotate in %d\x1b[0m\n", root->value);
		return right_rotation(root);
	}
	//right left
	if(balance < -1 && value < root->right->value){
		printf("\x1b[31mright rotate in %d\x1b[0m\n", root->value);
		root->right=right_rotation(root->right);
		printf("\x1b[34mleft rotate in %d\x1b[0m\n", root->value);
		return left_rotation(root);
	}
	return root;

}

Node* left_rotation(Node* root){
	Node* tmp1 = root->right;
	Node* tmp2 = tmp1->left;

	tmp1->left = root;
	root->right = tmp2;

	return tmp1;
}

Node* right_rotation(Node* root){
	Node* tmp1 = root->left;
	Node* tmp2 = tmp1->right;

	tmp1->right = root;
	root->left = tmp2;

	return tmp1;
}

Node* remove_element(Node* root, int value){
	/*
	 STEP 1:
	 Deletion from BST
	 */
	if(root == NULL)
		return root;
	if(value < root->value){
		root->left = remove_element(root->left, value);
	}
	else if(value > root->value){
		root->right = remove_element(root->right, value);
	}
	else{
		if(root->left == NULL || root->right == NULL){
			Node* tmp = (root->left) ? root->left : root->right;
			if(tmp == NULL){//case when we delete node that is leaf
				tmp = root;
				root = NULL;
			}
			else
				root = tmp;
			free(tmp);
		}
		else{
			Node* tmp = minimal_element(root->right);
			root->value = tmp->value;
			root->right = remove_element(root->right, root->value);
		}
	}
	if(root == NULL)
		return root;
	int balance = calculate_balance_factor(root);
	/*
	 STEP 2:
	 We distinguish 4 cases
	 */
	//left left
	if(balance > 1 && calculate_balance_factor(root->left) >= 0)
		return right_rotation(root);
	//right right
	if(balance < -1 && calculate_balance_factor(root->right) <= 0)
		return left_rotation(root);
	//left right
	if(balance > 1 && calculate_balance_factor(root->left) < 0){
		root->left = left_rotation(root->left);
		return right_rotation(root);
	}
	//right left
	if(balance < -1 && calculate_balance_factor(root->right) > 0){
		root->right = right_rotation(root->right);
		return left_rotation(root);
	}
	return root;
}


Node* minimal_element(Node* root){
	while(root->left != NULL)
		root = root->left;
	return root;
}

int calculate_balance_factor(Node* root){
	return height(root->left)-height(root->right);
}

int height(Node *root){
	if(root == NULL)
		return 0;
	int l = height(root->left);
	int d = height(root->right);
	return 1 + ((l > d) ? l : d);
}

void Preorder(Node* root){
	if(root == NULL)
		return;
	printf("%d ", root->value);
	Preorder(root->left);
	Preorder(root->right);
}

