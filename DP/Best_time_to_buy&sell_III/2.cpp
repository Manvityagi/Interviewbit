//TIME COMPLEXITY = O(kn^2)

int Solution::maxProfit(const vector<int> &prices) {
     int n = prices.size();
     if (n == 0)
            return 0;
        vector<vector<int>> dp(3, vector<int>(n));

        for (int k = 1; k <= 2; k++)
        {
            int minprice = prices[0];
            for (int i = 1; i < n; i++)
            {
                    minprice = min(minprice, prices[i] - dp[k - 1][i - 1]);
                dp[k][i] = max(dp[k][i - 1], prices[i] - minprice);
            }
        }
        return dp[2][n - 1];
    }
   

