/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode *root, int cnt, int k, int ans)
{

    if(!root)
    {
        return;
    }

    if (cnt == k)
    {
        ans = root->val;
        return;
    }

    inorder(root->left, cnt++, k, ans);
    if (cnt == k)
    {
        ans = root->val;
        return;
    }
    inorder(root->right, cnt++, k, ans);
}

int Solution::kthsmallest(TreeNode *root, int k)
{
    if (!root)
        return -1;
    if (k == 0)
        return root->val;

    int ans = -1;
    inorder(root,0,k,ans);
    return ans;
}
