void Solution::rotate(vector<vector<int>> &A)
{
    int n = A.size();

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            swap(A[i][j], A[j][i]);

    for (int i = 0; i < A.size(); i++)
        reverse(A[i].begin(), A[i].end());
}
