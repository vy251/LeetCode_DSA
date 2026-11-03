class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return n;
        int l=1,ll=0;
        for(int i=0;i<n;i++){
            int ans=l+ll;
            ll=l;
            l=ans;
        }
        return l;
    }
};