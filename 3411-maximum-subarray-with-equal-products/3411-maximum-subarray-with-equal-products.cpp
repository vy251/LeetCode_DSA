class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            long long p=1;
            long long g=nums[i];
            long long l=nums[i];
            for(int j=i;j<nums.size();j++){
                p*=nums[j];
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);
                if(p>g*l) break;
                if(p==g*l){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};