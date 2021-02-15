#include <stdio.h> 			
#include <stdlib.h> 
typedef int element;
typedef struct Listnode{
	element data;
	struct Listnode *link;
}Listnode;

void error(char *message){
	fprintf(stderr,"%s\n",message);
	exit(1);
}

Listnode *create_node(element data, Listnode *link){
	Listnode *newnode;
	newnode = (Listnode *)malloc(sizeof(Listnode));
	if(newnode ==NULL) error("memort allocation failed");
	newnode->data = data;
	newnode->link = link;
	return(newnode);
}

void display(Listnode *head){
	Listnode *p;
	if(head == NULL) return ;
	
	p= head;
	do{printf("%d -> ", p->data);
	p = p->link;
	
	}while(p != head);
}

void insert_first(Listnode **phead, Listnode *node){
	if(*phead == NULL){
		*phead = node;
		node->link = node;
	}
	
	else{
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
}

void insert_last(Listnode **phead, Listnode *node){
	if(*phead == NULL){
		*phead = node;
		node->link = node;
	}
	
	else{
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
	}
}

int main(){
	Listnode *list1 = NULL;
	
	 insert_first(&list1, create_node(10,NULL));
	  insert_first(&list1, create_node(20,NULL));
	   insert_last(&list1, create_node(30,NULL));
	   
	display(list1);
	
} 
