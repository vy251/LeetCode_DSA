class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>nodes(n);
        for(int i=0;i<flights.size();i++){
            int s=flights[i][0],d=flights[i][1],w=flights[i][2];
            nodes[s].push_back({d,w});
        }
        queue<pair<int,pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        pq.push({0,{src,0}});
        dist[src]=0;
        while(!pq.empty()){
            auto p=pq.front();
            pq.pop();
            int stop=p.first;
            int node=p.second.first;
            int d=p.second.second;
            if(stop>k) continue;
            for(auto i:nodes[node]){
                int no=i.first;
                int w=i.second;
                if((dist[no]>d+w)){
                    dist[no]=d+w;
                    pq.push({stop+1,{no,dist[no]}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};