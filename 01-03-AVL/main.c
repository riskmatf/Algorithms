#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void){

	Node *root = NULL;
	int tmp;
	while(scanf("%d", &tmp) != EOF)
		root = insert(root, tmp);
	preorder(root);
	printf("\nDelete:");
	scanf("%d", &tmp);


	root = remove_element(root,tmp);
	preorder(root);
	printf("\n");

	return 0;
}
