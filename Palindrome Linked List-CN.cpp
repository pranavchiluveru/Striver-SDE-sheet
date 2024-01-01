#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
#include<bits/stdc++.h>
LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    if(head->next==NULL)
        return head;
    LinkedListNode<int> *newNode=reverse(head->next);
    LinkedListNode<int> *temp=head->next;
    temp->next=head;
    head->next=NULL;
    return newNode;
}
bool isPalindrome(LinkedListNode<int> *head) {
    /* Write your code here.
    Tc=O(n) Sc=O(n)
    stack<int> s;
    LinkedListNode<int> *h1=head;
    while(h1!=NULL)
    {
        s.push(h1->data);
        h1=h1->next;
    }
    while(head!=NULL)
    {
        int x=s.top();
        s.pop();
        if(x!=head->data)
            return false;
        head=head->next;
    }
    return true;
    */
    //Using fast and slow pointers TC=O(n) SC=O(1)
    LinkedListNode<int> *fast=head,*slow=head;
    // When there is only zero or one node in given Linked List.
    if (slow == NULL||slow->next==NULL) {
        return true;
    }
    //find middle element using fast and slow pointers
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    /*
        Fast pointer would become NULL when there are even elements in the list and
        not NULL for odd elements. We need to skip the middle node for odd case.
    */
    if (fast != NULL) {
        slow = slow->next;
    }
    //reverse the second half
    slow=reverse(slow);
    //compare first half and second half
    LinkedListNode<int> *h1=head;
    while(slow!=NULL)
    {
        if(slow->data==h1->data)
        {
            slow=slow->next;
            h1=h1->next;
        }
        else
            return false;
    }
    return true;
}
