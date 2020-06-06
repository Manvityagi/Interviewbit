/* APPROACH

->


*/

/* LESSON


*/

#include <bits/stdc++.h>
using namespace std;

//  Definition for an interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool comp(const Interval &A, const Interval &B)
{
    return A.start < B.start;
}

vector<Interval> Solution::merge(vector<Interval> &A)
{
    sort(A.begin(), A.end(), comp);
    vector<Interval> ans;
    ans.emplace_back(A[0].start, A[0].end);

    int i = 0;
    while (i < A.size())
    {
        auto &last = ans.back();
        auto curr = A[i];

        if (curr.start <= last.end)
            last.end = max(last.end, curr.end);
        else
            ans.emplace_back(A[i]);

        i++;
    }
    return ans;
}