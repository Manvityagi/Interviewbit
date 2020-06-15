ListNode *Solution::reorderList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;

    //reverse list with head2
    ListNode *pre = NULL;
    ListNode *curr = head2;
    ListNode *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }

    head2 = pre;
    auto head1 = head;

    while (head1 && head2)
    {
        auto head1N = head1->next;
        head1->next = head2;
        head1 = head2;
        head2 = head1N;
    }
    return head;
}