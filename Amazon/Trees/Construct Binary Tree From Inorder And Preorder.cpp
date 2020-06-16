/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *helper(vector<int> &pre, vector<int> &in, int pre_st, int pre_end, int in_st, int in_end)
{
    if (pre_st > pre_end || in_st > in_end)
        return NULL;

    int idx;
    TreeNode *root = new TreeNode(pre[pre_st]);
    //search pre[pre_st] in inorder
    for (int i = in_st; i <= in_end; i++)
    {
        if (in[i] == pre[pre_st])
        {
            idx = i;
            break;
        }
    }

    root->left = helper(pre, in, pre_st + 1, pre_st + (idx - in_st), in_st, idx - 1);
    root->right = helper(pre, in, pre_st + (idx - in_st) + 1, pre_end, idx + 1, in_end);

    return root;
}

TreeNode *Solution::buildTree(vector<int> &pre, vector<int> &in)
{
    int pre_len = pre.size();
    int in_len = in.size();

    return helper(pre, in, 0, pre_len - 1, 0, in_len - 1);
}
