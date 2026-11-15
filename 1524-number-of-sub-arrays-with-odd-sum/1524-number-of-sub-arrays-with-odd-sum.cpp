class Solution {
public:
    int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int count=0,sum=0;
        int ec=1,oc=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0){
               count=(count+oc)%M;
               ec++;
            }
            else{
                count=(count+ec)%M;
                oc++;
            }
        }
        return count;
    }
};