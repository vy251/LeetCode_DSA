class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi=0;
        int zo=0,j=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==0) zo++;
           while(zo>k){
             if(nums[j]==0) zo--;
             j++;
           }
           maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};