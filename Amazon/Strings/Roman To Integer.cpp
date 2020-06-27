int Solution::romanToInt(string A)
{
    unordered_map<char, int> mp;
    mp['M'] = 1000;
    mp['D'] = 500;
    mp['C'] = 100;
    mp['L'] = 50;
    mp['X'] = 10;
    mp['V'] = 5;
    mp['I'] = 1;
    int n = A.size();
    int i = 0;
    int ans = 0;
    while (i < n)
    {
        if (i != n - 1 && mp[A[i + 1]] > mp[A[i]])
        {
            ans += (mp[A[i + 1]] - mp[A[i]]);
            i++;
        }
        else
            ans += mp[A[i]];
        i++;
    }
    return ans;
}
