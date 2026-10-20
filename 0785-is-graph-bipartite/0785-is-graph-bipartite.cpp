class Solution {
public:
    bool res=true;
    void dfs(vector<vector<int>>& graph,vector<int>&color,int i,int c){
         color[i]=c;
         for(int j:graph[i]){
            if(color[j]!=-1&&color[j]==c){
                res=false;
                break;
            }
            if(color[j]==-1){
                dfs(graph,color,j,1-c);
            }
         }
    }
    bool isBipartite(vector<vector<int>>& graph) {
         vector<int>color(graph.size(),-1);
         for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                dfs(graph,color,i,-1);
            }
         }
         return res;
    }
};