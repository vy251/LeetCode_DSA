class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int>m;
        int j=0;
        int maxi=1;
        for(int i=0;i<nums.size();i++){
           m[nums[i]]++;
           while(m.size()>2){
                m[nums[j]]--;
                if(m[nums[j]]==0) m.erase(nums[j]);
                j++;
           }
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};