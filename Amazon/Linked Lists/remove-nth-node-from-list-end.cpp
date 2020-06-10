/* APPROACH

-> Two pass is simple, clculating length
-> One pass is genius approach : Have 2 pointers, slow and fast, move fast by n+1 initially, 
   so as to have a gap of n nodes between slow and fast, so when, fast reaches end, 
   slow will be at the nth node from end

*/

/* LESSON


*/

//TWO PASS APPROACH
int length(ListNode *head)
{
    int l = 0;
    while (head)
    {
        head = head->next;
        l++;
    }
    return l;
}

ListNode *Solution::removeNthFromEnd(ListNode *A, int B)
{

    if (!A || !(A->next))
        return NULL;
    int len = length(A);
    if (B >= len)
    {
        A = A->next;
        return A;
    }
    int moves = len - B - 1;
    ListNode *tail = A;

    while (tail && moves--)
        tail = tail->next;

    if (tail)
        tail->next = tail->next->next;

    return A;
}

//One PASS APPROACH

ListNode *Solution::removeNthFromEnd(ListNode *A, int B)
{

    if (!A || !(A->next))
        return NULL;

    ListNode *dummyhead = new ListNode(0);
    ListNode *slow = dummyhead;
    ListNode *fast = dummyhead;
    slow->next = A;

    for (int i = 1; i <= B + 1 && fast; i++)
        fast = fast->next;

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummyhead->next;
}
