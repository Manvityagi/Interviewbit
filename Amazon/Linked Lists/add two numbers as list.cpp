/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::addTwoNumbers(ListNode *A, ListNode *B)
{
    ListNode *dummyhead = new ListNode(0);
    ListNode *tail = dummyhead;
    int carry = 0;
    while (A && B)
    {
        int val = (A->val + B->val + carry);
        carry = val / 10;
        val = val % 10;

        tail->next = new ListNode(val);
        tail = tail->next;

        A = A->next;
        B = B->next;
    }

    while (A)
    {
        int val = A->val + carry;
        carry = val / 10;
        val = val % 10;
        tail->next = new ListNode(val);
        tail = tail->next;
        A = A->next;
    }
    while (B)
    {
        int val = ((B->val) + carry);
        carry = val / 10;
        val = val % 10;
        tail->next = new ListNode(val);
        tail = tail->next;
        B = B->next;
    }

    if (carry)
        tail->next = new ListNode(carry);
    return dummyhead->next;
}

//Approach 2 (Taken from leetcode)
ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(0);
    ListNode *ptr = head;
    int carry = 0;
    while (ptr)
    {
        if (l1)
        {
            carry += l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            carry += l2->val;
            l2 = l2->next;
        }

        ptr->val = carry % 10;
        carry /= 10;

        if (l1 || l2 || carry)
            ptr->next = new ListNode(0);

        ptr = ptr->next;
    }

    return head;
}
