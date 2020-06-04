#define F first
#define S second
vector<int> Solution::solve(int A, vector<int> &B)
{
    vector<pair<int, int>> newB;

    int prev = INT_MAX;

    for (int i = 0; i < B.size(); i++)
    {
        if (prev > B[i])
        {
            newB.push_back(make_pair(i, B[i]));
            prev = B[i];
        }
    }

    vector<int> ans;
    int n = newB.size(), R = A;
    int i = 0;
    int min_st = newB[n - 1].S;
    int max_kicks = A / min_st;
    int temp = max_kicks * min_st;
    while (i < n)
    {

        if (R >= newB[i].S && (1 + (R - newB[i].S) / temp) == R / temp)
        {
            ans.push_back(newB[i].F);
            R -= newB[i].S;
        }
        else
            i++;
    }

    return ans;
}
