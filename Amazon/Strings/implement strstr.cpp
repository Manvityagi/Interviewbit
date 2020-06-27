class Solution
{
public:
    vector<int> calculateLPS(string pat)
    {
        int n = pat.size();
        vector<int> LPS(n);
        LPS[0] = 0;
        int j = 1, i = 0;
        while (i < n && j < n)
        {
            if (pat[i] == pat[j])
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

    int KMPSearch(string pat, string txt)
    {
        vector<int> LPS = calculateLPS(pat);
        //LPS[i] = where to start mathcing in pat after a mismatch at pos i+1
        int i = 0, j = 0;
        int n = txt.size(), m = pat.size();
        while (i < n)
        {
            if (txt[i] == pat[j])
                i++, j++;
            else
            {
                if (j > 0)
                    j = LPS[j - 1];
                else
                    i++;
            }
            if (j == m)
                return (i - j);
        }
        return -1;
    }

    int strStr(string A, string B)
    {
        if (A == B)
            return 0;
        if (!A.size())
            return -1;
        if (!B.size())
            return 0;

        return KMPSearch(B, A);
    }
};