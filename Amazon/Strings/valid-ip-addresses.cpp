vector<string> ans;

bool valid_group(string s)
{
    if (!s.size() || s.size() > 3)
        return 0;
    if (s.size() > 1 && s[0] == '0')
        return 0;
    return stoi(s) >= 0 && stoi(s) <= 255;
}

void helper(string &s, int idx, string curr, int group)
{
    int n = s.size();
    if (group > 4 || idx > n)
        return;
    if (idx == n)
    {
        if (group == 4)
            ans.emplace_back(curr);
        return;
    }

    if (valid_group(s.substr(idx, 1)))
        if (group != 3)
            helper(s, idx + 1, curr + s.substr(idx, 1) + '.', group + 1);
        else
            helper(s, idx + 1, curr + s.substr(idx, 1), group + 1);

    if (idx + 1 < n)
        if (valid_group(s.substr(idx, 2)))
            if (group != 3)
                helper(s, idx + 2, curr + s.substr(idx, 2) + '.', group + 1);
            else
                helper(s, idx + 2, curr + s.substr(idx, 2), group + 1);

    if (idx + 2 < n)
        if (valid_group(s.substr(idx, 3)))
            if (group != 3)
                helper(s, idx + 3, curr + s.substr(idx, 3) + '.', group + 1);
            else
                helper(s, idx + 3, curr + s.substr(idx, 3), group + 1);
}

vector<string> Solution::restoreIpAddresses(string s)
{
    ans.clear();
    if (s.size() > 12)
        return {};
    //25525511135
    //op1 - 2(1st group)   5525511135(3 groups)
    //op2 - 25(1st group)  525511135(3 groups)
    //op3 - 255(1st group) 25511135(3 groups)
    string curr;
    helper(s, 0, "", 0);
    return ans;
}
