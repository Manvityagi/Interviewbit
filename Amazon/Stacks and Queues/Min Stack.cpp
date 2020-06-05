/* APPROACH

-> This could have been done using an auxilary stack too, like a minstack kinda thing, which would just store the 
   minimum at each push and pop operation

-> Same approach of maintining a minimum corresponding to each stack entry can be implemented by storing a pair in stack 
   consisiting of the number and corresponding minimum till then

*/

/* LESSON


*/
stack<pair<int, int>> st;

MinStack::MinStack()
{
    while (!st.empty())
        st.pop();
}

void MinStack::push(int x)
{
    int currmin = st.empty() ? INT_MAX : st.top().second;
    int newmin = min(x, currmin);

    st.emplace(x, newmin);
}

void MinStack::pop()
{
    if (!st.empty())
        st.pop();
}

int MinStack::top()
{
    if (st.empty())
        return -1;
    return st.top().first;
}

int MinStack::getMin()
{
    if (st.empty())
        return -1;
    return st.top().second;
}
