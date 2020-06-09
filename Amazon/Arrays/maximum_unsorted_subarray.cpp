/* APPROACH

----------------------------------------------------------------------------------------------------

APPROACH 1 -> Sorting 
Time - O(nlogn)
Space - O(n)

----------------------------------------------------------------------------------------------------

APPROACH 2 -> Using stacks 
Time - O(n)
Space - O(1)

We have to basically find the deepest element from left and right which is at the wrong place
and what is its right place is actually the left/right depth we are looking for
Let's say - 1,4,7,2,3,6,8 
starting from left, each nums[i] should be greater than st.top() as we maintain the stack in an ascending order,
if that is not the case, we go deep in the stack and find the right place for the element violating our order,
and keep updating that minimum depth 

Similarly for right


----------------------------------------------------------------------------------------------------

APPROACH 3 -> 
Time - O(n)
Space - O(1)

find the first index from beginning and end which is causing problem, and from the end too, find the last number causing problem
     ________left_________right_______
     sorted       unsorted      sorted
                     ||
                     || 
                Minimum in this range(min_range) should be greater than A[left] 
                Maximum in this range(max_range) should be lesser tham A[right]
                     ||
                If this is not the case, find the correct position of min_range 
                and max_range in A[0...left] && A[right....n-1] 



*/

/* LESSON


*/



// APPROACH 1 -> Sorting
vector<int> Solution::subUnsort(vector<int> &A)
{
    vector<int> temp = A;

    sort(temp.begin(), temp.end());

    if (A == temp)
        return {-1};
    int n = A.size();
    int left = -1, right = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != temp[i])
        {
            left = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] != temp[i])
        {
            right = i;
            break;
        }
    }

    return {left, right};
}






// APPROACH 2 -> Stacks
vector<int> Solution::subUnsort(vector<int> &A)
{
    stack<int> st; //storing indices
    int n = nums.size();

    int left_depth = n; //as it can be max n , (INT_MAX was also fine)
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[i] < nums[st.top()])
        {
            left_depth = min(left_depth, st.top());
            st.pop();
        }

        st.push(i);
    }

    if (left_depth == n)
        return {-1};

    int right_depth = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[i] > nums[st.top()])
        {
            right_depth = max(right_depth, st.top());
            st.pop();
        }
        st.push(i);
    }

    return {left_depth, right_depth};
}




// APPROACH 3 -> O(n)
vector<int> Solution::subUnsort(vector<int> &A)
{
    int n = A.size();
    int left = n, right;

    //left, right => first observation
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i + 1] < A[i])
        {
            left = i;
            break;
        }
    }
    if (left == n)
        return {-1};
    for (int i = n - 1; i > 0; i--)
    {
        if (A[i - 1] > A[i])
        {
            right = i;
            break;
        }
    }
    //find min_max in [left,right]
    int min_range = INT_MAX, max_range = INT_MIN;
    for (int i = left; i <= right; i++)
    {
        min_range = min(min_range, A[i]);
        max_range = max(max_range, A[i]);
    }
    for (int i = 0; i <= left; i++)
    {
        if (min_range < A[i])
        {
            left = i;
            break;
        }
    }
    for (int i = n - 1; i >= right; i--)
    {
        if (max_range > A[i])
        {
            right = i;
            break;
        }
    }
    return {left, right};
}