/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::reverseList(ListNode *head, int k)
{
    if (k == 0 || k == 1 || !head || !(head->next))
        return head;

    ListNode *curr = head;
    ListNode *prev = NULL, *next;

    for (int i = 0; i < k; i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    ListNode *temphead = reverseList(curr, k);
    head->next = temphead;

    return prev;
}
