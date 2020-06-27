
/* APPROACH

(1) Use [i+1][j-1] result to check if curr string is also palindrome
    Time - O(n^2)
    Space - O(n^2)
    Verdict - MLE

(2) Expand from middle and check the maximum expansion possible
    (a) Consider odd length expansion - 1 middle 
    (b) Consider even length palindrome - 2 middles

*/

/*-----------------------------------APPROACH - 1 ---------------------------------------------------------*/

string Solution::longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>> isPal(n, vector<int>(n, -1));
    string ans;

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = i + gap; i < n, j < n; i++, j++)
        {
            if (gap == 0)
                isPal[i][j] = 1;
            else
                isPal[i][j] = (s[i] == s[j] && isPal[i + 1][j - 1]) ? 1 : 0;

            if (isPal[i][j])
                if (j - i + 1 > ans.size())
                    ans = s.substr(i, j - i + 1);
        }
    }
    return ans;
}

/*-----------------------------------APPROACH - 2 ---------------------------------------------------------*/

string expand(string s, int left, int right)
{
    int n = s.size();
    if (left > right || left < 0 || right >= n)
        return "";
    while (left >= 0 && right < n && s[left] == s[right])
        left--, right++;
    return s.substr(left + 1, right - left - 1);
}

string Solution::longestPalindrome(string s)
{
    int n = s.size();
    if (!n || n == 1)
        return s;

    int max_len = 1;
    int ans_st = 0;
    string ans = s.substr(0, 1);
    for (int i = 0; i < n; i++)
    {
        //odd length PAL
        if (i - 1 >= 0 && i + 1 < n)
        {
            string odd = expand(s, i - 1, i + 1);
            if (odd.size() > ans.size())
                ans = odd;
        }
        if (i + 1 < n && s[i] == s[i + 1])
        {
            if (ans.size() < 2)
                ans = s.substr(i, 2);
            string even = expand(s, i - 1, i + 2);
            if (even.size() > ans.size())
                ans = even;
        }
    }
    return ans;
}
