/* APPROACH

-> Tried with sets first, but each insert operation is O(logB), got MLE, dunno why

-> Maintain a deque such that greatest elt is always at the front, by removing extra elements(smaller than current element) both frm front and back

*/

/* LESSON

-> Its a famous trick to maintain the maximum element in a queue

*/

//Bad approach
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

//Good approach
vector<int> Solution::slidingMaximum(const vector<int> &nums, int k)
{
       int n = nums.size();
        deque<pair<int,int>> dq;
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
        {
            //agar curr number dq se front se bada hai to pop karte raho
            //ps: agar boundary exceed ho rahi hai to bhi pop kar do
            while(!dq.empty() && (dq.front().first < nums[i] || dq.front().second < i)) dq.pop_front();
        
            //agar curr number dq ke baqck se bada hai to pop karte raho
            while(!dq.empty() && (dq.back().first < nums[i] || dq.front().second < i)) dq.pop_back();
            dq.emplace_back(nums[i],i+k-1);
            if(i >= k-1){
                ans.emplace_back(dq.front().first);
            }
        }
        
        return ans;
}