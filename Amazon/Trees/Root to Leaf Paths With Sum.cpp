/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void helper(TreeNode *root, int &sum, vector<int> &curr, vector<vector<int>> &ans)
{
    if (!root)
        return;

    curr.push_back(root->val);
    if (root->val == sum && !(root->left) && !(root->right))
    {
        ans.emplace_back(curr);
    }

    int newsum = sum - root->val;
    helper(root->left, newsum, curr, ans);
    helper(root->right, newsum, curr, ans);
    curr.pop_back();
}
vector<vector<int>> Solution::pathSum(TreeNode *root, int sum)
{
    vector<vector<int>> ans;
    if (!root)
        return {};
    vector<int> curr;
    helper(root, sum, curr, ans);
    return ans;
}
