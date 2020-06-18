/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode *root)
{
    if (!root)
        return 0;
    if (!(root->left) && !(root->right))
        return 1;

    int left = INT_MAX;
    int right = INT_MAX;

    if (root->left)
        left = minDepth(root->left);
    if (root->right)
        right = minDepth(root->right);

    return 1 + min(left, right);
}
