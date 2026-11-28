class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>m;
        for(int i:s) m[i]++;
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        string ans;
        while(pq.size()>1){
            char a=pq.top().second;
            int ca=pq.top().first;
            ca--;
            pq.pop();
            char b=pq.top().second;
            int cb=pq.top().first;
            cb--;
            pq.pop();
            if(ca>0) pq.push({ca,a});
            if(cb>0) pq.push({cb,b});
            ans.push_back(a);
            ans.push_back(b);
        }
        if(pq.top().first>1) return "";
        if(!pq.empty()){
           ans.push_back(pq.top().second);
           pq.pop();
        }
        return ans;
    }
};