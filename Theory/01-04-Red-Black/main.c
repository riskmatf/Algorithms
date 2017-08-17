#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rb.h"

int main(void){

	Node* root=NULL;
	int tmp;
	while(scanf("%d", &tmp)!=EOF)
		insert_node(&root, tmp);
	inorder(root);
	printf("\nDelete: ");
	scanf("%d", &tmp);
	remove_node(&root, tmp);
	inorder(root);
	printf("\n");
	return 0;
}
