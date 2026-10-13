class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        // vector<vector<int>>vis(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int ans=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            ans=t;
            q.pop();
            for(int i=0;i<4;i++){
               int nr=r+dr[i];
               int nc=c+dc[i];
               if(nr<0||nr>=m||nc<0||nc>=n) continue;
               if(grid[nr][nc]==1){
                 grid[nr][nc]=2;
                 q.push({{nr,nc},t+1});
               }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};