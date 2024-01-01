/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include<bits/stdc++.h>
Node* merge(Node* ptr1,Node* ptr2)
{
	Node* dummy=new Node(-1);
	Node* res=dummy;
	while(ptr1!=nullptr&&ptr2!=nullptr)
	{
		if(ptr1->data<ptr2->data)
		{
			res->child=ptr1;
			res=ptr1;
			ptr1=ptr1->child;
		}
		else
		{
			res->child=ptr2;
			res=ptr2;
			ptr2=ptr2->child;
		}
		res->next=nullptr;

	}
	if(ptr1!=nullptr)
	{
		res->child=ptr1;
	}
	if(ptr2!=nullptr)
	{
		res->child=ptr2;
	}
	return dummy->child;
}
Node* solve(Node* head)
{
	if(head->next==nullptr)return head;
	Node *ptr=solve(head->next);
	return merge(head,ptr);
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	/*approach 1 : Using arrays TC=O(n*m)+O(log(n*m))+O(n*m) SC=O(n*m) where m is rows n is columns
	vector<int> a;
	Node* temp=head;
	while(temp!=nullptr)
	{
		Node* t1=temp;
		while(t1!=nullptr)
		{
			a.push_back(t1->data);
			t1=t1->child;
		}
		temp=temp->next;
	}
	sort(a.begin(),a.end());
	Node *dummy=new Node(-1);
	Node *t=dummy;
	for(int i=0;i<a.size();i++)
	{
		Node* newNode=new Node(a[i]);
		t->child=newNode;
		t=newNode;
	}
	return dummy->child;
	*/
	//approach 2 :TC=O(2m)*n SC=O(n)
	return solve(head);
}
