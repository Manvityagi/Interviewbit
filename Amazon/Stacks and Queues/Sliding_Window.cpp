/* APPROACH

-> Tried with sets first, but each insert operation is O(logB), got MLE, dunno why

-> Maintain a deque such that greatest elt is always at the front, by removing extra elements(smaller than current element) both frm front and back

*/

/* LESSON

-> Its a famous trick to maintain the maximum element in a queue

*/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
{
    set<int, greater<int>> pq;
    vector<int> ans;
    int i, j = 0;
    for (j = 0; j < B; j++)
    {
        pq.insert(A[j]);
    }

    while (j < n)
    {
        ans.push_back(pq[0]);
        auto it = pq.begin();
        pq.erase(it);

        pq.insert(A[j]);
    }
    return ans;
}
