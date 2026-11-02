class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ls=0,ts=0;
        for(int i:nums) ts+=i;
        for(int i=0;i<nums.size();i++){
           int rs=ts-ls-nums[i];
           if(rs==ls) return i;
           ls+=nums[i];
        }
        return -1;
    }
};