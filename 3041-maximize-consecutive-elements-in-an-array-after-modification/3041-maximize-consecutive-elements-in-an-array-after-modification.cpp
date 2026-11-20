class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&nums,int cv,int i){
        int j=lower_bound(nums.begin()+i,nums.end(),cv)-nums.begin();
        if(j<nums.size()&&nums[j]==cv){
           return j;
        }
        return -1;
    }
    int solve(vector<int>&nums,int inc,int i){
        if(i>=nums.size()) return 0;
        if(dp[i][inc]!=-1) return dp[i][inc];
        int cv=nums[i]+inc;
        int len=0;
        int j=find(nums,cv+1,i+1);
        if(j!=-1){
           len=max(len,1+solve(nums,0,j));
        }
        j=find(nums,cv,i+1);
        if(j!=-1){
            len=max(len,1+solve(nums,1,j));
        }
        return dp[i][inc]=len;
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        dp.assign(nums.size()+1,vector<int>(2,-1));
        for(int i=0;i<nums.size();i++){
            res=max(res,1+max(solve(nums,0,i),solve(nums,1,i)));
        }
        return res;
    }
};