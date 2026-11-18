class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int c1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') c1++;
            if((i+1)%2==0){
               ans+=min(c1,2-c1);
               c1=0;
            }
        }
        return ans;
    }
};