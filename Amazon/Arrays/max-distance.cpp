/* APPROACH

->Sort and save the numbers, for sorted index array, just want the minimum i for any bigger j, so just keep
   updating the minimum index and the max ans 


*/

/* LESSON


*/

int Solution::maximumGap(const vector<int> &A)
{
    int n = A.size();
    if (n == 0)
        return -1;
    int ans = 0;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
        arr.emplace_back(A[i], i);

    sort(arr.begin(), arr.end());

    int min_index = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i].second - min_index);
        min_index = min(min_index, arr[i].second);
    }

    return ans;
}
