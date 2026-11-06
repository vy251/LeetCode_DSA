class Solution {
public:
    int countElements(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        if(maxi==mini) return 0;
        int c1=0,c2=0;
        for(int i:nums){
           if(i==mini) c1++;
           if(i==maxi) c2++;
        }
        return nums.size()-c1-c2;
    }
};