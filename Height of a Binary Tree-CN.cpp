/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    /*DFS TC=O(n) SC=O(n)
    if(!root)return 0;
    return 1+max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right));
    */
    //BFS TC=O(n) SC=O(n)
    queue<TreeNode<int>*> q;
    q.push(root);
    int height=0;
    while(!q.empty())
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            TreeNode<int> *n=q.front();
            q.pop();
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        height++;
    }
    return height;
}
