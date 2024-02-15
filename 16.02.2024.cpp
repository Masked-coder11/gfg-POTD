class Solution
{
public:
    void inorder(Node *curr, Node *&prev)
    {
        if (curr == NULL)
            return;
        inorder(curr->left, prev);
        prev->left = NULL;
        prev->right = curr;
        prev = curr;
        inorder(curr->right, prev);
    }
    Node *flattenBST(Node *root)
    {
        Node *dummy = new Node(-1);
        Node *prev = dummy;
        inorder(root, prev);

        prev->left = NULL;
        prev->right = NULL;
        Node *ret = dummy->right;
        
        delete dummy;
        return ret;
    }
};
