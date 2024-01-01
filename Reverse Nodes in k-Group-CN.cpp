#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
#include<bits/stdc++.h>
Node* reverse(Node* ptr)
{
	Node* prev=NULL;
	while(ptr!=NULL)
	{
		Node* curr=ptr;
		ptr=ptr->next;
		curr->next=prev;
		prev=curr;
	}
	return prev;

}
Node* find(Node* node,int count)
{
	count-=1;
	while(node!=NULL&&count>0)
	{
		node=node->next;
		count--;
	}
	return node;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	int i=0;
	Node* t=head;
	Node* kthnode=head;
	Node* prevlist=NULL;
	Node* rev;
	Node* nextnode;
	while(t!=NULL&&i!=n)
	{
		if(b[i]==0)
		{
			i++;
			continue;
		}
		kthnode=find(t,b[i]);
		if(kthnode==NULL)
		{
			rev=reverse(t);
			if(t==head)
				head=rev;
			if(prevlist!=NULL)
				prevlist->next=rev;
			break;
		}
		nextnode=kthnode->next;
		kthnode->next=NULL;
		rev=reverse(t);
		if(t==head)
			head=rev;
		else
			prevlist->next=rev;
		prevlist=t;
		t=nextnode;
		i++;
	}
	if(i==n&&prevlist!=NULL)
		prevlist->next=t;
	
	return head;
}
