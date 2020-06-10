/* APPROACH

->


*/

/* LESSON

Dummyhead is a nice concept

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL || l2 == NULL)
    {
        return (l1 == NULL) ? l2 : l1;
    }

    ListNode *dummyhead = new ListNode(0);
    ListNode *tail = dummyhead;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }
    tail->next = (!l1) ? l2 : l1;
    return dummyhead->next;
}
