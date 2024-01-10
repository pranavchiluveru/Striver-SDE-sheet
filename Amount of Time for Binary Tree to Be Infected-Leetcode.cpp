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
    TreeNode* maptoparent(TreeNode* root,map<TreeNode*,TreeNode*> &mpp,int start)
    {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* n=q.front();
                q.pop();
                if(n->val==start)target=n;
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
        return target;
    }
    int timereq(TreeNode* root,map<TreeNode*,TreeNode*> &mpp)
    {
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*,int> visited;
        visited[root]=1;
        int time=0;
        while(!q.empty())
        {
            int s=q.size();
            int f=0;
            for(int i=0;i<s;i++)
            {
                TreeNode* n=q.front();
                q.pop();
                if(n->left&&visited[n->left]!=1)
                {
                    f=1;
                    visited[n->left]=1;
                    q.push(n->left);
                }
                if(n->right&&visited[n->right]!=1)
                {
                    f=1;
                    visited[n->right]=1;
                    q.push(n->right);
                }
                if(mpp[n]&&visited[mpp[n]]!=1)
                {
                    f=1;
                    visited[mpp[n]]=1;
                    q.push(mpp[n]);
                }
            }
            if(f==1)time++;

        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        //TC=O(n)+O(n) SC=O(n)+O(n)
        map<TreeNode*,TreeNode*> mpp;
        TreeNode* target=maptoparent(root,mpp,start);
        return timereq(target,mpp);
    }
};
