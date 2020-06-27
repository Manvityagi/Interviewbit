#include <bits/stdc++.h>
using namespace std;
vector<int> calculateLPS(string s)
{
    int n = s.size();
    vector<int> LPS(n);

    int i = 0, j = 1;

    while (i < n && j < n)
    {
        if (s[i] == s[j])
        {
            LPS[j] = i + 1;
            i++, j++;
        }
        else
        {
            if (i != 0)
                i = LPS[i - 1];
            else
            {
                LPS[j] = 0;
                j++;
            }
        }
    }

    return LPS;
}

int Solution::solve(string s)
{
    int n = s.size();
    if (n == 0 || n == 1)
        return 0;
    string rev = s;
    reverse(rev.begin(), rev.end());
    s += "*";
    s += rev;
    vector<int> LPS;
    LPS = calculateLPS(s);
    int longestPalInBeg = LPS[LPS.size() - 1];
    return n - longestPalInBeg;
}
