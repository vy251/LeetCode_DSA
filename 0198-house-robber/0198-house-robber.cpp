class Solution {
public:
    int possible(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+possible(nums,i+2,dp),possible(nums,i+1,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return possible(nums,0,dp);
    }
};