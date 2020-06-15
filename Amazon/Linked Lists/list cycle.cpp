/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::detectCycle(ListNode *A)
{
    if (!A || !(A->next))
        return NULL;

    ListNode *slow = A;
    ListNode *fast = A;

    while (fast && (fast->next))
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow != fast)
        return NULL;

    ListNode *curr = A;
    while (slow != curr)
    {
        slow = slow->next;
        curr = curr->next;
    }

    return curr;
}
