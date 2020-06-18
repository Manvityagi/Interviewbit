//12:33
vector<int> Solution::dNums(vector<int> &arr, int k)
{
    vector<int> ans;
    unordered_set<int> st;
    int n = arr.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        if (i - k >= 0)
        {
            if (mp.find(arr[i - k]) != mp.end())
            {
                if (mp[arr[i - k]] == 1)
                    mp.erase(arr[i - k]);
                else
                    mp[arr[i - k]]--;
            }
        }

        mp[arr[i]]++;

        if (i >= k - 1)
            ans.push_back(mp.size());
    }

    return ans;
}
