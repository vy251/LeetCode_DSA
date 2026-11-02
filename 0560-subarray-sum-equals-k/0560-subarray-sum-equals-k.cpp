class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int ps=0;
        int count=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            ps+=nums[i];
            int remove=ps-k;
            count+=m[remove];
            m[ps]++;
        }
        return count;
    }
};