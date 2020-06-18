/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool find(TreeNode *root, int val)
{
    if (!root)
        return 0;

    if (root->val == val)
        return 1;

    bool findLeft = 0, findRight = 0;
    if (val > root->val)
        findRight = find(root->right, val);
    else
        findLeft = find(root->left, val);

    return findLeft + findRight;
}

bool helper(TreeNode *root, int k, TreeNode *orig_root)
{
    if (!root)
        return 0;

    //find (k - root->val) in th tree, if found cool return ,
    //if not found, move on to other nodes

    int temp = root->val;
    root->val = INT_MAX;
    if (find(orig_root, k - temp))
        return 1;

    root->val = temp;

    return helper(root->left, k, orig_root) || helper(root->right, k, orig_root);
}

int Solution::t2Sum(TreeNode *root, int k)
{
    if (!root)
        return 0;

    return helper(root, k, root);
}
