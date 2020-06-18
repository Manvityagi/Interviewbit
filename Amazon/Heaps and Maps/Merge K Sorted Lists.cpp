
/* APPROACH
(1) store val,idx in pq
(2) store ListNode itself in pq - Faster, Better
*/

//Approach 1
#define MP make_pair
struct customComparator
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.first > p2.first;
    }
};
ListNode *Solution::mergeKLists(vector<ListNode *> &pointers)
{
    int k = pointers.size();
    if (!k)
        return NULL;
    priority_queue<pair<int, int>, vector<pair<int, int>>, customComparator> pq;
    for (int i = 0; i < k; i++)
    {
        if (pointers[i])
            pq.push(MP(pointers[i]->val, i));
    }

    ListNode *dummy_head = new ListNode(0);
    ListNode *tail = dummy_head;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ListNode *curr = new ListNode(top.first);
        tail->next = curr;
        tail = tail->next;

        //list whose pointer to move
        int move = top.second;
        if (pointers[move] && pointers[move]->next)
        {
            pointers[move] = pointers[move]->next;
            int next_val = pointers[move]->val; //next value to be inserted in pq
            pq.push(MP(next_val, move));
        }
    }
    return dummy_head->next;
}

// ----------------------------------APPROACH 2------------------------------------------------------------------//

struct compare
{
    bool operator()(ListNode *node1, ListNode *node2)
    {
        return node1->val > node2->val;
    }
};

ListNode *Solution::mergeKLists(vector<ListNode *> &pointers)
{
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;
    int k = pointers.size();

    for (int i = 0; i < k; i++)
    {
        if (pointers[i])
            pq.push(pointers[i]);
    }

    ListNode *dummy_head = new ListNode(0);
    ListNode *tail = dummy_head;
    while (pq.size())
    {
        auto top = pq.top();
        pq.pop();
        tail->next = top;
        if (top && top->next)
        {
            top = top->next;
            pq.push(top);
        }
        tail = tail->next;
    }
    return dummy_head->next;
}