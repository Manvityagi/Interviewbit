int helper(TreeNode *r1, TreeNode *r2)
{
    if (!r1 && !r2)
        return 1;
    if (!r1 || !r2)
        return 0;

    return (
        r1->val == r2->val &&
        helper(r1->left, r2->right) &&
        helper(r1->right, r2->left));
}

int Solution::isSymmetric(TreeNode *A)
{
    if (!A)
        return 1;
    return helper(A->left, A->right);
}