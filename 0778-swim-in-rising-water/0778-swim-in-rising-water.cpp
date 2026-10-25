class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
             auto p=pq.top();
             pq.pop();
             int d=p.first;
             int i=p.second.first;
             int j=p.second.second;
             if(i==m-1&&j==n-1) return d;
             for(int k=0;k<4;k++){
                int r=i+dr[k];
                int c=j+dc[k];
                if(r<0||r>=m||c<0||c>=n) continue;
                int maxi=max(grid[r][c],grid[i][j]);
                int diff=max(maxi,dist[i][j]);
                if(dist[r][c]>diff){
                    dist[r][c]=diff;
                    pq.push({diff,{r,c}});
                }
             }
        }
        return -1;
    }
};