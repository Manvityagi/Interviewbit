class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {
        int n = height.size();
        if (!n)
            return 0;

        stack<int> st;
        st.push(0);
        int max_area = height[0];
        int i, curr_area;
        for (i = 1; i < n; i++)
        {
            while (!st.empty() && height[i] < height[st.top()])
            {
                int top = st.top();
                st.pop();

                if (st.empty())
                    curr_area = height[top] * i;
                else
                    curr_area = height[top] * (i - st.top() - 1);

                max_area = max(max_area, curr_area);
            }
            st.push(i);
        }

        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (st.empty())
                curr_area = height[top] * i;
            else
                curr_area = height[top] * (i - st.top() - 1);

            max_area = max(curr_area, max_area);
        }
        return max_area;
    }
};