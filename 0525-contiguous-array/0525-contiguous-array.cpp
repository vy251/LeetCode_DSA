class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxi=0,sum=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==0) sum-=1;
           else sum+=1;
           if(sum==0) maxi=max(maxi,i+1);
           if(m.find(sum)!=m.end()){
              maxi=max(maxi,i-m[sum]);
           }
           else m[sum]=i;
        }
        return maxi;
    }
};