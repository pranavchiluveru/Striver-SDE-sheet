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

Node* reverseLinkedList(Node *head)
{
    // Write your code here
    /*Iterative approach TC=O(n) SC=O(1)
    Node *prev=NULL;
    while(head->next!=NULL)
    {
        Node *curr=head;
        head=head->next;
        curr->next=prev;
        prev=curr;
    }
    head->next=prev;
    return head;
    */
    //recursive TC=O(n) 
    if(head->next==NULL)return head;
    Node *newhead=reverseLinkedList(head->next);
    Node *front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;

}
