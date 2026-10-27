class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>des(n,INT_MAX);
        des[src]=0;
        for(int i=0;i<=k;i++){
            vector<int>temp=des;
            for(int j=0;j<flights.size();j++){
                int s=flights[j][0],d=flights[j][1],w=flights[j][2];
                if(des[s]!=INT_MAX&&temp[d]>des[s]+w){
                    temp[d]=des[s]+w;
                }
            }
            des=temp;
        }
        return des[dst]==INT_MAX?-1:des[dst];
    }
};