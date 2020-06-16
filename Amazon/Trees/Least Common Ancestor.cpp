/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::lca(TreeNode *root, int p, int q)
{
    if (!root)
        return -1;
    if (root->val == p || root->val == q)
        return root->val;

    int a = lca(root->left, p, q);
    int b = lca(root->right, p, q);

    if (a == -1 && b == -1)
        return -1;

    if (a != -1 && b != -1)
        return root->val;

    if (a == -1)
        return b;

    return a;
}
