/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int Solution::lPalin(ListNode *head)
{
    //finding mid
    if (!head || !(head->next))
        return true;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev_slow = NULL;

    while (fast && fast->next)
    {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev_slow->next = NULL;

    //reverse
    ListNode *prev = NULL;
    ListNode *curr = slow;
    ListNode *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    ListNode *head2 = prev;

    while (head && head2)
    {
        if (head->val != head2->val)
            return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;
}
