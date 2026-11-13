class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<mat.size();i++){
            m[i]=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) m[i]++;
            }
        }
        priority_queue<pair<int,int>>pq;
        for(auto i:m){
            pq.push({i.second,i.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};