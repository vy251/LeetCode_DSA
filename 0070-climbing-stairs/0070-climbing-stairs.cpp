class Solution {
public:
    int climbStairs(int n) {
        int on=0,en=1;
        for(int i=0;i<n;i++){
            int ans=on+en;
            on=en;
            en=ans;
        }
        return en;
    }
};