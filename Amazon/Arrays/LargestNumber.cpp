
/* APPROACH

->Directly concatenate and decide, whats better


*/

/* LESSON


*/
bool comp(const string &a, const string &b)
{
      return a + b > b + a;
}
string Solution::largestNumber(const vector<int> &nums)
{
    vector<string> arr;
    bool zero = true;
    for (auto a : nums)
    {
        if (a != 0)
            zero = false;
        arr.push_back(to_string(a));
    }
    if (zero)
        return "0";

    sort(arr.begin(), arr.end(), comp);
    string ans;
    for (auto a : arr)
        ans += a;

    return ans;
}
