string Solution::countAndSay(int n)
{
    if (n == 0 || n == 1 || n < 0)
        return "1";
    string prev = countAndSay(n - 1);

    string ans;
    int sz = prev.size();
    int i = 0;
    while (i < sz)
    {
        int cnt = 1;
        while (i + 1 < sz && prev[i] == prev[i + 1])
        {
            i++;
            cnt++;
        }
        ans += to_string(cnt) + prev.substr(i, 1);
        i++;
    }
    return ans;
}
