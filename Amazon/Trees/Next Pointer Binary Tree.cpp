/* APPROACH

(1) Recursive - O(n) space , O(n) time
(2) Level-order-Iterative - O(1) space, O(n) time 

*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */


// (1) Recursive - O(n) space , O(n) time

void Solution::connect(TreeLinkNode *root)
{
    if (!root)
        return;

    if (root->left)
        root->left->next = root->right;

    if (root->right && root->next)
        root->right->next = root->next->left;

    connect(root->left);
    connect(root->right);
}

// (2) Level-order-Iterative - O(1) space, O(n) time

void Solution::connect(TreeLinkNode *root)
{
    if (!root)
        return;
    //pre - the first node of each level
    TreeLinkNode *pre = root, *curr;
    while (pre) //moving to next level
    {
        curr = pre;
        while (curr && curr->left) //travelling on 1 level
        {
            curr->left->next = curr->right;
            if (curr->next)
                curr->right->next = curr->next->left;
            curr = curr->next;
        }
        pre = pre->left;
    }
}
