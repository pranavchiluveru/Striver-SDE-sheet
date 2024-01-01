/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/
#include<bits/stdc++.h>
bool detectCycle(Node *head)
{
	//	Write your code here
    /*TC=O(n) SC=O(n)
    unordered_set<Node*> s;
    while(head!=NULL)
    {
        if(s.find(head)==s.end())
        {
            s.insert(head);
            head=head->next;
        }
        else    
            return true;
    }
    return false;
    */
    //optimal approch using fast and slow pointers TC=O(n) SC=O(1)
    Node* fast,*slow;
    fast=slow=head;
    while(slow->next!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;


}
