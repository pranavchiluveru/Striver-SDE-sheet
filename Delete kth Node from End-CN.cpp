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

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    /*Naive APproach Traverse LL twice
    int count=0;
    Node* h1=head;
    while(h1!=NULL)
    {
        count++;
        h1=h1->next;
    }
    int loc=count-K+1;
    if(loc==1)
        return head->next;
    count=1;
    h1=head;
    while(count!=loc-1)
    {
        h1=h1->next;
        count++;
    }
    h1->next=h1->next->next;
    return head;
    */
    //Using two pointers fast and slow
   
    Node *start=new Node();
    start->next=head;
    Node *fast=start,*slow=start;
    for(int i=1;i<=K;i++)
    {
        fast=fast->next;
    }
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return start->next;

}
