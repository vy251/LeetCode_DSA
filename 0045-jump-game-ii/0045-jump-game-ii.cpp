class Solution {
public:
    int jump(vector<int>& nums) {
        int f=0,j=0,e=0;
        for(int i=0;i<nums.size()-1;i++){
            f=max(f,i+nums[i]);
            if(i==e){
              j++;
              e=f;
            }
        }
        return j;
    }
};