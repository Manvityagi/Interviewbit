/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> arr;
int curr_idx = 0;

void inorder(TreeNode *root)
{
    if (!root)
        return;

    inorder(root->left);
    arr.push_back(root->val);
    inorder(root->right);
}

BSTIterator::BSTIterator(TreeNode *root)
{
    inorder(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext()
{
    if (curr_idx < arr.size())
    {
        return true;
    }
    return false;
}

/** @return the next smallest number */
int BSTIterator::next()
{
    return arr[curr_idx++];
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
