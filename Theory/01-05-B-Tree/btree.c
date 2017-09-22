#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "../util.h"
/*
 *XXX
 *B <= num of children < 2B
  B-1 <= Num of keys < 2B-1
  XXX
 * */


//ovde ce ici implementacije funkcija
//
//

L_node* create_L_node(int val){
	L_node* new = malloc(sizeof(L_node));
	if(new != NULL){
		new->val = val;
		new->next = NULL;
	}
	return new;
}
B_node* create_B_node(int val){
	B_node* new = malloc(sizeof(B_node));
	if(new != NULL){
		new->head = create_L_node(val);
		new->num_of_keys = 1;
		new->p[0] = NULL;
	}
	return new;
}


/*List manipulation functions*/


void add_to_list(L_node** head, int val){
	L_node* new = create_L_node(val);
	if(new == NULL){
		set_color_fg(RED);
		print_debug("NULL node at adding to list");
		clear_attribute();
	}
	if(*head == NULL){//list is empty
		*head = new;
		return;
	}
	else if((*head)->val > val){
		new->next = (*head);
		*head=new;
		return;
	}
	else{
		L_node* tmp = find_insert_place(*head, val);
		new->next=tmp->next;
		tmp->next = new;
	}
}

L_node* find_insert_place(L_node* head, int val){
	if(head == NULL)
		return NULL;
	if(head->val > val)
		return head;

	while(head->next != NULL && head->next->val < val){
		head = head->next;
	}
	return head;
}



void print_list(L_node* head){
	while(head){
		printf("%d ", head->val);
		head=head->next;
	}
}
void remove_from_list(L_node** head, int val){

	if(*head == NULL)
		return;

	if((*head)->val == val){
		L_node* tmp = *head;
		*head=(*head)->next;
		free(tmp);
		return;
	}
	L_node* tmp = *head;
	while(tmp != NULL && tmp->next != NULL && tmp->next->val != val){
		if(tmp->next->val == val){
			L_node* tmp2 = tmp->next;
			tmp->next = tmp2->next;
			free(tmp2);
			return;
		}
		else
			tmp=tmp->next;
	}
	return;//prepraviti malo funkciju zbog razloga
}
int list_size(L_node* head){
	int n = 0;
	while(head != NULL){
		n++;
		head=head->next;
	}
	return n;
}
void split_list(L_node* head, L_node** left_head, L_node** right_head, L_node** pulled){
	int size = list_size(head);
	size/=2;
	*left_head = head;
	L_node* tmp = head;
	while(1){//hehe
		size--;
		tmp = tmp->next;
		if(size == 1){
			*pulled = tmp->next;
			*right_head = tmp->next->next;
			tmp->next->next = NULL;
			tmp->next = NULL;
			return;
		}
	}
}
