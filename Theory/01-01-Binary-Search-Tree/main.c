#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(){
	int pom;
	Node* root = NULL;
	while(scanf("%d", &pom)!=EOF)
		insert(&root, pom);
	inorder(root);
	printf("\nDelete: ");
	scanf("%d", &pom);
	delete(&root, pom);
	inorder(root);
	printf("\n");
	inorder_custom_function(root, &square);
	return 0;
}


