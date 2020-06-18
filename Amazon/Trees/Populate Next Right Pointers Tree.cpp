/* APPROACH

(1) Recursive
(2) Level-order


*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode *root)
{
    TreeLinkNode *un, *first, *cur = root;
    while (cur)
    {
        first = nullptr, un = nullptr;
        while (cur)
        {
            if (cur->left)
            {
                if (!first)
                    first = cur->left;
                if (un)
                {
                    un->next = cur->left;
                }
                un = cur->left;
            }
            if (cur->right)
            {
                if (!first)
                    first = cur->right;
                if (un)
                {
                    un->next = cur->right;
                }
                un = cur->right;
            }
            cur = cur->next;
        }
        cur = first;
    }
}
