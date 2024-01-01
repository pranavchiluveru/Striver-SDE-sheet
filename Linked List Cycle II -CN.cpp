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

Node *firstNode(Node *head)
{
    //    Write your code here.
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
            return head;
    }
    return NULL;
    */
    //using fast and slow pointers TC=O(N) SC=O(1)
    Node *fast=head,*slow=head;
    int flag=0;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        return NULL;
    while(slow!=head)
    {
        slow=slow->next;
        head=head->next;
    }
    return slow;    
}
