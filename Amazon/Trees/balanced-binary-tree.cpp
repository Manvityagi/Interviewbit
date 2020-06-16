/* APPROACH

->TOP-DOWN APPROACH
Time Complexity - O(nlogn) - for each level you are doing a total scan of N, and there are logN levels.

--------------------------------------------------------------------------------------------------------

->BOTTOM-UP APPROACH
Time Complexity - O(n)


The second method is based on DFS. Instead of calling depth() explicitly for each child node,
we return the height of the current node in DFS recursion

(taken from leetcode)
*/

//TOP-DOWN APPROACH
int depth(TreeNode *root)
{
    if (!root)
        return 0;
    return max(depth(root->left), depth(root->right)) + 1;
}

int Solution::isBalanced(TreeNode *root)
{
    if (!root)
        return 1;
    int rdepth = depth(root->right);
    int ldepth = depth(root->left);
    return abs(ldepth - rdepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}


// ->BOTTOM-UP APPROACH

int dfs(TreeNode *root)
{
    if (!root)
        return 1;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == -1 || right == -1 || (abs(left - right) > 1))
        return -1;

    return max(left, right) + 1;
}

int Solution::isBalanced(TreeNode *root)
{
    if (!root)
        return 1;
    return dfs(root) != -1;
}
