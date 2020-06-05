/* APPROACH

->Wohoo!! Immediate samller/bigger => stacks


*/

/* LESSON


*/

vector<int> Solution::prevSmaller(vector<int> &A)
{
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < A.size(); i++)
    {
        while (!st.empty() && st.top() >= A[i])
            st.pop();

        if (!st.empty())
            ans.emplace_back(st.top());
        else
            ans.emplace_back(-1);

        st.emplace(A[i]);
    }
    return ans;
}
