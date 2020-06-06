vector<int> Solution::wave(vector<int> &A)
{
    int n = A.size();
    sort(A.begin(),A.end());
    for(int i = 0; i < n; i+=2)
    {
        if(i+1 < n && A[i+1] > A[i]){
            swap(A[i],A[i+1]);
        }    
        if(i > 0 && A[i-1] > A[i]){
            swap(A[i],A[i-1]);
        }
    }
    return A;
}
