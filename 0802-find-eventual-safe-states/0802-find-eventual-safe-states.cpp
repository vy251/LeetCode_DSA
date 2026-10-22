class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>>radj(graph.size());
        vector<int>ind(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(int j:graph[i]){
                radj[j].push_back(i);
                ind[i]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<ind.size();i++){
           if(ind[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i:radj[node]){
                ind[i]--;
                if(ind[i]==0) q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};