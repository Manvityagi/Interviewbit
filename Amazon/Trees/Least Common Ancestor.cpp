/* APPROACH

Cases:
1. p in left subtree & q in right subtree or vice-versa
2. p,q both in left subtree
3. p,q both in right subtree

case 1 : ans would be root as seeing from the current root, if none of left_lca and right_lca is -1, that means one 
         is present in left subtree and other in right subtree
case 2 : right_lca will be -1, so left_lca will be the ans straight-forward 
case 3 : left_lca will be -1, so right_lca will be the ans straight-forward 

PS: The case of p or q not present in tree is handled differently.

*/

int helper(TreeNode *root, int p, int q)
{
    if (!root)
        return -1;

    if (root->val == p || root->val == q)
        return root->val;

    int left_lca = helper(root->left, p, q);
    int right_lca = helper(root->right, p, q);

    if (left_lca != -1 && right_lca != -1)
        return root->val;

    if (left_lca == -1)
        return right_lca;

    return left_lca;
}

bool find(TreeNode *root, int val)
{
    if (!root)
        return 0;
    if (root->val == val)
        return 1;
    return find(root->left, val) || find(root->right, val);
}

int Solution::lca(TreeNode *root, int p, int q)
{
    if (!find(root, p) || !find(root, q))
        return -1;

    return helper(root, p, q);
}
