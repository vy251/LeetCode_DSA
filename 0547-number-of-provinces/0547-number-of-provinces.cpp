class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<int>&vis,int i,int n){
        vis[i]=1;
        for(int j=0;j<n;j++){
           if(j!=i&&isConnected[i][j]==1&&!vis[j]){
              dfs(isConnected,vis,j,n);
           }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
        int n=isConnected[0].size();
        int ans=0;
        vector<int>vis(m,0);
        for(int i=0;i<m;i++){
            if(!vis[i]){
                ans++;
                dfs(isConnected,vis,i,n);
            }
        }
        return ans;
    }
};