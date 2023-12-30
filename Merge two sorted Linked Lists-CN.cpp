#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here. TC=O(n+m) SC=O(1)
    Node<int>* chain;
    Node<int>* head;
    if(first->data<second->data)
    {
        head=first;
        chain=first;
        first=first->next;
        
    }
    else
    {
        head=second;
        chain=second;
        second=second->next;
        
    }
    while(first!=NULL&&second!=NULL)
    {
        if(first->data<second->data)
        {
            chain->next=first;
            chain=chain->next;
            first=first->next;
        }
        else
        {
            chain->next=second;
            chain=chain->next;
            second=second->next;
        }
    }
    if(first!=NULL)
    {
        chain->next=first;
    }
    if(second!=NULL)
    {
        chain->next=second;
    }
    return head;

}
