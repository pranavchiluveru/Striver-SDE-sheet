/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
  // Write your code here.
  /*TC=O(n*k) SC=O(1)
  if(head->next==nullptr)return head;
  while(k>0){
  Node *temp = head;
  Node *prev=head;
  while (temp->next != nullptr)
  {
     prev=temp;
     temp=temp->next;
  }
  prev->next=nullptr;
  temp->next=head;
  head=temp;
  k--;
  }
  return head;
  */
  //TC=O(length)+O(length-k%length) SC=O(1)
  if(k==0)return head;
  Node* temp=head;
  int count=1;
  while(temp->next!=nullptr)
  {
       count++;
       temp=temp->next;
  }
  temp->next=head;
  k=k%count;
  k=count-k;
  while(k--)
  {
       temp=temp->next;
  }
  head=temp->next;
  temp->next=nullptr;
  return head;
}
