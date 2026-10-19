class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int node,int c,vector<int>&color){
        color[node]=c;
        for(int i:graph[node]){
            if(color[i]!=-1&&color[i]==c){
                return false;
            }
            else if(color[i]==-1){
                if(!dfs(graph,i,1-c,color)) return false;
            }  
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
         vector<int>color(graph.size(),-1);
         for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!dfs(graph,i,0,color)) return false;
            }
         }
         return true;
    }
};