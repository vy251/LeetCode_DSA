class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
         for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
         }
         sort(nums.begin(),nums.end(),greater<int>());
         int n=nums.size();
         long long sum=0;
         int size=n/2;
         if(n%2==0){
           for(int i=0;i<n;i++){
              if(i<size) sum+=nums[i]*nums[i];
              else sum-=nums[i]*nums[i];
           }
         }
         else{
             for(int i=0;i<n;i++){
                if(i<=size) sum+=nums[i]*nums[i];
                else sum-=nums[i]*nums[i];
             }
         }
         return sum;
    }
};