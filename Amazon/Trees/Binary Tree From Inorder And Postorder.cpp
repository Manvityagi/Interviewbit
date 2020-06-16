/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *helper(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd)
{

    if (postStart > postEnd || inStart > inEnd)
    {
        return NULL;
    }
    int val = postorder[postEnd];
    TreeNode *p = new TreeNode(val); //find parent element index from inorder
    int k = 0;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (val == inorder[i])
        {
            k = i;
            break;
        }
    }
    p->left =  helper(postorder, postStart, postStart + k - inStart - 1, inorder, inStart, k - 1);
    p->right = helper(postorder, postStart + k - inStart, postEnd - 1, inorder, k + 1, inEnd);
    return p;
}

TreeNode *Solution::buildTree(vector<int> &in, vector<int> &post)
{
    int len = in.size();

    return helper(post, 0, len - 1, in, 0, len - 1);
}
