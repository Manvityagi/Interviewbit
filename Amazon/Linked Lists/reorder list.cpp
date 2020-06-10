//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int len(ListNode *head)
{
    int l = 0;
    while (head)
    {
        head = head->next;
        l++;
    }

    return l;
}

ListNode *reverse(ListNode *head)
{
    if (!head || !(head->next))
        return head;

    ListNode *new_head = reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return new_head;
}
ListNode *Solution::reorderList(ListNode *head)
{
    if (!head || !(head->next))
        return head;
    int l = len(head);

    ListNode *second_head = head;
    int moves_till_mid = l / 2;
    while (moves_till_mid >= 2)
    {
        second_head = second_head->next;
        moves_till_mid--;
    }

    ListNode *mid_head = second_head->next;
    second_head->next = NULL;
    second_head = reverse(mid_head);

    ListNode *head1 = head;
    ListNode *head2 = second_head;

    while (head1 && head2)
    {
        ListNode *head1N = head1->next;
        head1->next = head2;
        head1 = head1N;

        ListNode *head2N = head2->next;

        if (head1)
            head2->next = head1;
        head2 = head2N;
    }
    return head;
}

//Shorter Cleaner
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