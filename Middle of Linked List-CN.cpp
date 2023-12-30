/*
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
*/

Node *findMiddle(Node *head) {
    // Write your code here
    /*TC=O(n)
    int count=0,middle,i=1;
    Node *head1=head;
    while(head1!=NULL)
    {
        count++;
        head1=head1->next;
    }
    middle=(count/2)+1;
    while(i!=middle)
    {
        head=head->next;
        i++;
    }
    return head;
    */
    //Approach 2 :Using fast and slow pointers TC=O(n)
    Node *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}

