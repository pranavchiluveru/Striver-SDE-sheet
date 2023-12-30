/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here. TC=O(n+m) SC=O(n+m)
    int sum=0,carry=0;
    Node *dummyhead=new Node(0);
    Node *curr=dummyhead;
    while(num1!=NULL&&num2!=NULL)
    {
        
        sum=num1->data+num2->data+carry;
        num1=num1->next;
        num2=num2->next;
        carry=sum/10;
        sum=sum%10;
        Node* newNode=new Node(sum);
        curr->next=newNode;
        curr=curr->next;
    }
    while(num1!=NULL)
    {
        sum=num1->data+carry;
        num1=num1->next;
        carry=sum/10;
        sum=sum%10;
        Node* newNode=new Node(sum);
        curr->next=newNode;
        curr=curr->next;
    }
    while(num2!=NULL)
    {
        sum=num2->data+carry;
        num2=num2->next;
        carry=sum/10;
        sum=sum%10;
        Node* newNode=new Node(sum);
        curr->next=newNode;
        curr=curr->next;
    }
    if(carry!=0)
    {
        Node* newNode=new Node(carry);
        curr->next=newNode;
        curr=curr->next;
    }
    return dummyhead->next;
}
