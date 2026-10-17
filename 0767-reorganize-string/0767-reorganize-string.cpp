class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        priority_queue<pair<int,char>>pq;
        int maxfreq=0;
        char maxc;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']>maxfreq){
                maxfreq=freq[s[i]-'a'];
                maxc=s[i];
            }
            if(freq[s[i]-'a']>(s.size()+1)/2) return "";
        }
            string ans=s;
            int i=0;
            while(freq[maxc-'a']>0){
                ans[i]=maxc;
                i+=2;
                freq[maxc-'a']--;
            }
            for(char c='a';c<='z';c++){
                while(freq[c-'a']>0){
                    if(i>=s.size()) i=1;
                    ans[i]=c;
                    i+=2;
                    freq[c-'a']--;
                }
            }
        return ans;
    }
};