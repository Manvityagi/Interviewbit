// O(1) solution - strore the sum of all the rows and cols in last row and col, if that sum != len(row) || len(col) , replace everything with 0
//edge case - last row/col = 0

void setZeroes(vector<vector<int>> &A)
{
    unordered_set<int> rows;
    unordered_set<int> cols;
    int m = A.size();
    if (m == 0)
        return;
    int n = A[0].size();

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (rows.find(i) != rows.end() || cols.find(j) != cols.end())
                A[i][j] = 0;
}
