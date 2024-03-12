/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        //TC=O(n) SC=O(n)
        unordered_map<int,ListNode*> mpp;//store prefixsum ,node
        ListNode* t=head;
        ListNode *dummy = new ListNode(0);
        mpp[0] = dummy;
        dummy->next = head;
        int prefix_sum=0;
        while(t!=NULL)
        {
            prefix_sum+=t->val;
            if(mpp.find(prefix_sum)!=mpp.end())//sum already present in map which implies we need to delete nodes from node->next to t 
            {
                ListNode* node=mpp[prefix_sum];
                ListNode* del=node->next;
                int p_sum=prefix_sum;
                while(del!=t)
                {
                    p_sum+=del->val;
                    mpp.erase(p_sum);
                    del=del->next;
                }
                node->next=del->next;
            }
            else
                mpp[prefix_sum]=t;
            t=t->next;
        }
        return dummy->next;
    }
};
