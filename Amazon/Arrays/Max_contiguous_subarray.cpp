//Kadanes Algo

int Solution::maxSubArray(const vector<int> &A) {
    int max_sum = INT_MIN;
    int n = A.size(), curr_sum=0;
    for(int i = 0; i < n; i++)
    {
       curr_sum += A[i];
       max_sum = max(max_sum,A[i]);
       if(curr_sum < 0) curr_sum = 0;
    }
    return max_sum;
}
