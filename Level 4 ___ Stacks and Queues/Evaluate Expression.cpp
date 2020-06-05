/* APPROACH

->


*/

/* LESSON


*/

int Solution::evalRPN(vector<string> &A)
{
    int n = A.size();
    if (n == 0)
        return 0;
    int curr_val = stoi(A[0]);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == "*" || A[i] == "+" || A[i] == "-" || A[i] == "/")
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            if (A[i] == "/")
                curr_val = op1 / op2;
            else if (A[i] == "*")
                curr_val = op1 * op2;
            else if (A[i] == "+")
                curr_val = op1 + op2;
            else
                curr_val = op1 - op2;

            st.push(curr_val);
        }
        else
            st.push(stoi(A[i]));
    }
    return curr_val;
}
