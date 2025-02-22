#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
	int val;
	struct linkedlist* next;
}sll;

sll* createnode(int val)
{
	sll* node=(sll*)malloc(sizeof(sll));
	node->val = val;	
	node->next=NULL;
	return node;
        	
}

sll* insert_last(sll* head,int val)
{
	if(!head)
	{
		head=createnode(val);
	}

	sll* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	sll* node=createnode(val);
	temp->next=node;                                                                                                                                                          
	return head;
}

sll* delete_last(sll* head )
{
	if(!head)
	{
		return head;
	}
	sll* temp =head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next = NULL;
	return head;
	
}

sll* search(sll* head,int val)
{
	if(!head)
	{
		return head;
	}
	sll* temp = head;
	while(temp->val !=val)
	{
		if(temp->val ==val)
		{
			printf("true");
		}
		else
		{
			temp = temp->next;
		}
	}
	return head;
}

void  display(sll* head)
{
	if(!head)
	{
		return ;
	}
	sll* temp =head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->val);
		temp=temp->next;
	}
	printf("NULL\n");


}

int main()
{
	sll* head=NULL;
	head = insert_last(head,3);
	head = insert_last(head,4);
	head = insert_last(head,5);
	head = search(head,4);
	head = delete_last(head);

	//linked list after deletion
	display(head);
}


	

	
