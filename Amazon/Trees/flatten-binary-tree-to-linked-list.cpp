/* APPROACH

(1) RECURSIVE WITH GLOBAL VARIABLE PARENT: 
If at each step, we maintain an updated parent,  we just need to do recursive calls

(2) ITERATIVE SOLUTION
    node X ke left me jo rakha hai, usey itha ke node ke right me rakhna hai, 
    aur jo left se subtree uthaya tha, uske rightmost me node X ka orignal right daalna hai, 
    ye hi process har right node ke liye karna hai, 




*/

// --------------------------------RECURSIVE SOLUTION------------------------------------------//

TreeNode *parent = nullptr;
void dfs(TreeNode *root)
{
    if (!root)
        return;
    if (parent)
        parent->right = root;
    parent = root;

    TreeNode *L = root->left, *R = root->right;
    root->left = nullptr;
    root->right = nullptr;

    dfs(L);
    dfs(R);
}
TreeNode *Solution::flatten(TreeNode *A)
{
    dfs(A);
    return A;
}

// --------------------------------ITERATIVE SOLUTION------------------------------------------//

TreeNode *Solution::flatten(TreeNode *root)
{
    TreeNode *now = root;
    while (now)
    {
        auto iter = now->left;
        if (iter)
        {
            while (iter->right)
                iter = iter->right;

            iter->right = now->right;
            now->right = now->left;
            now->left = NULL;
        }
        now = now->right;
    }

    return root;
}
