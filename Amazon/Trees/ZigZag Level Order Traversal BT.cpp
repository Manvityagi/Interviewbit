/* APPROACH

->


*/

void level_order(TreeNode *root, vector<vector<int>> &res, int level)
{
    if (!root)
        return;

    if (res.size() <= level)
        res.resize(res.size() + 1);

    if (!(level & 1))
        res[level].emplace_back(root->val);
    else
        res[level].insert(res[level].begin(), root->val);

    level_order(root->left, res, level + 1);
    level_order(root->right, res, level + 1);
}

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    level_order(root, res, 0);
    return res;
}
