/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    void childtoparentmap(TreeNode* root,map<TreeNode*,TreeNode*> &mpp)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* n=q.front();
                q.pop();
                if(n->left)
                {
                    mpp[n->left]=n;
                    q.push(n->left);
                }
                if(n->right)
                {
                    mpp[n->right]=n;
                    q.push(n->right);
                }
            }
        }
    }
    int findmaxdiff(TreeNode* root,map<TreeNode*,TreeNode*> &mpp)
    {
        int ans=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* n=q.front();
                q.pop();
                TreeNode* ancestor=mpp[n];
                while(ancestor)
                {
                    ans=max(ans,abs(n->val-ancestor->val));
                    ancestor=mpp[ancestor];
                }
                if(n->left)
                {
                    q.push(n->left);
                }
                if(n->right)
                {
                    q.push(n->right);
                }
            }
        }
        return ans;

    }
    */
    int ans=0;
    pair<int,int> find(TreeNode* root)
    {
        if(!root)
        {
            return {INT_MAX,INT_MIN};
        }
        pair<int,int> pLST,pRST;
        pLST=find(root->left);
        pRST=find(root->right);
        int currMIN=min(root->val,min(pLST.first,pRST.first));
        int currMAX=max(root->val,max(pLST.second,pRST.second));
        ans=max(ans,max(root->val-currMIN,currMAX-root->val));
        return {currMIN,currMAX};
    }
    int maxAncestorDiff(TreeNode* root) {
        /*Approach 1: TC=O(n)+O(nlogn) SC=O(n)
        map<TreeNode*,TreeNode*> mpp;
        childtoparentmap(root,mpp);
        int res=INT_MIN;
        return findmaxdiff(root,mpp);
        */
        //optimal approach USING DFS: get min,max values from LST and RST for a node TC=O(N) SC=O(N)
        find(root);
        return ans;
    }
};
