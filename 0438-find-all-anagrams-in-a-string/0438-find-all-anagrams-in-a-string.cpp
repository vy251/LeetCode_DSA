class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(int i:p) m1[i]++;
        int j=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            m2[s[i]]++;
            if(i-j+1>p.size()){
                m2[s[j]]--;
                if(m2[s[j]]==0) m2.erase(s[j]);
                j++;
            }
            if(i-j+1==p.size()){
               if(m1==m2) ans.push_back(j);
            }
        }
        return ans;
    }
};