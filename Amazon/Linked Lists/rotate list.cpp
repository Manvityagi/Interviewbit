/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *Solution::rotateRight(ListNode *head, int B)
{

    if (!head || !head->next || !B)
        return head;
    ListNode *new_head = head;
    ListNode *tail = head;
    int l = 1;

    while (tail->next && l++)
        tail = tail->next;

    B = B % l;
    if (!B) return head;

    ListNode *new_head_prev;
    int moves = l - B;

    while (moves > 0)
    {
        new_head_prev = new_head;
        new_head = new_head->next;
        moves--;
    }

    new_head_prev->next = NULL;
    tail->next = head;

    return new_head;
}
