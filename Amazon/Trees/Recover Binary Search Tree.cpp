/* APPROACH

-> If i know the parent of current node (parent as in - in the inorder), 
  than parent-> val should always be lesser than curr->val, if it is not, then there is some inconsistency in 
  parent and curr node,

  This inconsistency will occur 2 times

  For the first time, the larger value, i.e, parent is one of the swapped elements
  For the 2nd time, the smaller value, i.e curr node is one of the swapped elements

  So, we can actually keep track of whether we are hitting the inconsistency for the 1st time or 2nd
  and then decide our ans 
  OR
  we can also just directly put both curr,parent in an array 
  and then later on, the minimum and the maximum of the 4/2(in case of adjacent elts swapped), 
  elements, are the swapped elements
  (try to observe this thing in 1,2,3,4,5 and after swapping 1,5,3,4,2) and it will be clear


  **parent is actually prev of curr element in inorder


*/

/* LESSON

-> Maintaining parent actually helps in many questions

*/

vector<TreeNode *> arr;
TreeNode *par = nullptr;
void dfs(TreeNode *root)
{
    if (!root)
        return;
    dfs(root->left);
    if (par)
    {
        if (par->val > root->val)
        {
            arr.emplace_back(par);
            arr.emplace_back(root);
        }
    }
    par = root;
    dfs(root->right);
}
vector<int> Solution::recoverTree(TreeNode *A)
{
    arr.clear();
    par = nullptr;
    dfs(A);
    TreeNode *mx = arr[0], *mn = arr[0];
    for (auto i : arr)
    {
        if (i->val > mx->val)
            mx = i;
        if (i->val < mn->val)
            mn = i;
    }
    return vector<int>{mn->val, mx->val};
}