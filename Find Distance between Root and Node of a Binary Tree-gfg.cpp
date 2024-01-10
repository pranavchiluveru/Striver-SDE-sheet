// A utility function to create a new Binary
// Tree Node
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Returns -1 if x doesn't exist in tree. Else
// returns distance of x from root
int findDistance(Node *root, int x)
{
    // Base case
    if (root == NULL)
      return -1;
 
    // Initialize distance
    int dist = -1;
 
    // Check if x is present at root or in left
    // subtree or right subtree.
    if ((root->data == x) ||
        (dist = findDistance(root->left, x)) >= 0 ||
        (dist = findDistance(root->right, x)) >= 0)
        return dist + 1;
 
    return dist;
}
