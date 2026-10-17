class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                char c='a'+i;
                pq.push({freq[i],c});
            }
        }
        queue<pair<int,char>>q;
        string ans="";
        while(!pq.empty()){
             auto [count,c]=pq.top();
             pq.pop();
             count--;
             ans.push_back(c);
             if(q.size()>0){
                auto [a,b]=q.front();
                q.pop();
                if(a>0){
                    pq.push({a,b});
                }
             }
             if(count>0) q.push({count,c});
        }
        return ans.size()==s.size()?ans:"";
    }
};