class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(int i:t) m1[i]++;
        int mini=INT_MAX,count=0;
        int start=-1,j=0;
        for(int i=0;i<s.size();i++){
            m2[s[i]]++;
            if(m1.find(s[i])!=m1.end()&&m2[s[i]]<=m1[s[i]]) count++;
            while(count==t.size()){
                if(mini>i-j+1){
                    mini=i-j+1;
                    start=j;
                }
                if(m1.find(s[j])!=m1.end()&&m2[s[j]]<=m1[s[j]]) count--;
                m2[s[j]]--;
                j++;
            }
        }
        return mini==INT_MAX?"":s.substr(start,mini);
    }
};