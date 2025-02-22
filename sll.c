#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct linkedlist{
	int val;
	struct linkedlist *next;
} sll;

sll *createNode(int val){
	sll* node = (sll *)malloc(sizeof(sll));
	node->val = val;
	node->next = NULL;
	return node;
}

sll *insertLast(sll *head,int val){
	sll *temp = head;
	if(!head){
		head = createNode(val);
	}
	else{
		sll *node = createNode(val);
		while(temp->next){
			temp = temp->next;
		}
		temp->next = node;
		head = node;
	}
	printf("last");
	return head;
}

sll *insertStart(sll *head,int val){
	if(!head){
		head = createNode(val);
	}
	else{
		sll *node = createNode(val);
		node->next = head;
		head = node;
	}
	printf("start");
	return head;
		
}

sll *insertPos(sll *head,int val,int x){
	sll *temp = head;
	if(!head){
		head = createNode(val);
	}
	else{
		sll *node = createNode(val);
		while(x > 0){
			temp = temp->next;
			x--;
		}
		if(!temp->next){
			temp->next = node;
		}
		else
		{
			node->next = temp->next;
			temp->next = node;
		}
	}
	return head;
}
void display_list(sll *head)
{
	while(head!=NULL)
	{
		printf("%d->",head->val);
		head=head->next;
	}
//	printf("NULL\n");
}

void deleteFirst(sll *head){
	if(!head){
		return;
	}
	head = head->next;
}

void deleteLast(sll *head){
	if(!head){
		return;
	}
	sll *temp = head;
	while(temp->next->next){
		temp = temp->next;
	}
	temp->next = NULL;
}

void deletePos(sll *head,int x){
	sll *temp = head,*f=head,*s=head;
	if(!head){
		return;
	}
	while(x > 1){
		temp = temp->next;
		x--;
	}
	if(temp->next->next){
		temp->next = NULL;
	}
	else{
		temp->next = temp->next->next;
	}
}

int main(){

	sll *head = NULL;
	head=insertStart(head,2);
	head=insertStart(head,4);
	head=insertLast(head,8);
	display_list(head);

	return 0;
}
