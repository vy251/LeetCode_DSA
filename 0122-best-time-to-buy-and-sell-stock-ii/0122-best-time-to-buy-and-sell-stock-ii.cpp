class Solution {
public:
    int best(vector<int>&prices,int i,int k,vector<vector<int>>&dp){
        if(i==prices.size()) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k==2){
            return dp[i][k]=max(best(prices,i+1,k-1,dp)-prices[i],best(prices,i+1,k,dp));
        }
        else{
            return dp[i][k]=max(best(prices,i+1,2,dp)+prices[i],best(prices,i+1,k,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return best(prices,0,2,dp);
    }
};