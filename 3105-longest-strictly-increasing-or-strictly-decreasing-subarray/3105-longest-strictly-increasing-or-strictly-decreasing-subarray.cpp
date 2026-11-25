class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[j-1]){
                    maxi=max(maxi,j-i+1);
                }
                else break;
            }
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[j-1]){
                    maxi=max(maxi,j-i+1);
                }
                else break;
            }
        }
        return maxi==INT_MIN?1:maxi;
    }
};