class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
             string ans;
             int count=0;
             int sum=0;
             for(int i=0;i<s.size();i++){
                 count++;
                 sum+=(s[i]-'0');
                 if(count==k){
                    ans+=to_string(sum);
                    sum=0;
                    count=0;
                 }
             }
             if(count!=0)  ans+=to_string(sum);
             s=ans;
        }
        return s;
    }
};