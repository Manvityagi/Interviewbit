class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n));

        int cnt = 1;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;

        int dir = 0; //horizontal
        while (top <= bottom && left <= right)
        {
            if (dir == 0)
            { //top - left to right
                for (int i = left; i <= right; i++)
                {
                    ans[top][i] = cnt++;
                }
                top++, dir = 1;
            }
            else if (dir == 1) //right - top to bottom
            {
                for (int i = top; i <= bottom; i++)
                {
                    ans[i][right] = cnt++;
                }
                right--, dir = 2;
            }
            else if (dir == 2)
            { //bottom - right to left
                for (int i = right; i >= left; i--)
                {
                    ans[bottom][i] = cnt++;
                }
                bottom--, dir = 3;
            }
            else if (dir == 3)
            { //left - bottom to top
                for (int i = bottom; i >= top; i--)
                {
                    ans[i][left] = cnt++;
                }
                left++, dir = 0;
            }
        }
        return ans;
    }
};