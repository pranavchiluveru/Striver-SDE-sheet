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
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    /*Write your code here TC=O(n+m) SC=O(n)
    unordered_set<Node*> s;
    while(firstHead!=NULL)
    {
        s.insert(firstHead);
        firstHead=firstHead->next;
    }
    while(secondHead!=NULL)
    {
        
        if(s.find(secondHead)!=s.end())
            return secondHead;
        secondHead=secondHead->next;

    }
    return NULL;
    */

    //TC=O(n+m) sc=O(1)
    int len1=0,len2=0;
    Node* h1=firstHead,*h2=secondHead;
    while(h1!=NULL)
    {
        len1++;
        h1=h1->next;
    }
    while(h2!=NULL)
    {
        len2++;
        h2=h2->next;
    }
    int diff=len1-len2;
    if(diff>0)
    {
        while(diff>0)
        {
            firstHead=firstHead->next;
            diff--;
        }
    }
    else
    {
        while(diff<0)
        {
            secondHead=secondHead->next;
            diff++;
        }
    }
    while(firstHead!=NULL)
    {
        firstHead=firstHead->next;
        secondHead=secondHead->next;
        if(firstHead==secondHead)
            return firstHead;
    }
    return NULL;

    
}
