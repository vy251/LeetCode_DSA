class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int maxi=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            while(m.find(s[j])!=m.end()){
              m[s[i]]--;
              if(m[s[i]]==0) m.erase(s[i]);
              i++;
            }
            m[s[j]]++;
            maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};