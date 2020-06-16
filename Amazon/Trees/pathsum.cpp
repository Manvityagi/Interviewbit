int Solution::hasPathSum(TreeNode* root, int sum) {
    if(!(root)) return 0;
    if(root->val-sum == 0 && !(root->left) && !(root->right)) return 1;
 
    
    return hasPathSum(root->left, sum - root->val) || 
           hasPathSum(root->right, sum - root->val) ;
}
