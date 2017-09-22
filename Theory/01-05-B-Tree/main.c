#include <stdio.h>
#include <stdlib.h>
#include "btree.h"


int main(){
	L_node* head = NULL;
	add_to_list(&head, 1);
	add_to_list(&head, 4);
	add_to_list(&head, 23);
	add_to_list(&head, 32145);
	add_to_list(&head, 0);

	print_list(head);

	L_node *pulled, *left, *right;
	split_list(head, &left, &right, &pulled);
	printf("head: ");
	print_list(head);
	printf("\nleft head: ");
	print_list(left);
	printf("\nright head: ");
	print_list(right);
	printf("\npulled: ");
	print_list(pulled);

	return 0;
}
