class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        int l=0,e=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target) l++;
            if(nums[i]==target) e++;
        }
        for(int i=0;i<e;i++){
           ans.push_back(l+i);
        }
        return ans;
    }
};