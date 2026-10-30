class Solution {
public:
    bool Isfreq(vector<int>&f1,vector<int>&f2){
        for(int i=0;i<26;i++){
            if(f1[i]!=f2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
         vector<int>f1(26,0);
         for(int i=0;i<s1.size();i++){
            f1[s1[i]-'a']++;
         }
         for(int i=0;i<=s2.size()-s1.size();i++){
            vector<int>f2(26,0);
            for(int j=i;j<i+s1.size();j++){
                f2[s2[j]-'a']++;
            }
            if(Isfreq(f1,f2)) return true;
         }
         return false;
    }
};