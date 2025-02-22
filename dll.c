#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct doblinklist{
	int val;
	struct doblinklist *next;
	struct doblinklist *prev;
}dll;

dll *createNode(int val){
	dll *node = (dll*)malloc(sizeof(dll));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
}

dll *insertFirst(dll *head,int val){
	if(!head){
		head = createNode(val);
	}
	else{
		dll *node = createNode(val);
		head->prev = node;
		node->next = head;
		head = node;
	}
	return head;
}

dll *insertLast(dll *head,int val){
	if(!head){
		head = createNode(val);
	}
	else{
		dll *temp = head;
		dll *node = createNode(val);
		while(temp->next){
			temp = temp->next;
		}
		temp->next = node;
		node->prev = temp;
	}
	return head;
}

dll *insertPos(dll *head,int val,int x){
	if(!head){
		head = createNode(val);
	}
	else{
		dll *temp = head;
		dll *node = createNode(val);
		while(x > 0){
			temp = temp->next;
			x--;
		}
		if(!temp->next){
			temp->next = node;
			node->prev = temp;
		}
		else{
			node->next = temp->next;
			node->prev = temp;
			temp->next->prev = node;
			temp->next = node;
		}
	}
	return head;
}

dll *delNode(dll *head){
	if(head && head->next){
		head = head->next;
		head->prev = NULL;
	}
return head;
}

dll *delnodLast(dll *head){
	dll *temp = head;
	if(head){
		while(temp->next){
			temp = temp->next;
		}
		temp->prev->next = NULL;
		temp->prev = NULL;
	}
return head;
}

dll *delnodPos(dll *head,int x){
	dll *temp = head;
        if(head){
                while(x > 0 && temp->next){
                        temp = temp->next;
			x--;
                }
		if(x > 1){
                	temp->prev->next = NULL;
                	temp->prev = NULL;
		}
        }

return head;
}


int main(){
	dll *head = NULL;
	head = insertFirst(head,1);
return 0;
}
