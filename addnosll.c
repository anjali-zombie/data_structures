#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct linkedlist{
	int data;
	struct linkedlist* next;
}sll;

sll* createnode(int data){
	sll* node =(sll*)malloc(sizeof(sll));
	node->data = data;
	node->next = NULL;
	return node;
}
sll* insert_last(sll* head,int data)
{
	if(!head)
	{
		head =createnode(data);
	}
	sll* temp =head;
	while(temp->next !=NULL)
	{
		temp =temp->next;
	}
	sll* node =createnode(data);
        temp->next = node;
	return head;
}
char* reverse_node_val(sll* head)
{
	if(!head)
	{
		return NULL;
	}
	sll* temp = head;
	char* str =(char*)malloc(100);
	str[0]='\0';
	char val[12];
	while(temp != NULL)
	{
		sprintf(val,"%d",temp->data);
		strcat(str,val);
		temp=temp->next;
	}
	int len = strlen(str);
	char* str2 =(char*)malloc(len+1);
	for(int i=0;i<len-1;i++)
	{
		str2[i]=str[len-1-i];
	}
	str2[len]='\0';
	return str2;

}
char* add_nos(char* str,char* str2)
{
	int val1 = atoi(str);
	int val2 = atoi(str2);

	int ans = val1+val2;
	printf("before reversing %d\n",ans);
	char out[12];
	sprintf(out,"%d",ans);
	int len = strlen(out);
        char* out2 =(char*)malloc(len+1);
	
        for(int i=0;i<len;i++)
        {
                out2[i]=out[len-1-i];
        }
        out2[len]='\0';
	printf("after revesring\n");
        return out2;
}
int main()
{
	sll* head=NULL;
	head = insert_last(head,9);
	head = insert_last(head,9);
        head = insert_last(head,9);
	head = insert_last(head,9);
        head = insert_last(head,9);
        head = insert_last(head,9);
	head = insert_last(head,9);
	char* reverse1 = reverse_node_val(head);
	head = NULL;
	head = insert_last(head,9);
        head = insert_last(head,9);
        head = insert_last(head,9);
        head = insert_last(head,9);
	char* reverse2 = reverse_node_val(head);
	printf("%s\n",add_nos(reverse1,reverse2));

}
