#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
	int val;
	struct linkedlist* next;
}sll;

sll* create_node(int val)
{
	sll* node =(sll*)malloc(sizeof(sll));
	node->val = val;
	node->next =NULL;
	return node;
}

void display_ll(sll* head)
{
	if(!head)
	{
		return;
	}
	sll* temp = head;
	while(temp->next)
	{
		printf("%d\n",temp->val);
		temp = temp->next;
	}
	printf("end\n");

}


sll* insert_last(sll* head,int val)
{
	if(!head)
	{
		head=create_node(val);
		return head;
	}
	sll* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	sll* node = create_node(val);
	temp->next = node;
	return head;
}
sll* delete_at_pos(sll* head,int pos)
{
        if(!head)
        {
                return NULL;
        }

        sll* temp = head;
        for(int i=0; temp!=NULL & i < pos;i++)
        {
                temp = temp->next;
        }
	sll* node = temp->next;
        temp->next = node->next;
        return head;
}
sll* list_wo_mid(sll* head)
{
	if(!head)
	{
		return NULL;
	}
	int count=0;
	sll* temp =head;
	while(temp->next !=NULL)
	{
		temp = temp->next;
		count++;
	}
	int mid = count/2;//delete at position mid 
	head=delete_at_pos(head,mid);

	return head;
}
int main()
{
	sll* head = NULL;
	head = insert_last(head,2);
	head = insert_last(head,3);
	head = insert_last(head,4);
	head = insert_last(head,5);
	head = insert_last(head,6);
	head = insert_last(head,7);
	head = insert_last(head,8);

	//linked list after insertion
	display_ll(head);

	head=list_wo_mid(head);

	//linked list after middle element deletion
	display_ll(head);
}



		



	                                                                                

