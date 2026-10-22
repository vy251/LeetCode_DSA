class Solution {
public:
    int minOperations(string s) {
        if(s.size()==2 && s[0]>s[1]) return -1;
        string temp=s;
        sort(temp.begin(),temp.end());
        if(temp==s) return 0;
        char mn=*min_element(s.begin(),s.end());
        char mx=*max_element(s.begin(),s.end());
        if(mn==s[0]||mx==s[s.size()-1]) return 1;
        else if(mn==s[s.size()-1]&&mx==s[0]){
            int cmn=0,cmx=0;
            for(int i=0;i<s.size();i++){
                if(s[i]==mn) cmn++;
                if(s[i]==mx) cmx++; 
            }
            if(cmn==1&&cmx==1) return 3;
        }
        return 2;
    }
};