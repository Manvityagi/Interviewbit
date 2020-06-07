/* APPROACH

-> Sorting se to very easy
-> O(n) ke liye, find the first index from beginning and end which is causing problem, and from the end too, find the last number causing problem
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

// O(NlogN)
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

//O(n)

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