vector<int> Solution::spiralOrder(const vector<vector<int>> &A)
{
    int m = A.size(); //rows
    if (m == 0)
        return {};
    vector<int> ans;
    int n = A[0].size();
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    int dir = 0; //horizontal
    while (top <= bottom && left <= right)
    {
        if (dir == 0)
        { //top - left to right
            for (int i = left; i <= right; i++)
            {
                ans.push_back(A[top][i]);
            }
            top++, dir = 1;
        }
        else if (dir == 1) //right - top to bottom
        {
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(A[i][right]);
            }
            right--, dir = 2;
        }
        else if (dir == 2)
        { //bottom - right to left
            for (int i = right; i >= left; i--)
            {
                ans.push_back(A[bottom][i]);
            }
            bottom--, dir = 3;
        }
        else if (dir == 3)
        { //left - bottom to top
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(A[i][left]);
            }
            left++, dir = 0;
        }
    }
    return ans;
}
