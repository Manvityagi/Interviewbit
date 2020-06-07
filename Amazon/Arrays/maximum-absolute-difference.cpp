/* APPROACH

-> Just expand |A[i] - A[j]] + |i-j| , and you will observe it comes up something like Manhattan distance
   having only 4 possible values
*/

/* LESSON


*/

int Solution::maxArr(vector<int> &A)
{
    int n = A.size();
    int sum_min = INT_MAX, sum_max = INT_MIN, diff_min = INT_MAX, diff_max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum_min = min(sum_min, A[i] + i);
        sum_max = max(sum_max, A[i] + i);
        diff_min = min(diff_min, A[i] - i);
        diff_max = max(diff_max, A[i] - i);
    }
    return max(sum_max - sum_min, diff_max - diff_min);
}
