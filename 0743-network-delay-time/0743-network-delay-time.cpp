class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>nodes(n);
        for(int i=0;i<times.size();i++){
            int s=times[i][0],d=times[i][1],w=times[i][2];
            nodes[s-1].push_back({d-1,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>d(n,INT_MAX);
        d[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();
            for(auto i:nodes[node]){
                int no=i.first;
                int w=i.second;
                if(d[no]>w+wt){
                    d[no]=w+wt;
                    pq.push({w+wt,no});
                }
            }
        }
        int maxi=*max_element(d.begin(),d.end());
        if(maxi==INT_MAX) return -1;
        return maxi;
    }
};