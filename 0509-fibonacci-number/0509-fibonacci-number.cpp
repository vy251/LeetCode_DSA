class Solution {
public:
    int fib(int n) {
        if(n==0||n==1) return n;
        int p=1,pp=0;
        for(int i=2;i<=n;i++){
            int ans=p+pp;
            pp=p;
            p=ans;
        }
        return p;
    }
};