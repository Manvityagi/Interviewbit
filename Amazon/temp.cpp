class Solution
{
    static bool compare(const ListNode *a, const ListNode *b)
    {
        return a->val > b->val;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *first = nullptr, *cur = nullptr;
        priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> p(compare);

        for (auto &i : lists)
            if (i)
                p.emplace(i);

        while (p.size())
        {
            auto i = p.top();
            p.pop();
            if (!first)
                cur = i, first = i;
            else
            {
                cur->next = i;
                cur = i;
            }
            i = i->next;
            if (i)
                p.emplace(i);
        }
        return first;
    }
};