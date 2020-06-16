
/* APPROACH

(1) Recursion - O(n^2) time, O(n) space
(2) Stack - O(n) time, O(n) space


*/

/* LESSON


*/

// (1) Recursion - O(nlogn) time, O(n) space
TreeNode *helper(vector<int> &A, int st, int end)
{
    if (end <= st)
        return NULL;
    if (st == end - 1)
        return new TreeNode(A[st]);

    auto max_it = max_element(A.begin() + st, A.begin() + end);
    TreeNode *root = new TreeNode(*max_it);

    int max_idx = distance(A.begin(), max_it);
    TreeNode *lefthead = helper(A, st, max_idx);
    TreeNode *righthead = helper(A, max_idx + 1, end);

    root->left = lefthead;
    root->right = righthead;

    return root;
}

TreeNode *Solution::buildTree(vector<int> &A)
{
    int n = A.size();
    return helper(A, 0, n);
}


// (2) Stack - O(n) time, O(n) space