class Solution {
public:
    int best(vector<int>& prices, int i, int k, vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        if (k == 0)
            return 0;
        if (k % 2 == 0) {
            return dp[i][k] = max(best(prices, i + 1, k - 1, dp) - prices[i],
                                  best(prices, i + 1, k, dp));
        } else {
            return dp[i][k] = max(best(prices, i + 1, k - 1, dp) + prices[i],
                                  best(prices, i + 1, k, dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k=k*2;
        vector<vector<int>> dp(n + 1, vector<int>(k+1, -1));
        return best(prices, 0, k, dp);
    }
};