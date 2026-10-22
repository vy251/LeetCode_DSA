class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>&vis,vector<int>&path,vector<bool>&safe,int i){
         vis[i]=1;
         path[i]=1;
         for(int j:graph[i]){
             if(!vis[j]){
                if(dfs(graph,vis,path,safe,j)){
                    return true;
                }
             }
             else if(path[j]){
                return true;
             }
         }
         path[i]=0;
         safe[i]=true;
         return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
          vector<int>vis(graph.size(),0);
          vector<int>path(graph.size(),0);
          vector<bool>safe(graph.size(),false);
          vector<int>ans;
          for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                dfs(graph,vis,path,safe,i);
            }
          }
          for(int i=0;i<graph.size();i++){
            if(safe[i]==true) ans.push_back(i);
          }
          return ans;
    }
};