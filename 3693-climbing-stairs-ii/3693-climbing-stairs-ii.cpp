class Solution {
public:
    int steps(vector<int>&costs,int n,int i,vector<int>&dp){
        if(i==n) return 0;
        int j=i+1;
        int cost=INT_MAX;
        if(dp[i]!=-1) return dp[i];
        if(j<=n){
            cost=costs[j-1]+(j-i)*(j-i)+steps(costs,n,i+1,dp);
        }
        j=i+2;
        if(j<=n){
            cost=min(cost,costs[j-1]+(j-i)*(j-i)+steps(costs,n,i+2,dp));
        }
        j=i+3;
        if(j<=n){
            cost=min(cost,costs[j-1]+(j-i)*(j-i)+steps(costs,n,i+3,dp));
        }
        return dp[i]=cost;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return steps(costs,n,0,dp);
    }
};